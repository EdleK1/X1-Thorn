/**
  ******************************************************************************
  * @file           : Motor_PID.c
  * @brief          : General Purpose PID to control motor RPMs
  ******************************************************************************
*/


#include "Motor_PID.h"
#include <math.h>

void PID_Init(PID_HandleTypeDef *pid,
              float Kp, float Ki, float Kd,
              float dt,
              float outputMin, float outputMax,
              float integratorMin, float integratorMax,
              float tau)
{
    pid->Kp = Kp;
    pid->Ki = Ki;
    pid->Kd = Kd;
    pid->dt = dt;
    pid->outputMin = outputMin;
    pid->outputMax = outputMax;
    pid->integratorMin = integratorMin;
    pid->integratorMax = integratorMax;

    pid->integrator = 0.0f;
    pid->prevError  = 0.0f;
    pid->tau        = tau;

    /* initialize derivative filter state to zero */
    pid->dTermFilt  = 0.0f;
}

float PID_Update(PID_HandleTypeDef *pid, float measurement, float setpoint)
{
    /* 1) Compute error */
    float error = setpoint - measurement;

    /* 2) Proportional term */
    float Pout = pid->Kp * error;

    /* 3) Integral term (rectangle integration) */
    pid->integrator += 0.5f * pid->Ki * pid->dt * (error + pid->prevError);

    /* Anti‐windup: clamp integrator */
    if (pid->integrator > pid->integratorMax) {
        pid->integrator = pid->integratorMax;
    } else if (pid->integrator < pid->integratorMin) {
        pid->integrator = pid->integratorMin;
    }
    float Iout = pid->integrator;

    /* 4) Derivative term
     *    We can do a simple difference-based derivative:
     *        derivative = (error - prevError) / dt
     *    But often we low‐pass filter D to avoid noise. We use a 1st‐order filter:
     *
     *    α = dt / (τ + dt)
     *    dRaw  = (error - prevError) / dt
     *    dFilt = α * dRaw + (1 - α) * dTermFilt_prev
     *    Dout  = Kd * dFilt
     */

    float derivativeRaw = (error - pid->prevError) / pid->dt;
    float alpha = pid->dt / (pid->tau + pid->dt);
    pid->dTermFilt = alpha * derivativeRaw + (1.0f - alpha) * pid->dTermFilt;
    float Dout = pid->Kd * pid->dTermFilt;

    /* 5) Combine terms */
    float output = Pout + Iout + Dout;

    /* 6) Saturate PID output */
    if (output > pid->outputMax) {
        output = pid->outputMax;
    } else if (output < pid->outputMin) {
        output = pid->outputMin;
    }

    /* 7) Store current error for next iteration */
    pid->prevError = error;

    return output;
}
