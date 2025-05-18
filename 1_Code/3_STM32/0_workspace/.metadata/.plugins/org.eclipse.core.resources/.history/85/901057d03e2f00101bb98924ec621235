/**
  ******************************************************************************
  * @file           : TestAttitudeMPC.c
  * @brief          : Receive the commands from the esp32 and convert them to the reference to follow
  *
  *
  * Odometry, Ref, Omega, prevServoL prevServoR -> ServoL ServoR OmegaL OmegaR, sol_time
  ******************************************************************************
*/

#include "../../Core/Src/User/Peripheral/LCD/lcd.h"
#include "../../App/AttitudeMPC/AttitudeMPC.h"

MPC_Initial_State_t Aircraft_Initial_State;
MPC_Ref_t Aircraft_Reference;
MPC_Solution_t curr_MPC_sol;
static uint8_t text[50];


void AttitudeMPC_Test(void)
{

	Aircraft_Initial_State.p = 0;
	Aircraft_Initial_State.q = 0;
	Aircraft_Initial_State.r = 0;
	Aircraft_Initial_State.qW = 0.70710678;
	Aircraft_Initial_State.qX = 0;
	Aircraft_Initial_State.qY = -0.70710678;
	Aircraft_Initial_State.qZ = 0;
	Aircraft_Initial_State.OmegaR = 12500;
	Aircraft_Initial_State.OmegaL = 12500;
	Aircraft_Initial_State.ServoR = 0;
	Aircraft_Initial_State.ServoL = 0;

	Aircraft_Reference.p = 0;
	Aircraft_Reference.q = 0;
	Aircraft_Reference.r = 0;
	Aircraft_Reference.qW = 0.70710678;
	Aircraft_Reference.qX = 0;
	Aircraft_Reference.qY = -0.70710678;
	Aircraft_Reference.qZ = 0;
	Aircraft_Reference.OmegaR = 12500;
	Aircraft_Reference.OmegaL = 12500;
	Aircraft_Reference.ServoR = 0;
	Aircraft_Reference.ServoL = 0;
	Aircraft_Reference.DeltaOmega = 0;
	Aircraft_Reference.DeltaServoR = 0;
	Aircraft_Reference.DeltaServoL = 0;

	curr_MPC_sol.OmegaR = 12500;
	curr_MPC_sol.OmegaL = 12500;
	curr_MPC_sol.ServoR = 0;
	curr_MPC_sol.ServoL = 0;


	int status;
	static double elapsed_time;


	status = Attitude_MPC_Init();

	while (1)
	{
		elapsed_time =  Get_AttitudeMPC_Result(&Aircraft_Initial_State, &Aircraft_Reference, &curr_MPC_sol);

		sprintf((char *)&text, "time %f=                  ",elapsed_time);
		LCD_ShowString(4, 35, ST7735Ctx.Width, 16, 16, text);

		HAL_Delay(50);
	}





}




