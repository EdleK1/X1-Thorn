/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'Simulink_Simulation/Aircraft Dynamics/Solver Configuration'.
 */

#include <math.h>
#include <string.h>
#include "pm_std.h"
#include "sm_std.h"
#include "ne_std.h"
#include "ne_dae.h"
#include "sm_ssci_run_time_errors.h"
#include "sm_RuntimeDerivedValuesBundle.h"
#include "sm_CTarget.h"

void Simulink_Simulation_6a081443_1_setTargets(const RuntimeDerivedValuesBundle *
  rtdv, CTarget *targets)
{
  (void) rtdv;
  (void) targets;
}

void Simulink_Simulation_6a081443_1_resetAsmStateVector(const void *mech, double
  *state)
{
  double xx[1];
  (void) mech;
  xx[0] = 0.0;
  state[0] = xx[0];
  state[1] = xx[0];
  state[2] = xx[0];
  state[3] = 1.0;
  state[4] = xx[0];
  state[5] = xx[0];
  state[6] = xx[0];
  state[7] = xx[0];
  state[8] = xx[0];
  state[9] = xx[0];
  state[10] = xx[0];
  state[11] = xx[0];
  state[12] = xx[0];
  state[13] = xx[0];
  state[14] = xx[0];
  state[15] = xx[0];
  state[16] = xx[0];
}

void Simulink_Simulation_6a081443_1_initializeTrackedAngleState(const void *mech,
  const RuntimeDerivedValuesBundle *rtdv, const int *modeVector, const double
  *motionData, double *state)
{
  const double *rtdvd = rtdv->mDoubles.mValues;
  const int *rtdvi = rtdv->mInts.mValues;
  (void) mech;
  (void) rtdvd;
  (void) rtdvi;
  (void) state;
  (void) modeVector;
  (void) motionData;
}

void Simulink_Simulation_6a081443_1_computeDiscreteState(const void *mech, const
  RuntimeDerivedValuesBundle *rtdv, double *state)
{
  const double *rtdvd = rtdv->mDoubles.mValues;
  const int *rtdvi = rtdv->mInts.mValues;
  (void) mech;
  (void) rtdvd;
  (void) rtdvi;
  (void) state;
}

void Simulink_Simulation_6a081443_1_adjustPosition(const void *mech, const
  double *dofDeltas, double *state)
{
  double xx[11];
  (void) mech;
  xx[0] = state[3];
  xx[1] = state[4];
  xx[2] = state[5];
  xx[3] = state[6];
  xx[4] = dofDeltas[3];
  xx[5] = dofDeltas[4];
  xx[6] = dofDeltas[5];
  pm_math_Quaternion_compDeriv_ra(xx + 0, xx + 4, xx + 7);
  xx[0] = state[3] + xx[7];
  xx[1] = state[4] + xx[8];
  xx[2] = state[5] + xx[9];
  xx[3] = state[6] + xx[10];
  xx[4] = sqrt(xx[0] * xx[0] + xx[1] * xx[1] + xx[2] * xx[2] + xx[3] * xx[3]);
  xx[5] = 1.0e-64;
  if (xx[5] > xx[4])
    xx[4] = xx[5];
  state[0] = state[0] + dofDeltas[0];
  state[1] = state[1] + dofDeltas[1];
  state[2] = state[2] + dofDeltas[2];
  state[3] = xx[0] / xx[4];
  state[4] = xx[1] / xx[4];
  state[5] = xx[2] / xx[4];
  state[6] = xx[3] / xx[4];
  state[13] = state[13] + dofDeltas[6];
  state[15] = state[15] + dofDeltas[7];
}

static void perturbAsmJointPrimitiveState_0_0(double mag, double *state)
{
  state[0] = state[0] + mag;
}

static void perturbAsmJointPrimitiveState_0_0v(double mag, double *state)
{
  state[0] = state[0] + mag;
  state[7] = state[7] - 0.875 * mag;
}

static void perturbAsmJointPrimitiveState_0_1(double mag, double *state)
{
  state[1] = state[1] + mag;
}

static void perturbAsmJointPrimitiveState_0_1v(double mag, double *state)
{
  state[1] = state[1] + mag;
  state[8] = state[8] - 0.875 * mag;
}

