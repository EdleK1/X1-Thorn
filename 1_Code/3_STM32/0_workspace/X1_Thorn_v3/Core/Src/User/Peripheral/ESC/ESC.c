/**
  ******************************************************************************
  * @file           : ESC.c
  * @brief          : Provides a way of communicating with the ESC
  ******************************************************************************
*/

#include "ESC.h"
#include "../../Lib/Globals/Globals.h"
#include "cmsis_os2.h"
#include "FreeRTOS.h"
#include "tim.h"
#include "../../Lib/DshotProtocol/DShot.h"
#include "Motor_PI.h"
#include "../../Service/ErrorHandler/ErrorHandler.h"




uint16_t New_Throttle_2, New_Throttle_4;
uint32_t Curr_mRPM_2, Curr_mRPM_4;
static uint32_t Target_mRPM_2, Target_mRPM_4;
pid_handle_t Motor_PID_handle_2, Motor_PID_handle_4;

static float FFW_Gain = FFW_DATA_CONSTANT*16.0f;
static float PID_Throttle_2, PID_Throttle_4;

uint8_t ESC_Active, ESC_Ready_Flag;
uint8_t raw_telem[10];
static uint8_t telemetry_ARR = 0;
static uint8_t mRPM_validity = 0;

osSemaphoreId_t  ESC_Loop_Semaphore;


// Definitions for ESC_Task

osThreadId_t ESC_TaskHandle;
uint32_t ESC_TaskBuffer[ 8192 ];
StaticTask_t ESC_TaskControlBlock;
const osThreadAttr_t ESC_Task_attributes = {
  .name = "ESC_Task",
  .cb_mem = &ESC_TaskControlBlock,
  .cb_size = sizeof(ESC_TaskControlBlock),
  .stack_mem = &ESC_TaskBuffer[0],
  .stack_size = sizeof(ESC_TaskBuffer),
  .priority = (osPriority_t) osPriorityRealtime,
};




void ESC_Init(void)
{
	ESC_TaskHandle = osThreadNew(ESC_Task, NULL, &ESC_Task_attributes);
	ESC_Loop_Semaphore = osSemaphoreNew(1, 0, NULL);
}


void ESC_Task(void *argument)
{
	ESC_Start();

	for(;;)
	{
		ESC_Loop();
	}
}





uint8_t ESC_Start(void)
{

	if (DShot_Init() == 1)
	{
		ErrorHandler_SetError(ERROR_HANDLER_DSHOT_NOT_INITIALIZED);
	}

	// Init PIDs (Fer en un define porfa)

	Motor_PID_Init(&Motor_PID_handle_2, KP_MOTOR_PI, KI_MOTOR_PI, TS_MOTOR_PI, MOTOR_PI_OUTPUT_MIN, MOTOR_PI_OUTPUT_MAX);
	Motor_PID_Init(&Motor_PID_handle_4, KP_MOTOR_PI, KI_MOTOR_PI, TS_MOTOR_PI, MOTOR_PI_OUTPUT_MIN, MOTOR_PI_OUTPUT_MAX);

	// Initialize UART

	HAL_UART_Receive_IT(&huart8, raw_telem, 10);

	// Init ESC (We have to wait for it to start actually sending RPMs

	uint32_t armCycles = 8000;  // Arm cycles. a bit overkill

	HAL_TIM_Base_Start_IT(&htim17); // Initialize ESC timer to give

	for (uint32_t i = 0; i < armCycles; i++)
	{
		osSemaphoreAcquire(ESC_Loop_Semaphore, 1);
	    DShot_SendFrame(0, 0, &Curr_mRPM_2, &Curr_mRPM_4, 1, 0);
	}


	return 0;
}


