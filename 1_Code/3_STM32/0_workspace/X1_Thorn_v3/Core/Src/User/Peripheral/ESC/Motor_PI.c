/**
  ******************************************************************************
  * @file           : Motor_PI.c
  * @brief          : General Purpose PI to control motor RPMs
  ******************************************************************************
*/


#include "Motor_PI.h"
#include <math.h>


void Motor_PID_Init(pid_handle_t *pid, float Kp, float Ki, float dt, float outputMin, float outputMax)
{
    pid->Kp = Kp;
    pid->Ki = Ki;
    pid->dt = dt;
    pid->outputMin = outputMin;
    pid->outputMax = outputMax;

    pid->integrator = 0.0f;
    pid->prevError  = 0.0f;
}

float Motor_PID_Update(pid_handle_t *pid, float measurement, float setpoint)
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

    float output = Pout + Iout;

    /* 5) Saturate PID output */

    if (output > pid->outputMax)
    {
    	output = pid->outputMax;
    }
    else if (output < pid->outputMin)
    {
    	output = pid->outputMin;
    }

    /* 6) Store current error for next iteration */

    pid->prevError = error;

    return output;
}