static void perturbAsmJointPrimitiveState_0_2(double mag, double *state)
{
  state[2] = state[2] + mag;
}

static void perturbAsmJointPrimitiveState_0_2v(double mag, double *state)
{
  state[2] = state[2] + mag;
  state[9] = state[9] - 0.875 * mag;
}

static void perturbAsmJointPrimitiveState_0_3(double mag, double *state)
{
  double xx[15];
  xx[0] = 1.0;
  xx[1] = fabs(mag);
  xx[2] = xx[0] / (xx[1] - floor(xx[1]) + 1.0e-9);
  xx[1] = sin(xx[2]);
  xx[3] = 0.0;
  xx[4] = cos(xx[2]);
  xx[5] = sin(2.0 * xx[2]);
  xx[2] = 0.5 * mag;
  xx[6] = sqrt(xx[1] * xx[1] + xx[4] * xx[4] + xx[5] * xx[5]);
  xx[7] = xx[6] == 0.0 ? 0.0 : xx[1] / xx[6];
  xx[8] = sin(xx[2]);
  xx[9] = xx[6] == 0.0 ? 0.0 : xx[4] / xx[6];
  xx[10] = xx[6] == 0.0 ? 0.0 : xx[5] / xx[6];
  xx[11] = xx[1] == xx[3] && xx[4] == xx[3] && xx[5] == xx[3] ? xx[0] : cos(xx[2]);
  xx[12] = xx[7] * xx[8];
  xx[13] = xx[9] * xx[8];
  xx[14] = xx[10] * xx[8];
  xx[0] = state[3];
  xx[1] = state[4];
  xx[2] = state[5];
  xx[3] = state[6];
  pm_math_Quaternion_compose_ra(xx + 11, xx + 0, xx + 4);
  state[3] = xx[4];
  state[4] = xx[5];
  state[5] = xx[6];
  state[6] = xx[7];
}

static void perturbAsmJointPrimitiveState_0_3v(double mag, double *state)
{
  double xx[15];
  xx[0] = 1.0;
  xx[1] = fabs(mag);
  xx[2] = xx[0] / (xx[1] - floor(xx[1]) + 1.0e-9);
  xx[1] = sin(xx[2]);
  xx[3] = 0.0;
  xx[4] = cos(xx[2]);
  xx[5] = sin(2.0 * xx[2]);
  xx[2] = 0.5 * mag;
  xx[6] = sqrt(xx[1] * xx[1] + xx[4] * xx[4] + xx[5] * xx[5]);
  xx[7] = xx[6] == 0.0 ? 0.0 : xx[1] / xx[6];
  xx[8] = sin(xx[2]);
  xx[9] = xx[6] == 0.0 ? 0.0 : xx[4] / xx[6];
  xx[10] = xx[6] == 0.0 ? 0.0 : xx[5] / xx[6];
  xx[11] = xx[1] == xx[3] && xx[4] == xx[3] && xx[5] == xx[3] ? xx[0] : cos(xx[2]);
  xx[12] = xx[7] * xx[8];
  xx[13] = xx[9] * xx[8];
  xx[14] = xx[10] * xx[8];
  xx[3] = state[3];
  xx[4] = state[4];
  xx[5] = state[5];
  xx[6] = state[6];
  pm_math_Quaternion_compose_ra(xx + 11, xx + 3, xx + 7);
  state[3] = xx[7];
  state[4] = xx[8];
  state[5] = xx[9];
  state[6] = xx[10];
  state[10] = state[10] + 1.2 * mag;
  state[11] = state[11] - xx[2];
  state[12] = state[12] + 0.9 * mag;
}

static void perturbAsmJointPrimitiveState_1_0(double mag, double *state)
{
  state[13] = state[13] + mag;
}

static void perturbAsmJointPrimitiveState_1_0v(double mag, double *state)
{
  state[13] = state[13] + mag;
  state[14] = state[14] - 0.875 * mag;
}

static void perturbAsmJointPrimitiveState_2_0(double mag, double *state)
{
  state[15] = state[15] + mag;
}

static void perturbAsmJointPrimitiveState_2_0v(double mag, double *state)
{
  state[15] = state[15] + mag;
  state[16] = state[16] - 0.875 * mag;
}

void Simulink_Simulation_6a081443_1_perturbAsmJointPrimitiveState(const void
  *mech, size_t stageIdx, size_t primIdx, double mag, boolean_T
  doPerturbVelocity, double *state)
{
  (void) mech;
  (void) stageIdx;
  (void) primIdx;
  (void) mag;
  (void) doPerturbVelocity;
  (void) state;
  switch ((stageIdx * 6 + primIdx) * 2 + (doPerturbVelocity ? 1 : 0))
  {
   case 0:
    perturbAsmJointPrimitiveState_0_0(mag, state);
    break;

   case 1:
    perturbAsmJointPrimitiveState_0_0v(mag, state);
    break;

   case 2:
    perturbAsmJointPrimitiveState_0_1(mag, state);
    break;

   case 3:
    perturbAsmJointPrimitiveState_0_1v(mag, state);
    break;

   case 4:
    perturbAsmJointPrimitiveState_0_2(mag, state);
    break;

   case 5:
    perturbAsmJointPrimitiveState_0_2v(mag, state);
    break;

   case 6:
    perturbAsmJointPrimitiveState_0_3(mag, state);
    break;

   case 7:
    perturbAsmJointPrimitiveState_0_3v(mag, state);
    break;

   case 12:
    perturbAsmJointPrimitiveState_1_0(mag, state);
    break;

   case 13:
    perturbAsmJointPrimitiveState_1_0v(mag, state);
    break;

   case 24:
    perturbAsmJointPrimitiveState_2_0(mag, state);
    break;

   case 25:
    perturbAsmJointPrimitiveState_2_0v(mag, state);
    break;
  }
}

static void computePosDofBlendMatrix_0_3(const double *state, int partialType,
  double *matrix)
{
  double xx[20];
  xx[0] = 9.87654321;
  xx[1] = 2.0;
  xx[2] = xx[1] * (state[4] * state[5] - state[3] * state[6]);
  xx[3] = xx[2] * xx[2];
  xx[4] = 1.0;
  xx[5] = (state[3] * state[3] + state[4] * state[4]) * xx[1] - xx[4];
  xx[6] = xx[5] * xx[5];
  xx[7] = sqrt(xx[3] + xx[6]);
  xx[8] = xx[7] == 0.0 ? 0.0 : - xx[2] / xx[7];
  xx[9] = xx[6] + xx[3];
  xx[3] = sqrt(xx[9]);
  xx[6] = xx[3] == 0.0 ? 0.0 : xx[5] / xx[3];
  xx[10] = 0.0;
  xx[11] = (state[4] * state[6] + state[3] * state[5]) * xx[1];
  xx[1] = sqrt(xx[9] + xx[11] * xx[11]);
  xx[12] = xx[1] == 0.0 ? 0.0 : xx[5] / xx[1];
  xx[14] = xx[8];
  xx[15] = xx[6];
  xx[16] = xx[10];
  xx[17] = xx[8];
  xx[18] = xx[8];
  xx[19] = xx[12];
  xx[6] = xx[13 + (partialType)];
  xx[8] = xx[7] == 0.0 ? 0.0 : xx[5] / xx[7];
  xx[7] = xx[3] == 0.0 ? 0.0 : xx[2] / xx[3];
  xx[3] = xx[1] == 0.0 ? 0.0 : xx[2] / xx[1];
  xx[13] = xx[8];
  xx[14] = xx[7];
  xx[15] = xx[10];
  xx[16] = xx[8];
  xx[17] = xx[8];
  xx[18] = xx[3];
  xx[2] = xx[12 + (partialType)];
  xx[3] = xx[1] == 0.0 ? 0.0 : xx[11] / xx[1];
  xx[13] = xx[10];
  xx[14] = xx[10];
  xx[15] = xx[4];
  xx[16] = xx[10];
  xx[17] = xx[10];
  xx[18] = xx[3];
  xx[1] = xx[12 + (partialType)];
  xx[3] = xx[11] * xx[5];
  xx[5] = sqrt(xx[9] * xx[9] + xx[3] * xx[3]);
  xx[7] = xx[5] == 0.0 ? 0.0 : xx[9] / xx[5];
  xx[12] = xx[10];
  xx[13] = xx[10];
  xx[14] = xx[10];
  xx[15] = xx[7];
  xx[16] = xx[10];
  xx[17] = xx[10];
  xx[7] = xx[11 + (partialType)];
  xx[12] = xx[10];
  xx[13] = xx[10];
  xx[14] = xx[10];
  xx[15] = xx[10];
  xx[16] = xx[10];
  xx[17] = xx[10];
  xx[8] = xx[11 + (partialType)];
  xx[9] = xx[5] == 0.0 ? 0.0 : xx[3] / xx[5];
  xx[12] = xx[4];
  xx[13] = xx[4];
  xx[14] = xx[10];
  xx[15] = xx[9];
  xx[16] = xx[10];
  xx[17] = xx[10];
  xx[0] = xx[11 + (partialType)];
  matrix[0] = xx[6];
  matrix[1] = xx[2];
  matrix[2] = xx[1];
  matrix[3] = xx[7];
  matrix[4] = xx[8];
  matrix[5] = xx[0];
  matrix[6] = xx[8];
  matrix[7] = xx[8];
  matrix[8] = xx[8];
}

