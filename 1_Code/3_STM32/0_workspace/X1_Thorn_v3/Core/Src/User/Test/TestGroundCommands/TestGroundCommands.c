/**
  ******************************************************************************
  * @file           : TestGroundCommands.c
  * @brief          : Tests the reference
  *
  * activate = 0 if i2c communication failed, if the esp32 did not receive new controller data for 2 seconds or if the
  * triangle button was pressed on the ps4 controller
  *
  ******************************************************************************
*/

#include "../../Core/Src/User/Peripheral/LCD/lcd.h"
#include "../../Core/Src/User/App/GroundCommands/GroundCommands.h"
#include "../../Core/Src/User/App/Odometry/Odometry.h"

reference_t curr_reference_test;
odometry_t curr_odometry_test;
quaternion_t curr_attitude_test;
static uint8_t text[50];



static uint32_t tick1,tick2,tick3,tick4;
static uint32_t timdelta1,timdelta2;



void GroundCommands_Test_Init(void)
{

	Odometry_Init();
	GroundCommands_Init();
	HAL_Delay(1000);

	ST7735_LCD_Driver.FillRect(&st7735_pObj, 0, 0, ST7735Ctx.Width,ST7735Ctx.Height, BLACK);
}


void GroundCommands_Test_Loop(void)
{
  tick1 = HAL_GetTick();
  Odometry_Read(&curr_odometry_test);
  tick2 = HAL_GetTick();

  curr_attitude_test.w = curr_odometry_test.qw;
  curr_attitude_test.x = curr_odometry_test.qy;
  curr_attitude_test.y = curr_odometry_test.qx;
  curr_attitude_test.z = curr_odometry_test.qz;

  tick3 = HAL_GetTick();
  get_reference(curr_attitude_test, &curr_reference_test);
  tick4 = HAL_GetTick();

  timdelta1 = tick2 - tick1;
  timdelta2 = tick4 - tick3;

  sprintf((char *)&text, "ax_ref=%.3f p_ref=%.3f                  ",curr_reference_test.ax_ref,curr_reference_test.p_ref);
  LCD_ShowString(4, 20, ST7735Ctx.Width, 16, 16, text);

  sprintf((char *)&text, "q_ref=%.3f r_ref=%.3f                  ",curr_reference_test.q_ref,curr_reference_test.r_ref);
  LCD_ShowString(4, 35, ST7735Ctx.Width, 16, 16, text);
}
