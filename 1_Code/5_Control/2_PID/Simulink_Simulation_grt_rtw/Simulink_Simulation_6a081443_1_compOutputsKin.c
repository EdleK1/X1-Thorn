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
#include "Simulink_Simulation_6a081443_1_geometries.h"

PmfMessageId Simulink_Simulation_6a081443_1_compOutputsKin(const
  RuntimeDerivedValuesBundle *rtdv, const double *state, const int *modeVector,
  const double *input, const double *inputDot, const double *inputDdot, const
  double *discreteState, double *output, NeuDiagnosticManager *neDiagMgr)
{
  const double *rtdvd = rtdv->mDoubles.mValues;
  const int *rtdvi = rtdv->mInts.mValues;
  double xx[5];
  (void) rtdvd;
  (void) rtdvi;
  (void) modeVector;
  (void) input;
  (void) inputDot;
  (void) inputDdot;
  (void) discreteState;
  (void) neDiagMgr;
  xx[0] = 0.7071067811865476;
  xx[1] = xx[0] * state[3];
  xx[2] = xx[0] * state[5];
  xx[3] = xx[0] * state[4];
  xx[4] = xx[0] * state[6];
  output[0] = xx[1] + xx[2];
  output[1] = xx[3] - xx[4];
  output[2] = xx[2] - xx[1];
  output[3] = xx[4] + xx[3];
  output[4] = state[10];
  return NULL;
}
