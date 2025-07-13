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




void GroundCommands_Test_Init(void)
{

	Odometry_Init();
	GroundCommands_Init();
	HAL_Delay(1000);

	ST7735_LCD_Driver.FillRect(&st7735_pObj, 0, 0, ST7735Ctx.Width,ST7735Ctx.Height, BLACK);
}


void GroundCommands_Test_Loop(void)
{
	Odometry_Read(&curr_odometry_test);

	curr_attitude_test.w = curr_odometry_test.qw;
	curr_attitude_test.x = curr_odometry_test.qx;
	curr_attitude_test.y = curr_odometry_test.qy;
	curr_attitude_test.z = curr_odometry_test.qz;

	get_reference(curr_attitude_test, &curr_reference_test);


	sprintf((char *)&text, "ax=%.3f                   	", curr_reference_test.ax_ref);
	LCD_ShowString(4, 10, ST7735Ctx.Width, 16, 16, text);

	sprintf((char *)&text, "p=%.3f                   	", curr_reference_test.p_ref);
	LCD_ShowString(4, 25, ST7735Ctx.Width, 16, 16, text);

	sprintf((char *)&text, "q=%.3f                        ", curr_reference_test.q_ref);
	LCD_ShowString(4, 40, ST7735Ctx.Width, 16, 16, text);

	sprintf((char *)&text, "r=%.3f                  		", curr_reference_test.r_ref);
	LCD_ShowString(4, 55, ST7735Ctx.Width, 16, 16, text);

}
