/*
 * ESC_PID.h
 *
 *  Created on: Jun 17, 2025
 *      Author: marcv
 */

#ifndef SRC_USER_PERIPHERAL_ESC_MOTOR_PI_H_
#define SRC_USER_PERIPHERAL_ESC_MOTOR_PI_H_

#include <stdint.h>

typedef struct {
    float Kp;
    float Ki;

    float integrator;
    float prevError;
    float outputMin;
    float outputMax;

    /* For anti‐windup: we’ll clamp integrator so that output stays in bounds. */
    float integratorMin;
    float integratorMax;

    float dt;         // timestep (s)
} pid_handle_t;

/**
 * @brief  Initialize a PID instance.
 * @param  pid       Pointer to PID handle
 * @param  Kp, Ki, Kd Gains
 * @param  dt        Timestep (s)
 * @param  outputMin/Max  Saturation limits of PID output
 * @param  integratorMin/Max  Limits on integrator term (anti‐windup)
 * @param  tau       Derivative filter time constant (if zero, do plain D)
 */
void PID_Init(pid_handle_t *pid, float Kp, float Ki, float dt, uint16_t outputMin, uint16_t outputMax, float integratorMin, float integratorMax);

/**
 * @brief  Compute PID output given setpoint and measurement
 * @param  pid       Pointer to PID handle
 * @param  setpoint  Desired value
 * @param  measurement Current measured value
 * @retval control output (clamped between outputMin, outputMax)
 */
uint16_t PID_Update(pid_handle_t *pid, float measurement, float setpoint);

#endif /* SRC_USER_PERIPHERAL_ESC_MOTOR_PI_H_ */
