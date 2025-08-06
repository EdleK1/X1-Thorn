/*
 * ESP32.h
 *
 *  Created on: Apr 25, 2025
 *      Author: marcv
 */

#ifndef SRC_USER_PERIPHERAL_ESP32_ESP32_H_
#define SRC_USER_PERIPHERAL_ESP32_ESP32_H_

#include <stdint.h>


typedef struct {
	float thrust_command;			  				// longitudinal acceleration
    float p_command;        					// roll rate
    float pitch_command, yaw_command; 			// pitch and roll angles
} esp32_commands_t;


void ESP32_Init(void);
void ESP32_Get_Commands(esp32_commands_t *esp32_commands);
void ESP32_Send_ESC_Status(void);
void UART_ESP32_RxCpltCallback(void);
void UART_ESP32_ErrorCallback(void);


#endif /* SRC_USER_PERIPHERAL_ESP32_ESP32_H_ */
