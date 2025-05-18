/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
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
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
typedef StaticTask_t osStaticThreadDef_t;
typedef StaticSemaphore_t osStaticSemaphoreDef_t;
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */

/* USER CODE END Variables */
/* Definitions for defaultTask */
osThreadId_t defaultTaskHandle;
const osThreadAttr_t defaultTask_attributes = {
  .name = "defaultTask",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};
/* Definitions for ESCTask */
osThreadId_t ESCTaskHandle;
uint32_t ESCTaskBuffer[ 500 ];
osStaticThreadDef_t ESCTaskControlBlock;
const osThreadAttr_t ESCTask_attributes = {
  .name = "ESCTask",
  .cb_mem = &ESCTaskControlBlock,
  .cb_size = sizeof(ESCTaskControlBlock),
  .stack_mem = &ESCTaskBuffer[0],
  .stack_size = sizeof(ESCTaskBuffer),
  .priority = (osPriority_t) osPriorityRealtime,
};
/* Definitions for xDshotTxDoneSemaphore */
osSemaphoreId_t xDshotTxDoneSemaphoreHandle;
osStaticSemaphoreDef_t xDshotTxDoneSemaphoreControlBlock;
const osSemaphoreAttr_t xDshotTxDoneSemaphore_attributes = {
  .name = "xDshotTxDoneSemaphore",
  .cb_mem = &xDshotTxDoneSemaphoreControlBlock,
  .cb_size = sizeof(xDshotTxDoneSemaphoreControlBlock),
};
/* Definitions for xDshotRxDoneSemaphore */
osSemaphoreId_t xDshotRxDoneSemaphoreHandle;
osStaticSemaphoreDef_t xDshotRxDoneSemaphoreControlBlock;
const osSemaphoreAttr_t xDshotRxDoneSemaphore_attributes = {
  .name = "xDshotRxDoneSemaphore",
  .cb_mem = &xDshotRxDoneSemaphoreControlBlock,
  .cb_size = sizeof(xDshotRxDoneSemaphoreControlBlock),
};

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

void StartDefaultTask(void *argument);
void StartESCTask(void *argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* Create the semaphores(s) */
  /* creation of xDshotTxDoneSemaphore */
  xDshotTxDoneSemaphoreHandle = osSemaphoreNew(1, 0, &xDshotTxDoneSemaphore_attributes);

  /* creation of xDshotRxDoneSemaphore */
  xDshotRxDoneSemaphoreHandle = osSemaphoreNew(1, 0, &xDshotRxDoneSemaphore_attributes);

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* creation of defaultTask */
  defaultTaskHandle = osThreadNew(StartDefaultTask, NULL, &defaultTask_attributes);

  /* creation of ESCTask */
  ESCTaskHandle = osThreadNew(StartESCTask, NULL, &ESCTask_attributes);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* USER CODE BEGIN RTOS_EVENTS */
  /* add events, ... */
  /* USER CODE END RTOS_EVENTS */

}

/* USER CODE BEGIN Header_StartDefaultTask */
/**
  * @brief  Function implementing the defaultTask thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_StartDefaultTask */
void StartDefaultTask(void *argument)
{
  /* USER CODE BEGIN StartDefaultTask */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END StartDefaultTask */
}

/* USER CODE BEGIN Header_StartESCTask */
/**
* @brief Function implementing the ESCTask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartESCTask */
void StartESCTask(void *argument)
{
  /* USER CODE BEGIN StartESCTask */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END StartESCTask */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */

