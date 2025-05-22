/*
 * Simulink_Simulation_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Simulink_Simulation".
 *
 * Model version              : 1.126
 * Simulink Coder version : 9.8 (R2022b) 13-May-2022
 * C source code generated on : Wed May 21 19:00:57 2025
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Simulink_Simulation.h"

/* Block parameters (default storage) */
P_Simulink_Simulation_T Simulink_Simulation_P = {
  /* Mask Parameter: PIDController_D
   * Referenced by: '<S114>/Derivative Gain'
   */
  0.0,

  /* Mask Parameter: PIDController_D_j
   * Referenced by: '<S65>/Derivative Gain'
   */
  0.0,

  /* Mask Parameter: PIDController_D_i
   * Referenced by: '<S163>/Derivative Gain'
   */
  0.0,

  /* Mask Parameter: PIDController_I
   * Referenced by: '<S68>/Integral Gain'
   */
  1.0,

  /* Mask Parameter: PIDController_I_m
   * Referenced by: '<S117>/Integral Gain'
   */
  1.0,

  /* Mask Parameter: PIDController_I_k
   * Referenced by: '<S166>/Integral Gain'
   */
  1.0,

  /* Mask Parameter: PIDAcceleration_I
   * Referenced by: '<S216>/Integral Gain'
   */
  3.17079509107051E+7,

  /* Mask Parameter: PIDController_InitialConditionF
   * Referenced by: '<S115>/Filter'
   */
  0.0,

  /* Mask Parameter: PIDController_InitialConditio_o
   * Referenced by: '<S66>/Filter'
   */
  0.0,

  /* Mask Parameter: PIDController_InitialConditio_j
   * Referenced by: '<S164>/Filter'
   */
  0.0,

  /* Mask Parameter: PIDController_InitialConditio_l
   * Referenced by: '<S120>/Integrator'
   */
  0.0,

  /* Mask Parameter: PIDController_InitialConditio_e
   * Referenced by: '<S71>/Integrator'
   */
  0.0,

  /* Mask Parameter: PIDController_InitialConditio_d
   * Referenced by: '<S169>/Integrator'
   */
  0.0,

  /* Mask Parameter: PIDAcceleration_InitialConditio
   * Referenced by: '<S219>/Integrator'
   */
  0.0,

  /* Mask Parameter: PIDController_N
   * Referenced by: '<S123>/Filter Coefficient'
   */
  100.0,

  /* Mask Parameter: PIDController_N_p
   * Referenced by: '<S74>/Filter Coefficient'
   */
  100.0,

  /* Mask Parameter: PIDController_N_g
   * Referenced by: '<S172>/Filter Coefficient'
   */
  100.0,

  /* Mask Parameter: PIDController_P
   * Referenced by: '<S125>/Proportional Gain'
   */
  1.0,

  /* Mask Parameter: PIDController_P_o
   * Referenced by: '<S76>/Proportional Gain'
   */
  1.0,

  /* Mask Parameter: PIDController_P_a
   * Referenced by: '<S174>/Proportional Gain'
   */
  1.0,

  /* Mask Parameter: PIDAcceleration_P
   * Referenced by: '<S224>/Proportional Gain'
   */
  158530.774553526,

  /* Expression: 0.0
   * Referenced by: '<S1>/Delay2'
   */
  0.0,

  /* Expression: 0.0
   * Referenced by: '<Root>/Delay2'
   */
  0.0,

  /* Expression: 0.0
   * Referenced by: '<Root>/Delay3'
   */
  0.0,

  /* Expression: 0.0
   * Referenced by: '<Root>/Delay'
   */
  0.0,

  /* Expression: 0.0
   * Referenced by: '<Root>/Delay1'
   */
  0.0,

  /* Expression: 0.0
   * Referenced by: '<S1>/Delay1'
   */
  0.0,

  /* Expression: 0.0
   * Referenced by: '<S1>/Delay'
   */
  0.0,

  /* Expression: 1600
   * Referenced by: '<S1>/setpoint 1'
   */
  1600.0,

  /* Expression: 1600
   * Referenced by: '<S1>/setpoint 2'
   */
  1600.0,

  /* Expression: pi
   * Referenced by: '<S1>/Constant'
   */
  3.1415926535897931,

  /* Expression: 0.1*pi/180
   * Referenced by: '<S1>/Gain'
   */
  0.0017453292519943296,

  /* Expression: 0.1*pi/180
   * Referenced by: '<S1>/Gain1'
   */
  0.0017453292519943296,

  /* Expression: 0.1
   * Referenced by: '<Root>/Constant2'
   */
  0.1,

  /* Expression: 0
   * Referenced by: '<Root>/Constant3'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Constant1'
   */
  0.0,

  /* Computed Parameter: Integrator_gainval
   * Referenced by: '<S120>/Integrator'
   */
  0.01,

  /* Computed Parameter: Filter_gainval
   * Referenced by: '<S115>/Filter'
   */
  0.01,

  /* Computed Parameter: Integrator_gainval_j
   * Referenced by: '<S71>/Integrator'
   */
  0.01,

  /* Computed Parameter: Filter_gainval_j
   * Referenced by: '<S66>/Filter'
   */
  0.01,

  /* Computed Parameter: Integrator_gainval_c
   * Referenced by: '<S169>/Integrator'
   */
  0.01,

  /* Computed Parameter: Filter_gainval_c
   * Referenced by: '<S164>/Filter'
   */
  0.01,

  /* Expression: 1
   * Referenced by: '<Root>/Constant'
   */
  1.0,

  /* Computed Parameter: Integrator_gainval_h
   * Referenced by: '<S219>/Integrator'
   */
  0.01
};
