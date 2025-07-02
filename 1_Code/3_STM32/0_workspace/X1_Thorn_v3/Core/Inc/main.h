/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32h7xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define E3_Pin GPIO_PIN_3
#define E3_GPIO_Port GPIOE
#define KEY_Pin GPIO_PIN_13
#define KEY_GPIO_Port GPIOC
#define ServoR_SIGNAL_Pin GPIO_PIN_0
#define ServoR_SIGNAL_GPIO_Port GPIOA
#define ServoL_SIGNAL_Pin GPIO_PIN_1
#define ServoL_SIGNAL_GPIO_Port GPIOA
#define Debug2_Pin GPIO_PIN_3
#define Debug2_GPIO_Port GPIOA
#define DShot_MOTOR4_Pin GPIO_PIN_6
#define DShot_MOTOR4_GPIO_Port GPIOA
#define DShot_MOTOR2_Pin GPIO_PIN_7
#define DShot_MOTOR2_GPIO_Port GPIOA
#define ADC_CURR_Pin GPIO_PIN_0
#define ADC_CURR_GPIO_Port GPIOB
#define Debug1_Pin GPIO_PIN_9
#define Debug1_GPIO_Port GPIOE
#define LCD_CS_Pin GPIO_PIN_11
#define LCD_CS_GPIO_Port GPIOE
#define LCD_WR_RS_Pin GPIO_PIN_13
#define LCD_WR_RS_GPIO_Port GPIOE
#define I2C_SCL_IMU_Pin GPIO_PIN_10
#define I2C_SCL_IMU_GPIO_Port GPIOB
#define I2C_SDA_IMU_Pin GPIO_PIN_11
#define I2C_SDA_IMU_GPIO_Port GPIOB
#define UART_RX_ESP32_Pin GPIO_PIN_12
#define UART_RX_ESP32_GPIO_Port GPIOB
#define UART_TX_ESP32_Pin GPIO_PIN_13
#define UART_TX_ESP32_GPIO_Port GPIOB
#define UART_RX_ESC_Pin GPIO_PIN_0
#define UART_RX_ESC_GPIO_Port GPIOE
#define UART_TX_ESC_Pin GPIO_PIN_1
#define UART_TX_ESC_GPIO_Port GPIOE

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
