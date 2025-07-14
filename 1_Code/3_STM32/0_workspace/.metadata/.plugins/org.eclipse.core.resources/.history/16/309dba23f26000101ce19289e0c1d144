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
#define ERROR_HANDLER_BNO055_NOT_RESPONDING 1
#define ERROR_HANDLER_ESC_NOT_RESPONDING 2



void ErrorHandler_SetError(uint8_t Error_Code);
void ErrorHandler_RemoveError(uint8_t Error_Code);
int8_t ErrorHandler_GetFirstError(void);
void ErrorHandler_LogInit(void);
uint32_t ErrorHandler_GetErrors(void);

#endif /* SRC_USER_SERVICE_ERRORHANDLER_ERRORHANDLER_H_ */
