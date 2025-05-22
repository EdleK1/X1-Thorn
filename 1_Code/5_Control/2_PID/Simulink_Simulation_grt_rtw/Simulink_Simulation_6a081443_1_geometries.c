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

const sm_core_compiler_Plane *Simulink_Simulation_6a081443_1_geometry_0(const
  RuntimeDerivedValuesBundle *rtdv)
{
  static const sm_core_compiler_Plane plane = { 0 };

  (void) rtdv;
  return &plane;
}

const sm_core_compiler_Point *Simulink_Simulation_6a081443_1_geometry_1(const
  RuntimeDerivedValuesBundle *rtdv)
{
  static const sm_core_compiler_Point point = { 0 };

  (void) rtdv;
  return &point;
}

void Simulink_Simulation_6a081443_1_initializeGeometries(const struct
  RuntimeDerivedValuesBundleTag *rtdv)
{
  Simulink_Simulation_6a081443_1_geometry_0(rtdv);
  Simulink_Simulation_6a081443_1_geometry_1(rtdv);
}
