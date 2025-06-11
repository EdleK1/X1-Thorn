/**
  ******************************************************************************
  * @file           : PitchController.c
  * @brief          : PID controller for the Pitch movement
  *
  *
  * q_error -> elevator
  ******************************************************************************
*/


// Controller Parameters

static const float Kp = 4.0f;
static const float Ki = 0.5f;
static const float Kd = 0.1f;
static const float dt  = 0.01f;
static const float tau = 0.01f;    // ~10 ms derivative filter

// Saturation Limits

static const float outputMin = -1.0f;
static const float outputMax = +1.0f;
static const float integratorMin = -0.5f;
static const float integratorMax = +0.5f;

// File-local state variables

static float integrator = 0.0f;
static float prevError = 0.0f;
static float dTermFilt = 0.0f;


void PitchController_Init(void)
{
    integrator = 0.0f;
    prevError  = 0.0f;
    dTermFilt  = 0.0f;
}



float PitchController_Update(float curr_error)
{
    // 1) Proportional term:
    float Pout = Kp * curr_error;

    // 2) Integral term with conditional‐integration anti-windup:

    float deltaI = 0.5f * Ki * dt * (curr_error + prevError); // Trapezoidal (Tustin) increment:

    if (integrator >= integratorMax && deltaI > 0.0f) // Check if integrator is at an upper limit AND deltaI would push it higher:
    {
        // Skip incrementing. Prevents further positive windup.
    }
    else if (integrator <= integratorMin && deltaI < 0.0f) // Check if integrator is at a lower limit AND deltaI would push it lower:
    {
        // Skip incrementing. Prevents further negative windup.
    }
    else // Safe to integrate:
    {
        integrator += deltaI; // There exists the possibility that this pushes it over the limit, but we dont care
    }

    float Iout = Ki * integrator;

    // 3) Derivative term:

    float derivativeRaw = (curr_error - prevError) / dt;


    float Dout;
    if (tau <= 0.0f)     // If Ts == 0, skip filtering (i.e. purely P(difference)/dt). Otherwise do:
    {
        Dout = Kd * derivativeRaw;
        dTermFilt = derivativeRaw; // store for completeness
    }
    else {
        float alpha = dt / (tau + dt);
        dTermFilt = alpha * derivativeRaw + (1.0f - alpha) * dTermFilt;
        Dout = Kd * dTermFilt;
    }

    // 5) Combine P, I, D:
    float output = Pout + Iout + Dout;

    // 6) Saturate final output to [outputMin, outputMax]:
    if (output > outputMax)
    {
        output = outputMax;
    }
    else if (output < outputMin)
    {
        output = outputMin;
    }

    // 7) Save current error for next cycle:
    prevError = curr_error;

    return output;
}