void Simulink_Simulation_6a081443_1_computePosDofBlendMatrix(const void *mech,
  size_t stageIdx, size_t primIdx, const double *state, int partialType, double *
  matrix)
{
  (void) mech;
  (void) stageIdx;
  (void) primIdx;
  (void) state;
  (void) partialType;
  (void) matrix;
  switch ((stageIdx * 6 + primIdx))
  {
   case 3:
    computePosDofBlendMatrix_0_3(state, partialType, matrix);
    break;
  }
}

static void computeVelDofBlendMatrix_0_3(const double *state, int partialType,
  double *matrix)
{
  double xx[15];
  (void) state;
  xx[0] = 9.87654321;
  xx[1] = 0.0;
  xx[2] = 1.0;
  xx[4] = xx[1];
  xx[5] = xx[2];
  xx[6] = xx[1];
  xx[7] = xx[2];
  xx[8] = xx[1];
  xx[9] = xx[2];
  xx[10] = xx[3 + (partialType)];
  xx[4] = xx[2];
  xx[5] = xx[1];
  xx[6] = xx[1];
  xx[7] = xx[1];
  xx[8] = xx[2];
  xx[9] = xx[1];
  xx[11] = xx[3 + (partialType)];
  xx[4] = xx[1];
  xx[5] = xx[1];
  xx[6] = xx[2];
  xx[7] = xx[1];
  xx[8] = xx[1];
  xx[9] = xx[1];
  xx[12] = xx[3 + (partialType)];
  xx[4] = xx[1];
  xx[5] = xx[1];
  xx[6] = xx[1];
  xx[7] = xx[1];
  xx[8] = xx[1];
  xx[9] = xx[1];
  xx[13] = xx[3 + (partialType)];
  xx[4] = xx[1];
  xx[5] = xx[1];
  xx[6] = xx[1];
  xx[7] = xx[2];
  xx[8] = xx[1];
  xx[9] = xx[1];
  xx[14] = xx[3 + (partialType)];
  xx[4] = xx[2];
  xx[5] = xx[2];
  xx[6] = xx[1];
  xx[7] = xx[1];
  xx[8] = xx[1];
  xx[9] = xx[1];
  xx[0] = xx[3 + (partialType)];
  matrix[0] = xx[10];
  matrix[1] = xx[11];
  matrix[2] = xx[12];
  matrix[3] = xx[13];
  matrix[4] = xx[14];
  matrix[5] = xx[0];
  matrix[6] = xx[13];
  matrix[7] = xx[13];
  matrix[8] = xx[13];
}

void Simulink_Simulation_6a081443_1_computeVelDofBlendMatrix(const void *mech,
  size_t stageIdx, size_t primIdx, const double *state, int partialType, double *
  matrix)
{
  (void) mech;
  (void) stageIdx;
  (void) primIdx;
  (void) state;
  (void) partialType;
  (void) matrix;
  switch ((stageIdx * 6 + primIdx))
  {
   case 3:
    computeVelDofBlendMatrix_0_3(state, partialType, matrix);
    break;
  }
}

