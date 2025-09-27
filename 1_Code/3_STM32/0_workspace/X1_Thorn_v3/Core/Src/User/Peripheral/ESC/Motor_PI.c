/**
  ******************************************************************************
  * @file           : Motor_PI.c
  * @brief          : General Purpose PI to control motor RPMs
  ******************************************************************************
*/


#include "Motor_PI.h"
#include <math.h>


void Motor_PID_Init(pid_handle_t *pid, float Kp, float Ki, float dt, uint16_t outputMin, uint16_t outputMax)
{
    pid->Kp = Kp;
    pid->Ki = Ki;
    pid->dt = dt;
    pid->outputMin = outputMin;
    pid->outputMax = outputMax;

    pid->integrator = 0.0f;
    pid->prevError  = 0.0f;
}

uint16_t Motor_PID_Update(pid_handle_t *pid, float measurement, float setpoint)
{
    /* 1) Compute error */
    float error = setpoint - measurement;

    /* 2) Proportional term */
    float Pout = pid->Kp * error;

    /* 3) Integral term (rectangle integration) */
    pid->integrator += 0.5f * pid->Ki * pid->dt * (error + pid->prevError);

    /* Anti‐windup: clamp integrator */

    if (pid->integrator > (pid->outputMax - Pout))
    {
        pid->integrator = (pid->outputMax - Pout);
    }
    else if (pid->integrator < (pid->outputMin - Pout))
    {
        pid->integrator = (pid->outputMin - Pout);
    }

    float Iout = pid->integrator;

    /* 4) Combine terms */

    float outFloat = Pout + Iout;

    /* 5) Saturate PID output */

    if (outFloat > pid->outputMax)
    {
    	outFloat = pid->outputMax;
    }
    else if (outFloat < pid->outputMin)
    {
    	outFloat = pid->outputMin;
    }

    /* 6) Round FloatOutput */

    uint16_t output = (uint16_t)roundf(outFloat);

    /* 7) Store current error for next iteration */
    pid->prevError = error;

    return output;
}
