/*
 * ESC.h
 *
 *  Created on: Jun 17, 2025
 *      Author: marcv
 */

#ifndef SRC_USER_PERIPHERAL_ESC_ESC_H_
#define SRC_USER_PERIPHERAL_ESC_ESC_H_

#include <stdint.h>
#include "cmsis_os2.h"
#include "usart.h"

#define FFW_DATA_CONSTANT 1.3585f
#define KP_MOTOR_PI 0.25f
#define KI_MOTOR_PI 3.0f
#define TS_MOTOR_PI 1/2000.0f
#define MOTOR_PI_OUTPUT_MIN -300.0f
#define MOTOR_PI_OUTPUT_MAX 300.0f
#define THROTTLE_MIN 60.0f
#define THROTTLE_MAX 2047.0f


typedef struct {
	uint8_t Temperature;
    float Voltage, Current, Consumption;
    uint32_t RPM2, RPM4;
    uint8_t CRC_bit;
    uint32_t Throttle2, Throttle4;
} telemetry_t;


void ESC_Init(void);
void ESC_Task(void *argument);
uint8_t ESC_Start(void);
void ESC_Set_RPMs(uint32_t mRPM_2, uint32_t mRPM_4);
void ESC_Loop(void);
void Read_ESC_Telemetry(telemetry_t *New_Telemetry);
void UART_ESC_RxCpltCallback();
void UART_ESC_ErrorCallback();
void TIM_PeriodElapsedCallback_ESC_Timer(void);


#endif /* SRC_USER_PERIPHERAL_ESC_ESC_H_ */
