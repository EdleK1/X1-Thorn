/**
  ******************************************************************************
  * @file           : Test.c
  * @brief          : ESP32 communications test
  ******************************************************************************
*/


#include "../../Core/Src/User/Peripheral/LCD/lcd.h"
#include "tim.h"
#include "../../Core/Src/User/Peripheral/ESP32/ESP32.h"

static uint8_t active;
esp32_commands_t curr_esp32_commands_test;
static uint8_t text[50];


void ESP32_Test(void)
{
	esp32_Init();

	ST7735_LCD_Driver.FillRect(&st7735_pObj, 0, 0, ST7735Ctx.Width,ST7735Ctx.Height, BLACK);

    HAL_TIM_Base_Start_IT(&htim17);
    HAL_TIM_Base_Start(&htim17);

    while (1)
    {

  	  sprintf((char *)&text, "ax=%.2f p=%.2f                  ",curr_esp32_commands_test.ax_command,curr_esp32_commands_test.p_command);
  	  LCD_ShowString(4, 22, ST7735Ctx.Width, 16, 16, text);

  	  sprintf((char *)&text, "roll=%.2f pitch=%.2f            ",curr_esp32_commands_test.roll_command,curr_esp32_commands_test.pitch_command);
  	  LCD_ShowString(4, 40, ST7735Ctx.Width, 16, 16, text);

  	  sprintf((char *)&text, "active=%u            ",active);
  	  LCD_ShowString(4, 58, ST7735Ctx.Width, 16, 16, text);

  	  HAL_Delay(50);

    }

}


//void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
//{
//  /* Prevent unused argument(s) compilation warning */
//  if (htim == &htim17)
//  {
//	  active = get_esp32_commands(&curr_esp32_commands_test);
//  }
//
//  /* NOTE : This function should not be modified, when the callback is needed,
//            the HAL_TIM_PeriodElapsedCallback could be implemented in the user file
//   */
//}