static void projectPartiallyTargetedPos_0_3(const double *origState, int
  partialType, double *state)
{
  boolean_T bb[2];
  double xx[17];
  xx[0] = 2.0;
  xx[1] = (state[4] * state[6] + state[3] * state[5]) * xx[0];
  xx[2] = 0.99999999999999;
  bb[0] = fabs(xx[1]) > xx[2];
  xx[3] = 1.570796326794897;
  if (xx[1] < 0.0)
    xx[4] = -1.0;
  else if (xx[1] > 0.0)
    xx[4] = +1.0;
  else
    xx[4] = 0.0;
  xx[5] = fabs(xx[1]) > 1.0 ? atan2(xx[1], 0.0) : asin(xx[1]);
  xx[1] = bb[0] ? xx[3] * xx[4] : xx[5];
  xx[5] = (origState[4] * origState[6] + origState[3] * origState[5]) * xx[0];
  bb[1] = fabs(xx[5]) > xx[2];
  if (xx[5] < 0.0)
    xx[2] = -1.0;
  else if (xx[5] > 0.0)
    xx[2] = +1.0;
  else
    xx[2] = 0.0;
  xx[6] = fabs(xx[5]) > 1.0 ? atan2(xx[5], 0.0) : asin(xx[5]);
  xx[5] = bb[1] ? xx[3] * xx[2] : xx[6];
  xx[6] = xx[1];
  xx[7] = xx[1];
  xx[8] = xx[5];
  xx[9] = xx[5];
  xx[10] = xx[1];
  xx[11] = xx[1];
  xx[12] = xx[5];
  xx[1] = xx[6 + (partialType)];
  xx[3] = cos(xx[1]);
  xx[5] = 0.5;
  xx[6] = state[5] * state[6];
  xx[7] = state[3] * state[4];
  xx[8] = state[3] * state[3];
  xx[9] = 1.0;
  xx[10] = (xx[8] + state[5] * state[5]) * xx[0] - xx[9];
  xx[11] = (xx[6] + xx[7]) * xx[0];
  xx[10] = (xx[11] == 0.0 && xx[10] == 0.0) ? 0.0 : atan2(xx[11], xx[10]);
  xx[11] = (xx[8] + state[6] * state[6]) * xx[0] - xx[9];
  xx[12] = - (xx[0] * (xx[6] - xx[7]));
  xx[11] = (xx[12] == 0.0 && xx[11] == 0.0) ? 0.0 : atan2(xx[12], xx[11]);
  xx[6] = bb[0] ? xx[5] * xx[10] : xx[11];
  xx[7] = (xx[8] + state[4] * state[4]) * xx[0] - xx[9];
  xx[10] = - (xx[0] * (state[4] * state[5] - state[3] * state[6]));
  xx[7] = (xx[10] == 0.0 && xx[7] == 0.0) ? 0.0 : atan2(xx[10], xx[7]);
  xx[8] = bb[0] ? xx[4] * xx[6] : xx[7];
  xx[4] = origState[5] * origState[6];
  xx[7] = origState[3] * origState[4];
  xx[10] = origState[3] * origState[3];
  xx[11] = (xx[10] + origState[5] * origState[5]) * xx[0] - xx[9];
  xx[12] = (xx[4] + xx[7]) * xx[0];
  xx[11] = (xx[12] == 0.0 && xx[11] == 0.0) ? 0.0 : atan2(xx[12], xx[11]);
  xx[12] = (xx[10] + origState[6] * origState[6]) * xx[0] - xx[9];
  xx[13] = - (xx[0] * (xx[4] - xx[7]));
  xx[12] = (xx[13] == 0.0 && xx[12] == 0.0) ? 0.0 : atan2(xx[13], xx[12]);
  xx[4] = bb[1] ? xx[5] * xx[11] : xx[12];
  xx[5] = (xx[10] + origState[4] * origState[4]) * xx[0] - xx[9];
  xx[7] = - (xx[0] * (origState[4] * origState[5] - origState[3] * origState[6]));
  xx[5] = (xx[7] == 0.0 && xx[5] == 0.0) ? 0.0 : atan2(xx[7], xx[5]);
  xx[0] = bb[1] ? xx[2] * xx[4] : xx[5];
  xx[9] = xx[8];
  xx[10] = xx[8];
  xx[11] = xx[8];
  xx[12] = xx[8];
  xx[13] = xx[0];
  xx[14] = xx[0];
  xx[15] = xx[0];
  xx[0] = xx[9 + (partialType)];
  xx[2] = cos(xx[0]);
  xx[5] = sin(xx[0]);
  xx[0] = sin(xx[1]);
  xx[7] = xx[6];
  xx[8] = xx[4];
  xx[9] = xx[6];
  xx[10] = xx[4];
  xx[11] = xx[6];
  xx[12] = xx[4];
  xx[13] = xx[6];
  xx[1] = xx[7 + (partialType)];
  xx[4] = cos(xx[1]);
  xx[6] = sin(xx[1]);
  xx[1] = xx[2] * xx[6];
  xx[7] = xx[4] * xx[2];
  xx[8] = xx[3] * xx[2];
  xx[9] = - (xx[3] * xx[5]);
  xx[10] = xx[0];
  xx[11] = xx[4] * xx[5] + xx[1] * xx[0];
  xx[12] = xx[7] - xx[6] * xx[0] * xx[5];
  xx[13] = - (xx[3] * xx[6]);
  xx[14] = xx[6] * xx[5] - xx[7] * xx[0];
  xx[15] = xx[1] + xx[4] * xx[0] * xx[5];
  xx[16] = xx[4] * xx[3];
  pm_math_Quaternion_Matrix3x3Ctor_ra(xx + 8, xx + 0);
  state[3] = xx[0];
  state[4] = xx[1];
  state[5] = xx[2];
  state[6] = xx[3];
}

