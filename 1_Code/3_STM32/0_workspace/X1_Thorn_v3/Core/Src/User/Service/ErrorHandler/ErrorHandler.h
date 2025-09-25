/*
 * ErrorHandler.h
 *
 *  Created on: Jul 14, 2025
 *      Author: marcv
 */

#ifndef SRC_USER_SERVICE_ERRORHANDLER_ERRORHANDLER_H_
#define SRC_USER_SERVICE_ERRORHANDLER_ERRORHANDLER_H_

#include <stdint.h>



#define ERROR_HANDLER_ESP32_NOT_RESPONDING 0
#define ERROR_HANDLER_BNO055_WRONG_UNITS 1
#define ERROR_HANDLER_ESC_NOT_RESPONDING 2
#define ERROR_HANDLER_DSHOT_NOT_INITIALIZED 3
#define ERROR_HANDLER_UNDERVOLTAGE 4
#define ERROR_HANDLER_OVERTEMPERATURE 5


void ErrorHandler_Init(void);
void ErrorHandler_SetError(uint8_t Error_Code);
void ErrorHandler_RemoveError(uint8_t Error_Code);
int8_t * ErrorHandler_GetFirstError(void);
uint32_t * ErrorHandler_GetErrors(void);
uint8_t ErrorHandler_CheckError(uint8_t Error_Code);

#endif /* SRC_USER_SERVICE_ERRORHANDLER_ERRORHANDLER_H_ */