void ESC_Loop(void)
{

	if (g_Status == 1 || g_Status == 2) // Aircraft either activated or in landing mode
	{

		// Calculate FFW Gain from Voltage and past Data

		float curr_Voltage = (raw_telem[1]<<8 | raw_telem[2])/100.0;

		if (curr_Voltage > 9.0f && curr_Voltage < 18.0f)	// Only update the value if we have a valid voltage reading
		{
			FFW_Gain = FFW_DATA_CONSTANT * curr_Voltage;
		}

		// Calculate FFW Throttle

		float FFW_Throttle_2 = Target_mRPM_2 / FFW_Gain;
		float FFW_Throttle_4 = Target_mRPM_4 / FFW_Gain;

		// Calculate new PID_Throttles if there are valid rpms and RPMs > 2000 (to avoid saturating the integrator when idling)

		if (mRPM_validity == 0 && Curr_mRPM_2 > 2000.0f && Curr_mRPM_4 > 2000.0f) // mRPM_validity == 0 means no error
		{
			PID_Throttle_2 = Motor_PID_Update(&Motor_PID_handle_2, Curr_mRPM_2, Target_mRPM_2);
			PID_Throttle_4 = Motor_PID_Update(&Motor_PID_handle_4, Curr_mRPM_4, Target_mRPM_4);
		}

		// Add the two contributions

		float New_Throttle_2_float = FFW_Throttle_2 + PID_Throttle_2;
		float New_Throttle_4_float = FFW_Throttle_4 + PID_Throttle_4;

		// Clamp the throttle

		if (New_Throttle_2_float < THROTTLE_MIN)
		{
			New_Throttle_2_float = THROTTLE_MIN;
		}
		else if (New_Throttle_2_float > THROTTLE_MAX)
		{
			New_Throttle_2_float = THROTTLE_MAX;
		}


		if (New_Throttle_4_float < THROTTLE_MIN)
		{
			New_Throttle_4_float = THROTTLE_MIN;
		}
		else if (New_Throttle_4_float > THROTTLE_MAX)
		{
			New_Throttle_4_float = THROTTLE_MAX;
		}

		// Cast into uint16

		New_Throttle_2 = (uint16_t)roundf(New_Throttle_2_float);
		New_Throttle_4 = (uint16_t)roundf(New_Throttle_4_float);


		if (++telemetry_ARR <= 40)
		{
			osSemaphoreAcquire(ESC_Loop_Semaphore, 10);
			mRPM_validity = DShot_SendFrame(New_Throttle_2, New_Throttle_4, &Curr_mRPM_2, &Curr_mRPM_4, 1, 0); // change the 0 0
		}

		else
		{
			telemetry_ARR = 0;
			osSemaphoreAcquire(ESC_Loop_Semaphore, 10);
			mRPM_validity = DShot_SendFrame(New_Throttle_2, New_Throttle_4, &Curr_mRPM_2, &Curr_mRPM_4, 1, 1);  // change the 0 0
		}


		g_ESC_Active = 1;

		if (Target_mRPM_2 == 0 && Target_mRPM_4 == 0 && Curr_mRPM_2 < 1500 && Curr_mRPM_4 < 1500) // abans era 500
		{
			g_ESC_Active = 0;
		}
	}
	else // Aircraft Deactivated
	{
		if (++telemetry_ARR <= 40)
		{
			osSemaphoreAcquire(ESC_Loop_Semaphore, 10);
			mRPM_validity = DShot_SendFrame(0, 0, &Curr_mRPM_2, &Curr_mRPM_4, 1, 0);
		}

		else
		{
			telemetry_ARR = 0;
			osSemaphoreAcquire(ESC_Loop_Semaphore, 10);
			mRPM_validity = DShot_SendFrame(0, 0, &Curr_mRPM_2, &Curr_mRPM_4, 1, 1);
		}
	}
}


void ESC_Set_RPMs(uint32_t mRPM_2, uint32_t mRPM_4)
{
	Target_mRPM_2 = mRPM_2;
	Target_mRPM_4 = mRPM_4;
}


void Read_ESC_Telemetry(telemetry_t *New_Telemetry)
{
	New_Telemetry->Temperature = raw_telem[0];
	New_Telemetry->Voltage = (raw_telem[1]<<8 | raw_telem[2])/100.0;
	New_Telemetry->Current = (raw_telem[3]<<8 | raw_telem[4])/100.0;
	New_Telemetry->Consumption = (raw_telem[5]<<8 | raw_telem[6]);
	New_Telemetry->RPM2 = Curr_mRPM_2;
	New_Telemetry->RPM4 = Curr_mRPM_4;
	New_Telemetry->CRC_bit = raw_telem[9];
	New_Telemetry->Throttle2 = (uint32_t)New_Throttle_2;
	New_Telemetry->Throttle4 = (uint32_t)New_Throttle_4;
}


void TIM_PeriodElapsedCallback_ESC_Timer(void)
{
	osSemaphoreRelease(ESC_Loop_Semaphore);
}


void UART_ESC_RxCpltCallback()
{
	HAL_UART_Receive_IT(&huart8, raw_telem, 10);
}


void UART_ESC_ErrorCallback()
{
	// Clear the error flags
	__HAL_UART_CLEAR_OREFLAG(&huart8);
	// Optionally log huart5.ErrorCode
	// Re-arm reception so you don’t lock up
	HAL_UART_Receive_IT(&huart8, raw_telem, 10);
}


