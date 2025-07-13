/**
  ******************************************************************************
  * @file           : Control.c
  * @brief          : Generate setpoints for servos and motors from odometry and ground commands.
  *
  *
  * Odometry, GroundCommands -> actuators_t
  ******************************************************************************
*/

#include "cmsis_os2.h"
#include "FreeRTOS.h"
#include "Control.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tim.h"
#include "../GroundCommands/GroundCommands.h"
#include "../Odometry/Odometry.h"
#include <math.h>
#include "PitchController/PitchController.h"
#include "RollController/RollController.h"
#include "ThrustController/ThrustController.h"
#include "YawController/YawController.h"
#include "../../Peripheral/ESC/ESC.h"
#include "../../Peripheral/Servo/Servo.h"
#include "../../Service/Logger/SD_Logger.h"
#include "../SystemMonitor/SystemMonitor.h"
#include "../../Peripheral/LCD/lcd.h"


odometry_t curr_odometry;
reference_t curr_reference;
quaternion_t curr_attitude;
Actuators_t newActuators;
FlightControlOutputs_t newFlightControlOutputs;
servo_t Servo_L;
servo_t Servo_R;
osSemaphoreId_t  Control_Loop_Semaphore;
const static float Kq_PitchRate = 0.4f;
const static float Kr_YawRate = 0.2f;
const static int16_t ServoLim = 200;



// Definitions for Control_Task

osThreadId_t Control_TaskHandle;
uint32_t Control_TaskBuffer[ 8192 ];
StaticTask_t Control_TaskControlBlock;
const osThreadAttr_t Control_Task_attributes = {
  .name = "Control_Task",
  .cb_mem = &Control_TaskControlBlock,
  .cb_size = sizeof(Control_TaskControlBlock),
  .stack_mem = &Control_TaskBuffer[0],
  .stack_size = sizeof(Control_TaskBuffer),
  .priority = (osPriority_t) osPriorityHigh,
};


void Control_Init(void)
{
	Control_TaskHandle = osThreadNew(Control_Task, NULL, &Control_Task_attributes);
	Control_Loop_Semaphore = osSemaphoreNew(1, 0, NULL);
}


void Control_Task(void *argument)
{
	Control_Start();

  for(;;)
  {
	  osSemaphoreAcquire(Control_Loop_Semaphore, 100);
	  Control_Loop();
  }
}

uint8_t Control_Start(void)
{
	// Initialize LCD (we need it to calibrate the BNO055 sensor

	LCD_LoadScreen();

    // Initialize Odometry

	Odometry_Init();

    // Init Ground Commands

	GroundCommands_Init();

	// Initialize Actuators

	ESC_Init();
	Servo_Init(&Servo_L, &htim5, TIM_CHANNEL_2, 1570);
	Servo_Init(&Servo_R, &htim5, TIM_CHANNEL_1, 1550);

	// Initialize System Monitor Task

	System_Monitor_Init();

	// Initialize PIDs

	Yaw_Controller_Init();
	Roll_Controller_Init();
	Pitch_Controller_Init();
	Thrust_Controller_Init();

	// Initialize the logger

	SD_Logger_RegisterVariable(&curr_odometry.ax, LOG_TYPE_FLOAT, "curr_ax");
	SD_Logger_RegisterVariable(&curr_odometry.p, LOG_TYPE_FLOAT, "curr_roll_rate");
	SD_Logger_RegisterVariable(&curr_odometry.q, LOG_TYPE_FLOAT, "curr_pitch_rate");
	SD_Logger_RegisterVariable(&curr_odometry.r, LOG_TYPE_FLOAT, "curr_yaw_rate");
	SD_Logger_RegisterVariable(&curr_odometry.qw, LOG_TYPE_FLOAT, "curr_qw");
	SD_Logger_RegisterVariable(&curr_odometry.qx, LOG_TYPE_FLOAT, "curr_qx");
	SD_Logger_RegisterVariable(&curr_odometry.qy, LOG_TYPE_FLOAT, "curr_qy");
	SD_Logger_RegisterVariable(&curr_odometry.qz, LOG_TYPE_FLOAT, "curr_qz");
	SD_Logger_RegisterVariable(&curr_reference.ax_ref, LOG_TYPE_FLOAT, "ax_ref");
	SD_Logger_RegisterVariable(&curr_reference.p_ref, LOG_TYPE_FLOAT, "p_ref");
	SD_Logger_RegisterVariable(&curr_reference.q_ref, LOG_TYPE_FLOAT, "q_ref");
	SD_Logger_RegisterVariable(&curr_reference.r_ref, LOG_TYPE_FLOAT, "r_ref");
	SD_Logger_RegisterVariable(&newActuators.omega_L, LOG_TYPE_UINT32, "omega_L_ref");
	SD_Logger_RegisterVariable(&newActuators.omega_R, LOG_TYPE_UINT32, "omega_R_ref");
	SD_Logger_RegisterVariable(&newActuators.servo_L, LOG_TYPE_INT32, "servo_L_ref");
	SD_Logger_RegisterVariable(&newActuators.servo_R, LOG_TYPE_INT32, "servo_R_ref");

	SD_Logger_Init();

	// Initialize the Control timer

	HAL_TIM_Base_Start_IT(&htim2);

	return 0;
}