void Simulink_Simulation_6a081443_1_projectPartiallyTargetedPos(const void *mech,
  size_t stageIdx, size_t primIdx, const double *origState, int partialType,
  double *state)
{
  (void) mech;
  (void) stageIdx;
  (void) primIdx;
  (void) origState;
  (void) partialType;
  (void) state;
  switch ((stageIdx * 6 + primIdx))
  {
   case 3:
    projectPartiallyTargetedPos_0_3(origState, partialType, state);
    break;
  }
}

void Simulink_Simulation_6a081443_1_propagateMotion(const void *mech, const
  RuntimeDerivedValuesBundle *rtdv, const double *state, double *motionData)
{
  const double *rtdvd = rtdv->mDoubles.mValues;
  const int *rtdvi = rtdv->mInts.mValues;
  double xx[55];
  (void) mech;
  (void) rtdvd;
  (void) rtdvi;
  xx[0] = 0.7071067811865476;
  xx[1] = xx[0] * state[5];
  xx[2] = xx[0] * state[3];
  xx[3] = - (xx[1] + xx[2]);
  xx[4] = xx[0] * state[4];
  xx[5] = xx[0] * state[6];
  xx[6] = - (xx[4] - xx[5]);
  xx[7] = - (xx[1] - xx[2]);
  xx[1] = - (xx[4] + xx[5]);
  xx[8] = - state[4];
  xx[9] = - state[5];
  xx[10] = - state[6];
  xx[2] = 5.0e-3;
  xx[4] = 0.01;
  xx[5] = xx[4] * state[6] - xx[2] * state[4];
  xx[11] = xx[4] * state[5];
  xx[12] = xx[2] * state[5];
  xx[13] = xx[5];
  xx[14] = - xx[11];
  pm_math_Vector3_cross_ra(xx + 8, xx + 12, xx + 15);
  xx[8] = 2.0;
  xx[9] = state[0] - (xx[15] - xx[2] * state[3] * state[5]) * xx[8] + xx[4];
  xx[10] = state[2] - xx[8] * (xx[17] + xx[11] * state[3]) + xx[2];
  xx[11] = xx[0] * xx[10] * xx[0];
  xx[12] = xx[0] * xx[9] * xx[0];
  xx[13] = 8.438054056036925e-6;
  xx[17] = - 0.9999972452156369;
  xx[18] = 2.877348962337933e-5;
  xx[19] = xx[13];
  xx[20] = 2.34705390287071e-3;
  xx[14] = 0.5;
  xx[15] = xx[14] * state[13];
  xx[21] = 4.694094388902115e-3;
  xx[22] = sin(xx[15]);
  xx[23] = 0.999988981020127;
  xx[24] = 5.758642985231877e-5;
  xx[25] = cos(xx[15]);
  xx[26] = - (xx[21] * xx[22]);
  xx[27] = xx[23] * xx[22];
  xx[28] = xx[24] * xx[22];
  pm_math_Quaternion_compose_ra(xx + 17, xx + 25, xx + 29);
  xx[15] = 0.095;
  xx[17] = 0.02051076413170222;
  xx[18] = xx[17];
  xx[19] = 0.037478670727467;
  xx[20] = 2.057763936351717e-6;
  pm_math_Quaternion_xform_ra(xx + 29, xx + 18, xx + 25);
  xx[18] = - (xx[15] + xx[25]);
  xx[19] = 0.1145 - xx[26];
  xx[20] = - (xx[2] + xx[27]);
  xx[25] = - 2.347053902870877e-3;
  xx[26] = - xx[13];
  xx[27] = 2.877348962354587e-5;
  xx[28] = - 0.999997245215637;
  xx[13] = xx[14] * state[15];
  xx[14] = 4.694094388902448e-3;
  xx[22] = sin(xx[13]);
  xx[33] = 0.9999889810201272;
  xx[34] = 5.758642985254081e-5;
  xx[35] = cos(xx[13]);
  xx[36] = - (xx[14] * xx[22]);
  xx[37] = xx[33] * xx[22];
  xx[38] = xx[34] * xx[22];
  pm_math_Quaternion_compose_ra(xx + 25, xx + 35, xx + 39);
  xx[25] = xx[17];
  xx[26] = 0.03747867072746697;
  xx[27] = 2.057763936358107e-6;
  pm_math_Quaternion_xform_ra(xx + 39, xx + 25, xx + 35);
  xx[13] = - (xx[15] + xx[35]);
  xx[15] = - (0.1145 + xx[36]);
  xx[17] = - (xx[2] + xx[37]);
  xx[25] = xx[3];
  xx[26] = xx[6];
  xx[27] = xx[7];
  xx[28] = xx[1];
  xx[22] = xx[0] * xx[0] * state[9];
  xx[35] = xx[0] * xx[0] * state[7];
  xx[36] = state[7] - xx[8] * (xx[22] + xx[35]);
  xx[37] = state[8];
  xx[38] = state[9] - (xx[22] - xx[35]) * xx[8];
  pm_math_Quaternion_inverseXform_ra(xx + 25, xx + 36, xx + 43);
  xx[0] = xx[43] + xx[2] * state[11];
  xx[22] = xx[44] + xx[4] * state[12] - xx[2] * state[10];
  xx[2] = xx[45] - xx[4] * state[11];
  xx[25] = state[10];
  xx[26] = state[11];
  xx[27] = state[12];
  pm_math_Quaternion_inverseXform_ra(xx + 29, xx + 25, xx + 35);
  pm_math_Vector3_cross_ra(xx + 25, xx + 18, xx + 43);
  xx[46] = xx[43] + xx[0];
  xx[47] = xx[44] + xx[22];
  xx[48] = xx[45] + xx[2];
  pm_math_Quaternion_inverseXform_ra(xx + 29, xx + 46, xx + 43);
  pm_math_Quaternion_inverseXform_ra(xx + 39, xx + 25, xx + 46);
  xx[49] = xx[13];
  xx[50] = xx[15];
  xx[51] = xx[17];
  pm_math_Vector3_cross_ra(xx + 25, xx + 49, xx + 52);
  xx[25] = xx[52] + xx[0];
  xx[26] = xx[53] + xx[22];
  xx[27] = xx[54] + xx[2];
  pm_math_Quaternion_inverseXform_ra(xx + 39, xx + 25, xx + 49);
  motionData[0] = xx[3];
  motionData[1] = xx[6];
  motionData[2] = xx[7];
  motionData[3] = xx[1];
  motionData[4] = xx[9] - xx[8] * (xx[11] + xx[12]);
  motionData[5] = state[1] - xx[8] * (xx[16] - xx[5] * state[3]);
  motionData[6] = xx[10] - (xx[11] - xx[12]) * xx[8];
  motionData[7] = xx[29];
  motionData[8] = xx[30];
  motionData[9] = xx[31];
  motionData[10] = xx[32];
  motionData[11] = xx[18];
  motionData[12] = xx[19];
  motionData[13] = xx[20];
  motionData[14] = xx[39];
  motionData[15] = xx[40];
  motionData[16] = xx[41];
  motionData[17] = xx[42];
  motionData[18] = xx[13];
  motionData[19] = xx[15];
  motionData[20] = xx[17];
  motionData[21] = state[10];
  motionData[22] = state[11];
  motionData[23] = state[12];
  motionData[24] = xx[0];
  motionData[25] = xx[22];
  motionData[26] = xx[2];
  motionData[27] = xx[35] - xx[21] * state[14];
  motionData[28] = xx[36] + xx[23] * state[14];
  motionData[29] = xx[37] + xx[24] * state[14];
  motionData[30] = xx[43] + 1.005215809131126e-7 * state[14];
  motionData[31] = xx[44] - 1.190801018035039e-6 * state[14];
  motionData[32] = xx[45] + 0.02068646654197039 * state[14];
  motionData[33] = xx[46] - xx[14] * state[16];
  motionData[34] = xx[47] + xx[33] * state[16];
  motionData[35] = xx[48] + xx[34] * state[16];
  motionData[36] = xx[49] + 1.005215809150426e-7 * state[16];
  motionData[37] = xx[50] - 1.190801018039624e-6 * state[16];
  motionData[38] = xx[51] + 0.0206864665419704 * state[16];
}

