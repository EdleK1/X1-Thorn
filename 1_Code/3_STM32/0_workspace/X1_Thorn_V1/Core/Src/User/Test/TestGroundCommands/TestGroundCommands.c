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
#include "tim.h"

reference_t curr_reference;
odometry_t curr_odometry;
quaternion_t curr_attitude;
static uint8_t text[50];
static uint8_t active;



static uint32_t tick1,tick2,tick3,tick4;
static uint32_t timdelta1,timdelta2;



void GroundCommands_Test(void)
{

	Odometry_Init();
	GroundCommands_Init();
	HAL_Delay(1000);

	ST7735_LCD_Driver.FillRect(&st7735_pObj, 0, 0, ST7735Ctx.Width,ST7735Ctx.Height, BLACK);

    HAL_TIM_Base_Start_IT(&htim17);
    HAL_TIM_Base_Start(&htim17);

    while (1)
    {
  	  sprintf((char *)&text, "q0=%.2f q1=%.2f                  ",curr_reference.q0_ref,curr_reference.q1_ref);
  	  LCD_ShowString(4, 20, ST7735Ctx.Width, 16, 16, text);

  	  sprintf((char *)&text, "q2=%.2f q3=%.2f                  ",curr_reference.q2_ref,curr_reference.q3_ref);
  	  LCD_ShowString(4, 35, ST7735Ctx.Width, 16, 16, text);

  	  HAL_Delay(50);
    }

}





void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  /* Prevent unused argument(s) compilation warning */
  if (htim == &htim17)
  {

	  tick1 = HAL_GetTick();
	  Odometry_Read(&curr_odometry);
	  tick2 = HAL_GetTick();

	  curr_attitude.w = curr_odometry.q0;
	  curr_attitude.x = curr_odometry.q1;
	  curr_attitude.y = curr_odometry.q2;
	  curr_attitude.z = curr_odometry.q3;

	  tick3 = HAL_GetTick();
	  active = get_reference(&curr_attitude, &curr_reference);
	  tick4 = HAL_GetTick();

	  timdelta1 = tick1 - tick2;
	  timdelta2 = tick3 - tick4;

  }

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_TIM_PeriodElapsedCallback could be implemented in the user file
   */
}