void Control_Loop(void)
{
	// Read Odometry

	Odometry_Read(&curr_odometry);

	curr_attitude.w = curr_odometry.qw;
	curr_attitude.x = curr_odometry.qx;
	curr_attitude.y = curr_odometry.qy;
	curr_attitude.z = curr_odometry.qz;

	// Get reference from ground commands (p_ref, q_ref, r_ref, ax_ref)

	get_reference(curr_attitude, &curr_reference);

	// Calculate the errors, from the way q_ref and r_ref are calculated, they do not need to be substracted their actual value

	float ax_error, p_error, q_error, r_error;

	ax_error = curr_reference.ax_ref - curr_odometry.ax;
	p_error = curr_reference.p_ref - curr_odometry.p;
	q_error = curr_reference.q_ref - Kq_PitchRate * curr_odometry.q;
	r_error = curr_reference.r_ref - Kr_YawRate * curr_odometry.r;

	// Thrust Control: Calculate required rpm1 and rpm2 from ThrustController

	newFlightControlOutputs.omegaThrustController = Thrust_Controller_Update(ax_error);

	// Attitude Control: Calculate required elevator, rudder and aileron from Roll, Pitch and Yaw controllers

	newFlightControlOutputs.aileron = Roll_Controller_Update(p_error);
	newFlightControlOutputs.elevator = Pitch_Controller_Update(q_error);
	newFlightControlOutputs.rudder = Yaw_Controller_Update(r_error);

	// Convert Controller outputs to servo PWM and motor RPM

	newActuators = Control_To_Actuators(newFlightControlOutputs);

	// Set the new motor RPM and servo PWM setpoints

	ESC_Set_RPMs(newActuators.omega_L, newActuators.omega_R);
	Servo_Set_Position(&Servo_L, newActuators.servo_L);
	Servo_Set_Position(&Servo_R, newActuators.servo_R);
}



Actuators_t Control_To_Actuators(FlightControlOutputs_t FlightControlOutputs)
{
	Actuators_t actuators_output;

	if (FlightControlOutputs.omegaThrustController/2 + FlightControlOutputs.rudder < 0)
	{
		actuators_output.omega_R = 0;
	}
	else
	{
		actuators_output.omega_R = (uint32_t) roundf(sqrt(FlightControlOutputs.omegaThrustController/2 + FlightControlOutputs.rudder));
	}


	if (FlightControlOutputs.omegaThrustController/2 - FlightControlOutputs.rudder < 0)
	{
		actuators_output.omega_L = 0;
	}
	else
	{
		actuators_output.omega_L = (uint32_t) roundf(sqrt(FlightControlOutputs.omegaThrustController/2 - FlightControlOutputs.rudder));
	}

	// Limit Servo range and make it round instead of truncating

	actuators_output.servo_R = (int32_t) roundf(-FlightControlOutputs.aileron - FlightControlOutputs.elevator);
	actuators_output.servo_L = (int32_t) roundf(-FlightControlOutputs.aileron + FlightControlOutputs.elevator);


	if (actuators_output.servo_R < -ServoLim)
	{
		actuators_output.servo_R = -ServoLim;
	}

	else if (actuators_output.servo_R > ServoLim)
	{
		actuators_output.servo_R = ServoLim;
	}


	if (actuators_output.servo_L < -ServoLim)
	{
		actuators_output.servo_L = -ServoLim;
	}

	else if (actuators_output.servo_L > ServoLim)
	{
		actuators_output.servo_L = ServoLim;
	}



	return actuators_output;
}



void TIM_PeriodElapsedCallback_Control_Timer(void)
{
	osSemaphoreRelease(Control_Loop_Semaphore);
}
