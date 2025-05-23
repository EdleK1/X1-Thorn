/**
  ******************************************************************************
  * @file           : Test.c
  * @brief          : Main test program body
  ******************************************************************************
*/




/* USER CODE BEGIN Includes */

#include "../../Core/Src/User/Peripheral/LCD/lcd.h"
#include "TestESP32/TestESP32.h"
#include "TestGroundCommands/TestGroundCommands.h"
#include "TestOdometry/TestOdometry.h"

/* USER CODE END Includes */


/* USER CODE BEGIN Variable Declaration */



/* USER CODE END Variable Declaration */



void Test_Init(void)
{

    LCD_LoadScreen();

    Odometry_Test_Init();
//    ESP32_Test();
//    GroundCommands_Test();
//    AttitudeMPC_Test_Init(void)


}





void Test_Loop(void)
{
	Odometry_Test_Loop();
}
