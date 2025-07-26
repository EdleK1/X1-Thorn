/*
 * SD_LOGGER.h
 *
 *  Created on: 28 june. 2025
 *      Author: david
 */


#ifndef INC_SD_LOGGER_H_
#define INC_SD_LOGGER_H_


#include "FreeRTOS.h"
#include "math.h"
#include "cmsis_os.h"
#include "fatfs.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>


extern SD_HandleTypeDef hsd1;


#define SD_LOGGER_DEBUG_ENABLE
#define SD_LOGGER_DEBUG_ERROR_ENABLE



typedef enum
{
    LOG_TYPE_INT32,
    LOG_TYPE_UINT32,
    LOG_TYPE_FLOAT
} SD_Logger_DataType_t;


void 		SD_Logger_Init(void);

uint8_t		SD_Logger_RegisterVariable(void* var_ptr, SD_Logger_DataType_t type, const char* header_name);

uint8_t		SD_Logger_GetLogNum(void);


#endif /* INC_SD_LOGGER_H_ */
