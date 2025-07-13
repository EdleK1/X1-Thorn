/*
 * Servo.h
 *
 *  Created on: Apr 25, 2025
 *      Author: marcv
 */

#ifndef SRC_USER_PERIPHERAL_SERVO_SERVO_H_
#define SRC_USER_PERIPHERAL_SERVO_SERVO_H_

#include "tim.h"

typedef struct {
    TIM_HandleTypeDef *htim;
    uint32_t channel;
    uint32_t setpoint;
} servo_t;


int Servo_Init(servo_t *servo, TIM_HandleTypeDef *htim, uint32_t channel, uint16_t setpoint);
void Servo_Set_Position(const servo_t *servo, int32_t position);


#endif /* SRC_USER_PERIPHERAL_SERVO_SERVO_H_ */
