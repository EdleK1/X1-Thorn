/**
  ******************************************************************************
  * @file           : PitchController.c
  * @brief          : PID controller for the Pitch movement
  *
  *
  * q_error -> elevator
  ******************************************************************************
*/

#include "PitchController.h"
#include <math.h>


// Controller Parameters

static const float Kp = -150.0f; // -300
static const float Ki = -90.0f; // -50
static const float Kd = -70.0f; // -10
static const float Kq = 0.15f; // -10
static const float dt  = 0.01f;
static const float tau = 1.0f/20.0f;    // N = 20

// Saturation Limits

static const float outputMin = -200.0f;
static const float outputMax = +200.0f;
static const float integratorMin = -100.0f;
static const float integratorMax = +100.0f;

// File-local state variables

static float integrator = 0.0f;
static float prevError = 0.0f;
static float dTermFilt = 0.0f;


void Pitch_Controller_Init(void)
{
    integrator = 0.0f;
    prevError  = 0.0f;
    dTermFilt  = 0.0f;
}



float Pitch_Controller_Update(float pitch_ref, float q_measured)
{
	// 0) Calculate error

	float q_ref = Kq * pitch_ref;

	float curr_error = q_ref - q_measured;

    // 1) Proportional term:

    float Pout = Kp * curr_error;

    // 2) Integral term with conditional‐integration anti-windup:

    integrator += 0.5f * Ki * dt * (curr_error + prevError);

    if (integrator > integratorMax)
    {
        integrator = integratorMax;
    }
    else if (integrator < integratorMin)
    {
        integrator = integratorMin;
    }

    float Iout = integrator;

    // 3) Derivative term:

    float derivativeRaw = (curr_error - prevError) / dt;

	float alpha = dt / (tau + dt);
	dTermFilt = alpha * derivativeRaw + (1.0f - alpha) * dTermFilt;
    float  Dout = Kd * dTermFilt;

    // 4) Combine P, I, D:

    float output = Pout + Iout + Dout;

    // 5) Saturate final output to [outputMin, outputMax]:

    if (output > outputMax)
    {
        output = outputMax;
    }
    else if (output < outputMin)
    {
        output = outputMin;
    }

    // 6) Save current error for next cycle:

    prevError = curr_error;

    return output;
}
