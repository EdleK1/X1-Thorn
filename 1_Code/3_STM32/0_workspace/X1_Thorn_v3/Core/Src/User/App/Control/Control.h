/*
 * Control.h
 *
 *  Created on: May 13, 2025
 *      Author: marcv
 */

#ifndef SRC_USER_APP_CONTROL_CONTROL_H_
#define SRC_USER_APP_CONTROL_CONTROL_H_

#include <stdint.h>
#include "cmsis_os2.h"

typedef struct {
    uint16_t servo_R;
    uint16_t servo_L;
    float omega_R;
    float omega_L;
} Actuators_t;

typedef struct {
    float aileron;
    float elevator;
    float rudder;
    float omegaThrustController_R;
    float omegaThrustController_L;
} FlightControlOutputs_t;



void Control_Init(void);
uint8_t Control_Start(void);
void Control_Loop(void);
void Control_Task(void *argument);

Actuators_t Control_To_Actuators(FlightControlOutputs_t FlightControlOutputs);
void Omega_Distribution(float omega, FlightControlOutputs_t *newFlightControlOutputs);
void TIM_PeriodElapsedCallback_Control_Timer(void);

#endif /* SRC_USER_APP_CONTROL_CONTROL_H_ */
