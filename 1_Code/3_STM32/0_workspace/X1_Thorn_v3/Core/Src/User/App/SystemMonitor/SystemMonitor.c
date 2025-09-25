/**
  ******************************************************************************
  * @file           : SystemMonitor.c
  * @brief          : Displays the critical variables on the LCD display and logs more data into the SD card
  *
  ******************************************************************************
*/

#include "cmsis_os2.h"
#include "FreeRTOS.h"
#include "SystemMonitor.h"
#include "../../Peripheral/LCD/lcd.h"
#include "../../Lib/Globals/Globals.h"
#include "../../Peripheral/ESC/ESC.h"
#include "../../Service/Logger/SD_Logger.h"
#include "../../Service/ErrorHandler/ErrorHandler.h"
#include <stdint.h>


static uint8_t text[64];
static int8_t * first_error_pointer;
telemetry_t New_Telemetry;
static uint8_t CSV_number = 0;


osThreadId_t SystemMonitor_TaskHandle;
uint32_t SystemMonitor_TaskBuffer[ 8192 ];
StaticTask_t SystemMonitor_TaskControlBlock;
const osThreadAttr_t SystemMonitor_Task_attributes = {
  .name = "SystemMonitor_Task",
  .cb_mem = &SystemMonitor_TaskControlBlock,
  .cb_size = sizeof(SystemMonitor_TaskControlBlock),
  .stack_mem = &SystemMonitor_TaskBuffer[0],
  .stack_size = sizeof(SystemMonitor_TaskBuffer),
  .priority = (osPriority_t) osPriorityLow,
};




void System_Monitor_Init(void)
{
	SystemMonitor_TaskHandle = osThreadNew(System_Monitor_Task, NULL, &SystemMonitor_Task_attributes);
}





void System_Monitor_Task(void *argument)
{
	System_Monitor_Start();

  for(;;)
  {
	  CSV_number = SD_Logger_GetLogNum(); // Abans estava a monitor Loop
	  System_Monitor_Loop();
	  osDelay(50);
  }
}



void System_Monitor_Start(void)
{

	SD_Logger_RegisterVariable(&New_Telemetry.Temperature, LOG_TYPE_UINT32, "Temperature");
	SD_Logger_RegisterVariable(&New_Telemetry.Voltage, LOG_TYPE_FLOAT, "Voltage");
	SD_Logger_RegisterVariable(&New_Telemetry.Current, LOG_TYPE_FLOAT, "Current");
	SD_Logger_RegisterVariable(&New_Telemetry.RPM2, LOG_TYPE_UINT32, "RPM2");
	SD_Logger_RegisterVariable(&New_Telemetry.RPM4, LOG_TYPE_UINT32, "RPM4");
	SD_Logger_RegisterVariable(&New_Telemetry.Throttle2, LOG_TYPE_UINT32, "Throttle2");
	SD_Logger_RegisterVariable(&New_Telemetry.Throttle4, LOG_TYPE_UINT32, "Throttle4");
	SD_Logger_RegisterVariable(ErrorHandler_GetErrors(), LOG_TYPE_UINT32, "ErrorCodes");

	first_error_pointer = ErrorHandler_GetFirstError();
}




void System_Monitor_Loop(void)
{

	Read_ESC_Telemetry(&New_Telemetry); // get rpms, voltage and temeperature from ESC telemetry


	if (New_Telemetry.Voltage < 12.5f && ErrorHandler_CheckError(ERROR_HANDLER_UNDERVOLTAGE) == 0)
	{
		ErrorHandler_SetError(ERROR_HANDLER_UNDERVOLTAGE);
	}
	else if (New_Telemetry.Voltage > 12.5f && ErrorHandler_CheckError(ERROR_HANDLER_UNDERVOLTAGE) == 1)
	{
		ErrorHandler_RemoveError(ERROR_HANDLER_UNDERVOLTAGE);
	}


	if (New_Telemetry.Temperature > 70U && ErrorHandler_CheckError(ERROR_HANDLER_OVERTEMPERATURE) == 0)
	{
		ErrorHandler_SetError(ERROR_HANDLER_OVERTEMPERATURE);
	}
	else if (New_Telemetry.Temperature < 70U && ErrorHandler_CheckError(ERROR_HANDLER_OVERTEMPERATURE) == 1)
	{
		ErrorHandler_RemoveError(ERROR_HANDLER_UNDERVOLTAGE);
	}



	sprintf((char *)&text, "rpm2=%lu | %lu                  	", New_Telemetry.RPM2, New_Telemetry.Throttle2);
	LCD_ShowString(4, 10, ST7735Ctx.Width, 16, 16, text);

	sprintf((char *)&text, "rpm4=%lu | %lu                  	", New_Telemetry.RPM4, New_Telemetry.Throttle4);
	LCD_ShowString(4, 25, ST7735Ctx.Width, 16, 16, text);

	sprintf((char *)&text, "Volt=%.2f | E=%d                     ", New_Telemetry.Voltage, (int)*first_error_pointer);
	LCD_ShowString(4, 40, ST7735Ctx.Width, 16, 16, text);

	sprintf((char *)&text, "Temp=%u | CSV=%u                 		", New_Telemetry.Temperature, CSV_number);
	LCD_ShowString(4, 55, ST7735Ctx.Width, 16, 16, text);

}