size_t Simulink_Simulation_6a081443_1_computeAssemblyError(const void *mech,
  const RuntimeDerivedValuesBundle *rtdv, size_t constraintIdx, const int
  *modeVector, const double *motionData, double *error)
{
  (void) mech;
  (void)rtdv;
  (void) modeVector;
  (void) motionData;
  (void) error;
  switch (constraintIdx)
  {
  }

  return 0;
}

size_t Simulink_Simulation_6a081443_1_computeAssemblyJacobian(const void *mech,
  const RuntimeDerivedValuesBundle *rtdv, size_t constraintIdx, boolean_T
  forVelocitySatisfaction, const double *state, const int *modeVector, const
  double *motionData, double *J)
{
  (void) mech;
  (void) rtdv;
  (void) state;
  (void) modeVector;
  (void) forVelocitySatisfaction;
  (void) motionData;
  (void) J;
  switch (constraintIdx)
  {
  }

  return 0;
}

size_t Simulink_Simulation_6a081443_1_computeFullAssemblyJacobian(const void
  *mech, const RuntimeDerivedValuesBundle *rtdv, const double *state, const int *
  modeVector, const double *motionData, double *J)
{
  const double *rtdvd = rtdv->mDoubles.mValues;
  const int *rtdvi = rtdv->mInts.mValues;
  (void) mech;
  (void) rtdvd;
  (void) rtdvi;
  (void) state;
  (void) modeVector;
  (void) motionData;
  (void) J;
  return 0;
}

boolean_T Simulink_Simulation_6a081443_1_isInKinematicSingularity(const void
  *mech, const RuntimeDerivedValuesBundle *rtdv, size_t constraintIdx, const int
  *modeVector, const double *motionData)
{
  (void) mech;
  (void) rtdv;
  (void) modeVector;
  (void) motionData;
  switch (constraintIdx)
  {
  }

  return 0;
}

void Simulink_Simulation_6a081443_1_convertStateVector(const void *asmMech,
  const RuntimeDerivedValuesBundle *rtdv, const void *simMech, const double
  *asmState, const int *asmModeVector, const int *simModeVector, double
  *simState)
{
  const double *rtdvd = rtdv->mDoubles.mValues;
  const int *rtdvi = rtdv->mInts.mValues;
  (void) asmMech;
  (void) rtdvd;
  (void) rtdvi;
  (void) simMech;
  (void) asmModeVector;
  (void) simModeVector;
  simState[0] = asmState[0];
  simState[1] = asmState[1];
  simState[2] = asmState[2];
  simState[3] = asmState[3];
  simState[4] = asmState[4];
  simState[5] = asmState[5];
  simState[6] = asmState[6];
  simState[7] = asmState[7];
  simState[8] = asmState[8];
  simState[9] = asmState[9];
  simState[10] = asmState[10];
  simState[11] = asmState[11];
  simState[12] = asmState[12];
  simState[13] = asmState[13];
  simState[14] = asmState[14];
  simState[15] = asmState[15];
  simState[16] = asmState[16];
}
