/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "adc.h"
#include "i2c.h"
#include "memorymap.h"
#include "spi.h"
#include "tim.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "lcd.h"
#include <string.h>
#include <stdio.h>
#include "BNO055_STM32.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

HAL_StatusTypeDef ret;
float Ground_Commands[5];  // Float array to store received data
uint8_t buffer[sizeof(Ground_Commands)];  // Byte buffer for receiving

BNO055_Sensors_t BNO055;	/*!BNO055 data structure definition which hold euler, quaternion, linearaccel, gyro etc. parameters*/
uint8_t OffsetDatas[22];


/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MPU_Config(void);
/* USER CODE BEGIN PFP */

void IMU_Init(void);

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MPU Configuration--------------------------------------------------------*/
  MPU_Config();

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_TIM1_Init();
  MX_SPI4_Init();
  MX_ADC3_Init();
  MX_I2C2_Init();
  MX_I2C1_Init();
  /* USER CODE BEGIN 2 */

  LCD_Test();

//  if (HAL_I2C_Master_Transmit(&hi2c2, 0x28<<1, 1, sizeof(1), 50) != HAL_OK)
//  {
//    /* Calibration Error */
//    Error_Handler();
//  }

  IMU_Init();

  HAL_Delay(1000);

  if (HAL_ADCEx_Calibration_Start(&hadc3, ADC_CALIB_OFFSET, ADC_SINGLE_ENDED) != HAL_OK)
  {
    /* Calibration Error */
    Error_Handler();
  }


  ST7735_LCD_Driver.FillRect(&st7735_pObj, 0, 0, ST7735Ctx.Width,ST7735Ctx.Height, BLACK);

  uint8_t text[30];
  __IO uint16_t uhADCxConvertedValue;
  __IO uint32_t uhADCxInputVoltage;
  uint32_t tempsensor;





  #define Avg_Slope (2) // mV/°C
  #define V30  (620)  // mV, V30: 0.62V,datasheet P278

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {


	  HAL_ADC_Start(&hadc3);
	  HAL_ADC_PollForConversion(&hadc3, 100);
	  uhADCxConvertedValue = HAL_ADC_GetValue(&hadc3);
	  uhADCxInputVoltage = ((uhADCxConvertedValue * 3300) / 0xFFFF);
	  HAL_ADC_Stop(&hadc3);

	  tempsensor = ((int32_t)uhADCxInputVoltage - V30)/Avg_Slope + 30; // C



	  sprintf((char *)&text, "temp: %3lu 'C", tempsensor);
	  LCD_ShowString(0, 62, ST7735Ctx.Width,16,12,text);



	  HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3, 1);
	  HAL_Delay(100);
	  HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3, 0);
	  HAL_Delay(100);



	  ret = HAL_I2C_Master_Receive(&hi2c1, (0x20<<1) | 0x01, buffer, sizeof(buffer), 50);

	  if (ret == HAL_OK) {
	          memcpy(Ground_Commands, buffer, sizeof(Ground_Commands));  // Convert bytes to float array

	  }


	  sprintf((char *)&text, "Activated = %d", (int)Ground_Commands[4]);
	  LCD_ShowString(0, 20, ST7735Ctx.Width,16,12,text);


	  ReadData(&BNO055, SENSOR_QUATERNION|SENSOR_ACCEL|SENSOR_GYRO);


	  sprintf((char *)&text, "Ax = %.2f", BNO055.Accel.X);
	  LCD_ShowString(0, 40, ST7735Ctx.Width,16,12,text);






    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Supply configuration update enable
  */
  HAL_PWREx_ConfigSupply(PWR_LDO_SUPPLY);

  /** Configure the main internal regulator output voltage
  */
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE0);

  while(!__HAL_PWR_GET_FLAG(PWR_FLAG_VOSRDY)) {}

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 5;
  RCC_OscInitStruct.PLL.PLLN = 192;
  RCC_OscInitStruct.PLL.PLLP = 2;
  RCC_OscInitStruct.PLL.PLLQ = 2;
  RCC_OscInitStruct.PLL.PLLR = 2;
  RCC_OscInitStruct.PLL.PLLRGE = RCC_PLL1VCIRANGE_2;
  RCC_OscInitStruct.PLL.PLLVCOSEL = RCC_PLL1VCOWIDE;
  RCC_OscInitStruct.PLL.PLLFRACN = 0;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2
                              |RCC_CLOCKTYPE_D3PCLK1|RCC_CLOCKTYPE_D1PCLK1;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.SYSCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB3CLKDivider = RCC_APB3_DIV2;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_APB1_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_APB2_DIV2;
  RCC_ClkInitStruct.APB4CLKDivider = RCC_APB4_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_4) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */


void IMU_Init(void)
{
	BNO_Status_t Status = {0};

	//Init structure definition section
	BNO055_Init_t BNO055_InitStruct = {0};

	//Reset section
	ResetBNO055();

	/*============================ *BNO055 Initialization* ============================*/

	BNO055_InitStruct.ACC_Range = Range_16G;			//Range_X
	BNO055_InitStruct.Axis = DEFAULT_AXIS_REMAP;			//value will be entered by looking at the data sheet
	BNO055_InitStruct.Axis_sign = DEFAULT_AXIS_SIGN;		//value will be entered by looking at the data sheet
	BNO055_InitStruct.Clock_Source = CLOCK_EXTERNAL;		//CLOCK_EXTERNAL or CLOCK_INTERNAL
	BNO055_InitStruct.Mode = BNO055_NORMAL_MODE;			//BNO055_X_MODE   X:NORMAL, LOWPOWER, SUSPEND
	BNO055_InitStruct.OP_Modes = NDOF;
	BNO055_InitStruct.Unit_Sel = (UNIT_ORI_ANDROID | UNIT_TEMP_CELCIUS | UNIT_EUL_DEG | UNIT_GYRO_DPS | UNIT_ACC_MS2);
									//(UNIT_ORI_X | UNIT_TEMP_X | UNIT_EUL_X | UNIT_GYRO_X | UNIT_ACC_X)
	BNO055_Init(BNO055_InitStruct);

	//------------------BNO055 Calibration------------------

	/*This function allows the sensor offset data obtained after BNO055 is calibrated once to be written
	 *to the registers. In this way, there is no need to calibrate the sensor every time it is powered on.
	 */
	//setSensorOffsets(OffsetDatas);

	/*-=-=-=-=-=-=Calibration Part-=-=-=-=-=-=*/

	if(Calibrate_BNO055())
	{
		getSensorOffsets(OffsetDatas);
	}
	else
	{
		printf("Sensor calibration failed.\nFailed to retrieve offset data\n");
		Error_Handler();
	}

	Check_Status(&Status);
	printf("Selftest Result: %d\t",Status.STresult);
	printf("System Status: %d\t",Status.SYSStatus);
	printf("System Error: %d\n",Status.SYSError);

}


/* USER CODE END 4 */

 /* MPU Configuration */

void MPU_Config(void)
{
  MPU_Region_InitTypeDef MPU_InitStruct = {0};

  /* Disables the MPU */
  HAL_MPU_Disable();

  /** Initializes and configures the Region and the memory to be protected
  */
  MPU_InitStruct.Enable = MPU_REGION_ENABLE;
  MPU_InitStruct.Number = MPU_REGION_NUMBER0;
  MPU_InitStruct.BaseAddress = 0x0;
  MPU_InitStruct.Size = MPU_REGION_SIZE_4GB;
  MPU_InitStruct.SubRegionDisable = 0x87;
  MPU_InitStruct.TypeExtField = MPU_TEX_LEVEL0;
  MPU_InitStruct.AccessPermission = MPU_REGION_NO_ACCESS;
  MPU_InitStruct.DisableExec = MPU_INSTRUCTION_ACCESS_DISABLE;
  MPU_InitStruct.IsShareable = MPU_ACCESS_SHAREABLE;
  MPU_InitStruct.IsCacheable = MPU_ACCESS_NOT_CACHEABLE;
  MPU_InitStruct.IsBufferable = MPU_ACCESS_NOT_BUFFERABLE;

  HAL_MPU_ConfigRegion(&MPU_InitStruct);
  /* Enables the MPU */
  HAL_MPU_Enable(MPU_PRIVILEGED_DEFAULT);

}

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */


	ST7735_LCD_Driver.FillRect(&st7735_pObj, 0, 0, ST7735Ctx.Width,ST7735Ctx.Height, MAGENTA);


  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
