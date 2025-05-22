/*
 * Simulink_Simulation.c
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
#include "rtwtypes.h"
#include <math.h>
#include <string.h>
#include <emmintrin.h>
#include "rt_nonfinite.h"
#include <stddef.h>
#include "Simulink_Simulation_private.h"

/* Block signals (default storage) */
B_Simulink_Simulation_T Simulink_Simulation_B;

/* Continuous states */
X_Simulink_Simulation_T Simulink_Simulation_X;

/* Block states (default storage) */
DW_Simulink_Simulation_T Simulink_Simulation_DW;

/* Real-time model */
static RT_MODEL_Simulink_Simulation_T Simulink_Simulation_M_;
RT_MODEL_Simulink_Simulation_T *const Simulink_Simulation_M =
  &Simulink_Simulation_M_;

/* Forward declaration for local functions */
static void Simulink_Simulation_sqrt(creal_T *x);
static void Simulink_Simulation_xzlartg_m(const creal_T f, const creal_T g,
  real_T *cs, creal_T *sn);
static void Simulink_Simulation_xzlartg(const creal_T f, const creal_T g, real_T
  *cs, creal_T *sn, creal_T *r);
static void Simulink_Simulation_xzhgeqz(creal_T A[16], int32_T ilo, int32_T ihi,
  creal_T Z[16], int32_T *info, creal_T alpha1[4], creal_T beta1[4]);
static void Simulink_Simulation_xztgevc(const creal_T A[16], creal_T V[16]);
static void Simulink_Simulation_xzgeev(const real_T A[16], int32_T *info,
  creal_T alpha1[4], creal_T beta1[4], creal_T V[16]);
static real_T Simulink_Simulation_xnrm2(int32_T n, const real_T x[16], int32_T
  ix0);
static void Simulink_Simulation_xzlarf(int32_T m, int32_T n, int32_T iv0, real_T
  tau, real_T C[16], int32_T ic0, real_T work[4]);
static real_T Simulink_Simulation_xnrm2_f(int32_T n, const real_T x[3]);
static real_T Simulink_Simulation_xzlarfg(int32_T n, real_T *alpha1, real_T x[3]);
static void Simulink_Simulation_xdlanv2(real_T *a, real_T *b, real_T *c, real_T *
  d, real_T *rt1r, real_T *rt1i, real_T *rt2r, real_T *rt2i, real_T *cs, real_T *
  sn);
static int32_T Simulink_Simulation_xhseqr(real_T h[16], real_T z[16]);
static void Simulink_Simulation_schur(const real_T A[16], real_T V[16], real_T
  T[16]);
static real_T Simulink_Simulation_xnrm2_fx(int32_T n, const real_T x[12],
  int32_T ix0);
static void Simulink_Simulation_mldivide(const real_T A[12], const real_T B[4],
  real_T Y[3]);
static void rate_scheduler(void);

/*
 *         This function updates active task flag for each subrate.
 *         The function is called at model base rate, hence the
 *         generated code self-manages all its subrates.
 */
static void rate_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (Simulink_Simulation_M->Timing.TaskCounters.TID[2])++;
  if ((Simulink_Simulation_M->Timing.TaskCounters.TID[2]) > 99) {/* Sample time: [0.01s, 0.0s] */
    Simulink_Simulation_M->Timing.TaskCounters.TID[2] = 0;
  }
}

/* Projection for root system: '<Root>' */
void Simulink_Simulation_projection(void)
{
  NeslSimulationData *simulationData;
  NeuDiagnosticManager *diagnosticManager;
  NeuDiagnosticTree *diagnosticTree;
  real_T tmp_0[32];
  real_T time;
  int32_T tmp_2;
  int_T tmp_1[9];
  boolean_T tmp;

  /* Projection for SimscapeExecutionBlock: '<S17>/STATE_1' */
  simulationData = (NeslSimulationData *)Simulink_Simulation_DW.STATE_1_SimData;
  time = Simulink_Simulation_M->Timing.t[0];
  simulationData->mData->mTime.mN = 1;
  simulationData->mData->mTime.mX = &time;
  simulationData->mData->mContStates.mN = 13;
  simulationData->mData->mContStates.mX =
    &Simulink_Simulation_X.Simulink_SimulationAircraft_Dyn[0];
  simulationData->mData->mDiscStates.mN = 0;
  simulationData->mData->mDiscStates.mX =
    &Simulink_Simulation_DW.STATE_1_Discrete;
  simulationData->mData->mModeVector.mN = 0;
  simulationData->mData->mModeVector.mX = &Simulink_Simulation_DW.STATE_1_Modes;
  tmp = false;
  simulationData->mData->mFoundZcEvents = tmp;
  simulationData->mData->mIsMajorTimeStep = rtmIsMajorTimeStep
    (Simulink_Simulation_M);
  tmp = false;
  simulationData->mData->mIsSolverAssertCheck = tmp;
  simulationData->mData->mIsSolverCheckingCIC = false;
  tmp = rtsiIsSolverComputingJacobian(&Simulink_Simulation_M->solverInfo);
  simulationData->mData->mIsComputingJacobian = tmp;
  simulationData->mData->mIsEvaluatingF0 = false;
  simulationData->mData->mIsSolverRequestingReset = false;
  simulationData->mData->mIsModeUpdateTimeStep = rtsiIsModeUpdateTimeStep
    (&Simulink_Simulation_M->solverInfo);
  tmp_1[0] = 0;
  tmp_0[0] = Simulink_Simulation_B.INPUT_1_1_1[0];
  tmp_0[1] = Simulink_Simulation_B.INPUT_1_1_1[1];
  tmp_0[2] = Simulink_Simulation_B.INPUT_1_1_1[2];
  tmp_0[3] = Simulink_Simulation_B.INPUT_1_1_1[3];
  tmp_1[1] = 4;
  tmp_0[4] = Simulink_Simulation_B.INPUT_2_1_1[0];
  tmp_0[5] = Simulink_Simulation_B.INPUT_2_1_1[1];
  tmp_0[6] = Simulink_Simulation_B.INPUT_2_1_1[2];
  tmp_0[7] = Simulink_Simulation_B.INPUT_2_1_1[3];
  tmp_1[2] = 8;
  tmp_0[8] = Simulink_Simulation_B.INPUT_4_1_1[0];
  tmp_0[9] = Simulink_Simulation_B.INPUT_4_1_1[1];
  tmp_0[10] = Simulink_Simulation_B.INPUT_4_1_1[2];
  tmp_0[11] = Simulink_Simulation_B.INPUT_4_1_1[3];
  tmp_1[3] = 12;
  tmp_0[12] = Simulink_Simulation_B.INPUT_5_1_1[0];
  tmp_0[13] = Simulink_Simulation_B.INPUT_5_1_1[1];
  tmp_0[14] = Simulink_Simulation_B.INPUT_5_1_1[2];
  tmp_0[15] = Simulink_Simulation_B.INPUT_5_1_1[3];
  tmp_1[4] = 16;
  tmp_0[16] = Simulink_Simulation_B.INPUT_6_1_1[0];
  tmp_0[17] = Simulink_Simulation_B.INPUT_6_1_1[1];
  tmp_0[18] = Simulink_Simulation_B.INPUT_6_1_1[2];
  tmp_0[19] = Simulink_Simulation_B.INPUT_6_1_1[3];
  tmp_1[5] = 20;
  tmp_0[20] = Simulink_Simulation_B.INPUT_7_1_1[0];
  tmp_0[21] = Simulink_Simulation_B.INPUT_7_1_1[1];
  tmp_0[22] = Simulink_Simulation_B.INPUT_7_1_1[2];
  tmp_0[23] = Simulink_Simulation_B.INPUT_7_1_1[3];
  tmp_1[6] = 24;
  tmp_0[24] = Simulink_Simulation_B.INPUT_8_1_1[0];
  tmp_0[25] = Simulink_Simulation_B.INPUT_8_1_1[1];
  tmp_0[26] = Simulink_Simulation_B.INPUT_8_1_1[2];
  tmp_0[27] = Simulink_Simulation_B.INPUT_8_1_1[3];
  tmp_1[7] = 28;
  tmp_0[28] = Simulink_Simulation_B.INPUT_3_1_1[0];
  tmp_0[29] = Simulink_Simulation_B.INPUT_3_1_1[1];
  tmp_0[30] = Simulink_Simulation_B.INPUT_3_1_1[2];
  tmp_0[31] = Simulink_Simulation_B.INPUT_3_1_1[3];
  tmp_1[8] = 32;
  simulationData->mData->mInputValues.mN = 32;
  simulationData->mData->mInputValues.mX = &tmp_0[0];
  simulationData->mData->mInputOffsets.mN = 9;
  simulationData->mData->mInputOffsets.mX = &tmp_1[0];
  diagnosticManager = (NeuDiagnosticManager *)
    Simulink_Simulation_DW.STATE_1_DiagMgr;
  diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
  tmp_2 = ne_simulator_method((NeslSimulator *)
    Simulink_Simulation_DW.STATE_1_Simulator, NESL_SIM_PROJECTION,
    simulationData, diagnosticManager);
  if (tmp_2 != 0) {
    tmp = error_buffer_is_empty(rtmGetErrorStatus(Simulink_Simulation_M));
    if (tmp) {
      char *msg;
      msg = rtw_diagnostics_msg(diagnosticTree);
      rtmSetErrorStatus(Simulink_Simulation_M, msg);
    }
  }

  /* End of Projection for SimscapeExecutionBlock: '<S17>/STATE_1' */
}

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 13;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  Simulink_Simulation_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  Simulink_Simulation_step();
  Simulink_Simulation_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  Simulink_Simulation_step();
  Simulink_Simulation_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  Simulink_Simulation_step();
  Simulink_Simulation_projection();
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

real_T rt_hypotd_snf(real_T u0, real_T u1)
{
  real_T a;
  real_T b;
  real_T y;
  a = fabs(u0);
  b = fabs(u1);
  if (a < b) {
    a /= b;
    y = sqrt(a * a + 1.0) * b;
  } else if (a > b) {
    b /= a;
    y = sqrt(b * b + 1.0) * a;
  } else if (rtIsNaN(b)) {
    y = (rtNaN);
  } else {
    y = a * 1.4142135623730951;
  }

  return y;
}

/* Function for MATLAB Function: '<S2>/Reference Generator' */
static void Simulink_Simulation_sqrt(creal_T *x)
{
  real_T absxr;
  real_T xr;
  xr = x->re;
  if (x->im == 0.0) {
    if (x->re < 0.0) {
      absxr = 0.0;
      xr = sqrt(-x->re);
    } else {
      absxr = sqrt(x->re);
      xr = 0.0;
    }
  } else if (x->re == 0.0) {
    if (x->im < 0.0) {
      absxr = sqrt(-x->im / 2.0);
      xr = -absxr;
    } else {
      absxr = sqrt(x->im / 2.0);
      xr = absxr;
    }
  } else if (rtIsNaN(x->re)) {
    absxr = (rtNaN);
  } else if (rtIsNaN(x->im)) {
    absxr = (rtNaN);
    xr = (rtNaN);
  } else if (rtIsInf(x->im)) {
    absxr = fabs(x->im);
    xr = x->im;
  } else if (rtIsInf(x->re)) {
    if (x->re < 0.0) {
      absxr = 0.0;
      xr = x->im * -x->re;
    } else {
      absxr = x->re;
      xr = 0.0;
    }
  } else {
    absxr = fabs(x->re);
    xr = fabs(x->im);
    if ((absxr > 4.4942328371557893E+307) || (xr > 4.4942328371557893E+307)) {
      absxr *= 0.5;
      xr = rt_hypotd_snf(absxr, xr * 0.5);
      if (xr > absxr) {
        absxr = sqrt(absxr / xr + 1.0) * sqrt(xr);
      } else {
        absxr = sqrt(xr) * 1.4142135623730951;
      }
    } else {
      absxr = sqrt((rt_hypotd_snf(absxr, xr) + absxr) * 0.5);
    }

    if (x->re > 0.0) {
      xr = x->im / absxr * 0.5;
    } else {
      if (x->im < 0.0) {
        xr = -absxr;
      } else {
        xr = absxr;
      }

      absxr = x->im / xr * 0.5;
    }
  }

  x->re = absxr;
  x->im = xr;
}

/* Function for MATLAB Function: '<S2>/Reference Generator' */
static void Simulink_Simulation_xzlartg_m(const creal_T f, const creal_T g,
  real_T *cs, creal_T *sn)
{
  real_T di;
  real_T f2s;
  real_T fs_im;
  real_T fs_re;
  real_T g2;
  real_T g2_tmp;
  real_T gs_im;
  real_T gs_re;
  real_T scale;
  int32_T count;
  boolean_T guard1 = false;
  di = fabs(f.re);
  scale = di;
  g2_tmp = fabs(f.im);
  if (g2_tmp > di) {
    scale = g2_tmp;
  }

  g2 = fabs(g.re);
  f2s = fabs(g.im);
  if (f2s > g2) {
    g2 = f2s;
  }

  if (g2 > scale) {
    scale = g2;
  }

  fs_re = f.re;
  fs_im = f.im;
  gs_re = g.re;
  gs_im = g.im;
  count = 0;
  guard1 = false;
  if (scale >= 7.4428285367870146E+137) {
    do {
      count++;
      fs_re *= 1.3435752215134178E-138;
      fs_im *= 1.3435752215134178E-138;
      gs_re *= 1.3435752215134178E-138;
      gs_im *= 1.3435752215134178E-138;
      scale *= 1.3435752215134178E-138;
    } while ((scale >= 7.4428285367870146E+137) && (count < 20));

    guard1 = true;
  } else if (scale <= 1.3435752215134178E-138) {
    if (((g.re == 0.0) && (g.im == 0.0)) || (rtIsNaN(g.re) || rtIsNaN(g.im))) {
      *cs = 1.0;
      sn->re = 0.0;
      sn->im = 0.0;
    } else {
      do {
        fs_re *= 7.4428285367870146E+137;
        fs_im *= 7.4428285367870146E+137;
        gs_re *= 7.4428285367870146E+137;
        gs_im *= 7.4428285367870146E+137;
        scale *= 7.4428285367870146E+137;
      } while (scale <= 1.3435752215134178E-138);

      guard1 = true;
    }
  } else {
    guard1 = true;
  }

  if (guard1) {
    scale = fs_re * fs_re + fs_im * fs_im;
    g2 = gs_re * gs_re + gs_im * gs_im;
    f2s = g2;
    if (g2 < 1.0) {
      f2s = 1.0;
    }

    if (scale <= f2s * 2.0041683600089728E-292) {
      if ((f.re == 0.0) && (f.im == 0.0)) {
        *cs = 0.0;
        g2 = rt_hypotd_snf(gs_re, gs_im);
        sn->re = gs_re / g2;
        sn->im = -gs_im / g2;
      } else {
        scale = sqrt(g2);
        *cs = rt_hypotd_snf(fs_re, fs_im) / scale;
        g2 = di;
        if (g2_tmp > di) {
          g2 = g2_tmp;
        }

        if (g2 > 1.0) {
          g2 = rt_hypotd_snf(f.re, f.im);
          fs_re = f.re / g2;
          fs_im = f.im / g2;
        } else {
          f2s = 7.4428285367870146E+137 * f.re;
          di = 7.4428285367870146E+137 * f.im;
          g2 = rt_hypotd_snf(f2s, di);
          fs_re = f2s / g2;
          fs_im = di / g2;
        }

        gs_re /= scale;
        gs_im = -gs_im / scale;
        sn->re = fs_re * gs_re - fs_im * gs_im;
        sn->im = fs_re * gs_im + fs_im * gs_re;
      }
    } else {
      f2s = sqrt(g2 / scale + 1.0);
      *cs = 1.0 / f2s;
      g2 += scale;
      fs_re = f2s * fs_re / g2;
      fs_im = f2s * fs_im / g2;
      sn->re = fs_re * gs_re - fs_im * -gs_im;
      sn->im = fs_re * -gs_im + fs_im * gs_re;
    }
  }
}

/* Function for MATLAB Function: '<S2>/Reference Generator' */
static void Simulink_Simulation_xzlartg(const creal_T f, const creal_T g, real_T
  *cs, creal_T *sn, creal_T *r)
{
  real_T di;
  real_T f2s;
  real_T fs_im;
  real_T fs_re;
  real_T g2;
  real_T g2_tmp;
  real_T gs_im;
  real_T gs_re;
  real_T scale;
  int32_T b_i;
  int32_T count;
  int8_T rescaledir;
  boolean_T guard1 = false;
  di = fabs(f.re);
  scale = di;
  g2_tmp = fabs(f.im);
  if (g2_tmp > di) {
    scale = g2_tmp;
  }

  g2 = fabs(g.re);
  f2s = fabs(g.im);
  if (f2s > g2) {
    g2 = f2s;
  }

  if (g2 > scale) {
    scale = g2;
  }

  fs_re = f.re;
  fs_im = f.im;
  gs_re = g.re;
  gs_im = g.im;
  count = -1;
  rescaledir = 0;
  guard1 = false;
  if (scale >= 7.4428285367870146E+137) {
    do {
      count++;
      fs_re *= 1.3435752215134178E-138;
      fs_im *= 1.3435752215134178E-138;
      gs_re *= 1.3435752215134178E-138;
      gs_im *= 1.3435752215134178E-138;
      scale *= 1.3435752215134178E-138;
    } while ((scale >= 7.4428285367870146E+137) && (count + 1 < 20));

    rescaledir = 1;
    guard1 = true;
  } else if (scale <= 1.3435752215134178E-138) {
    if (((g.re == 0.0) && (g.im == 0.0)) || (rtIsNaN(g.re) || rtIsNaN(g.im))) {
      *cs = 1.0;
      sn->re = 0.0;
      sn->im = 0.0;
      *r = f;
    } else {
      do {
        count++;
        fs_re *= 7.4428285367870146E+137;
        fs_im *= 7.4428285367870146E+137;
        gs_re *= 7.4428285367870146E+137;
        gs_im *= 7.4428285367870146E+137;
        scale *= 7.4428285367870146E+137;
      } while (scale <= 1.3435752215134178E-138);

      rescaledir = -1;
      guard1 = true;
    }
  } else {
    guard1 = true;
  }

  if (guard1) {
    scale = fs_re * fs_re + fs_im * fs_im;
    g2 = gs_re * gs_re + gs_im * gs_im;
    f2s = g2;
    if (g2 < 1.0) {
      f2s = 1.0;
    }

    if (scale <= f2s * 2.0041683600089728E-292) {
      if ((f.re == 0.0) && (f.im == 0.0)) {
        *cs = 0.0;
        r->re = rt_hypotd_snf(g.re, g.im);
        r->im = 0.0;
        g2 = rt_hypotd_snf(gs_re, gs_im);
        sn->re = gs_re / g2;
        sn->im = -gs_im / g2;
      } else {
        scale = sqrt(g2);
        *cs = rt_hypotd_snf(fs_re, fs_im) / scale;
        g2 = di;
        if (g2_tmp > di) {
          g2 = g2_tmp;
        }

        if (g2 > 1.0) {
          g2 = rt_hypotd_snf(f.re, f.im);
          fs_re = f.re / g2;
          fs_im = f.im / g2;
        } else {
          f2s = 7.4428285367870146E+137 * f.re;
          di = 7.4428285367870146E+137 * f.im;
          g2 = rt_hypotd_snf(f2s, di);
          fs_re = f2s / g2;
          fs_im = di / g2;
        }

        gs_re /= scale;
        gs_im = -gs_im / scale;
        sn->re = fs_re * gs_re - fs_im * gs_im;
        sn->im = fs_re * gs_im + fs_im * gs_re;
        r->re = (sn->re * g.re - sn->im * g.im) + *cs * f.re;
        r->im = (sn->re * g.im + sn->im * g.re) + *cs * f.im;
      }
    } else {
      f2s = sqrt(g2 / scale + 1.0);
      r->re = f2s * fs_re;
      r->im = f2s * fs_im;
      *cs = 1.0 / f2s;
      g2 += scale;
      scale = r->re / g2;
      g2 = r->im / g2;
      sn->re = scale * gs_re - g2 * -gs_im;
      sn->im = scale * -gs_im + g2 * gs_re;
      if (rescaledir > 0) {
        for (b_i = 0; b_i <= count; b_i++) {
          r->re *= 7.4428285367870146E+137;
          r->im *= 7.4428285367870146E+137;
        }
      } else if (rescaledir < 0) {
        for (b_i = 0; b_i <= count; b_i++) {
          r->re *= 1.3435752215134178E-138;
          r->im *= 1.3435752215134178E-138;
        }
      }
    }
  }
}

/* Function for MATLAB Function: '<S2>/Reference Generator' */
static void Simulink_Simulation_xzhgeqz(creal_T A[16], int32_T ilo, int32_T ihi,
  creal_T Z[16], int32_T *info, creal_T alpha1[4], creal_T beta1[4])
{
  creal_T anorm_0;
  creal_T ctemp;
  creal_T stemp;
  creal_T y;
  real_T absxk;
  real_T anorm;
  real_T colscale;
  real_T eshift_im;
  real_T eshift_re;
  real_T scale;
  real_T ssq;
  real_T t;
  int32_T col;
  int32_T ifirst;
  int32_T iiter;
  int32_T ilast;
  int32_T jp1;
  int32_T nm1;
  boolean_T failed;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  *info = 0;
  alpha1[0].re = 0.0;
  alpha1[0].im = 0.0;
  beta1[0].re = 1.0;
  beta1[0].im = 0.0;
  alpha1[1].re = 0.0;
  alpha1[1].im = 0.0;
  beta1[1].re = 1.0;
  beta1[1].im = 0.0;
  alpha1[2].re = 0.0;
  alpha1[2].im = 0.0;
  beta1[2].re = 1.0;
  beta1[2].im = 0.0;
  alpha1[3].re = 0.0;
  alpha1[3].im = 0.0;
  beta1[3].re = 1.0;
  beta1[3].im = 0.0;
  eshift_re = 0.0;
  eshift_im = 0.0;
  ctemp.re = 0.0;
  ctemp.im = 0.0;
  anorm = 0.0;
  if (ilo <= ihi) {
    scale = 3.3121686421112381E-170;
    ssq = 0.0;
    nm1 = ihi - ilo;
    for (ilast = 0; ilast <= nm1; ilast++) {
      colscale = 3.3121686421112381E-170;
      anorm = 0.0;
      col = (ilo + ilast) - 1;
      if (ilast + 1 <= nm1) {
        jp1 = ilast + 1;
      } else {
        jp1 = nm1;
      }

      iiter = ilo + jp1;
      for (ifirst = ilo; ifirst <= iiter; ifirst++) {
        absxk = fabs(A[((col << 2) + ifirst) - 1].re);
        if (absxk > colscale) {
          t = colscale / absxk;
          anorm = anorm * t * t + 1.0;
          colscale = absxk;
        } else {
          t = absxk / colscale;
          anorm += t * t;
        }

        absxk = fabs(A[((col << 2) + ifirst) - 1].im);
        if (absxk > colscale) {
          t = colscale / absxk;
          anorm = anorm * t * t + 1.0;
          colscale = absxk;
        } else {
          t = absxk / colscale;
          anorm += t * t;
        }
      }

      if (scale >= colscale) {
        colscale /= scale;
        ssq += colscale * colscale * anorm;
      } else {
        scale /= colscale;
        ssq = scale * scale * ssq + anorm;
        scale = colscale;
      }
    }

    anorm = scale * sqrt(ssq);
  }

  ssq = 2.2250738585072014E-308;
  scale = 2.2204460492503131E-16 * anorm;
  if (scale > 2.2250738585072014E-308) {
    ssq = scale;
  }

  scale = 2.2250738585072014E-308;
  if (anorm > 2.2250738585072014E-308) {
    scale = anorm;
  }

  anorm = 1.0 / scale;
  failed = true;
  for (ilast = ihi + 1; ilast < 5; ilast++) {
    alpha1[ilast - 1] = A[(((ilast - 1) << 2) + ilast) - 1];
  }

  guard1 = false;
  guard2 = false;
  if (ihi >= ilo) {
    int32_T jiter;
    boolean_T goto60;
    boolean_T goto70;
    boolean_T goto90;
    ifirst = ilo;
    nm1 = ilo;
    ilast = ihi - 1;
    col = ihi - 2;
    iiter = 0;
    goto60 = false;
    goto70 = false;
    goto90 = false;
    jiter = 0;
    int32_T exitg1;
    do {
      exitg1 = 0;
      if (jiter <= ((ihi - ilo) + 1) * 30 - 1) {
        int32_T ctemp_tmp_tmp;
        int32_T j;
        boolean_T exitg2;
        if (ilast + 1 == ilo) {
          goto60 = true;
        } else {
          jp1 = col << 2;
          ctemp_tmp_tmp = jp1 + ilast;
          j = (ilast << 2) + ilast;
          jp1 += col;
          if (fabs(A[ctemp_tmp_tmp].re) + fabs(A[ctemp_tmp_tmp].im) <= fmax
              (2.2250738585072014E-308, ((fabs(A[j].re) + fabs(A[j].im)) + (fabs
                 (A[jp1].re) + fabs(A[jp1].im))) * 2.2204460492503131E-16)) {
            A[ctemp_tmp_tmp].re = 0.0;
            A[ctemp_tmp_tmp].im = 0.0;
            goto60 = true;
          } else {
            boolean_T guard3 = false;
            j = col;
            guard3 = false;
            exitg2 = false;
            while ((!exitg2) && (j + 1 >= ilo)) {
              if (j + 1 == ilo) {
                guard3 = true;
                exitg2 = true;
              } else {
                jp1 = ((j - 1) << 2) + j;
                ctemp_tmp_tmp = (j << 2) + j;
                if (fabs(A[jp1].re) + fabs(A[jp1].im) <= fmax
                    (2.2250738585072014E-308, ((fabs(A[jp1 - 1].re) + fabs(A[jp1
                        - 1].im)) + (fabs(A[ctemp_tmp_tmp].re) + fabs
                                     (A[ctemp_tmp_tmp].im))) *
                     2.2204460492503131E-16)) {
                  A[jp1].re = 0.0;
                  A[jp1].im = 0.0;
                  guard3 = true;
                  exitg2 = true;
                } else {
                  j--;
                  guard3 = false;
                }
              }
            }

            if (guard3) {
              ifirst = j + 1;
              goto70 = true;
            }
          }
        }

        if ((!goto60) && (!goto70)) {
          alpha1[0].re = (rtNaN);
          alpha1[0].im = 0.0;
          beta1[0].re = (rtNaN);
          beta1[0].im = 0.0;
          alpha1[1].re = (rtNaN);
          alpha1[1].im = 0.0;
          beta1[1].re = (rtNaN);
          beta1[1].im = 0.0;
          alpha1[2].re = (rtNaN);
          alpha1[2].im = 0.0;
          beta1[2].re = (rtNaN);
          beta1[2].im = 0.0;
          alpha1[3].re = (rtNaN);
          alpha1[3].im = 0.0;
          beta1[3].re = (rtNaN);
          beta1[3].im = 0.0;
          for (jp1 = 0; jp1 < 16; jp1++) {
            Z[jp1].re = (rtNaN);
            Z[jp1].im = 0.0;
          }

          *info = 1;
          exitg1 = 1;
        } else if (goto60) {
          goto60 = false;
          alpha1[ilast] = A[(ilast << 2) + ilast];
          ilast = col;
          col--;
          if (ilast + 1 < ilo) {
            failed = false;
            guard2 = true;
            exitg1 = 1;
          } else {
            iiter = 0;
            eshift_re = 0.0;
            eshift_im = 0.0;
            jiter++;
          }
        } else {
          if (goto70) {
            real_T ad22_im;
            real_T stemp_tmp_0;
            int32_T ctemp_tmp;
            goto70 = false;
            iiter++;
            if (iiter - iiter / 10 * 10 != 0) {
              j = (ilast << 2) + ilast;
              absxk = A[j].re * anorm;
              scale = A[j].im * anorm;
              if (scale == 0.0) {
                t = absxk / 0.5;
                ad22_im = 0.0;
              } else if (absxk == 0.0) {
                t = 0.0;
                ad22_im = scale / 0.5;
              } else {
                t = absxk / 0.5;
                ad22_im = scale / 0.5;
              }

              j = (ilast << 2) + col;
              absxk = A[j].re * anorm;
              scale = A[j].im * anorm;
              if (scale == 0.0) {
                stemp.re = absxk / 0.5;
                stemp.im = 0.0;
              } else if (absxk == 0.0) {
                stemp.re = 0.0;
                stemp.im = scale / 0.5;
              } else {
                stemp.re = absxk / 0.5;
                stemp.im = scale / 0.5;
              }

              Simulink_Simulation_sqrt(&stemp);
              j = (col << 2) + ilast;
              absxk = A[j].re * anorm;
              scale = A[j].im * anorm;
              if (scale == 0.0) {
                y.re = absxk / 0.5;
                y.im = 0.0;
              } else if (absxk == 0.0) {
                y.re = 0.0;
                y.im = scale / 0.5;
              } else {
                y.re = absxk / 0.5;
                y.im = scale / 0.5;
              }

              Simulink_Simulation_sqrt(&y);
              ctemp.re = stemp.re * y.re - stemp.im * y.im;
              ctemp.im = stemp.re * y.im + stemp.im * y.re;
              if ((ctemp.re != 0.0) || (ctemp.im != 0.0)) {
                real_T stemp_im_tmp;
                real_T x_im;
                j = (col << 2) + col;
                absxk = A[j].re * anorm;
                scale = A[j].im * anorm;
                if (scale == 0.0) {
                  absxk /= 0.5;
                  scale = 0.0;
                } else if (absxk == 0.0) {
                  absxk = 0.0;
                  scale /= 0.5;
                } else {
                  absxk /= 0.5;
                  scale /= 0.5;
                }

                absxk = (absxk - t) * 0.5;
                x_im = (scale - ad22_im) * 0.5;
                scale = fabs(absxk) + fabs(x_im);
                colscale = fmax(fabs(ctemp.re) + fabs(ctemp.im), scale);
                if (x_im == 0.0) {
                  stemp.re = absxk / colscale;
                  stemp.im = 0.0;
                } else if (absxk == 0.0) {
                  stemp.re = 0.0;
                  stemp.im = x_im / colscale;
                } else {
                  stemp.re = absxk / colscale;
                  stemp.im = x_im / colscale;
                }

                if (ctemp.im == 0.0) {
                  y.re = ctemp.re / colscale;
                  y.im = 0.0;
                } else if (ctemp.re == 0.0) {
                  y.re = 0.0;
                  y.im = ctemp.im / colscale;
                } else {
                  y.re = ctemp.re / colscale;
                  y.im = ctemp.im / colscale;
                }

                stemp_im_tmp = stemp.re * stemp.im;
                stemp.re = (stemp.re * stemp.re - stemp.im * stemp.im) + (y.re *
                  y.re - y.im * y.im);
                stemp_tmp_0 = y.re * y.im;
                stemp.im = (stemp_tmp_0 + stemp_tmp_0) + (stemp_im_tmp +
                  stemp_im_tmp);
                Simulink_Simulation_sqrt(&stemp);
                y.re = colscale * stemp.re;
                y.im = colscale * stemp.im;
                if (scale > 0.0) {
                  if (x_im == 0.0) {
                    stemp_tmp_0 = absxk / scale;
                    scale = 0.0;
                  } else {
                    if (absxk == 0.0) {
                      stemp_tmp_0 = 0.0;
                    } else {
                      stemp_tmp_0 = absxk / scale;
                    }

                    scale = x_im / scale;
                  }

                  if (stemp_tmp_0 * y.re + scale * y.im < 0.0) {
                    y.re = -y.re;
                    y.im = -y.im;
                  }
                }

                absxk += y.re;
                x_im += y.im;
                if (x_im == 0.0) {
                  if (ctemp.im == 0.0) {
                    scale = ctemp.re / absxk;
                    absxk = 0.0;
                  } else if (ctemp.re == 0.0) {
                    scale = 0.0;
                    absxk = ctemp.im / absxk;
                  } else {
                    scale = ctemp.re / absxk;
                    absxk = ctemp.im / absxk;
                  }
                } else if (absxk == 0.0) {
                  if (ctemp.re == 0.0) {
                    scale = ctemp.im / x_im;
                    absxk = 0.0;
                  } else if (ctemp.im == 0.0) {
                    scale = 0.0;
                    absxk = -(ctemp.re / x_im);
                  } else {
                    scale = ctemp.im / x_im;
                    absxk = -(ctemp.re / x_im);
                  }
                } else {
                  stemp_tmp_0 = fabs(absxk);
                  scale = fabs(x_im);
                  if (stemp_tmp_0 > scale) {
                    stemp_tmp_0 = x_im / absxk;
                    absxk += stemp_tmp_0 * x_im;
                    scale = (stemp_tmp_0 * ctemp.im + ctemp.re) / absxk;
                    absxk = (ctemp.im - stemp_tmp_0 * ctemp.re) / absxk;
                  } else if (scale == stemp_tmp_0) {
                    absxk = absxk > 0.0 ? 0.5 : -0.5;
                    x_im = x_im > 0.0 ? 0.5 : -0.5;
                    scale = (ctemp.re * absxk + ctemp.im * x_im) / stemp_tmp_0;
                    absxk = (ctemp.im * absxk - ctemp.re * x_im) / stemp_tmp_0;
                  } else {
                    stemp_tmp_0 = absxk / x_im;
                    absxk = stemp_tmp_0 * absxk + x_im;
                    scale = (stemp_tmp_0 * ctemp.re + ctemp.im) / absxk;
                    absxk = (stemp_tmp_0 * ctemp.im - ctemp.re) / absxk;
                  }
                }

                t -= ctemp.re * scale - ctemp.im * absxk;
                ad22_im -= ctemp.re * absxk + ctemp.im * scale;
              }
            } else {
              if (iiter - iiter / 20 * 20 == 0) {
                j = (ilast << 2) + ilast;
                absxk = A[j].re * anorm;
                scale = A[j].im * anorm;
                if (scale == 0.0) {
                  absxk /= 0.5;
                  scale = 0.0;
                } else if (absxk == 0.0) {
                  absxk = 0.0;
                  scale /= 0.5;
                } else {
                  absxk /= 0.5;
                  scale /= 0.5;
                }

                eshift_re += absxk;
                eshift_im += scale;
              } else {
                j = (col << 2) + ilast;
                absxk = A[j].re * anorm;
                scale = A[j].im * anorm;
                if (scale == 0.0) {
                  absxk /= 0.5;
                  scale = 0.0;
                } else if (absxk == 0.0) {
                  absxk = 0.0;
                  scale /= 0.5;
                } else {
                  absxk /= 0.5;
                  scale /= 0.5;
                }

                eshift_re += absxk;
                eshift_im += scale;
              }

              t = eshift_re;
              ad22_im = eshift_im;
            }

            j = col;
            jp1 = col + 1;
            exitg2 = false;
            while ((!exitg2) && (j + 1 > ifirst)) {
              nm1 = j + 1;
              ctemp_tmp_tmp = j << 2;
              ctemp_tmp = ctemp_tmp_tmp + j;
              ctemp.re = A[ctemp_tmp].re * anorm - t * 0.5;
              ctemp.im = A[ctemp_tmp].im * anorm - ad22_im * 0.5;
              colscale = fabs(ctemp.re) + fabs(ctemp.im);
              jp1 += ctemp_tmp_tmp;
              scale = (fabs(A[jp1].re) + fabs(A[jp1].im)) * anorm;
              absxk = colscale;
              if (scale > colscale) {
                absxk = scale;
              }

              if ((absxk < 1.0) && (absxk != 0.0)) {
                colscale /= absxk;
                scale /= absxk;
              }

              jp1 = ((j - 1) << 2) + j;
              if ((fabs(A[jp1].re) + fabs(A[jp1].im)) * scale <= colscale * ssq)
              {
                goto90 = true;
                exitg2 = true;
              } else {
                jp1 = j;
                j--;
              }
            }

            if (!goto90) {
              nm1 = ifirst;
              ctemp_tmp = (((ifirst - 1) << 2) + ifirst) - 1;
              ctemp.re = A[ctemp_tmp].re * anorm - t * 0.5;
              ctemp.im = A[ctemp_tmp].im * anorm - ad22_im * 0.5;
            }

            goto90 = false;
            j = ((nm1 - 1) << 2) + nm1;
            anorm_0.re = A[j].re * anorm;
            anorm_0.im = A[j].im * anorm;
            Simulink_Simulation_xzlartg_m(ctemp, anorm_0, &scale, &y);
            j = nm1;
            jp1 = nm1 - 2;
            while (j < ilast + 1) {
              int32_T stemp_tmp;
              if (j > nm1) {
                Simulink_Simulation_xzlartg(A[(j + (jp1 << 2)) - 1], A[j + (jp1 <<
                  2)], &scale, &y, &A[(j + (jp1 << 2)) - 1]);
                jp1 = (jp1 << 2) + j;
                A[jp1].re = 0.0;
                A[jp1].im = 0.0;
              }

              for (jp1 = j; jp1 < 5; jp1++) {
                ctemp_tmp_tmp = ((jp1 - 1) << 2) + j;
                stemp_tmp_0 = A[ctemp_tmp_tmp].im;
                t = A[ctemp_tmp_tmp].re;
                ad22_im = A[ctemp_tmp_tmp - 1].re;
                stemp.re = (t * y.re - stemp_tmp_0 * y.im) + ad22_im * scale;
                absxk = A[ctemp_tmp_tmp - 1].im;
                stemp.im = (stemp_tmp_0 * y.re + t * y.im) + absxk * scale;
                A[ctemp_tmp_tmp].re = t * scale - (ad22_im * y.re + absxk * y.im);
                A[ctemp_tmp_tmp].im = A[ctemp_tmp_tmp].im * scale - (y.re *
                  absxk - y.im * ad22_im);
                A[ctemp_tmp_tmp - 1] = stemp;
              }

              y.re = -y.re;
              y.im = -y.im;
              ctemp_tmp = j;
              if (ilast + 1 < j + 2) {
                ctemp_tmp = ilast - 1;
              }

              for (jp1 = 1; jp1 <= ctemp_tmp + 2; jp1++) {
                ctemp_tmp_tmp = (((j - 1) << 2) + jp1) - 1;
                stemp_tmp_0 = A[ctemp_tmp_tmp].im;
                t = A[ctemp_tmp_tmp].re;
                stemp_tmp = ((j << 2) + jp1) - 1;
                ad22_im = A[stemp_tmp].re;
                stemp.re = (t * y.re - stemp_tmp_0 * y.im) + ad22_im * scale;
                absxk = A[stemp_tmp].im;
                stemp.im = (stemp_tmp_0 * y.re + t * y.im) + absxk * scale;
                A[ctemp_tmp_tmp].re = t * scale - (ad22_im * y.re + absxk * y.im);
                A[ctemp_tmp_tmp].im = A[ctemp_tmp_tmp].im * scale - (y.re *
                  absxk - y.im * ad22_im);
                A[stemp_tmp] = stemp;
              }

              ctemp_tmp_tmp = (j - 1) << 2;
              colscale = Z[ctemp_tmp_tmp].im;
              t = Z[ctemp_tmp_tmp].re;
              stemp_tmp = j << 2;
              ad22_im = Z[stemp_tmp].re;
              stemp.re = (t * y.re - colscale * y.im) + ad22_im * scale;
              absxk = Z[stemp_tmp].im;
              stemp.im = (colscale * y.re + t * y.im) + absxk * scale;
              Z[ctemp_tmp_tmp].re = t * scale - (ad22_im * y.re + absxk * y.im);
              Z[ctemp_tmp_tmp].im = Z[ctemp_tmp_tmp].im * scale - (y.re * absxk
                - y.im * ad22_im);
              Z[stemp_tmp] = stemp;
              colscale = Z[ctemp_tmp_tmp + 1].im;
              t = Z[ctemp_tmp_tmp + 1].re;
              ad22_im = Z[stemp_tmp + 1].re;
              stemp.re = (t * y.re - colscale * y.im) + ad22_im * scale;
              absxk = Z[stemp_tmp + 1].im;
              stemp.im = (colscale * y.re + t * y.im) + absxk * scale;
              Z[ctemp_tmp_tmp + 1].re = t * scale - (ad22_im * y.re + absxk *
                y.im);
              Z[ctemp_tmp_tmp + 1].im = Z[ctemp_tmp_tmp + 1].im * scale - (y.re *
                absxk - y.im * ad22_im);
              Z[stemp_tmp + 1] = stemp;
              colscale = Z[ctemp_tmp_tmp + 2].im;
              t = Z[ctemp_tmp_tmp + 2].re;
              ad22_im = Z[stemp_tmp + 2].re;
              stemp.re = (t * y.re - colscale * y.im) + ad22_im * scale;
              absxk = Z[stemp_tmp + 2].im;
              stemp.im = (colscale * y.re + t * y.im) + absxk * scale;
              Z[ctemp_tmp_tmp + 2].re = t * scale - (ad22_im * y.re + absxk *
                y.im);
              Z[ctemp_tmp_tmp + 2].im = Z[ctemp_tmp_tmp + 2].im * scale - (y.re *
                absxk - y.im * ad22_im);
              Z[stemp_tmp + 2] = stemp;
              colscale = Z[ctemp_tmp_tmp + 3].im;
              t = Z[ctemp_tmp_tmp + 3].re;
              ad22_im = Z[stemp_tmp + 3].re;
              stemp.re = (t * y.re - colscale * y.im) + ad22_im * scale;
              absxk = Z[stemp_tmp + 3].im;
              stemp.im = (colscale * y.re + t * y.im) + absxk * scale;
              Z[ctemp_tmp_tmp + 3].re = t * scale - (ad22_im * y.re + absxk *
                y.im);
              Z[ctemp_tmp_tmp + 3].im = Z[ctemp_tmp_tmp + 3].im * scale - (y.re *
                absxk - y.im * ad22_im);
              Z[stemp_tmp + 3] = stemp;
              jp1 = j - 1;
              j++;
            }
          }

          jiter++;
        }
      } else {
        guard2 = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  } else {
    guard1 = true;
  }

  if (guard2) {
    if (failed) {
      *info = ilast + 1;
      for (ifirst = 0; ifirst <= ilast; ifirst++) {
        alpha1[ifirst].re = (rtNaN);
        alpha1[ifirst].im = 0.0;
        beta1[ifirst].re = (rtNaN);
        beta1[ifirst].im = 0.0;
      }

      for (jp1 = 0; jp1 < 16; jp1++) {
        Z[jp1].re = (rtNaN);
        Z[jp1].im = 0.0;
      }
    } else {
      guard1 = true;
    }
  }

  if (guard1) {
    ifirst = (uint8_T)(ilo - 1);
    for (ilast = 0; ilast < ifirst; ilast++) {
      alpha1[ilast] = A[(ilast << 2) + ilast];
    }
  }
}

/* Function for MATLAB Function: '<S2>/Reference Generator' */
static void Simulink_Simulation_xztgevc(const creal_T A[16], creal_T V[16])
{
  creal_T work1[4];
  real_T rworka[4];
  real_T anorm;
  real_T ascale;
  int32_T d_re_tmp;
  int32_T i;
  int32_T j;
  int32_T rworka_tmp;
  rworka[0] = 0.0;
  rworka[1] = 0.0;
  rworka[2] = 0.0;
  rworka[3] = 0.0;
  anorm = fabs(A[0].re) + fabs(A[0].im);
  for (j = 0; j < 3; j++) {
    for (i = 0; i <= j; i++) {
      rworka_tmp = ((j + 1) << 2) + i;
      rworka[j + 1] += fabs(A[rworka_tmp].re) + fabs(A[rworka_tmp].im);
    }

    i = (((j + 1) << 2) + j) + 1;
    ascale = (fabs(A[i].re) + fabs(A[i].im)) + rworka[j + 1];
    if (ascale > anorm) {
      anorm = ascale;
    }
  }

  ascale = anorm;
  if (anorm < 2.2250738585072014E-308) {
    ascale = 2.2250738585072014E-308;
  }

  ascale = 1.0 / ascale;
  for (j = 3; j >= 0; j--) {
    real_T acoeff;
    real_T d_im;
    real_T d_re;
    real_T salpha_im;
    real_T salpha_re;
    real_T scale;
    real_T temp;
    real_T work2_idx_2_im;
    real_T work2_idx_3_im;
    real_T work2_idx_3_re;
    int32_T d_re_tmp_tmp;
    boolean_T lscalea;
    boolean_T lscaleb;
    rworka_tmp = j << 2;
    i = rworka_tmp + j;
    salpha_re = A[i].re;
    salpha_im = A[i].im;
    acoeff = (fabs(salpha_re) + fabs(salpha_im)) * ascale;
    if (acoeff < 1.0) {
      acoeff = 1.0;
    }

    temp = 1.0 / acoeff;
    salpha_re = salpha_re * temp * ascale;
    salpha_im = salpha_im * temp * ascale;
    acoeff = temp * ascale;
    lscalea = ((temp >= 2.2250738585072014E-308) && (acoeff <
                4.0083367200179456E-292));
    d_im = fabs(salpha_re) + fabs(salpha_im);
    if ((d_im >= 2.2250738585072014E-308) && (d_im < 4.0083367200179456E-292)) {
      lscaleb = true;
    } else {
      lscaleb = false;
    }

    scale = 1.0;
    if (lscalea) {
      scale = anorm;
      if (anorm > 2.4948003869184E+291) {
        scale = 2.4948003869184E+291;
      }

      scale *= 4.0083367200179456E-292 / temp;
    }

    if (lscaleb) {
      d_re = 4.0083367200179456E-292 / d_im;
      if (d_re > scale) {
        scale = d_re;
      }
    }

    if (lscalea || lscaleb) {
      d_re = acoeff;
      if (acoeff < 1.0) {
        d_re = 1.0;
      }

      if (d_im > d_re) {
        d_re = d_im;
      }

      d_re = 1.0 / (2.2250738585072014E-308 * d_re);
      if (d_re < scale) {
        scale = d_re;
      }

      if (lscalea) {
        acoeff = scale * temp * ascale;
      } else {
        acoeff *= scale;
      }

      salpha_re *= scale;
      salpha_im *= scale;
    }

    memset(&work1[0], 0, sizeof(creal_T) << 2U);
    work1[j].re = 1.0;
    work1[j].im = 0.0;
    scale = 2.2204460492503131E-16 * acoeff * anorm;
    temp = (fabs(salpha_re) + fabs(salpha_im)) * 2.2204460492503131E-16;
    if (temp > scale) {
      scale = temp;
    }

    if (scale < 2.2250738585072014E-308) {
      scale = 2.2250738585072014E-308;
    }

    for (i = 0; i < j; i++) {
      d_re_tmp_tmp = rworka_tmp + i;
      work1[i].re = A[d_re_tmp_tmp].re * acoeff;
      work1[i].im = A[d_re_tmp_tmp].im * acoeff;
    }

    work1[j].re = 1.0;
    work1[j].im = 0.0;
    for (i = j; i >= 1; i--) {
      creal_T work1_0;
      d_re_tmp_tmp = (i - 1) << 2;
      d_re_tmp = (d_re_tmp_tmp + i) - 1;
      d_re = A[d_re_tmp].re * acoeff - salpha_re;
      d_im = A[d_re_tmp].im * acoeff - salpha_im;
      if (fabs(d_re) + fabs(d_im) <= scale) {
        d_re = scale;
        d_im = 0.0;
      }

      work2_idx_2_im = fabs(d_re);
      work2_idx_3_im = fabs(d_im);
      temp = work2_idx_2_im + work2_idx_3_im;
      if (temp < 1.0) {
        work2_idx_3_re = fabs(work1[i - 1].re) + fabs(work1[i - 1].im);
        if (work2_idx_3_re >= temp * 1.1235582092889474E+307) {
          temp = 1.0 / work2_idx_3_re;
          for (d_re_tmp = 0; d_re_tmp <= j; d_re_tmp++) {
            work1_0 = work1[d_re_tmp];
            work1_0.re *= temp;
            work1_0.im *= temp;
            work1[d_re_tmp] = work1_0;
          }
        }
      }

      temp = work1[i - 1].re;
      work2_idx_3_re = work1[i - 1].im;
      if (d_im == 0.0) {
        if (-work2_idx_3_re == 0.0) {
          work1[i - 1].re = -temp / d_re;
          work1[i - 1].im = 0.0;
        } else if (-temp == 0.0) {
          work1[i - 1].re = 0.0;
          work1[i - 1].im = -work2_idx_3_re / d_re;
        } else {
          work1[i - 1].re = -temp / d_re;
          work1[i - 1].im = -work2_idx_3_re / d_re;
        }
      } else if (d_re == 0.0) {
        if (-temp == 0.0) {
          work1[i - 1].re = -work2_idx_3_re / d_im;
          work1[i - 1].im = 0.0;
        } else if (-work2_idx_3_re == 0.0) {
          work1[i - 1].re = 0.0;
          work1[i - 1].im = -(-temp / d_im);
        } else {
          work1[i - 1].re = -work2_idx_3_re / d_im;
          work1[i - 1].im = -(-temp / d_im);
        }
      } else if (work2_idx_2_im > work2_idx_3_im) {
        work2_idx_2_im = d_im / d_re;
        d_im = work2_idx_2_im * d_im + d_re;
        work1[i - 1].re = (work2_idx_2_im * -work2_idx_3_re - temp) / d_im;
        work1[i - 1].im = (-work2_idx_3_re - work2_idx_2_im * -temp) / d_im;
      } else if (work2_idx_3_im == work2_idx_2_im) {
        d_re = d_re > 0.0 ? 0.5 : -0.5;
        d_im = d_im > 0.0 ? 0.5 : -0.5;
        work1[i - 1].re = (-temp * d_re + -work2_idx_3_re * d_im) /
          work2_idx_2_im;
        work1[i - 1].im = (-work2_idx_3_re * d_re - -temp * d_im) /
          work2_idx_2_im;
      } else {
        work2_idx_2_im = d_re / d_im;
        d_im += work2_idx_2_im * d_re;
        work1[i - 1].re = (work2_idx_2_im * -temp - work2_idx_3_re) / d_im;
        work1[i - 1].im = (work2_idx_2_im * -work2_idx_3_re - (-temp)) / d_im;
      }

      if (i > 1) {
        if (fabs(work1[i - 1].re) + fabs(work1[i - 1].im) > 1.0) {
          temp = 1.0 / (fabs(work1[i - 1].re) + fabs(work1[i - 1].im));
          if (rworka[i - 1] * acoeff >= 1.1235582092889474E+307 * temp) {
            for (d_re_tmp = 0; d_re_tmp <= j; d_re_tmp++) {
              work1_0 = work1[d_re_tmp];
              work1_0.re *= temp;
              work1_0.im *= temp;
              work1[d_re_tmp] = work1_0;
            }
          }
        }

        d_re = work1[i - 1].re * acoeff;
        d_im = work1[i - 1].im * acoeff;
        for (d_re_tmp = 0; d_re_tmp <= i - 2; d_re_tmp++) {
          int32_T work1_tmp;
          work1_0 = work1[d_re_tmp];
          work1_tmp = d_re_tmp_tmp + d_re_tmp;
          temp = A[work1_tmp].im;
          work2_idx_2_im = A[work1_tmp].re;
          work1_0.re += work2_idx_2_im * d_re - temp * d_im;
          work1_0.im += temp * d_re + work2_idx_2_im * d_im;
          work1[d_re_tmp] = work1_0;
        }
      }
    }

    salpha_re = 0.0;
    salpha_im = 0.0;
    scale = 0.0;
    d_im = 0.0;
    d_re = 0.0;
    work2_idx_2_im = 0.0;
    work2_idx_3_re = 0.0;
    work2_idx_3_im = 0.0;
    for (i = 0; i <= j; i++) {
      real_T work2_idx_0_re_tmp;
      real_T work2_idx_0_re_tmp_0;
      d_re_tmp_tmp = i << 2;
      work2_idx_0_re_tmp = V[d_re_tmp_tmp].re;
      acoeff = work1[i].im;
      work2_idx_0_re_tmp_0 = V[d_re_tmp_tmp].im;
      temp = work1[i].re;
      salpha_re += work2_idx_0_re_tmp * temp - work2_idx_0_re_tmp_0 * acoeff;
      salpha_im += work2_idx_0_re_tmp * acoeff + work2_idx_0_re_tmp_0 * temp;
      work2_idx_0_re_tmp = V[d_re_tmp_tmp + 1].re;
      work2_idx_0_re_tmp_0 = V[d_re_tmp_tmp + 1].im;
      scale += work2_idx_0_re_tmp * temp - work2_idx_0_re_tmp_0 * acoeff;
      d_im += work2_idx_0_re_tmp * acoeff + work2_idx_0_re_tmp_0 * temp;
      work2_idx_0_re_tmp = V[d_re_tmp_tmp + 2].re;
      work2_idx_0_re_tmp_0 = V[d_re_tmp_tmp + 2].im;
      d_re += work2_idx_0_re_tmp * temp - work2_idx_0_re_tmp_0 * acoeff;
      work2_idx_2_im += work2_idx_0_re_tmp * acoeff + work2_idx_0_re_tmp_0 *
        temp;
      work2_idx_0_re_tmp = V[d_re_tmp_tmp + 3].re;
      work2_idx_0_re_tmp_0 = V[d_re_tmp_tmp + 3].im;
      work2_idx_3_re += work2_idx_0_re_tmp * temp - work2_idx_0_re_tmp_0 *
        acoeff;
      work2_idx_3_im += work2_idx_0_re_tmp * acoeff + work2_idx_0_re_tmp_0 *
        temp;
    }

    acoeff = fabs(salpha_re) + fabs(salpha_im);
    temp = fabs(scale) + fabs(d_im);
    if (temp > acoeff) {
      acoeff = temp;
    }

    temp = fabs(d_re) + fabs(work2_idx_2_im);
    if (temp > acoeff) {
      acoeff = temp;
    }

    temp = fabs(work2_idx_3_re) + fabs(work2_idx_3_im);
    if (temp > acoeff) {
      acoeff = temp;
    }

    if (acoeff > 2.2250738585072014E-308) {
      temp = 1.0 / acoeff;
      V[rworka_tmp].re = temp * salpha_re;
      V[rworka_tmp].im = temp * salpha_im;
      d_re_tmp_tmp = (j << 2) + 1;
      V[d_re_tmp_tmp].re = temp * scale;
      V[d_re_tmp_tmp].im = temp * d_im;
      d_re_tmp_tmp = (j << 2) + 2;
      V[d_re_tmp_tmp].re = temp * d_re;
      V[d_re_tmp_tmp].im = temp * work2_idx_2_im;
      d_re_tmp_tmp = (j << 2) + 3;
      V[d_re_tmp_tmp].re = temp * work2_idx_3_re;
      V[d_re_tmp_tmp].im = temp * work2_idx_3_im;
    } else {
      V[rworka_tmp].re = 0.0;
      V[rworka_tmp].im = 0.0;
      V[rworka_tmp + 1].re = 0.0;
      V[rworka_tmp + 1].im = 0.0;
      V[rworka_tmp + 2].re = 0.0;
      V[rworka_tmp + 2].im = 0.0;
      V[rworka_tmp + 3].re = 0.0;
      V[rworka_tmp + 3].im = 0.0;
    }
  }
}

/* Function for MATLAB Function: '<S2>/Reference Generator' */
static void Simulink_Simulation_xzgeev(const real_T A[16], int32_T *info,
  creal_T alpha1[4], creal_T beta1[4], creal_T V[16])
{
  creal_T At[16];
  creal_T atmp;
  real_T anrm;
  real_T b_absxk;
  real_T cfromc;
  real_T ctoc;
  int32_T rscale[4];
  int32_T atmp_tmp;
  int32_T b_k;
  int32_T g_k;
  int32_T ii;
  int32_T jcol;
  int32_T jrow;
  boolean_T exitg1;
  for (atmp_tmp = 0; atmp_tmp < 16; atmp_tmp++) {
    At[atmp_tmp].re = A[atmp_tmp];
    At[atmp_tmp].im = 0.0;
  }

  *info = 0;
  anrm = 0.0;
  b_k = 0;
  exitg1 = false;
  while ((!exitg1) && (b_k < 16)) {
    b_absxk = rt_hypotd_snf(At[b_k].re, At[b_k].im);
    if (rtIsNaN(b_absxk)) {
      anrm = (rtNaN);
      exitg1 = true;
    } else {
      if (b_absxk > anrm) {
        anrm = b_absxk;
      }

      b_k++;
    }
  }

  if (rtIsInf(anrm) || rtIsNaN(anrm)) {
    alpha1[0].re = (rtNaN);
    alpha1[0].im = 0.0;
    beta1[0].re = (rtNaN);
    beta1[0].im = 0.0;
    alpha1[1].re = (rtNaN);
    alpha1[1].im = 0.0;
    beta1[1].re = (rtNaN);
    beta1[1].im = 0.0;
    alpha1[2].re = (rtNaN);
    alpha1[2].im = 0.0;
    beta1[2].re = (rtNaN);
    beta1[2].im = 0.0;
    alpha1[3].re = (rtNaN);
    alpha1[3].im = 0.0;
    beta1[3].re = (rtNaN);
    beta1[3].im = 0.0;
    for (atmp_tmp = 0; atmp_tmp < 16; atmp_tmp++) {
      V[atmp_tmp].re = (rtNaN);
      V[atmp_tmp].im = 0.0;
    }
  } else {
    real_T cfrom1;
    real_T cto1;
    real_T stemp_im_tmp;
    int32_T exitg3;
    int32_T jj;
    int32_T nzcount;
    boolean_T exitg4;
    boolean_T guard1 = false;
    boolean_T ilascl;
    boolean_T notdone;
    ilascl = false;
    b_absxk = anrm;
    guard1 = false;
    if ((anrm > 0.0) && (anrm < 6.7178761075670888E-139)) {
      b_absxk = 6.7178761075670888E-139;
      ilascl = true;
      guard1 = true;
    } else if (anrm > 1.4885657073574029E+138) {
      b_absxk = 1.4885657073574029E+138;
      ilascl = true;
      guard1 = true;
    }

    if (guard1) {
      cfromc = anrm;
      ctoc = b_absxk;
      notdone = true;
      while (notdone) {
        cfrom1 = cfromc * 2.0041683600089728E-292;
        cto1 = ctoc / 4.9896007738368E+291;
        if ((cfrom1 > ctoc) && (ctoc != 0.0)) {
          stemp_im_tmp = 2.0041683600089728E-292;
          cfromc = cfrom1;
        } else if (cto1 > cfromc) {
          stemp_im_tmp = 4.9896007738368E+291;
          ctoc = cto1;
        } else {
          stemp_im_tmp = ctoc / cfromc;
          notdone = false;
        }

        for (atmp_tmp = 0; atmp_tmp < 16; atmp_tmp++) {
          atmp = At[atmp_tmp];
          atmp.re *= stemp_im_tmp;
          atmp.im *= stemp_im_tmp;
          At[atmp_tmp] = atmp;
        }
      }
    }

    rscale[0] = 1;
    rscale[1] = 1;
    rscale[2] = 1;
    rscale[3] = 1;
    g_k = 1;
    b_k = 4;
    do {
      exitg3 = 0;
      jrow = 0;
      jcol = 0;
      notdone = false;
      ii = b_k;
      exitg1 = false;
      while ((!exitg1) && (ii > 0)) {
        nzcount = 0;
        jrow = ii;
        jcol = b_k;
        jj = 0;
        exitg4 = false;
        while ((!exitg4) && (jj <= (uint8_T)b_k - 1)) {
          atmp_tmp = ((jj << 2) + ii) - 1;
          if ((At[atmp_tmp].re != 0.0) || (At[atmp_tmp].im != 0.0) || (jj + 1 ==
               ii)) {
            if (nzcount == 0) {
              jcol = jj + 1;
              nzcount = 1;
              jj++;
            } else {
              nzcount = 2;
              exitg4 = true;
            }
          } else {
            jj++;
          }
        }

        if (nzcount < 2) {
          notdone = true;
          exitg1 = true;
        } else {
          ii--;
        }
      }

      if (!notdone) {
        exitg3 = 2;
      } else {
        if (jrow != b_k) {
          atmp = At[jrow - 1];
          At[jrow - 1] = At[b_k - 1];
          At[b_k - 1] = atmp;
          atmp = At[jrow + 3];
          At[jrow + 3] = At[b_k + 3];
          At[b_k + 3] = atmp;
          atmp = At[jrow + 7];
          At[jrow + 7] = At[b_k + 7];
          At[b_k + 7] = atmp;
          atmp = At[jrow + 11];
          At[jrow + 11] = At[b_k + 11];
          At[b_k + 11] = atmp;
        }

        if (jcol != b_k) {
          for (jrow = 0; jrow < b_k; jrow++) {
            atmp_tmp = ((jcol - 1) << 2) + jrow;
            atmp = At[atmp_tmp];
            nzcount = ((b_k - 1) << 2) + jrow;
            At[atmp_tmp] = At[nzcount];
            At[nzcount] = atmp;
          }
        }

        rscale[b_k - 1] = jcol;
        b_k--;
        if (b_k == 1) {
          rscale[0] = 1;
          exitg3 = 1;
        }
      }
    } while (exitg3 == 0);

    if (exitg3 == 1) {
    } else {
      int32_T exitg2;
      do {
        exitg2 = 0;
        jrow = 0;
        jcol = 0;
        notdone = false;
        ii = g_k;
        exitg1 = false;
        while ((!exitg1) && (ii <= b_k)) {
          nzcount = 0;
          jrow = b_k;
          jcol = ii;
          jj = g_k;
          exitg4 = false;
          while ((!exitg4) && (jj <= b_k)) {
            atmp_tmp = (((ii - 1) << 2) + jj) - 1;
            if ((At[atmp_tmp].re != 0.0) || (At[atmp_tmp].im != 0.0) || (jj ==
                 ii)) {
              if (nzcount == 0) {
                jrow = jj;
                nzcount = 1;
                jj++;
              } else {
                nzcount = 2;
                exitg4 = true;
              }
            } else {
              jj++;
            }
          }

          if (nzcount < 2) {
            notdone = true;
            exitg1 = true;
          } else {
            ii++;
          }
        }

        if (!notdone) {
          exitg2 = 1;
        } else {
          if (jrow != g_k) {
            for (ii = g_k; ii < 5; ii++) {
              atmp_tmp = (ii - 1) << 2;
              jj = (atmp_tmp + jrow) - 1;
              atmp = At[jj];
              nzcount = (atmp_tmp + g_k) - 1;
              At[jj] = At[nzcount];
              At[nzcount] = atmp;
            }
          }

          if (jcol != g_k) {
            for (jrow = 0; jrow < b_k; jrow++) {
              atmp_tmp = ((jcol - 1) << 2) + jrow;
              atmp = At[atmp_tmp];
              nzcount = ((g_k - 1) << 2) + jrow;
              At[atmp_tmp] = At[nzcount];
              At[nzcount] = atmp;
            }
          }

          rscale[g_k - 1] = jcol;
          g_k++;
          if (g_k == b_k) {
            rscale[g_k - 1] = g_k;
            exitg2 = 1;
          }
        }
      } while (exitg2 == 0);
    }

    memset(&V[0], 0, sizeof(creal_T) << 4U);
    V[0].re = 1.0;
    V[0].im = 0.0;
    V[5].re = 1.0;
    V[5].im = 0.0;
    V[10].re = 1.0;
    V[10].im = 0.0;
    V[15].re = 1.0;
    V[15].im = 0.0;
    if (b_k >= g_k + 2) {
      for (jcol = g_k - 1; jcol + 1 < b_k - 1; jcol++) {
        for (jrow = b_k - 1; jrow + 1 > jcol + 2; jrow--) {
          Simulink_Simulation_xzlartg(At[(jrow + (jcol << 2)) - 1], At[jrow +
            (jcol << 2)], &cfromc, &atmp, &At[(jrow + (jcol << 2)) - 1]);
          atmp_tmp = (jcol << 2) + jrow;
          At[atmp_tmp].re = 0.0;
          At[atmp_tmp].im = 0.0;
          for (ii = jcol + 2; ii < 5; ii++) {
            atmp_tmp = ((ii - 1) << 2) + jrow;
            ctoc = At[atmp_tmp].im;
            cfrom1 = At[atmp_tmp].re;
            cto1 = At[atmp_tmp - 1].re;
            stemp_im_tmp = At[atmp_tmp - 1].im;
            At[atmp_tmp].re = cfrom1 * cfromc - (cto1 * atmp.re + stemp_im_tmp *
              atmp.im);
            At[atmp_tmp].im = ctoc * cfromc - (stemp_im_tmp * atmp.re - atmp.im *
              cto1);
            At[atmp_tmp - 1].re = (cfrom1 * atmp.re - ctoc * atmp.im) + cto1 *
              cfromc;
            At[atmp_tmp - 1].im = (ctoc * atmp.re + cfrom1 * atmp.im) +
              stemp_im_tmp * cfromc;
          }

          atmp.re = -atmp.re;
          atmp.im = -atmp.im;
          for (ii = 1; ii <= b_k; ii++) {
            atmp_tmp = (((jrow - 1) << 2) + ii) - 1;
            ctoc = At[atmp_tmp].im;
            cfrom1 = At[atmp_tmp].re;
            nzcount = ((jrow << 2) + ii) - 1;
            cto1 = At[nzcount].re;
            stemp_im_tmp = At[nzcount].im;
            At[atmp_tmp].re = cfrom1 * cfromc - (cto1 * atmp.re + stemp_im_tmp *
              atmp.im);
            At[atmp_tmp].im = ctoc * cfromc - (stemp_im_tmp * atmp.re - atmp.im *
              cto1);
            At[nzcount].re = (cfrom1 * atmp.re - ctoc * atmp.im) + cto1 * cfromc;
            At[nzcount].im = (ctoc * atmp.re + cfrom1 * atmp.im) + stemp_im_tmp *
              cfromc;
          }

          atmp_tmp = (jrow - 1) << 2;
          ctoc = V[atmp_tmp].im;
          cfrom1 = V[atmp_tmp].re;
          nzcount = jrow << 2;
          cto1 = V[nzcount].re;
          stemp_im_tmp = V[nzcount].im;
          V[atmp_tmp].re = cfrom1 * cfromc - (cto1 * atmp.re + stemp_im_tmp *
            atmp.im);
          V[atmp_tmp].im = ctoc * cfromc - (stemp_im_tmp * atmp.re - atmp.im *
            cto1);
          V[nzcount].re = (cfrom1 * atmp.re - ctoc * atmp.im) + cto1 * cfromc;
          V[nzcount].im = (ctoc * atmp.re + cfrom1 * atmp.im) + stemp_im_tmp *
            cfromc;
          ctoc = V[atmp_tmp + 1].im;
          cfrom1 = V[atmp_tmp + 1].re;
          cto1 = V[nzcount + 1].re;
          stemp_im_tmp = V[nzcount + 1].im;
          V[atmp_tmp + 1].re = cfrom1 * cfromc - (cto1 * atmp.re + stemp_im_tmp *
            atmp.im);
          V[atmp_tmp + 1].im = ctoc * cfromc - (stemp_im_tmp * atmp.re - atmp.im
            * cto1);
          V[nzcount + 1].re = (cfrom1 * atmp.re - ctoc * atmp.im) + cto1 *
            cfromc;
          V[nzcount + 1].im = (ctoc * atmp.re + cfrom1 * atmp.im) + stemp_im_tmp
            * cfromc;
          ctoc = V[atmp_tmp + 2].im;
          cfrom1 = V[atmp_tmp + 2].re;
          cto1 = V[nzcount + 2].re;
          stemp_im_tmp = V[nzcount + 2].im;
          V[atmp_tmp + 2].re = cfrom1 * cfromc - (cto1 * atmp.re + stemp_im_tmp *
            atmp.im);
          V[atmp_tmp + 2].im = ctoc * cfromc - (stemp_im_tmp * atmp.re - atmp.im
            * cto1);
          V[nzcount + 2].re = (cfrom1 * atmp.re - ctoc * atmp.im) + cto1 *
            cfromc;
          V[nzcount + 2].im = (ctoc * atmp.re + cfrom1 * atmp.im) + stemp_im_tmp
            * cfromc;
          ctoc = V[atmp_tmp + 3].im;
          cfrom1 = V[atmp_tmp + 3].re;
          cto1 = V[nzcount + 3].re;
          stemp_im_tmp = V[nzcount + 3].im;
          V[atmp_tmp + 3].re = cfrom1 * cfromc - (cto1 * atmp.re + stemp_im_tmp *
            atmp.im);
          V[atmp_tmp + 3].im = ctoc * cfromc - (stemp_im_tmp * atmp.re - atmp.im
            * cto1);
          V[nzcount + 3].re = (cfrom1 * atmp.re - ctoc * atmp.im) + cto1 *
            cfromc;
          V[nzcount + 3].im = (ctoc * atmp.re + cfrom1 * atmp.im) + stemp_im_tmp
            * cfromc;
        }
      }
    }

    Simulink_Simulation_xzhgeqz(At, g_k, b_k, V, info, alpha1, beta1);
    if (*info == 0) {
      Simulink_Simulation_xztgevc(At, V);
      if (g_k > 1) {
        for (jcol = g_k - 2; jcol + 1 >= 1; jcol--) {
          g_k = rscale[jcol] - 1;
          if (jcol + 1 != rscale[jcol]) {
            atmp = V[jcol];
            V[jcol] = V[g_k];
            V[g_k] = atmp;
            atmp = V[jcol + 4];
            V[jcol + 4] = V[g_k + 4];
            V[g_k + 4] = atmp;
            atmp = V[jcol + 8];
            V[jcol + 8] = V[g_k + 8];
            V[g_k + 8] = atmp;
            atmp = V[jcol + 12];
            V[jcol + 12] = V[g_k + 12];
            V[g_k + 12] = atmp;
          }
        }
      }

      if (b_k < 4) {
        for (jcol = b_k + 1; jcol < 5; jcol++) {
          g_k = rscale[jcol - 1];
          if (g_k != jcol) {
            atmp = V[jcol - 1];
            V[jcol - 1] = V[g_k - 1];
            V[g_k - 1] = atmp;
            atmp = V[jcol + 3];
            V[jcol + 3] = V[g_k + 3];
            V[g_k + 3] = atmp;
            atmp = V[jcol + 7];
            V[jcol + 7] = V[g_k + 7];
            V[g_k + 7] = atmp;
            atmp = V[jcol + 11];
            V[jcol + 11] = V[g_k + 11];
            V[g_k + 11] = atmp;
          }
        }
      }

      for (b_k = 0; b_k < 4; b_k++) {
        jcol = b_k << 2;
        cfrom1 = V[jcol].re;
        cto1 = V[jcol].im;
        cfromc = fabs(cfrom1) + fabs(cto1);
        ctoc = fabs(V[jcol + 1].re) + fabs(V[jcol + 1].im);
        if (ctoc > cfromc) {
          cfromc = ctoc;
        }

        ctoc = fabs(V[jcol + 2].re) + fabs(V[jcol + 2].im);
        if (ctoc > cfromc) {
          cfromc = ctoc;
        }

        ctoc = fabs(V[jcol + 3].re) + fabs(V[jcol + 3].im);
        if (ctoc > cfromc) {
          cfromc = ctoc;
        }

        if (cfromc >= 6.7178761075670888E-139) {
          cfromc = 1.0 / cfromc;
          V[jcol].re = cfrom1 * cfromc;
          V[jcol].im = cto1 * cfromc;
          V[jcol + 1].re *= cfromc;
          V[jcol + 1].im *= cfromc;
          V[jcol + 2].re *= cfromc;
          V[jcol + 2].im *= cfromc;
          V[jcol + 3].re *= cfromc;
          V[jcol + 3].im *= cfromc;
        }
      }

      if (ilascl) {
        while (ilascl) {
          cfromc = b_absxk * 2.0041683600089728E-292;
          ctoc = anrm / 4.9896007738368E+291;
          if ((cfromc > anrm) && (anrm != 0.0)) {
            cfrom1 = 2.0041683600089728E-292;
            b_absxk = cfromc;
          } else if (ctoc > b_absxk) {
            cfrom1 = 4.9896007738368E+291;
            anrm = ctoc;
          } else {
            cfrom1 = anrm / b_absxk;
            ilascl = false;
          }

          alpha1[0].re *= cfrom1;
          alpha1[0].im *= cfrom1;
          alpha1[1].re *= cfrom1;
          alpha1[1].im *= cfrom1;
          alpha1[2].re *= cfrom1;
          alpha1[2].im *= cfrom1;
          alpha1[3].re *= cfrom1;
          alpha1[3].im *= cfrom1;
        }
      }
    }
  }

  for (b_k = 0; b_k <= 12; b_k += 4) {
    anrm = 0.0;
    b_absxk = 3.3121686421112381E-170;
    for (g_k = b_k + 1; g_k <= b_k + 4; g_k++) {
      cfromc = fabs(V[g_k - 1].re);
      if (cfromc > b_absxk) {
        ctoc = b_absxk / cfromc;
        anrm = anrm * ctoc * ctoc + 1.0;
        b_absxk = cfromc;
      } else {
        ctoc = cfromc / b_absxk;
        anrm += ctoc * ctoc;
      }

      cfromc = fabs(V[g_k - 1].im);
      if (cfromc > b_absxk) {
        ctoc = b_absxk / cfromc;
        anrm = anrm * ctoc * ctoc + 1.0;
        b_absxk = cfromc;
      } else {
        ctoc = cfromc / b_absxk;
        anrm += ctoc * ctoc;
      }
    }

    anrm = b_absxk * sqrt(anrm);
    for (g_k = b_k + 1; g_k <= b_k + 4; g_k++) {
      b_absxk = V[g_k - 1].re;
      cfromc = V[g_k - 1].im;
      if (cfromc == 0.0) {
        V[g_k - 1].re = b_absxk / anrm;
        V[g_k - 1].im = 0.0;
      } else if (b_absxk == 0.0) {
        V[g_k - 1].re = 0.0;
        V[g_k - 1].im = cfromc / anrm;
      } else {
        V[g_k - 1].re = b_absxk / anrm;
        V[g_k - 1].im = cfromc / anrm;
      }
    }
  }
}

/* Function for MATLAB Function: '<S2>/Reference Generator' */
static real_T Simulink_Simulation_xnrm2(int32_T n, const real_T x[16], int32_T
  ix0)
{
  real_T y;
  int32_T k;
  y = 0.0;
  if (n >= 1) {
    if (n == 1) {
      y = fabs(x[ix0 - 1]);
    } else {
      real_T scale;
      scale = 3.3121686421112381E-170;
      for (k = ix0; k <= ix0 + 1; k++) {
        real_T absxk;
        absxk = fabs(x[k - 1]);
        if (absxk > scale) {
          real_T t;
          t = scale / absxk;
          y = y * t * t + 1.0;
          scale = absxk;
        } else {
          real_T t;
          t = absxk / scale;
          y += t * t;
        }
      }

      y = scale * sqrt(y);
    }
  }

  return y;
}

/* Function for MATLAB Function: '<S2>/Reference Generator' */
static void Simulink_Simulation_xzlarf(int32_T m, int32_T n, int32_T iv0, real_T
  tau, real_T C[16], int32_T ic0, real_T work[4])
{
  int32_T coltop;
  int32_T jA;
  int32_T lastc;
  int32_T lastv;
  if (tau != 0.0) {
    boolean_T exitg2;
    lastv = m;
    lastc = iv0 + m;
    while ((lastv > 0) && (C[lastc - 2] == 0.0)) {
      lastv--;
      lastc--;
    }

    lastc = n;
    exitg2 = false;
    while ((!exitg2) && (lastc > 0)) {
      int32_T exitg1;
      coltop = ((lastc - 1) << 2) + ic0;
      jA = coltop;
      do {
        exitg1 = 0;
        if (jA <= (coltop + lastv) - 1) {
          if (C[jA - 1] != 0.0) {
            exitg1 = 1;
          } else {
            jA++;
          }
        } else {
          lastc--;
          exitg1 = 2;
        }
      } while (exitg1 == 0);

      if (exitg1 == 1) {
        exitg2 = true;
      }
    }
  } else {
    lastv = 0;
    lastc = 0;
  }

  if (lastv > 0) {
    real_T c;
    int32_T d;
    int32_T e;
    if (lastc != 0) {
      memset(&work[0], 0, (uint8_T)lastc * sizeof(real_T));
      d = ((lastc - 1) << 2) + ic0;
      for (coltop = ic0; coltop <= d; coltop += 4) {
        c = 0.0;
        e = coltop + lastv;
        for (jA = coltop; jA < e; jA++) {
          c += C[((iv0 + jA) - coltop) - 1] * C[jA - 1];
        }

        jA = (coltop - ic0) >> 2;
        work[jA] += c;
      }
    }

    if (!(-tau == 0.0)) {
      jA = ic0;
      d = (uint8_T)lastc;
      for (lastc = 0; lastc < d; lastc++) {
        if (work[lastc] != 0.0) {
          c = work[lastc] * -tau;
          e = lastv + jA;
          for (coltop = jA; coltop < e; coltop++) {
            C[coltop - 1] += C[((iv0 + coltop) - jA) - 1] * c;
          }
        }

        jA += 4;
      }
    }
  }
}

/* Function for MATLAB Function: '<S2>/Reference Generator' */
static real_T Simulink_Simulation_xnrm2_f(int32_T n, const real_T x[3])
{
  real_T y;
  y = 0.0;
  if (n >= 1) {
    if (n == 1) {
      y = fabs(x[1]);
    } else {
      real_T absxk;
      real_T scale;
      real_T t;
      scale = 3.3121686421112381E-170;
      absxk = fabs(x[1]);
      if (absxk > 3.3121686421112381E-170) {
        y = 1.0;
        scale = absxk;
      } else {
        t = absxk / 3.3121686421112381E-170;
        y = t * t;
      }

      absxk = fabs(x[2]);
      if (absxk > scale) {
        t = scale / absxk;
        y = y * t * t + 1.0;
        scale = absxk;
      } else {
        t = absxk / scale;
        y += t * t;
      }

      y = scale * sqrt(y);
    }
  }

  return y;
}

/* Function for MATLAB Function: '<S2>/Reference Generator' */
static real_T Simulink_Simulation_xzlarfg(int32_T n, real_T *alpha1, real_T x[3])
{
  real_T tau;
  int32_T c_k;
  int32_T knt;
  tau = 0.0;
  if (n > 0) {
    real_T xnorm;
    xnorm = Simulink_Simulation_xnrm2_f(n - 1, x);
    if (xnorm != 0.0) {
      xnorm = rt_hypotd_snf(*alpha1, xnorm);
      if (*alpha1 >= 0.0) {
        xnorm = -xnorm;
      }

      if (fabs(xnorm) < 1.0020841800044864E-292) {
        __m128d tmp;
        real_T a;
        int32_T scalarLB;
        int32_T vectorUB;
        knt = 0;
        do {
          knt++;
          scalarLB = (((n - 1) / 2) << 1) + 2;
          vectorUB = scalarLB - 2;
          for (c_k = 2; c_k <= vectorUB; c_k += 2) {
            tmp = _mm_loadu_pd(&x[c_k - 1]);
            _mm_storeu_pd(&x[c_k - 1], _mm_mul_pd(tmp, _mm_set1_pd
              (9.9792015476736E+291)));
          }

          for (c_k = scalarLB; c_k <= n; c_k++) {
            x[c_k - 1] *= 9.9792015476736E+291;
          }

          xnorm *= 9.9792015476736E+291;
          *alpha1 *= 9.9792015476736E+291;
        } while ((fabs(xnorm) < 1.0020841800044864E-292) && (knt < 20));

        xnorm = rt_hypotd_snf(*alpha1, Simulink_Simulation_xnrm2_f(n - 1, x));
        if (*alpha1 >= 0.0) {
          xnorm = -xnorm;
        }

        tau = (xnorm - *alpha1) / xnorm;
        a = 1.0 / (*alpha1 - xnorm);
        scalarLB = (((n - 1) / 2) << 1) + 2;
        vectorUB = scalarLB - 2;
        for (c_k = 2; c_k <= vectorUB; c_k += 2) {
          tmp = _mm_loadu_pd(&x[c_k - 1]);
          _mm_storeu_pd(&x[c_k - 1], _mm_mul_pd(tmp, _mm_set1_pd(a)));
        }

        for (c_k = scalarLB; c_k <= n; c_k++) {
          x[c_k - 1] *= a;
        }

        for (c_k = 0; c_k < knt; c_k++) {
          xnorm *= 1.0020841800044864E-292;
        }

        *alpha1 = xnorm;
      } else {
        real_T a;
        int32_T scalarLB;
        int32_T vectorUB;
        tau = (xnorm - *alpha1) / xnorm;
        a = 1.0 / (*alpha1 - xnorm);
        scalarLB = (((n - 1) / 2) << 1) + 2;
        vectorUB = scalarLB - 2;
        for (knt = 2; knt <= vectorUB; knt += 2) {
          __m128d tmp;
          tmp = _mm_loadu_pd(&x[knt - 1]);
          _mm_storeu_pd(&x[knt - 1], _mm_mul_pd(tmp, _mm_set1_pd(a)));
        }

        for (knt = scalarLB; knt <= n; knt++) {
          x[knt - 1] *= a;
        }

        *alpha1 = xnorm;
      }
    }
  }

  return tau;
}

/* Function for MATLAB Function: '<S2>/Reference Generator' */
static void Simulink_Simulation_xdlanv2(real_T *a, real_T *b, real_T *c, real_T *
  d, real_T *rt1r, real_T *rt1i, real_T *rt2r, real_T *rt2i, real_T *cs, real_T *
  sn)
{
  if (*c == 0.0) {
    *cs = 1.0;
    *sn = 0.0;
  } else if (*b == 0.0) {
    real_T temp;
    *cs = 0.0;
    *sn = 1.0;
    temp = *d;
    *d = *a;
    *a = temp;
    *b = -*c;
    *c = 0.0;
  } else {
    real_T temp;
    temp = *a - *d;
    if ((temp == 0.0) && ((*b < 0.0) != (*c < 0.0))) {
      *cs = 1.0;
      *sn = 0.0;
    } else {
      real_T bcmax;
      real_T bcmis;
      real_T p;
      real_T scale;
      real_T z;
      int32_T count;
      int32_T tmp;
      p = 0.5 * temp;
      bcmis = fabs(*b);
      scale = fabs(*c);
      bcmax = fmax(bcmis, scale);
      if (!(*b < 0.0)) {
        count = 1;
      } else {
        count = -1;
      }

      if (!(*c < 0.0)) {
        tmp = 1;
      } else {
        tmp = -1;
      }

      bcmis = fmin(bcmis, scale) * (real_T)count * (real_T)tmp;
      scale = fmax(fabs(p), bcmax);
      z = p / scale * p + bcmax / scale * bcmis;
      if (z >= 8.8817841970012523E-16) {
        if (!(p < 0.0)) {
          temp = sqrt(scale) * sqrt(z);
        } else {
          temp = -(sqrt(scale) * sqrt(z));
        }

        z = p + temp;
        *a = *d + z;
        *d -= bcmax / z * bcmis;
        bcmax = rt_hypotd_snf(*c, z);
        *cs = z / bcmax;
        *sn = *c / bcmax;
        *b -= *c;
        *c = 0.0;
      } else {
        p = *b + *c;
        scale = fmax(fabs(temp), fabs(p));
        count = 0;
        while ((scale >= 7.4428285367870146E+137) && (count <= 20)) {
          p *= 1.3435752215134178E-138;
          temp *= 1.3435752215134178E-138;
          scale = fmax(fabs(temp), fabs(p));
          count++;
        }

        while ((scale <= 1.3435752215134178E-138) && (count <= 20)) {
          p *= 7.4428285367870146E+137;
          temp *= 7.4428285367870146E+137;
          scale = fmax(fabs(temp), fabs(p));
          count++;
        }

        bcmax = rt_hypotd_snf(p, temp);
        *cs = sqrt((fabs(p) / bcmax + 1.0) * 0.5);
        if (!(p < 0.0)) {
          count = 1;
        } else {
          count = -1;
        }

        *sn = -(0.5 * temp / (bcmax * *cs)) * (real_T)count;
        temp = *a * *cs + *b * *sn;
        p = -*a * *sn + *b * *cs;
        bcmax = *c * *cs + *d * *sn;
        bcmis = -*c * *sn + *d * *cs;
        *b = p * *cs + bcmis * *sn;
        *c = -temp * *sn + bcmax * *cs;
        temp = ((temp * *cs + bcmax * *sn) + (-p * *sn + bcmis * *cs)) * 0.5;
        *a = temp;
        *d = temp;
        if (*c != 0.0) {
          if (*b != 0.0) {
            if ((*b < 0.0) == (*c < 0.0)) {
              scale = sqrt(fabs(*b));
              bcmis = sqrt(fabs(*c));
              p = scale * bcmis;
              if (*c < 0.0) {
                p = -p;
              }

              bcmax = 1.0 / sqrt(fabs(*b + *c));
              *a = temp + p;
              *d = temp - p;
              *b -= *c;
              *c = 0.0;
              p = scale * bcmax;
              bcmax *= bcmis;
              temp = *cs * p - *sn * bcmax;
              *sn = *cs * bcmax + *sn * p;
              *cs = temp;
            }
          } else {
            *b = -*c;
            *c = 0.0;
            temp = *cs;
            *cs = -*sn;
            *sn = temp;
          }
        }
      }
    }
  }

  *rt1r = *a;
  *rt2r = *d;
  if (*c == 0.0) {
    *rt1i = 0.0;
    *rt2i = 0.0;
  } else {
    *rt1i = sqrt(fabs(*b)) * sqrt(fabs(*c));
    *rt2i = -*rt1i;
  }
}

/* Function for MATLAB Function: '<S2>/Reference Generator' */
static int32_T Simulink_Simulation_xhseqr(real_T h[16], real_T z[16])
{
  real_T v[3];
  real_T a__4;
  real_T aa;
  real_T ab;
  real_T ba;
  real_T h12;
  real_T htmp1;
  real_T tst;
  real_T tst_tmp;
  real_T tst_tmp_tmp;
  int32_T c_ix;
  int32_T i;
  int32_T info;
  int32_T j;
  int32_T kdefl;
  boolean_T exitg1;
  info = 0;
  v[0] = 0.0;
  v[1] = 0.0;
  v[2] = 0.0;
  h[2] = 0.0;
  h[3] = 0.0;
  h[7] = 0.0;
  kdefl = 0;
  i = 3;
  exitg1 = false;
  while ((!exitg1) && (i + 1 >= 1)) {
    int32_T L;
    int32_T hoffset;
    int32_T iy;
    int32_T k;
    int32_T m;
    boolean_T exitg2;
    boolean_T goto150;
    L = 1;
    goto150 = false;
    iy = 0;
    exitg2 = false;
    while ((!exitg2) && (iy < 301)) {
      boolean_T exitg3;
      k = i;
      exitg3 = false;
      while ((!exitg3) && (k + 1 > L)) {
        hoffset = ((k - 1) << 2) + k;
        if (fabs(h[hoffset]) <= 4.0083367200179456E-292) {
          exitg3 = true;
        } else {
          c_ix = (k << 2) + k;
          tst = fabs(h[hoffset - 1]) + fabs(h[c_ix]);
          if (tst == 0.0) {
            if (k - 1 >= 1) {
              tst = fabs(h[(((k - 2) << 2) + k) - 1]);
            }

            if (k + 2 <= 4) {
              tst += fabs(h[c_ix + 1]);
            }
          }

          ba = fabs(h[hoffset]);
          if (ba <= 2.2204460492503131E-16 * tst) {
            tst = fabs(h[c_ix - 1]);
            if (ba > tst) {
              ab = ba;
              ba = tst;
            } else {
              ab = tst;
            }

            tst = h[c_ix];
            htmp1 = fabs(tst);
            tst = fabs(h[hoffset - 1] - tst);
            if (htmp1 > tst) {
              aa = htmp1;
              htmp1 = tst;
            } else {
              aa = tst;
            }

            tst = aa + ab;
            if (ab / tst * ba <= fmax(4.0083367200179456E-292, aa / tst * htmp1 *
                 2.2204460492503131E-16)) {
              exitg3 = true;
            } else {
              k--;
            }
          } else {
            k--;
          }
        }
      }

      L = k + 1;
      if (k + 1 > 1) {
        h[k + ((k - 1) << 2)] = 0.0;
      }

      if (k + 1 >= i) {
        goto150 = true;
        exitg2 = true;
      } else {
        kdefl++;
        if (kdefl - kdefl / 20 * 20 == 0) {
          tst = fabs(h[(((i - 2) << 2) + i) - 1]) + fabs(h[((i - 1) << 2) + i]);
          ba = h[(i << 2) + i] + 0.75 * tst;
          h12 = -0.4375 * tst;
          aa = tst;
          htmp1 = ba;
        } else if (kdefl - kdefl / 10 * 10 == 0) {
          tst = fabs(h[(((k + 1) << 2) + k) + 2]) + fabs(h[((k << 2) + k) + 1]);
          ba = h[(k << 2) + k] + 0.75 * tst;
          h12 = -0.4375 * tst;
          aa = tst;
          htmp1 = ba;
        } else {
          hoffset = ((i - 1) << 2) + i;
          ba = h[hoffset - 1];
          aa = h[hoffset];
          c_ix = (i << 2) + i;
          h12 = h[c_ix - 1];
          htmp1 = h[c_ix];
        }

        tst = ((fabs(ba) + fabs(h12)) + fabs(aa)) + fabs(htmp1);
        if (tst == 0.0) {
          ba = 0.0;
          htmp1 = 0.0;
          ab = 0.0;
          aa = 0.0;
        } else {
          ba /= tst;
          htmp1 /= tst;
          ab = (ba + htmp1) / 2.0;
          ba = (ba - ab) * (htmp1 - ab) - h12 / tst * (aa / tst);
          aa = sqrt(fabs(ba));
          if (ba >= 0.0) {
            ba = ab * tst;
            ab = ba;
            htmp1 = aa * tst;
            aa = -htmp1;
          } else {
            ba = ab + aa;
            ab -= aa;
            if (fabs(ba - htmp1) <= fabs(ab - htmp1)) {
              ba *= tst;
              ab = ba;
            } else {
              ab *= tst;
              ba = ab;
            }

            htmp1 = 0.0;
            aa = 0.0;
          }
        }

        m = i - 1;
        exitg3 = false;
        while ((!exitg3) && (m >= k + 1)) {
          c_ix = ((m - 1) << 2) + m;
          h12 = h[c_ix];
          tst_tmp_tmp = h[c_ix - 1];
          tst_tmp = tst_tmp_tmp - ab;
          tst = (fabs(tst_tmp) + fabs(aa)) + fabs(h12);
          h12 /= tst;
          c_ix = (m << 2) + m;
          v[0] = (tst_tmp / tst * (tst_tmp_tmp - ba) + h[c_ix - 1] * h12) - aa /
            tst * htmp1;
          tst_tmp = h[c_ix];
          v[1] = (((tst_tmp_tmp + tst_tmp) - ba) - ab) * h12;
          v[2] = h[c_ix + 1] * h12;
          tst = (fabs(v[0]) + fabs(v[1])) + fabs(v[2]);
          v[0] /= tst;
          v[1] /= tst;
          v[2] /= tst;
          if ((k + 1 == m) || (fabs(h[m - 1]) * (fabs(v[1]) + fabs(v[2])) <=
                               ((fabs(tst_tmp_tmp) + fabs(h[0])) + fabs(tst_tmp))
                               * (2.2204460492503131E-16 * fabs(v[0])))) {
            exitg3 = true;
          } else {
            m--;
          }
        }

        for (c_ix = m; c_ix <= i; c_ix++) {
          int32_T nr;
          nr = (i - c_ix) + 2;
          if (nr >= 3) {
            nr = 3;
          }

          if (c_ix > m) {
            hoffset = (((c_ix - 2) << 2) + c_ix) - 1;
            for (j = 0; j < nr; j++) {
              v[j] = h[j + hoffset];
            }
          }

          htmp1 = v[0];
          tst = Simulink_Simulation_xzlarfg(nr, &htmp1, v);
          v[0] = htmp1;
          if (c_ix > m) {
            h[(c_ix + ((c_ix - 2) << 2)) - 1] = htmp1;
            h[c_ix + ((c_ix - 2) << 2)] = 0.0;
            if (c_ix < i) {
              h[c_ix + 1] = 0.0;
            }
          } else if (m > k + 1) {
            h[c_ix - 1] *= 1.0 - tst;
          }

          htmp1 = v[1];
          ab = tst * v[1];
          if (nr == 3) {
            int32_T ba_tmp;
            int32_T ba_tmp_0;
            aa = v[2];
            h12 = tst * v[2];
            for (j = c_ix; j < 5; j++) {
              hoffset = ((j - 1) << 2) + c_ix;
              ba_tmp = (((j - 1) << 2) + c_ix) - 1;
              ba = (h[hoffset] * htmp1 + h[ba_tmp]) + h[hoffset + 1] * aa;
              h[ba_tmp] -= ba * tst;
              h[hoffset] -= ba * ab;
              h[hoffset + 1] -= ba * h12;
            }

            if (c_ix + 3 <= i + 1) {
              nr = c_ix + 3;
            } else {
              nr = i + 1;
            }

            for (j = 0; j < nr; j++) {
              hoffset = ((c_ix - 1) << 2) + j;
              ba_tmp = (c_ix << 2) + j;
              ba_tmp_0 = ((c_ix + 1) << 2) + j;
              ba = (h[ba_tmp] * htmp1 + h[hoffset]) + h[ba_tmp_0] * aa;
              h[hoffset] -= ba * tst;
              h[ba_tmp] -= ba * ab;
              h[ba_tmp_0] -= ba * h12;
            }

            for (j = 0; j < 4; j++) {
              hoffset = ((c_ix - 1) << 2) + j;
              ba_tmp = (c_ix << 2) + j;
              ba_tmp_0 = ((c_ix + 1) << 2) + j;
              ba = (z[ba_tmp] * htmp1 + z[hoffset]) + z[ba_tmp_0] * aa;
              z[hoffset] -= ba * tst;
              z[ba_tmp] -= ba * ab;
              z[ba_tmp_0] -= ba * h12;
            }
          } else if (nr == 2) {
            int32_T ba_tmp;
            for (j = c_ix; j < 5; j++) {
              hoffset = ((j - 1) << 2) + c_ix;
              aa = h[hoffset - 1];
              ba = h[hoffset] * htmp1 + aa;
              h[hoffset - 1] = aa - ba * tst;
              h[hoffset] -= ba * ab;
            }

            for (j = 0; j <= i; j++) {
              hoffset = ((c_ix - 1) << 2) + j;
              ba_tmp = (c_ix << 2) + j;
              ba = h[ba_tmp] * htmp1 + h[hoffset];
              h[hoffset] -= ba * tst;
              h[ba_tmp] -= ba * ab;
            }

            for (j = 0; j < 4; j++) {
              hoffset = ((c_ix - 1) << 2) + j;
              aa = z[hoffset];
              ba_tmp = (c_ix << 2) + j;
              ba = z[ba_tmp] * htmp1 + aa;
              z[hoffset] = aa - ba * tst;
              z[ba_tmp] -= ba * ab;
            }
          }
        }

        iy++;
      }
    }

    if (!goto150) {
      info = i + 1;
      exitg1 = true;
    } else {
      if ((i + 1 != L) && (L == i)) {
        kdefl = i << 2;
        iy = kdefl + i;
        ab = h[iy - 1];
        m = (i - 1) << 2;
        hoffset = m + i;
        ba = h[hoffset];
        aa = h[iy];
        Simulink_Simulation_xdlanv2(&h[(i + ((i - 1) << 2)) - 1], &ab, &ba, &aa,
          &h12, &tst_tmp_tmp, &tst_tmp, &a__4, &tst, &htmp1);
        h[iy - 1] = ab;
        h[hoffset] = ba;
        h[iy] = aa;
        if (i + 1 < 4) {
          hoffset = ((i + 1) << 2) + i;
          k = 3 - i;
          for (c_ix = 0; c_ix < k; c_ix++) {
            j = (c_ix << 2) + hoffset;
            ab = h[j];
            ba = h[j - 1];
            h[j] = ab * tst - ba * htmp1;
            h[j - 1] = ba * tst + ab * htmp1;
          }
        }

        if (i - 1 >= 1) {
          k = (uint8_T)(i - 1);
          for (c_ix = 0; c_ix < k; c_ix++) {
            iy = kdefl + c_ix;
            j = m + c_ix;
            ab = h[j] * tst + h[iy] * htmp1;
            h[iy] = h[iy] * tst - h[j] * htmp1;
            h[j] = ab;
          }
        }

        ab = tst * z[m] + htmp1 * z[kdefl];
        z[kdefl] = tst * z[kdefl] - htmp1 * z[m];
        z[m] = ab;
        ab = z[kdefl + 1];
        ba = z[m + 1];
        z[kdefl + 1] = ab * tst - ba * htmp1;
        z[m + 1] = ba * tst + ab * htmp1;
        ab = z[kdefl + 2];
        ba = z[m + 2];
        z[kdefl + 2] = ab * tst - ba * htmp1;
        z[m + 2] = ba * tst + ab * htmp1;
        ab = z[kdefl + 3];
        ba = z[m + 3];
        z[kdefl + 3] = ab * tst - ba * htmp1;
        z[m + 3] = ba * tst + ab * htmp1;
      }

      kdefl = 0;
      i = L - 2;
    }
  }

  h[3] = 0.0;
  return info;
}

/* Function for MATLAB Function: '<S2>/Reference Generator' */
static void Simulink_Simulation_schur(const real_T A[16], real_T V[16], real_T
  T[16])
{
  real_T work[4];
  real_T tau[3];
  real_T A_0;
  int32_T b_ix;
  int32_T c_ia;
  int32_T im1n;
  int32_T in;
  int32_T itau;
  int32_T jy;
  int32_T knt;
  int32_T l;
  int32_T lastc;
  int32_T rowleft;
  int32_T vectorUB;
  boolean_T p;
  p = true;
  for (itau = 0; itau < 16; itau++) {
    A_0 = A[itau];
    if (p && ((!rtIsInf(A_0)) && (!rtIsNaN(A_0)))) {
    } else {
      p = false;
    }
  }

  if (!p) {
    for (lastc = 0; lastc < 16; lastc++) {
      V[lastc] = (rtNaN);
    }

    itau = 2;
    for (im1n = 0; im1n < 3; im1n++) {
      if (itau <= 4) {
        memset(&V[((im1n << 2) + itau) + -1], 0, (uint32_T)(-itau + 5) * sizeof
               (real_T));
      }

      itau++;
    }

    for (lastc = 0; lastc < 16; lastc++) {
      T[lastc] = (rtNaN);
    }
  } else {
    __m128d tmp_0;
    int32_T alpha1_tmp;
    memcpy(&T[0], &A[0], sizeof(real_T) << 4U);
    work[0] = 0.0;
    work[1] = 0.0;
    work[2] = 0.0;
    work[3] = 0.0;
    for (itau = 0; itau < 3; itau++) {
      real_T beta1;
      im1n = itau << 2;
      in = (itau + 1) << 2;
      alpha1_tmp = (im1n + itau) + 1;
      A_0 = T[alpha1_tmp];
      if (itau + 3 <= 4) {
        lastc = itau + 3;
      } else {
        lastc = 4;
      }

      lastc += im1n;
      tau[itau] = 0.0;
      beta1 = Simulink_Simulation_xnrm2(2 - itau, T, lastc);
      if (beta1 != 0.0) {
        beta1 = rt_hypotd_snf(A_0, beta1);
        if (A_0 >= 0.0) {
          beta1 = -beta1;
        }

        if (fabs(beta1) < 1.0020841800044864E-292) {
          knt = 0;
          do {
            knt++;
            jy = (lastc - itau) + 1;
            b_ix = ((((jy - lastc) + 1) / 2) << 1) + lastc;
            vectorUB = b_ix - 2;
            for (rowleft = lastc; rowleft <= vectorUB; rowleft += 2) {
              tmp_0 = _mm_loadu_pd(&T[rowleft - 1]);
              _mm_storeu_pd(&T[rowleft - 1], _mm_mul_pd(tmp_0, _mm_set1_pd
                (9.9792015476736E+291)));
            }

            for (rowleft = b_ix; rowleft <= jy; rowleft++) {
              T[rowleft - 1] *= 9.9792015476736E+291;
            }

            beta1 *= 9.9792015476736E+291;
            A_0 *= 9.9792015476736E+291;
          } while ((fabs(beta1) < 1.0020841800044864E-292) && (knt < 20));

          beta1 = rt_hypotd_snf(A_0, Simulink_Simulation_xnrm2(2 - itau, T,
            lastc));
          if (A_0 >= 0.0) {
            beta1 = -beta1;
          }

          tau[itau] = (beta1 - A_0) / beta1;
          A_0 = 1.0 / (A_0 - beta1);
          jy = (lastc - itau) + 1;
          b_ix = ((((jy - lastc) + 1) / 2) << 1) + lastc;
          vectorUB = b_ix - 2;
          for (rowleft = lastc; rowleft <= vectorUB; rowleft += 2) {
            tmp_0 = _mm_loadu_pd(&T[rowleft - 1]);
            _mm_storeu_pd(&T[rowleft - 1], _mm_mul_pd(tmp_0, _mm_set1_pd(A_0)));
          }

          for (rowleft = b_ix; rowleft <= jy; rowleft++) {
            T[rowleft - 1] *= A_0;
          }

          for (lastc = 0; lastc < knt; lastc++) {
            beta1 *= 1.0020841800044864E-292;
          }

          A_0 = beta1;
        } else {
          tau[itau] = (beta1 - A_0) / beta1;
          A_0 = 1.0 / (A_0 - beta1);
          knt = (lastc - itau) + 1;
          b_ix = ((((knt - lastc) + 1) / 2) << 1) + lastc;
          vectorUB = b_ix - 2;
          for (jy = lastc; jy <= vectorUB; jy += 2) {
            tmp_0 = _mm_loadu_pd(&T[jy - 1]);
            _mm_storeu_pd(&T[jy - 1], _mm_mul_pd(tmp_0, _mm_set1_pd(A_0)));
          }

          for (jy = b_ix; jy <= knt; jy++) {
            T[jy - 1] *= A_0;
          }

          A_0 = beta1;
        }
      }

      T[alpha1_tmp] = 1.0;
      jy = (itau + im1n) + 1;
      if (tau[itau] != 0.0) {
        boolean_T exitg2;
        knt = 2 - itau;
        lastc = (jy - itau) + 2;
        while ((knt + 1 > 0) && (T[lastc] == 0.0)) {
          knt--;
          lastc--;
        }

        lastc = 4;
        exitg2 = false;
        while ((!exitg2) && (lastc > 0)) {
          int32_T exitg1;
          rowleft = in + lastc;
          c_ia = rowleft;
          do {
            exitg1 = 0;
            if (c_ia <= (knt << 2) + rowleft) {
              if (T[c_ia - 1] != 0.0) {
                exitg1 = 1;
              } else {
                c_ia += 4;
              }
            } else {
              lastc--;
              exitg1 = 2;
            }
          } while (exitg1 == 0);

          if (exitg1 == 1) {
            exitg2 = true;
          }
        }
      } else {
        knt = -1;
        lastc = 0;
      }

      if (knt + 1 > 0) {
        int32_T work_tmp;
        if (lastc != 0) {
          memset(&work[0], 0, (uint32_T)lastc * sizeof(real_T));
          rowleft = jy;
          c_ia = ((knt << 2) + in) + 1;
          for (b_ix = in + 1; b_ix <= c_ia; b_ix += 4) {
            l = b_ix + lastc;
            for (vectorUB = b_ix; vectorUB < l; vectorUB++) {
              work_tmp = vectorUB - b_ix;
              work[work_tmp] += T[vectorUB - 1] * T[rowleft];
            }

            rowleft++;
          }
        }

        if (!(-tau[itau] == 0.0)) {
          rowleft = in;
          for (c_ia = 0; c_ia <= knt; c_ia++) {
            if (T[jy] != 0.0) {
              beta1 = T[jy] * -tau[itau];
              work_tmp = lastc + rowleft;
              b_ix = ((((work_tmp - rowleft) / 2) << 1) + rowleft) + 1;
              vectorUB = b_ix - 2;
              for (l = rowleft + 1; l <= vectorUB; l += 2) {
                __m128d tmp;
                tmp_0 = _mm_loadu_pd(&work[(l - rowleft) - 1]);
                tmp = _mm_loadu_pd(&T[l - 1]);
                _mm_storeu_pd(&T[l - 1], _mm_add_pd(_mm_mul_pd(tmp_0,
                  _mm_set1_pd(beta1)), tmp));
              }

              for (l = b_ix; l <= work_tmp; l++) {
                T[l - 1] += work[(l - rowleft) - 1] * beta1;
              }
            }

            jy++;
            rowleft += 4;
          }
        }
      }

      Simulink_Simulation_xzlarf(3 - itau, 3 - itau, (itau + im1n) + 2, tau[itau],
        T, (itau + in) + 2, work);
      T[alpha1_tmp] = A_0;
    }

    memcpy(&V[0], &T[0], sizeof(real_T) << 4U);
    for (itau = 2; itau >= 0; itau--) {
      im1n = (itau + 1) << 2;
      for (in = 0; in <= itau; in++) {
        V[im1n + in] = 0.0;
      }

      for (in = itau + 3; in < 5; in++) {
        alpha1_tmp = im1n + in;
        V[alpha1_tmp - 1] = V[alpha1_tmp - 5];
      }
    }

    V[1] = 0.0;
    V[2] = 0.0;
    V[3] = 0.0;
    V[0] = 1.0;
    work[0] = 0.0;
    work[1] = 0.0;
    work[2] = 0.0;
    work[3] = 0.0;
    for (im1n = 2; im1n >= 0; im1n--) {
      in = ((im1n << 2) + im1n) + 5;
      if (im1n + 1 < 3) {
        V[in] = 1.0;
        Simulink_Simulation_xzlarf(3 - im1n, 2 - im1n, in + 1, tau[im1n], V, in
          + 5, work);
        lastc = (in - im1n) + 3;
        b_ix = (((((lastc - in) - 1) / 2) << 1) + in) + 2;
        vectorUB = b_ix - 2;
        for (knt = in + 2; knt <= vectorUB; knt += 2) {
          tmp_0 = _mm_loadu_pd(&V[knt - 1]);
          _mm_storeu_pd(&V[knt - 1], _mm_mul_pd(tmp_0, _mm_set1_pd(-tau[im1n])));
        }

        for (knt = b_ix; knt <= lastc; knt++) {
          V[knt - 1] *= -tau[im1n];
        }
      }

      V[in] = 1.0 - tau[im1n];
      for (knt = 0; knt < im1n; knt++) {
        V[(in - knt) - 1] = 0.0;
      }
    }

    Simulink_Simulation_xhseqr(T, V);
  }
}

/* Function for MATLAB Function: '<S2>/Reference Generator' */
static real_T Simulink_Simulation_xnrm2_fx(int32_T n, const real_T x[12],
  int32_T ix0)
{
  real_T y;
  int32_T k;
  y = 0.0;
  if (n == 1) {
    y = fabs(x[ix0 - 1]);
  } else {
    real_T scale;
    int32_T kend;
    scale = 3.3121686421112381E-170;
    kend = (ix0 + n) - 1;
    for (k = ix0; k <= kend; k++) {
      real_T absxk;
      absxk = fabs(x[k - 1]);
      if (absxk > scale) {
        real_T t;
        t = scale / absxk;
        y = y * t * t + 1.0;
        scale = absxk;
      } else {
        real_T t;
        t = absxk / scale;
        y += t * t;
      }
    }

    y = scale * sqrt(y);
  }

  return y;
}

/* Function for MATLAB Function: '<S2>/Reference Generator' */
static void Simulink_Simulation_mldivide(const real_T A[12], const real_T B[4],
  real_T Y[3])
{
  __m128d tmp_0;
  real_T b_A[12];
  real_T b_B[4];
  real_T tau[3];
  real_T vn1[3];
  real_T vn2[3];
  real_T work[3];
  real_T absxk;
  real_T scale;
  real_T smax;
  int32_T b_ix;
  int32_T ia;
  int32_T ii;
  int32_T ix;
  int32_T jy;
  int32_T pvt;
  int32_T rankA;
  int32_T scalarLB;
  int32_T vectorUB;
  int8_T jpvt[3];
  memcpy(&b_A[0], &A[0], 12U * sizeof(real_T));
  b_B[0] = B[0];
  b_B[1] = B[1];
  b_B[2] = B[2];
  b_B[3] = B[3];
  for (rankA = 0; rankA < 3; rankA++) {
    jpvt[rankA] = (int8_T)(rankA + 1);
    tau[rankA] = 0.0;
    work[rankA] = 0.0;
    ii = (rankA << 2) + 1;
    smax = 0.0;
    scale = 3.3121686421112381E-170;
    for (pvt = ii; pvt <= ii + 3; pvt++) {
      absxk = fabs(A[pvt - 1]);
      if (absxk > scale) {
        real_T t;
        t = scale / absxk;
        smax = smax * t * t + 1.0;
        scale = absxk;
      } else {
        real_T t;
        t = absxk / scale;
        smax += t * t;
      }
    }

    smax = scale * sqrt(smax);
    vn2[rankA] = smax;
    vn1[rankA] = smax;
  }

  for (rankA = 0; rankA < 3; rankA++) {
    ii = (rankA << 2) + rankA;
    pvt = 3 - rankA;
    b_ix = 0;
    if (3 - rankA > 1) {
      ix = rankA;
      smax = fabs(vn1[rankA]);
      for (jy = 2; jy <= pvt; jy++) {
        ix++;
        scale = fabs(vn1[ix]);
        if (scale > smax) {
          b_ix = jy - 1;
          smax = scale;
        }
      }
    }

    pvt = rankA + b_ix;
    if (pvt != rankA) {
      b_ix = pvt << 2;
      ix = rankA << 2;
      smax = b_A[b_ix];
      b_A[b_ix] = b_A[ix];
      b_A[ix] = smax;
      smax = b_A[b_ix + 1];
      b_A[b_ix + 1] = b_A[ix + 1];
      b_A[ix + 1] = smax;
      smax = b_A[b_ix + 2];
      b_A[b_ix + 2] = b_A[ix + 2];
      b_A[ix + 2] = smax;
      smax = b_A[b_ix + 3];
      b_A[b_ix + 3] = b_A[ix + 3];
      b_A[ix + 3] = smax;
      b_ix = jpvt[pvt];
      jpvt[pvt] = jpvt[rankA];
      jpvt[rankA] = (int8_T)b_ix;
      vn1[pvt] = vn1[rankA];
      vn2[pvt] = vn2[rankA];
    }

    scale = b_A[ii];
    pvt = ii + 2;
    tau[rankA] = 0.0;
    smax = Simulink_Simulation_xnrm2_fx(3 - rankA, b_A, ii + 2);
    if (smax != 0.0) {
      smax = rt_hypotd_snf(b_A[ii], smax);
      if (b_A[ii] >= 0.0) {
        smax = -smax;
      }

      if (fabs(smax) < 1.0020841800044864E-292) {
        b_ix = 0;
        do {
          b_ix++;
          ix = (ii - rankA) + 4;
          scalarLB = (((((ix - ii) - 1) / 2) << 1) + ii) + 2;
          vectorUB = scalarLB - 2;
          for (jy = pvt; jy <= vectorUB; jy += 2) {
            tmp_0 = _mm_loadu_pd(&b_A[jy - 1]);
            _mm_storeu_pd(&b_A[jy - 1], _mm_mul_pd(tmp_0, _mm_set1_pd
              (9.9792015476736E+291)));
          }

          for (jy = scalarLB; jy <= ix; jy++) {
            b_A[jy - 1] *= 9.9792015476736E+291;
          }

          smax *= 9.9792015476736E+291;
          scale *= 9.9792015476736E+291;
        } while ((fabs(smax) < 1.0020841800044864E-292) && (b_ix < 20));

        smax = rt_hypotd_snf(scale, Simulink_Simulation_xnrm2_fx(3 - rankA, b_A,
          ii + 2));
        if (scale >= 0.0) {
          smax = -smax;
        }

        tau[rankA] = (smax - scale) / smax;
        scale = 1.0 / (scale - smax);
        scalarLB = (((((ix - ii) - 1) / 2) << 1) + ii) + 2;
        vectorUB = scalarLB - 2;
        for (jy = pvt; jy <= vectorUB; jy += 2) {
          tmp_0 = _mm_loadu_pd(&b_A[jy - 1]);
          _mm_storeu_pd(&b_A[jy - 1], _mm_mul_pd(tmp_0, _mm_set1_pd(scale)));
        }

        for (jy = scalarLB; jy <= ix; jy++) {
          b_A[jy - 1] *= scale;
        }

        for (pvt = 0; pvt < b_ix; pvt++) {
          smax *= 1.0020841800044864E-292;
        }

        scale = smax;
      } else {
        tau[rankA] = (smax - b_A[ii]) / smax;
        scale = 1.0 / (b_A[ii] - smax);
        b_ix = (ii - rankA) + 4;
        scalarLB = (((((b_ix - ii) - 1) / 2) << 1) + ii) + 2;
        vectorUB = scalarLB - 2;
        for (ix = pvt; ix <= vectorUB; ix += 2) {
          tmp_0 = _mm_loadu_pd(&b_A[ix - 1]);
          _mm_storeu_pd(&b_A[ix - 1], _mm_mul_pd(tmp_0, _mm_set1_pd(scale)));
        }

        for (ix = scalarLB; ix <= b_ix; ix++) {
          b_A[ix - 1] *= scale;
        }

        scale = smax;
      }
    }

    b_A[ii] = scale;
    if (rankA + 1 < 3) {
      smax = b_A[ii];
      b_A[ii] = 1.0;
      if (tau[rankA] != 0.0) {
        boolean_T exitg2;
        pvt = 4 - rankA;
        b_ix = (ii - rankA) + 3;
        while ((pvt > 0) && (b_A[b_ix] == 0.0)) {
          pvt--;
          b_ix--;
        }

        b_ix = 1 - rankA;
        exitg2 = false;
        while ((!exitg2) && (b_ix + 1 > 0)) {
          int32_T exitg1;
          ix = ((b_ix << 2) + ii) + 4;
          jy = ix;
          do {
            exitg1 = 0;
            if (jy + 1 <= ix + pvt) {
              if (b_A[jy] != 0.0) {
                exitg1 = 1;
              } else {
                jy++;
              }
            } else {
              b_ix--;
              exitg1 = 2;
            }
          } while (exitg1 == 0);

          if (exitg1 == 1) {
            exitg2 = true;
          }
        }
      } else {
        pvt = 0;
        b_ix = -1;
      }

      if (pvt > 0) {
        if (b_ix + 1 != 0) {
          memset(&work[0], 0, (uint32_T)(b_ix + 1) * sizeof(real_T));
          ix = 0;
          jy = ((b_ix << 2) + ii) + 5;
          for (scalarLB = ii + 5; scalarLB <= jy; scalarLB += 4) {
            scale = 0.0;
            vectorUB = scalarLB + pvt;
            for (ia = scalarLB; ia < vectorUB; ia++) {
              scale += b_A[(ii + ia) - scalarLB] * b_A[ia - 1];
            }

            work[ix] += scale;
            ix++;
          }
        }

        if (!(-tau[rankA] == 0.0)) {
          ix = ii + 4;
          for (scalarLB = 0; scalarLB <= b_ix; scalarLB++) {
            scale = work[scalarLB];
            if (scale != 0.0) {
              scale *= -tau[rankA];
              vectorUB = pvt + ix;
              for (ia = ix + 1; ia <= vectorUB; ia++) {
                b_A[ia - 1] += b_A[((ii + ia) - ix) - 1] * scale;
              }
            }

            ix += 4;
          }
        }
      }

      b_A[ii] = smax;
    }

    for (ii = rankA + 2; ii < 4; ii++) {
      pvt = ((ii - 1) << 2) + rankA;
      absxk = vn1[ii - 1];
      if (absxk != 0.0) {
        smax = fabs(b_A[pvt]) / absxk;
        smax = 1.0 - smax * smax;
        if (smax < 0.0) {
          smax = 0.0;
        }

        scale = absxk / vn2[ii - 1];
        scale = scale * scale * smax;
        if (scale <= 1.4901161193847656E-8) {
          vn1[ii - 1] = Simulink_Simulation_xnrm2_fx(3 - rankA, b_A, pvt + 2);
          vn2[ii - 1] = vn1[ii - 1];
        } else {
          vn1[ii - 1] = absxk * sqrt(smax);
        }
      }
    }
  }

  rankA = 0;
  smax = 8.8817841970012523E-15 * fabs(b_A[0]);
  while ((rankA < 3) && (!(fabs(b_A[(rankA << 2) + rankA]) <= smax))) {
    rankA++;
  }

  for (ii = 0; ii < 3; ii++) {
    scale = tau[ii];
    Y[ii] = 0.0;
    if (scale != 0.0) {
      smax = b_B[ii];
      for (pvt = ii + 2; pvt < 5; pvt++) {
        smax += b_A[((ii << 2) + pvt) - 1] * b_B[pvt - 1];
      }

      smax *= scale;
      if (smax != 0.0) {
        b_B[ii] -= smax;
        scalarLB = ((((3 - ii) / 2) << 1) + ii) + 2;
        vectorUB = scalarLB - 2;
        for (pvt = ii + 2; pvt <= vectorUB; pvt += 2) {
          __m128d tmp;
          tmp_0 = _mm_loadu_pd(&b_A[((ii << 2) + pvt) - 1]);
          tmp = _mm_loadu_pd(&b_B[pvt - 1]);
          _mm_storeu_pd(&b_B[pvt - 1], _mm_sub_pd(tmp, _mm_mul_pd(tmp_0,
            _mm_set1_pd(smax))));
        }

        for (pvt = scalarLB; pvt < 5; pvt++) {
          b_B[pvt - 1] -= b_A[((ii << 2) + pvt) - 1] * smax;
        }
      }
    }
  }

  for (pvt = 0; pvt < rankA; pvt++) {
    Y[jpvt[pvt] - 1] = b_B[pvt];
  }

  for (ii = rankA; ii >= 1; ii--) {
    pvt = jpvt[ii - 1] - 1;
    jy = (ii - 1) << 2;
    Y[pvt] /= b_A[(jy + ii) - 1];
    for (b_ix = 0; b_ix <= ii - 2; b_ix++) {
      ix = jpvt[b_ix] - 1;
      Y[ix] -= b_A[jy + b_ix] * Y[pvt];
    }
  }
}

/* Model step function */
void Simulink_Simulation_step(void)
{
  /* local block i/o variables */
  real_T rtb_FilterCoefficient;
  real_T rtb_FilterCoefficient_a;
  real_T rtb_FilterCoefficient_d;
  real_T rtb_IntegralGain;
  real_T rtb_IntegralGain_g;
  real_T rtb_IntegralGain_p;
  real_T rtb_IntegralGain_h;
  if (rtmIsMajorTimeStep(Simulink_Simulation_M)) {
    /* set solver stop time */
    if (!(Simulink_Simulation_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&Simulink_Simulation_M->solverInfo,
                            ((Simulink_Simulation_M->Timing.clockTickH0 + 1) *
        Simulink_Simulation_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&Simulink_Simulation_M->solverInfo,
                            ((Simulink_Simulation_M->Timing.clockTick0 + 1) *
        Simulink_Simulation_M->Timing.stepSize0 +
        Simulink_Simulation_M->Timing.clockTickH0 *
        Simulink_Simulation_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(Simulink_Simulation_M)) {
    Simulink_Simulation_M->Timing.t[0] = rtsiGetT
      (&Simulink_Simulation_M->solverInfo);
  }

  {
    NeslSimulationData *simulationData;
    NeuDiagnosticManager *diagnosticManager;
    NeuDiagnosticTree *diagnosticTree;
    NeuDiagnosticTree *diagnosticTree_0;
    NeuDiagnosticTree *diagnosticTree_1;
    creal_T V[16];
    creal_T x[4];
    creal_T y[4];
    real_T tmp_3[45];
    real_T tmp_5[45];
    real_T tmp_0[32];
    real_T A[16];
    real_T T[16];
    real_T U[16];
    real_T M[12];
    real_T a[9];
    real_T b[9];
    real_T b_0[9];
    real_T rtb_Sum_0[9];
    real_T rtb_Delay2[4];
    real_T rtb_Delay2_1[4];
    real_T vec_z_World[3];
    real_T Tx_L;
    real_T Tx_R;
    real_T Tz_L;
    real_T Tz_R;
    real_T delta;
    real_T q_curr_idx_1;
    real_T q_curr_idx_2;
    real_T rtb_Delay;
    real_T rtb_Delay1;
    real_T rtb_Delay2_g;
    real_T rtb_Delay3;
    real_T rtb_Filter_k;
    real_T rtb_Integrator_j;
    real_T rtb_Sqrt;
    real_T rtb_Sum;
    real_T rtb_Sum1;
    real_T rtb_omega1_PID;
    real_T time;
    real_T time_0;
    real_T time_1;
    real_T time_2;
    real_T time_3;
    real_T time_4;
    int32_T d_i;
    int32_T rtb_Delay2_tmp;
    int_T tmp_4[10];
    int_T tmp_6[10];
    int_T tmp_1[9];
    int8_T tmp_7[16];
    boolean_T c_p;
    boolean_T tmp;
    boolean_T tmp_2;
    static const int8_T a_0[3] = { 0, 0, 1 };

    static const int8_T e[9] = { 1, 0, 0, 0, 1, 0, 0, 0, 1 };

    if (rtmIsMajorTimeStep(Simulink_Simulation_M) &&
        Simulink_Simulation_M->Timing.TaskCounters.TID[1] == 0) {
      /* Delay: '<S1>/Delay2' */
      rtb_Delay2[0] = Simulink_Simulation_DW.Delay2_DSTATE[0];
      rtb_Delay2[1] = Simulink_Simulation_DW.Delay2_DSTATE[1];
      rtb_Delay2[2] = Simulink_Simulation_DW.Delay2_DSTATE[2];
      rtb_Delay2[3] = Simulink_Simulation_DW.Delay2_DSTATE[3];
    }

    if (rtmIsMajorTimeStep(Simulink_Simulation_M) &&
        Simulink_Simulation_M->Timing.TaskCounters.TID[2] == 0) {
      /* Delay: '<Root>/Delay2' */
      rtb_Delay2_g = Simulink_Simulation_DW.Delay2_DSTATE_k;

      /* Delay: '<Root>/Delay3' */
      rtb_Delay3 = Simulink_Simulation_DW.Delay3_DSTATE;

      /* Delay: '<Root>/Delay' */
      rtb_Filter_k = Simulink_Simulation_DW.Delay_DSTATE;

      /* Delay: '<Root>/Delay1' */
      rtb_Integrator_j = Simulink_Simulation_DW.Delay1_DSTATE;
    }

    if (rtmIsMajorTimeStep(Simulink_Simulation_M) &&
        Simulink_Simulation_M->Timing.TaskCounters.TID[1] == 0) {
      /* Delay: '<S1>/Delay1' */
      rtb_Delay1 = Simulink_Simulation_DW.Delay1_DSTATE_j;

      /* Delay: '<S1>/Delay' */
      rtb_Delay = Simulink_Simulation_DW.Delay_DSTATE_c;
    }

    if (rtmIsMajorTimeStep(Simulink_Simulation_M) &&
        Simulink_Simulation_M->Timing.TaskCounters.TID[2] == 0) {
      real_T Tx_ctrl_tmp;

      /* Sum: '<S1>/Sum' incorporates:
       *  Constant: '<S1>/setpoint 1'
       */
      rtb_Sum = rtb_Integrator_j + Simulink_Simulation_P.setpoint1_Value;

      /* Sum: '<S1>/Sum1' incorporates:
       *  Constant: '<S1>/setpoint 2'
       */
      rtb_Sum1 = rtb_Filter_k + Simulink_Simulation_P.setpoint2_Value;

      /* MATLAB Function: '<S11>/MATLAB Function' */
      q_curr_idx_1 = rtb_Delay3 * rtb_Delay3;
      Tx_R = cos((rtb_Sum - 1600.0) * 0.0025) * (q_curr_idx_1 * 3.3E-8);
      rtb_Sum = sin((rtb_Sum - 1600.0) * 0.008);
      Tz_R = q_curr_idx_1 * -9.0E-9 * rtb_Sum;
      q_curr_idx_2 = rtb_Delay2_g * rtb_Delay2_g;
      Tx_L = cos((rtb_Sum1 - 1600.0) * 0.0025) * (q_curr_idx_2 * 3.3E-8);
      rtb_Sum1 = sin((rtb_Sum1 - 1600.0) * 0.008);
      Tz_L = q_curr_idx_2 * -9.0E-9 * rtb_Sum1;
      Tx_ctrl_tmp = Tx_R + Tx_L;
      Simulink_Simulation_B.Tx_ctrl = Tx_ctrl_tmp;
      Simulink_Simulation_B.Ty_ctrl = 0.0;
      Simulink_Simulation_B.Tz_ctrl = Tz_R - Tz_L;
      Simulink_Simulation_B.Mx_ctrl = (Tz_R + Tz_L) * 0.0725;
      Simulink_Simulation_B.My_ctrl = (((q_curr_idx_1 * -1.5E-9 * rtb_Sum -
        q_curr_idx_2 * -1.5E-9 * rtb_Sum1) + Tz_R * -0.049999999999999996) -
        Tz_L * -0.049999999999999996) - Tx_ctrl_tmp * 0.005;
      Simulink_Simulation_B.Mz_ctrl = (Tx_L - Tx_R) * 0.0725;

      /* Gain: '<S1>/Gain' */
      Simulink_Simulation_B.Gain = Simulink_Simulation_P.Gain_Gain *
        rtb_Integrator_j;

      /* Sum: '<S1>/Sum2' incorporates:
       *  Constant: '<S1>/Constant'
       *  Gain: '<S1>/Gain1'
       */
      Simulink_Simulation_B.Sum2 = Simulink_Simulation_P.Gain1_Gain *
        rtb_Filter_k + Simulink_Simulation_P.Constant_Value;
    }

    /* SimscapeInputBlock: '<S17>/INPUT_1_1_1' */
    Simulink_Simulation_B.INPUT_1_1_1[0] = Simulink_Simulation_B.Gain;
    Simulink_Simulation_B.INPUT_1_1_1[1] = 0.0;
    Simulink_Simulation_B.INPUT_1_1_1[2] = 0.0;
    if (rtmIsMajorTimeStep(Simulink_Simulation_M)) {
      Simulink_Simulation_DW.INPUT_1_1_1_Discrete[0] =
        !(Simulink_Simulation_B.INPUT_1_1_1[0] ==
          Simulink_Simulation_DW.INPUT_1_1_1_Discrete[1]);
      Simulink_Simulation_DW.INPUT_1_1_1_Discrete[1] =
        Simulink_Simulation_B.INPUT_1_1_1[0];
    }

    Simulink_Simulation_B.INPUT_1_1_1[0] =
      Simulink_Simulation_DW.INPUT_1_1_1_Discrete[1];
    Simulink_Simulation_B.INPUT_1_1_1[3] =
      Simulink_Simulation_DW.INPUT_1_1_1_Discrete[0];

    /* End of SimscapeInputBlock: '<S17>/INPUT_1_1_1' */

    /* SimscapeInputBlock: '<S17>/INPUT_2_1_1' */
    Simulink_Simulation_B.INPUT_2_1_1[0] = Simulink_Simulation_B.Sum2;
    Simulink_Simulation_B.INPUT_2_1_1[1] = 0.0;
    Simulink_Simulation_B.INPUT_2_1_1[2] = 0.0;
    if (rtmIsMajorTimeStep(Simulink_Simulation_M)) {
      Simulink_Simulation_DW.INPUT_2_1_1_Discrete[0] =
        !(Simulink_Simulation_B.INPUT_2_1_1[0] ==
          Simulink_Simulation_DW.INPUT_2_1_1_Discrete[1]);
      Simulink_Simulation_DW.INPUT_2_1_1_Discrete[1] =
        Simulink_Simulation_B.INPUT_2_1_1[0];
    }

    Simulink_Simulation_B.INPUT_2_1_1[0] =
      Simulink_Simulation_DW.INPUT_2_1_1_Discrete[1];
    Simulink_Simulation_B.INPUT_2_1_1[3] =
      Simulink_Simulation_DW.INPUT_2_1_1_Discrete[0];

    /* End of SimscapeInputBlock: '<S17>/INPUT_2_1_1' */

    /* SimscapeInputBlock: '<S17>/INPUT_4_1_1' */
    Simulink_Simulation_B.INPUT_4_1_1[0] = Simulink_Simulation_B.Tx_ctrl;
    Simulink_Simulation_B.INPUT_4_1_1[1] = 0.0;
    Simulink_Simulation_B.INPUT_4_1_1[2] = 0.0;
    if (rtmIsMajorTimeStep(Simulink_Simulation_M)) {
      Simulink_Simulation_DW.INPUT_4_1_1_Discrete[0] =
        !(Simulink_Simulation_B.INPUT_4_1_1[0] ==
          Simulink_Simulation_DW.INPUT_4_1_1_Discrete[1]);
      Simulink_Simulation_DW.INPUT_4_1_1_Discrete[1] =
        Simulink_Simulation_B.INPUT_4_1_1[0];
    }

    Simulink_Simulation_B.INPUT_4_1_1[0] =
      Simulink_Simulation_DW.INPUT_4_1_1_Discrete[1];
    Simulink_Simulation_B.INPUT_4_1_1[3] =
      Simulink_Simulation_DW.INPUT_4_1_1_Discrete[0];

    /* End of SimscapeInputBlock: '<S17>/INPUT_4_1_1' */

    /* SimscapeInputBlock: '<S17>/INPUT_5_1_1' */
    Simulink_Simulation_B.INPUT_5_1_1[0] = Simulink_Simulation_B.Ty_ctrl;
    Simulink_Simulation_B.INPUT_5_1_1[1] = 0.0;
    Simulink_Simulation_B.INPUT_5_1_1[2] = 0.0;
    if (rtmIsMajorTimeStep(Simulink_Simulation_M)) {
      Simulink_Simulation_DW.INPUT_5_1_1_Discrete[0] =
        !(Simulink_Simulation_B.INPUT_5_1_1[0] ==
          Simulink_Simulation_DW.INPUT_5_1_1_Discrete[1]);
      Simulink_Simulation_DW.INPUT_5_1_1_Discrete[1] =
        Simulink_Simulation_B.INPUT_5_1_1[0];
    }

    Simulink_Simulation_B.INPUT_5_1_1[0] =
      Simulink_Simulation_DW.INPUT_5_1_1_Discrete[1];
    Simulink_Simulation_B.INPUT_5_1_1[3] =
      Simulink_Simulation_DW.INPUT_5_1_1_Discrete[0];

    /* End of SimscapeInputBlock: '<S17>/INPUT_5_1_1' */

    /* SimscapeInputBlock: '<S17>/INPUT_6_1_1' */
    Simulink_Simulation_B.INPUT_6_1_1[0] = Simulink_Simulation_B.Tz_ctrl;
    Simulink_Simulation_B.INPUT_6_1_1[1] = 0.0;
    Simulink_Simulation_B.INPUT_6_1_1[2] = 0.0;
    if (rtmIsMajorTimeStep(Simulink_Simulation_M)) {
      Simulink_Simulation_DW.INPUT_6_1_1_Discrete[0] =
        !(Simulink_Simulation_B.INPUT_6_1_1[0] ==
          Simulink_Simulation_DW.INPUT_6_1_1_Discrete[1]);
      Simulink_Simulation_DW.INPUT_6_1_1_Discrete[1] =
        Simulink_Simulation_B.INPUT_6_1_1[0];
    }

    Simulink_Simulation_B.INPUT_6_1_1[0] =
      Simulink_Simulation_DW.INPUT_6_1_1_Discrete[1];
    Simulink_Simulation_B.INPUT_6_1_1[3] =
      Simulink_Simulation_DW.INPUT_6_1_1_Discrete[0];

    /* End of SimscapeInputBlock: '<S17>/INPUT_6_1_1' */

    /* SimscapeInputBlock: '<S17>/INPUT_7_1_1' */
    Simulink_Simulation_B.INPUT_7_1_1[0] = Simulink_Simulation_B.Mx_ctrl;
    Simulink_Simulation_B.INPUT_7_1_1[1] = 0.0;
    Simulink_Simulation_B.INPUT_7_1_1[2] = 0.0;
    if (rtmIsMajorTimeStep(Simulink_Simulation_M)) {
      Simulink_Simulation_DW.INPUT_7_1_1_Discrete[0] =
        !(Simulink_Simulation_B.INPUT_7_1_1[0] ==
          Simulink_Simulation_DW.INPUT_7_1_1_Discrete[1]);
      Simulink_Simulation_DW.INPUT_7_1_1_Discrete[1] =
        Simulink_Simulation_B.INPUT_7_1_1[0];
    }

    Simulink_Simulation_B.INPUT_7_1_1[0] =
      Simulink_Simulation_DW.INPUT_7_1_1_Discrete[1];
    Simulink_Simulation_B.INPUT_7_1_1[3] =
      Simulink_Simulation_DW.INPUT_7_1_1_Discrete[0];

    /* End of SimscapeInputBlock: '<S17>/INPUT_7_1_1' */

    /* SimscapeInputBlock: '<S17>/INPUT_8_1_1' */
    Simulink_Simulation_B.INPUT_8_1_1[0] = Simulink_Simulation_B.My_ctrl;
    Simulink_Simulation_B.INPUT_8_1_1[1] = 0.0;
    Simulink_Simulation_B.INPUT_8_1_1[2] = 0.0;
    if (rtmIsMajorTimeStep(Simulink_Simulation_M)) {
      Simulink_Simulation_DW.INPUT_8_1_1_Discrete[0] =
        !(Simulink_Simulation_B.INPUT_8_1_1[0] ==
          Simulink_Simulation_DW.INPUT_8_1_1_Discrete[1]);
      Simulink_Simulation_DW.INPUT_8_1_1_Discrete[1] =
        Simulink_Simulation_B.INPUT_8_1_1[0];
    }

    Simulink_Simulation_B.INPUT_8_1_1[0] =
      Simulink_Simulation_DW.INPUT_8_1_1_Discrete[1];
    Simulink_Simulation_B.INPUT_8_1_1[3] =
      Simulink_Simulation_DW.INPUT_8_1_1_Discrete[0];

    /* End of SimscapeInputBlock: '<S17>/INPUT_8_1_1' */

    /* SimscapeInputBlock: '<S17>/INPUT_3_1_1' */
    Simulink_Simulation_B.INPUT_3_1_1[0] = Simulink_Simulation_B.Mz_ctrl;
    Simulink_Simulation_B.INPUT_3_1_1[1] = 0.0;
    Simulink_Simulation_B.INPUT_3_1_1[2] = 0.0;
    if (rtmIsMajorTimeStep(Simulink_Simulation_M)) {
      Simulink_Simulation_DW.INPUT_3_1_1_Discrete[0] =
        !(Simulink_Simulation_B.INPUT_3_1_1[0] ==
          Simulink_Simulation_DW.INPUT_3_1_1_Discrete[1]);
      Simulink_Simulation_DW.INPUT_3_1_1_Discrete[1] =
        Simulink_Simulation_B.INPUT_3_1_1[0];
    }

    Simulink_Simulation_B.INPUT_3_1_1[0] =
      Simulink_Simulation_DW.INPUT_3_1_1_Discrete[1];
    Simulink_Simulation_B.INPUT_3_1_1[3] =
      Simulink_Simulation_DW.INPUT_3_1_1_Discrete[0];

    /* End of SimscapeInputBlock: '<S17>/INPUT_3_1_1' */

    /* SimscapeExecutionBlock: '<S17>/STATE_1' incorporates:
     *  SimscapeExecutionBlock: '<S17>/OUTPUT_1_0'
     *  SimscapeExecutionBlock: '<S17>/OUTPUT_1_1'
     */
    simulationData = (NeslSimulationData *)
      Simulink_Simulation_DW.STATE_1_SimData;
    rtb_Filter_k = Simulink_Simulation_M->Timing.t[0];
    time = rtb_Filter_k;
    simulationData->mData->mTime.mN = 1;
    simulationData->mData->mTime.mX = &time;
    simulationData->mData->mContStates.mN = 13;
    simulationData->mData->mContStates.mX =
      &Simulink_Simulation_X.Simulink_SimulationAircraft_Dyn[0];
    simulationData->mData->mDiscStates.mN = 0;
    simulationData->mData->mDiscStates.mX =
      &Simulink_Simulation_DW.STATE_1_Discrete;
    simulationData->mData->mModeVector.mN = 0;
    simulationData->mData->mModeVector.mX =
      &Simulink_Simulation_DW.STATE_1_Modes;
    c_p = false;
    simulationData->mData->mFoundZcEvents = c_p;
    c_p = rtmIsMajorTimeStep(Simulink_Simulation_M);
    simulationData->mData->mIsMajorTimeStep = c_p;
    tmp = false;
    simulationData->mData->mIsSolverAssertCheck = tmp;
    simulationData->mData->mIsSolverCheckingCIC = false;
    tmp = rtsiIsSolverComputingJacobian(&Simulink_Simulation_M->solverInfo);
    simulationData->mData->mIsComputingJacobian = tmp;
    simulationData->mData->mIsEvaluatingF0 = false;
    simulationData->mData->mIsSolverRequestingReset = false;
    tmp = rtsiIsModeUpdateTimeStep(&Simulink_Simulation_M->solverInfo);
    simulationData->mData->mIsModeUpdateTimeStep = tmp;
    tmp_1[0] = 0;
    tmp_0[0] = Simulink_Simulation_B.INPUT_1_1_1[0];
    tmp_0[1] = Simulink_Simulation_B.INPUT_1_1_1[1];
    tmp_0[2] = Simulink_Simulation_B.INPUT_1_1_1[2];
    tmp_0[3] = Simulink_Simulation_B.INPUT_1_1_1[3];
    tmp_1[1] = 4;
    tmp_0[4] = Simulink_Simulation_B.INPUT_2_1_1[0];
    tmp_0[5] = Simulink_Simulation_B.INPUT_2_1_1[1];
    tmp_0[6] = Simulink_Simulation_B.INPUT_2_1_1[2];
    tmp_0[7] = Simulink_Simulation_B.INPUT_2_1_1[3];
    tmp_1[2] = 8;
    tmp_0[8] = Simulink_Simulation_B.INPUT_4_1_1[0];
    tmp_0[9] = Simulink_Simulation_B.INPUT_4_1_1[1];
    tmp_0[10] = Simulink_Simulation_B.INPUT_4_1_1[2];
    tmp_0[11] = Simulink_Simulation_B.INPUT_4_1_1[3];
    tmp_1[3] = 12;
    tmp_0[12] = Simulink_Simulation_B.INPUT_5_1_1[0];
    tmp_0[13] = Simulink_Simulation_B.INPUT_5_1_1[1];
    tmp_0[14] = Simulink_Simulation_B.INPUT_5_1_1[2];
    tmp_0[15] = Simulink_Simulation_B.INPUT_5_1_1[3];
    tmp_1[4] = 16;
    tmp_0[16] = Simulink_Simulation_B.INPUT_6_1_1[0];
    tmp_0[17] = Simulink_Simulation_B.INPUT_6_1_1[1];
    tmp_0[18] = Simulink_Simulation_B.INPUT_6_1_1[2];
    tmp_0[19] = Simulink_Simulation_B.INPUT_6_1_1[3];
    tmp_1[5] = 20;
    tmp_0[20] = Simulink_Simulation_B.INPUT_7_1_1[0];
    tmp_0[21] = Simulink_Simulation_B.INPUT_7_1_1[1];
    tmp_0[22] = Simulink_Simulation_B.INPUT_7_1_1[2];
    tmp_0[23] = Simulink_Simulation_B.INPUT_7_1_1[3];
    tmp_1[6] = 24;
    tmp_0[24] = Simulink_Simulation_B.INPUT_8_1_1[0];
    tmp_0[25] = Simulink_Simulation_B.INPUT_8_1_1[1];
    tmp_0[26] = Simulink_Simulation_B.INPUT_8_1_1[2];
    tmp_0[27] = Simulink_Simulation_B.INPUT_8_1_1[3];
    tmp_1[7] = 28;
    tmp_0[28] = Simulink_Simulation_B.INPUT_3_1_1[0];
    tmp_0[29] = Simulink_Simulation_B.INPUT_3_1_1[1];
    tmp_0[30] = Simulink_Simulation_B.INPUT_3_1_1[2];
    tmp_0[31] = Simulink_Simulation_B.INPUT_3_1_1[3];
    tmp_1[8] = 32;
    simulationData->mData->mInputValues.mN = 32;
    simulationData->mData->mInputValues.mX = &tmp_0[0];
    simulationData->mData->mInputOffsets.mN = 9;
    simulationData->mData->mInputOffsets.mX = &tmp_1[0];
    simulationData->mData->mOutputs.mN = 13;
    simulationData->mData->mOutputs.mX = &Simulink_Simulation_B.STATE_1[0];
    simulationData->mData->mTolerances.mN = 0;
    simulationData->mData->mTolerances.mX = NULL;
    simulationData->mData->mCstateHasChanged = false;
    rtb_Integrator_j = Simulink_Simulation_M->Timing.t[0];
    time_0 = rtb_Integrator_j;
    simulationData->mData->mTime.mN = 1;
    simulationData->mData->mTime.mX = &time_0;
    simulationData->mData->mSampleHits.mN = 0;
    simulationData->mData->mSampleHits.mX = NULL;
    simulationData->mData->mIsFundamentalSampleHit = false;
    diagnosticManager = (NeuDiagnosticManager *)
      Simulink_Simulation_DW.STATE_1_DiagMgr;
    diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
    d_i = ne_simulator_method((NeslSimulator *)
      Simulink_Simulation_DW.STATE_1_Simulator, NESL_SIM_OUTPUTS, simulationData,
      diagnosticManager);
    if (d_i != 0) {
      tmp_2 = error_buffer_is_empty(rtmGetErrorStatus(Simulink_Simulation_M));
      if (tmp_2) {
        char *msg;
        msg = rtw_diagnostics_msg(diagnosticTree);
        rtmSetErrorStatus(Simulink_Simulation_M, msg);
      }
    }

    /* End of SimscapeExecutionBlock: '<S17>/STATE_1' */

    /* SimscapeExecutionBlock: '<S17>/OUTPUT_1_0' */
    simulationData = (NeslSimulationData *)
      Simulink_Simulation_DW.OUTPUT_1_0_SimData;
    time_1 = rtb_Filter_k;
    simulationData->mData->mTime.mN = 1;
    simulationData->mData->mTime.mX = &time_1;
    simulationData->mData->mContStates.mN = 0;
    simulationData->mData->mContStates.mX = NULL;
    simulationData->mData->mDiscStates.mN = 0;
    simulationData->mData->mDiscStates.mX =
      &Simulink_Simulation_DW.OUTPUT_1_0_Discrete;
    simulationData->mData->mModeVector.mN = 0;
    simulationData->mData->mModeVector.mX =
      &Simulink_Simulation_DW.OUTPUT_1_0_Modes;
    tmp_2 = false;
    simulationData->mData->mFoundZcEvents = tmp_2;
    simulationData->mData->mIsMajorTimeStep = c_p;
    tmp_2 = false;
    simulationData->mData->mIsSolverAssertCheck = tmp_2;
    simulationData->mData->mIsSolverCheckingCIC = false;
    simulationData->mData->mIsComputingJacobian = false;
    simulationData->mData->mIsEvaluatingF0 = false;
    simulationData->mData->mIsSolverRequestingReset = false;
    simulationData->mData->mIsModeUpdateTimeStep = tmp;
    tmp_4[0] = 0;
    tmp_3[0] = Simulink_Simulation_B.INPUT_1_1_1[0];
    tmp_3[1] = Simulink_Simulation_B.INPUT_1_1_1[1];
    tmp_3[2] = Simulink_Simulation_B.INPUT_1_1_1[2];
    tmp_3[3] = Simulink_Simulation_B.INPUT_1_1_1[3];
    tmp_4[1] = 4;
    tmp_3[4] = Simulink_Simulation_B.INPUT_2_1_1[0];
    tmp_3[5] = Simulink_Simulation_B.INPUT_2_1_1[1];
    tmp_3[6] = Simulink_Simulation_B.INPUT_2_1_1[2];
    tmp_3[7] = Simulink_Simulation_B.INPUT_2_1_1[3];
    tmp_4[2] = 8;
    tmp_3[8] = Simulink_Simulation_B.INPUT_4_1_1[0];
    tmp_3[9] = Simulink_Simulation_B.INPUT_4_1_1[1];
    tmp_3[10] = Simulink_Simulation_B.INPUT_4_1_1[2];
    tmp_3[11] = Simulink_Simulation_B.INPUT_4_1_1[3];
    tmp_4[3] = 12;
    tmp_3[12] = Simulink_Simulation_B.INPUT_5_1_1[0];
    tmp_3[13] = Simulink_Simulation_B.INPUT_5_1_1[1];
    tmp_3[14] = Simulink_Simulation_B.INPUT_5_1_1[2];
    tmp_3[15] = Simulink_Simulation_B.INPUT_5_1_1[3];
    tmp_4[4] = 16;
    tmp_3[16] = Simulink_Simulation_B.INPUT_6_1_1[0];
    tmp_3[17] = Simulink_Simulation_B.INPUT_6_1_1[1];
    tmp_3[18] = Simulink_Simulation_B.INPUT_6_1_1[2];
    tmp_3[19] = Simulink_Simulation_B.INPUT_6_1_1[3];
    tmp_4[5] = 20;
    tmp_3[20] = Simulink_Simulation_B.INPUT_7_1_1[0];
    tmp_3[21] = Simulink_Simulation_B.INPUT_7_1_1[1];
    tmp_3[22] = Simulink_Simulation_B.INPUT_7_1_1[2];
    tmp_3[23] = Simulink_Simulation_B.INPUT_7_1_1[3];
    tmp_4[6] = 24;
    tmp_3[24] = Simulink_Simulation_B.INPUT_8_1_1[0];
    tmp_3[25] = Simulink_Simulation_B.INPUT_8_1_1[1];
    tmp_3[26] = Simulink_Simulation_B.INPUT_8_1_1[2];
    tmp_3[27] = Simulink_Simulation_B.INPUT_8_1_1[3];
    tmp_4[7] = 28;
    tmp_3[28] = Simulink_Simulation_B.INPUT_3_1_1[0];
    tmp_3[29] = Simulink_Simulation_B.INPUT_3_1_1[1];
    tmp_3[30] = Simulink_Simulation_B.INPUT_3_1_1[2];
    tmp_3[31] = Simulink_Simulation_B.INPUT_3_1_1[3];
    tmp_4[8] = 32;
    memcpy(&tmp_3[32], &Simulink_Simulation_B.STATE_1[0], 13U * sizeof(real_T));
    tmp_4[9] = 45;
    simulationData->mData->mInputValues.mN = 45;
    simulationData->mData->mInputValues.mX = &tmp_3[0];
    simulationData->mData->mInputOffsets.mN = 10;
    simulationData->mData->mInputOffsets.mX = &tmp_4[0];
    simulationData->mData->mOutputs.mN = 5;
    simulationData->mData->mOutputs.mX = &Simulink_Simulation_B.OUTPUT_1_0[0];
    simulationData->mData->mTolerances.mN = 0;
    simulationData->mData->mTolerances.mX = NULL;
    simulationData->mData->mCstateHasChanged = false;
    time_2 = rtb_Integrator_j;
    simulationData->mData->mTime.mN = 1;
    simulationData->mData->mTime.mX = &time_2;
    simulationData->mData->mSampleHits.mN = 0;
    simulationData->mData->mSampleHits.mX = NULL;
    simulationData->mData->mIsFundamentalSampleHit = false;
    diagnosticManager = (NeuDiagnosticManager *)
      Simulink_Simulation_DW.OUTPUT_1_0_DiagMgr;
    diagnosticTree_0 = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
    d_i = ne_simulator_method((NeslSimulator *)
      Simulink_Simulation_DW.OUTPUT_1_0_Simulator, NESL_SIM_OUTPUTS,
      simulationData, diagnosticManager);
    if (d_i != 0) {
      tmp_2 = error_buffer_is_empty(rtmGetErrorStatus(Simulink_Simulation_M));
      if (tmp_2) {
        char *msg_0;
        msg_0 = rtw_diagnostics_msg(diagnosticTree_0);
        rtmSetErrorStatus(Simulink_Simulation_M, msg_0);
      }
    }

    /* SimscapeExecutionBlock: '<S17>/OUTPUT_1_1' */
    simulationData = (NeslSimulationData *)
      Simulink_Simulation_DW.OUTPUT_1_1_SimData;
    time_3 = rtb_Filter_k;
    simulationData->mData->mTime.mN = 1;
    simulationData->mData->mTime.mX = &time_3;
    simulationData->mData->mContStates.mN = 0;
    simulationData->mData->mContStates.mX = NULL;
    simulationData->mData->mDiscStates.mN = 0;
    simulationData->mData->mDiscStates.mX =
      &Simulink_Simulation_DW.OUTPUT_1_1_Discrete;
    simulationData->mData->mModeVector.mN = 0;
    simulationData->mData->mModeVector.mX =
      &Simulink_Simulation_DW.OUTPUT_1_1_Modes;
    tmp_2 = false;
    simulationData->mData->mFoundZcEvents = tmp_2;
    simulationData->mData->mIsMajorTimeStep = c_p;
    c_p = false;
    simulationData->mData->mIsSolverAssertCheck = c_p;
    simulationData->mData->mIsSolverCheckingCIC = false;
    simulationData->mData->mIsComputingJacobian = false;
    simulationData->mData->mIsEvaluatingF0 = false;
    simulationData->mData->mIsSolverRequestingReset = false;
    simulationData->mData->mIsModeUpdateTimeStep = tmp;
    tmp_6[0] = 0;
    tmp_5[0] = Simulink_Simulation_B.INPUT_1_1_1[0];
    tmp_5[1] = Simulink_Simulation_B.INPUT_1_1_1[1];
    tmp_5[2] = Simulink_Simulation_B.INPUT_1_1_1[2];
    tmp_5[3] = Simulink_Simulation_B.INPUT_1_1_1[3];
    tmp_6[1] = 4;
    tmp_5[4] = Simulink_Simulation_B.INPUT_2_1_1[0];
    tmp_5[5] = Simulink_Simulation_B.INPUT_2_1_1[1];
    tmp_5[6] = Simulink_Simulation_B.INPUT_2_1_1[2];
    tmp_5[7] = Simulink_Simulation_B.INPUT_2_1_1[3];
    tmp_6[2] = 8;
    tmp_5[8] = Simulink_Simulation_B.INPUT_4_1_1[0];
    tmp_5[9] = Simulink_Simulation_B.INPUT_4_1_1[1];
    tmp_5[10] = Simulink_Simulation_B.INPUT_4_1_1[2];
    tmp_5[11] = Simulink_Simulation_B.INPUT_4_1_1[3];
    tmp_6[3] = 12;
    tmp_5[12] = Simulink_Simulation_B.INPUT_5_1_1[0];
    tmp_5[13] = Simulink_Simulation_B.INPUT_5_1_1[1];
    tmp_5[14] = Simulink_Simulation_B.INPUT_5_1_1[2];
    tmp_5[15] = Simulink_Simulation_B.INPUT_5_1_1[3];
    tmp_6[4] = 16;
    tmp_5[16] = Simulink_Simulation_B.INPUT_6_1_1[0];
    tmp_5[17] = Simulink_Simulation_B.INPUT_6_1_1[1];
    tmp_5[18] = Simulink_Simulation_B.INPUT_6_1_1[2];
    tmp_5[19] = Simulink_Simulation_B.INPUT_6_1_1[3];
    tmp_6[5] = 20;
    tmp_5[20] = Simulink_Simulation_B.INPUT_7_1_1[0];
    tmp_5[21] = Simulink_Simulation_B.INPUT_7_1_1[1];
    tmp_5[22] = Simulink_Simulation_B.INPUT_7_1_1[2];
    tmp_5[23] = Simulink_Simulation_B.INPUT_7_1_1[3];
    tmp_6[6] = 24;
    tmp_5[24] = Simulink_Simulation_B.INPUT_8_1_1[0];
    tmp_5[25] = Simulink_Simulation_B.INPUT_8_1_1[1];
    tmp_5[26] = Simulink_Simulation_B.INPUT_8_1_1[2];
    tmp_5[27] = Simulink_Simulation_B.INPUT_8_1_1[3];
    tmp_6[7] = 28;
    tmp_5[28] = Simulink_Simulation_B.INPUT_3_1_1[0];
    tmp_5[29] = Simulink_Simulation_B.INPUT_3_1_1[1];
    tmp_5[30] = Simulink_Simulation_B.INPUT_3_1_1[2];
    tmp_5[31] = Simulink_Simulation_B.INPUT_3_1_1[3];
    tmp_6[8] = 32;
    memcpy(&tmp_5[32], &Simulink_Simulation_B.STATE_1[0], 13U * sizeof(real_T));
    tmp_6[9] = 45;
    simulationData->mData->mInputValues.mN = 45;
    simulationData->mData->mInputValues.mX = &tmp_5[0];
    simulationData->mData->mInputOffsets.mN = 10;
    simulationData->mData->mInputOffsets.mX = &tmp_6[0];
    simulationData->mData->mOutputs.mN = 1;

    /* SimscapeExecutionBlock: '<S17>/OUTPUT_1_1' */
    simulationData->mData->mOutputs.mX = &Simulink_Simulation_B.OUTPUT_1_1;

    /* SimscapeExecutionBlock: '<S17>/OUTPUT_1_1' */
    simulationData->mData->mTolerances.mN = 0;
    simulationData->mData->mTolerances.mX = NULL;
    simulationData->mData->mCstateHasChanged = false;
    time_4 = rtb_Integrator_j;
    simulationData->mData->mTime.mN = 1;
    simulationData->mData->mTime.mX = &time_4;
    simulationData->mData->mSampleHits.mN = 0;
    simulationData->mData->mSampleHits.mX = NULL;
    simulationData->mData->mIsFundamentalSampleHit = false;
    diagnosticManager = (NeuDiagnosticManager *)
      Simulink_Simulation_DW.OUTPUT_1_1_DiagMgr;
    diagnosticTree_1 = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
    d_i = ne_simulator_method((NeslSimulator *)
      Simulink_Simulation_DW.OUTPUT_1_1_Simulator, NESL_SIM_OUTPUTS,
      simulationData, diagnosticManager);
    if (d_i != 0) {
      c_p = error_buffer_is_empty(rtmGetErrorStatus(Simulink_Simulation_M));
      if (c_p) {
        char *msg_1;
        msg_1 = rtw_diagnostics_msg(diagnosticTree_1);
        rtmSetErrorStatus(Simulink_Simulation_M, msg_1);
      }
    }

    if (rtmIsMajorTimeStep(Simulink_Simulation_M) &&
        Simulink_Simulation_M->Timing.TaskCounters.TID[1] == 0) {
      __m128d tmp_8;
      __m128d tmp_9;
      int32_T c_j;
      int32_T sgn;
      boolean_T exitg2;

      /* MATLAB Function: '<S2>/Reference Generator' incorporates:
       *  Constant: '<Root>/Constant1'
       *  Constant: '<Root>/Constant3'
       */
      rtb_Sum1 = rtb_Delay2[0];
      q_curr_idx_1 = rtb_Delay2[1];
      q_curr_idx_2 = rtb_Delay2[2];
      Tz_L = rtb_Delay2[3];
      rtb_Filter_k = (rtb_Delay2[1] * rtb_Delay2[2] - rtb_Delay2[0] *
                      rtb_Delay2[3]) * 2.0;
      rtb_Integrator_j = 1.0 - (rtb_Delay2[1] * rtb_Delay2[1] + rtb_Delay2[3] *
        rtb_Delay2[3]) * 2.0;
      rtb_Sum = (rtb_Delay2[2] * rtb_Delay2[3] + rtb_Delay2[0] * rtb_Delay2[1]) *
        2.0;
      vec_z_World[0] = 0.0 * rtb_Sum - rtb_Integrator_j;
      vec_z_World[1] = rtb_Filter_k - 0.0 * rtb_Sum;
      vec_z_World[2] = 0.0 * rtb_Integrator_j - 0.0 * rtb_Filter_k;
      rtb_Filter_k = sin(-Simulink_Simulation_P.Constant1_Value);
      rtb_Integrator_j = cos(-Simulink_Simulation_P.Constant1_Value);
      Tx_R = sin(Simulink_Simulation_P.Constant3_Value);
      rtb_Sum = cos(Simulink_Simulation_P.Constant3_Value);
      b[1] = 0.0;
      b[4] = rtb_Integrator_j;
      b[7] = -rtb_Filter_k;
      b[2] = 0.0;
      b[5] = rtb_Filter_k;
      b[8] = rtb_Integrator_j;
      rtb_Sum_0[0] = rtb_Sum;
      rtb_Sum_0[3] = 0.0;
      rtb_Sum_0[6] = Tx_R;
      b[0] = 1.0;
      rtb_Sum_0[1] = 0.0;
      b[3] = 0.0;
      rtb_Sum_0[4] = 1.0;
      b[6] = 0.0;
      rtb_Sum_0[7] = 0.0;
      rtb_Sum_0[2] = -Tx_R;
      rtb_Sum_0[5] = 0.0;
      rtb_Sum_0[8] = rtb_Sum;
      a[3] = vec_z_World[1] - vec_z_World[2] * 0.0;
      a[4] = vec_z_World[2] * 0.0 - vec_z_World[0];
      a[5] = vec_z_World[0] * 0.0 - vec_z_World[1] * 0.0;
      for (rtb_Delay2_tmp = 0; rtb_Delay2_tmp < 3; rtb_Delay2_tmp++) {
        for (d_i = 0; d_i <= 0; d_i += 2) {
          c_j = 3 * rtb_Delay2_tmp + d_i;
          _mm_storeu_pd(&b_0[c_j], _mm_set1_pd(0.0));
          tmp_8 = _mm_loadu_pd(&b[d_i]);
          tmp_9 = _mm_loadu_pd(&b_0[c_j]);
          _mm_storeu_pd(&b_0[c_j], _mm_add_pd(tmp_9, _mm_mul_pd(_mm_set1_pd
            (rtb_Sum_0[3 * rtb_Delay2_tmp]), tmp_8)));
          tmp_8 = _mm_loadu_pd(&b[d_i + 3]);
          tmp_9 = _mm_loadu_pd(&b_0[c_j]);
          _mm_storeu_pd(&b_0[c_j], _mm_add_pd(_mm_mul_pd(_mm_set1_pd(rtb_Sum_0[3
            * rtb_Delay2_tmp + 1]), tmp_8), tmp_9));
          tmp_8 = _mm_loadu_pd(&b[d_i + 6]);
          tmp_9 = _mm_loadu_pd(&b_0[c_j]);
          _mm_storeu_pd(&b_0[c_j], _mm_add_pd(_mm_mul_pd(_mm_set1_pd(rtb_Sum_0[3
            * rtb_Delay2_tmp + 2]), tmp_8), tmp_9));
        }

        for (d_i = 2; d_i < 3; d_i++) {
          c_j = 3 * rtb_Delay2_tmp + d_i;
          b_0[c_j] = 0.0;
          b_0[c_j] += rtb_Sum_0[3 * rtb_Delay2_tmp] * b[d_i];
          b_0[c_j] += rtb_Sum_0[3 * rtb_Delay2_tmp + 1] * b[d_i + 3];
          b_0[c_j] += rtb_Sum_0[3 * rtb_Delay2_tmp + 2] * b[d_i + 6];
        }

        a[rtb_Delay2_tmp] = a_0[rtb_Delay2_tmp];
        a[rtb_Delay2_tmp + 6] = vec_z_World[rtb_Delay2_tmp];
      }

      for (rtb_Delay2_tmp = 0; rtb_Delay2_tmp < 3; rtb_Delay2_tmp++) {
        for (d_i = 0; d_i <= 0; d_i += 2) {
          c_j = 3 * rtb_Delay2_tmp + d_i;
          _mm_storeu_pd(&b[c_j], _mm_set1_pd(0.0));
          tmp_8 = _mm_loadu_pd(&b_0[d_i]);
          tmp_9 = _mm_loadu_pd(&b[c_j]);
          _mm_storeu_pd(&b[c_j], _mm_add_pd(tmp_9, _mm_mul_pd(_mm_set1_pd(a[3 *
            rtb_Delay2_tmp]), tmp_8)));
          tmp_8 = _mm_loadu_pd(&b_0[d_i + 3]);
          tmp_9 = _mm_loadu_pd(&b[c_j]);
          _mm_storeu_pd(&b[c_j], _mm_add_pd(_mm_mul_pd(_mm_set1_pd(a[3 *
            rtb_Delay2_tmp + 1]), tmp_8), tmp_9));
          tmp_8 = _mm_loadu_pd(&b_0[d_i + 6]);
          tmp_9 = _mm_loadu_pd(&b[c_j]);
          _mm_storeu_pd(&b[c_j], _mm_add_pd(_mm_mul_pd(_mm_set1_pd(a[3 *
            rtb_Delay2_tmp + 2]), tmp_8), tmp_9));
        }

        for (d_i = 2; d_i < 3; d_i++) {
          c_j = 3 * rtb_Delay2_tmp + d_i;
          b[c_j] = 0.0;
          b[c_j] += a[3 * rtb_Delay2_tmp] * b_0[d_i];
          b[c_j] += a[3 * rtb_Delay2_tmp + 1] * b_0[d_i + 3];
          b[c_j] += a[3 * rtb_Delay2_tmp + 2] * b_0[d_i + 6];
        }
      }

      rtb_Filter_k = b[1] + b[3];
      rtb_Integrator_j = b[2] + b[6];
      Tx_R = b[5] - b[7];
      rtb_Sum = b[5] + b[7];
      Tz_R = b[6] - b[2];
      Tx_L = b[1] - b[3];
      A[0] = ((b[0] - b[4]) - b[8]) / 3.0;
      A[4] = rtb_Filter_k / 3.0;
      A[8] = rtb_Integrator_j / 3.0;
      A[12] = Tx_R / 3.0;
      A[1] = rtb_Filter_k / 3.0;
      A[5] = ((b[4] - b[0]) - b[8]) / 3.0;
      A[9] = rtb_Sum / 3.0;
      A[13] = Tz_R / 3.0;
      A[2] = rtb_Integrator_j / 3.0;
      A[6] = rtb_Sum / 3.0;
      A[10] = ((b[8] - b[0]) - b[4]) / 3.0;
      A[14] = Tx_L / 3.0;
      A[3] = Tx_R / 3.0;
      A[7] = Tz_R / 3.0;
      A[11] = Tx_L / 3.0;
      A[15] = ((b[0] + b[4]) + b[8]) / 3.0;
      c_p = true;
      for (d_i = 0; d_i < 16; d_i++) {
        rtb_Filter_k = A[d_i];
        if (c_p && ((!rtIsInf(rtb_Filter_k)) && (!rtIsNaN(rtb_Filter_k)))) {
        } else {
          c_p = false;
        }
      }

      if (!c_p) {
        for (rtb_Delay2_tmp = 0; rtb_Delay2_tmp < 16; rtb_Delay2_tmp++) {
          V[rtb_Delay2_tmp].re = (rtNaN);
          V[rtb_Delay2_tmp].im = 0.0;
        }

        x[0].re = (rtNaN);
        x[1].re = (rtNaN);
        x[2].re = (rtNaN);
        x[3].re = (rtNaN);
      } else {
        int32_T exitg1;
        d_i = 0;
        exitg2 = false;
        while ((!exitg2) && (d_i < 4)) {
          c_j = 0;
          do {
            exitg1 = 0;
            if (c_j <= d_i) {
              if (!(A[(d_i << 2) + c_j] == A[(c_j << 2) + d_i])) {
                c_p = false;
                exitg1 = 1;
              } else {
                c_j++;
              }
            } else {
              d_i++;
              exitg1 = 2;
            }
          } while (exitg1 == 0);

          if (exitg1 == 1) {
            exitg2 = true;
          }
        }

        if (c_p) {
          Simulink_Simulation_schur(A, U, T);
          rtb_Delay2[0] = T[0];
          rtb_Delay2[1] = T[5];
          rtb_Delay2[2] = T[10];
          rtb_Delay2[3] = T[15];
          for (rtb_Delay2_tmp = 0; rtb_Delay2_tmp < 16; rtb_Delay2_tmp++) {
            V[rtb_Delay2_tmp].re = U[rtb_Delay2_tmp];
            V[rtb_Delay2_tmp].im = 0.0;
          }

          x[0].re = rtb_Delay2[0];
          x[1].re = rtb_Delay2[1];
          x[2].re = rtb_Delay2[2];
          x[3].re = rtb_Delay2[3];
        } else {
          c_p = true;
          d_i = 0;
          exitg2 = false;
          while ((!exitg2) && (d_i < 4)) {
            c_j = 0;
            do {
              exitg1 = 0;
              if (c_j <= d_i) {
                if (!(A[(d_i << 2) + c_j] == -A[(c_j << 2) + d_i])) {
                  c_p = false;
                  exitg1 = 1;
                } else {
                  c_j++;
                }
              } else {
                d_i++;
                exitg1 = 2;
              }
            } while (exitg1 == 0);

            if (exitg1 == 1) {
              exitg2 = true;
            }
          }

          if (c_p) {
            Simulink_Simulation_schur(A, U, T);
            d_i = 1;
            do {
              exitg1 = 0;
              if (d_i <= 4) {
                boolean_T guard1 = false;
                guard1 = false;
                if (d_i != 4) {
                  rtb_Integrator_j = T[((d_i - 1) << 2) + d_i];
                  if (rtb_Integrator_j != 0.0) {
                    rtb_Filter_k = fabs(rtb_Integrator_j);
                    x[d_i - 1].re = 0.0;
                    x[d_i - 1].im = rtb_Filter_k;
                    x[d_i].re = 0.0;
                    x[d_i].im = -rtb_Filter_k;
                    d_i += 2;
                  } else {
                    guard1 = true;
                  }
                } else {
                  guard1 = true;
                }

                if (guard1) {
                  x[d_i - 1].re = 0.0;
                  x[d_i - 1].im = 0.0;
                  d_i++;
                }
              } else {
                exitg1 = 1;
              }
            } while (exitg1 == 0);

            for (rtb_Delay2_tmp = 0; rtb_Delay2_tmp < 16; rtb_Delay2_tmp++) {
              V[rtb_Delay2_tmp].re = U[rtb_Delay2_tmp];
              V[rtb_Delay2_tmp].im = 0.0;
            }

            c_j = 1;
            do {
              exitg1 = 0;
              if (c_j <= 4) {
                if (c_j != 4) {
                  rtb_Delay2_tmp = (c_j - 1) << 2;
                  rtb_Integrator_j = T[rtb_Delay2_tmp + c_j];
                  if (rtb_Integrator_j != 0.0) {
                    if (rtb_Integrator_j < 0.0) {
                      sgn = 1;
                    } else {
                      sgn = -1;
                    }

                    rtb_Filter_k = V[rtb_Delay2_tmp].re;
                    d_i = c_j << 2;
                    rtb_Integrator_j = V[d_i].re * (real_T)sgn;
                    if (rtb_Integrator_j == 0.0) {
                      V[rtb_Delay2_tmp].re = rtb_Filter_k / 1.4142135623730951;
                      V[rtb_Delay2_tmp].im = 0.0;
                    } else if (rtb_Filter_k == 0.0) {
                      V[rtb_Delay2_tmp].re = 0.0;
                      V[rtb_Delay2_tmp].im = rtb_Integrator_j /
                        1.4142135623730951;
                    } else {
                      V[rtb_Delay2_tmp].re = rtb_Filter_k / 1.4142135623730951;
                      V[rtb_Delay2_tmp].im = rtb_Integrator_j /
                        1.4142135623730951;
                    }

                    V[d_i].re = V[rtb_Delay2_tmp].re;
                    V[d_i].im = -V[rtb_Delay2_tmp].im;
                    rtb_Filter_k = V[rtb_Delay2_tmp + 1].re;
                    rtb_Integrator_j = V[d_i + 1].re * (real_T)sgn;
                    if (rtb_Integrator_j == 0.0) {
                      V[rtb_Delay2_tmp + 1].re = rtb_Filter_k /
                        1.4142135623730951;
                      V[rtb_Delay2_tmp + 1].im = 0.0;
                    } else if (rtb_Filter_k == 0.0) {
                      V[rtb_Delay2_tmp + 1].re = 0.0;
                      V[rtb_Delay2_tmp + 1].im = rtb_Integrator_j /
                        1.4142135623730951;
                    } else {
                      V[rtb_Delay2_tmp + 1].re = rtb_Filter_k /
                        1.4142135623730951;
                      V[rtb_Delay2_tmp + 1].im = rtb_Integrator_j /
                        1.4142135623730951;
                    }

                    V[d_i + 1].re = V[rtb_Delay2_tmp + 1].re;
                    V[d_i + 1].im = -V[rtb_Delay2_tmp + 1].im;
                    rtb_Filter_k = V[rtb_Delay2_tmp + 2].re;
                    rtb_Integrator_j = V[d_i + 2].re * (real_T)sgn;
                    if (rtb_Integrator_j == 0.0) {
                      V[rtb_Delay2_tmp + 2].re = rtb_Filter_k /
                        1.4142135623730951;
                      V[rtb_Delay2_tmp + 2].im = 0.0;
                    } else if (rtb_Filter_k == 0.0) {
                      V[rtb_Delay2_tmp + 2].re = 0.0;
                      V[rtb_Delay2_tmp + 2].im = rtb_Integrator_j /
                        1.4142135623730951;
                    } else {
                      V[rtb_Delay2_tmp + 2].re = rtb_Filter_k /
                        1.4142135623730951;
                      V[rtb_Delay2_tmp + 2].im = rtb_Integrator_j /
                        1.4142135623730951;
                    }

                    V[d_i + 2].re = V[rtb_Delay2_tmp + 2].re;
                    V[d_i + 2].im = -V[rtb_Delay2_tmp + 2].im;
                    rtb_Filter_k = V[rtb_Delay2_tmp + 3].re;
                    rtb_Integrator_j = V[d_i + 3].re * (real_T)sgn;
                    if (rtb_Integrator_j == 0.0) {
                      V[rtb_Delay2_tmp + 3].re = rtb_Filter_k /
                        1.4142135623730951;
                      V[rtb_Delay2_tmp + 3].im = 0.0;
                    } else if (rtb_Filter_k == 0.0) {
                      V[rtb_Delay2_tmp + 3].re = 0.0;
                      V[rtb_Delay2_tmp + 3].im = rtb_Integrator_j /
                        1.4142135623730951;
                    } else {
                      V[rtb_Delay2_tmp + 3].re = rtb_Filter_k /
                        1.4142135623730951;
                      V[rtb_Delay2_tmp + 3].im = rtb_Integrator_j /
                        1.4142135623730951;
                    }

                    V[d_i + 3].re = V[rtb_Delay2_tmp + 3].re;
                    V[d_i + 3].im = -V[rtb_Delay2_tmp + 3].im;
                    c_j += 2;
                  } else {
                    c_j++;
                  }
                } else {
                  c_j++;
                }
              } else {
                exitg1 = 1;
              }
            } while (exitg1 == 0);
          } else {
            Simulink_Simulation_xzgeev(A, &d_i, x, y, V);
            if (y[0].im == 0.0) {
              if (x[0].im == 0.0) {
                rtb_Filter_k = x[0].re / y[0].re;
              } else if (x[0].re == 0.0) {
                rtb_Filter_k = 0.0;
              } else {
                rtb_Filter_k = x[0].re / y[0].re;
              }
            } else if (y[0].re == 0.0) {
              if (x[0].re == 0.0) {
                rtb_Filter_k = x[0].im / y[0].im;
              } else if (x[0].im == 0.0) {
                rtb_Filter_k = 0.0;
              } else {
                rtb_Filter_k = x[0].im / y[0].im;
              }
            } else {
              rtb_Filter_k = fabs(y[0].re);
              rtb_Integrator_j = fabs(y[0].im);
              if (rtb_Filter_k > rtb_Integrator_j) {
                rtb_Filter_k = y[0].im / y[0].re;
                rtb_Filter_k = (rtb_Filter_k * x[0].im + x[0].re) /
                  (rtb_Filter_k * y[0].im + y[0].re);
              } else if (rtb_Integrator_j == rtb_Filter_k) {
                rtb_Filter_k = ((y[0].re > 0.0 ? 0.5 : -0.5) * x[0].re + (y[0].
                  im > 0.0 ? 0.5 : -0.5) * x[0].im) / rtb_Filter_k;
              } else {
                rtb_Filter_k = y[0].re / y[0].im;
                rtb_Filter_k = (rtb_Filter_k * x[0].re + x[0].im) /
                  (rtb_Filter_k * y[0].re + y[0].im);
              }
            }

            x[0].re = rtb_Filter_k;
            if (y[1].im == 0.0) {
              if (x[1].im == 0.0) {
                rtb_Filter_k = x[1].re / y[1].re;
              } else if (x[1].re == 0.0) {
                rtb_Filter_k = 0.0;
              } else {
                rtb_Filter_k = x[1].re / y[1].re;
              }
            } else if (y[1].re == 0.0) {
              if (x[1].re == 0.0) {
                rtb_Filter_k = x[1].im / y[1].im;
              } else if (x[1].im == 0.0) {
                rtb_Filter_k = 0.0;
              } else {
                rtb_Filter_k = x[1].im / y[1].im;
              }
            } else {
              rtb_Filter_k = fabs(y[1].re);
              rtb_Integrator_j = fabs(y[1].im);
              if (rtb_Filter_k > rtb_Integrator_j) {
                rtb_Filter_k = y[1].im / y[1].re;
                rtb_Filter_k = (rtb_Filter_k * x[1].im + x[1].re) /
                  (rtb_Filter_k * y[1].im + y[1].re);
              } else if (rtb_Integrator_j == rtb_Filter_k) {
                rtb_Filter_k = ((y[1].re > 0.0 ? 0.5 : -0.5) * x[1].re + (y[1].
                  im > 0.0 ? 0.5 : -0.5) * x[1].im) / rtb_Filter_k;
              } else {
                rtb_Filter_k = y[1].re / y[1].im;
                rtb_Filter_k = (rtb_Filter_k * x[1].re + x[1].im) /
                  (rtb_Filter_k * y[1].re + y[1].im);
              }
            }

            x[1].re = rtb_Filter_k;
            if (y[2].im == 0.0) {
              if (x[2].im == 0.0) {
                rtb_Filter_k = x[2].re / y[2].re;
              } else if (x[2].re == 0.0) {
                rtb_Filter_k = 0.0;
              } else {
                rtb_Filter_k = x[2].re / y[2].re;
              }
            } else if (y[2].re == 0.0) {
              if (x[2].re == 0.0) {
                rtb_Filter_k = x[2].im / y[2].im;
              } else if (x[2].im == 0.0) {
                rtb_Filter_k = 0.0;
              } else {
                rtb_Filter_k = x[2].im / y[2].im;
              }
            } else {
              rtb_Filter_k = fabs(y[2].re);
              rtb_Integrator_j = fabs(y[2].im);
              if (rtb_Filter_k > rtb_Integrator_j) {
                rtb_Filter_k = y[2].im / y[2].re;
                rtb_Filter_k = (rtb_Filter_k * x[2].im + x[2].re) /
                  (rtb_Filter_k * y[2].im + y[2].re);
              } else if (rtb_Integrator_j == rtb_Filter_k) {
                rtb_Filter_k = ((y[2].re > 0.0 ? 0.5 : -0.5) * x[2].re + (y[2].
                  im > 0.0 ? 0.5 : -0.5) * x[2].im) / rtb_Filter_k;
              } else {
                rtb_Filter_k = y[2].re / y[2].im;
                rtb_Filter_k = (rtb_Filter_k * x[2].re + x[2].im) /
                  (rtb_Filter_k * y[2].re + y[2].im);
              }
            }

            x[2].re = rtb_Filter_k;
            if (y[3].im == 0.0) {
              if (x[3].im == 0.0) {
                rtb_Filter_k = x[3].re / y[3].re;
              } else if (x[3].re == 0.0) {
                rtb_Filter_k = 0.0;
              } else {
                rtb_Filter_k = x[3].re / y[3].re;
              }
            } else if (y[3].re == 0.0) {
              if (x[3].re == 0.0) {
                rtb_Filter_k = x[3].im / y[3].im;
              } else if (x[3].im == 0.0) {
                rtb_Filter_k = 0.0;
              } else {
                rtb_Filter_k = x[3].im / y[3].im;
              }
            } else {
              rtb_Filter_k = fabs(y[3].re);
              rtb_Integrator_j = fabs(y[3].im);
              if (rtb_Filter_k > rtb_Integrator_j) {
                rtb_Filter_k = y[3].im / y[3].re;
                rtb_Filter_k = (rtb_Filter_k * x[3].im + x[3].re) /
                  (rtb_Filter_k * y[3].im + y[3].re);
              } else if (rtb_Integrator_j == rtb_Filter_k) {
                rtb_Filter_k = ((y[3].re > 0.0 ? 0.5 : -0.5) * x[3].re + (y[3].
                  im > 0.0 ? 0.5 : -0.5) * x[3].im) / rtb_Filter_k;
              } else {
                rtb_Filter_k = y[3].re / y[3].im;
                rtb_Filter_k = (rtb_Filter_k * x[3].re + x[3].im) /
                  (rtb_Filter_k * y[3].re + y[3].im);
              }
            }

            x[3].re = rtb_Filter_k;
          }
        }
      }

      rtb_Delay2[0] = x[0].re;
      rtb_Delay2[1] = x[1].re;
      rtb_Delay2[2] = x[2].re;
      rtb_Delay2[3] = x[3].re;
      if (!rtIsNaN(rtb_Delay2[0])) {
        c_j = 0;
      } else {
        c_j = -1;
        d_i = 2;
        exitg2 = false;
        while ((!exitg2) && (d_i < 5)) {
          if (!rtIsNaN(rtb_Delay2[d_i - 1])) {
            c_j = d_i - 1;
            exitg2 = true;
          } else {
            d_i++;
          }
        }
      }

      if (c_j + 1 == 0) {
        sgn = 0;
      } else {
        rtb_Filter_k = rtb_Delay2[c_j];
        sgn = c_j;
        for (d_i = c_j + 2; d_i < 5; d_i++) {
          rtb_Integrator_j = rtb_Delay2[d_i - 1];
          if (rtb_Filter_k < rtb_Integrator_j) {
            rtb_Filter_k = rtb_Integrator_j;
            sgn = d_i - 1;
          }
        }
      }

      rtb_Delay2_tmp = sgn << 2;
      rtb_Delay2[0] = V[rtb_Delay2_tmp + 3].re;
      rtb_Delay2[1] = V[rtb_Delay2_tmp].re;
      rtb_Delay2[2] = V[rtb_Delay2_tmp + 1].re;
      rtb_Delay2[3] = V[rtb_Delay2_tmp + 2].re;
      if (rtb_Delay2[0] < 0.0) {
        rtb_Delay2[0] = -rtb_Delay2[0];
        rtb_Delay2[1] = -rtb_Delay2[1];
        rtb_Delay2[2] = -rtb_Delay2[2];
        rtb_Delay2[3] = -rtb_Delay2[3];
      }

      tmp_7[0] = 0;
      tmp_7[5] = 0;
      tmp_7[10] = 0;
      tmp_7[15] = 0;
      for (d_i = 0; d_i < 3; d_i++) {
        int8_T tmp_a;
        int8_T tmp_b;
        tmp_7[4] = (int8_T)-e[d_i];
        tmp_b = e[d_i + 3];
        tmp_7[8] = (int8_T)-tmp_b;
        tmp_a = e[d_i + 6];
        tmp_7[12] = (int8_T)-tmp_a;
        tmp_7[1] = e[d_i];
        tmp_7[9] = tmp_a;
        tmp_7[13] = (int8_T)-tmp_b;
        tmp_7[2] = tmp_b;
        tmp_7[6] = (int8_T)-tmp_a;
        tmp_7[14] = e[d_i];
        tmp_7[3] = tmp_a;
        tmp_7[7] = tmp_b;
        tmp_7[11] = (int8_T)-e[d_i];
        for (rtb_Delay2_tmp = 0; rtb_Delay2_tmp < 4; rtb_Delay2_tmp++) {
          c_j = (d_i << 2) + rtb_Delay2_tmp;
          M[c_j] = 0.0;
          M[c_j] += (real_T)tmp_7[rtb_Delay2_tmp] * rtb_Sum1;
          M[c_j] += (real_T)tmp_7[rtb_Delay2_tmp + 4] * q_curr_idx_1;
          M[c_j] += (real_T)tmp_7[rtb_Delay2_tmp + 8] * q_curr_idx_2;
          M[c_j] += (real_T)tmp_7[rtb_Delay2_tmp + 12] * Tz_L;
        }
      }

      rtb_Delay2_1[0] = rtb_Delay2[0] - rtb_Sum1;
      rtb_Delay2_1[1] = rtb_Delay2[1] - q_curr_idx_1;
      rtb_Delay2_1[2] = rtb_Delay2[2] - q_curr_idx_2;
      rtb_Delay2_1[3] = rtb_Delay2[3] - Tz_L;
      Simulink_Simulation_mldivide(M, rtb_Delay2_1, vec_z_World);
      Simulink_Simulation_B.q_error = 2.0 * vec_z_World[1];
      Simulink_Simulation_B.r_error = 2.0 * vec_z_World[2];

      /* Sum: '<S2>/Sum1' incorporates:
       *  Constant: '<Root>/Constant2'
       *  MATLAB Function: '<S2>/Reference Generator'
       *  Sum: '<S2>/Sum'
       */
      Simulink_Simulation_B.Sum1 = (Simulink_Simulation_P.Constant2_Value -
        rtb_Delay1) + 2.0 * vec_z_World[0];

      /* Sum: '<S3>/Sum' incorporates:
       *  Constant: '<Root>/Constant'
       */
      Simulink_Simulation_B.Sum = Simulink_Simulation_P.Constant_Value_g -
        rtb_Delay;
    }

    if (rtmIsMajorTimeStep(Simulink_Simulation_M) &&
        Simulink_Simulation_M->Timing.TaskCounters.TID[2] == 0) {
      /* DiscreteIntegrator: '<S120>/Integrator' */
      rtb_Integrator_j = Simulink_Simulation_DW.Integrator_DSTATE;

      /* DiscreteIntegrator: '<S115>/Filter' */
      rtb_Filter_k = Simulink_Simulation_DW.Filter_DSTATE;

      /* Gain: '<S123>/Filter Coefficient' incorporates:
       *  Gain: '<S114>/Derivative Gain'
       *  Sum: '<S115>/SumD'
       */
      rtb_FilterCoefficient = (Simulink_Simulation_P.PIDController_D *
        Simulink_Simulation_B.Sum1 - rtb_Filter_k) *
        Simulink_Simulation_P.PIDController_N;

      /* Sum: '<S129>/Sum' incorporates:
       *  Gain: '<S125>/Proportional Gain'
       */
      rtb_Filter_k = (Simulink_Simulation_P.PIDController_P *
                      Simulink_Simulation_B.Sum1 + rtb_Integrator_j) +
        rtb_FilterCoefficient;

      /* Gain: '<S74>/Filter Coefficient' incorporates:
       *  DiscreteIntegrator: '<S66>/Filter'
       *  Gain: '<S65>/Derivative Gain'
       *  Sum: '<S66>/SumD'
       */
      rtb_FilterCoefficient_a = (Simulink_Simulation_P.PIDController_D_j *
        Simulink_Simulation_B.q_error - Simulink_Simulation_DW.Filter_DSTATE_k) *
        Simulink_Simulation_P.PIDController_N_p;

      /* Sum: '<S80>/Sum' incorporates:
       *  DiscreteIntegrator: '<S71>/Integrator'
       *  Gain: '<S76>/Proportional Gain'
       */
      rtb_Integrator_j = (Simulink_Simulation_P.PIDController_P_o *
                          Simulink_Simulation_B.q_error +
                          Simulink_Simulation_DW.Integrator_DSTATE_f) +
        rtb_FilterCoefficient_a;

      /* Gain: '<S172>/Filter Coefficient' incorporates:
       *  DiscreteIntegrator: '<S164>/Filter'
       *  Gain: '<S163>/Derivative Gain'
       *  Sum: '<S164>/SumD'
       */
      rtb_FilterCoefficient_d = (Simulink_Simulation_P.PIDController_D_i *
        Simulink_Simulation_B.r_error - Simulink_Simulation_DW.Filter_DSTATE_l) *
        Simulink_Simulation_P.PIDController_N_g;

      /* Sum: '<S178>/Sum' incorporates:
       *  DiscreteIntegrator: '<S169>/Integrator'
       *  Gain: '<S174>/Proportional Gain'
       */
      rtb_Sum = (Simulink_Simulation_P.PIDController_P_a *
                 Simulink_Simulation_B.r_error +
                 Simulink_Simulation_DW.Integrator_DSTATE_m) +
        rtb_FilterCoefficient_d;

      /* Sum: '<S228>/Sum' incorporates:
       *  DiscreteIntegrator: '<S219>/Integrator'
       *  Gain: '<S224>/Proportional Gain'
       */
      rtb_Delay1 = Simulink_Simulation_P.PIDAcceleration_P *
        Simulink_Simulation_B.Sum + Simulink_Simulation_DW.Integrator_DSTATE_e;

      /* Sqrt: '<S3>/Sqrt' */
      rtb_Sqrt = sqrt(rtb_Delay1);

      /* MATLAB Function: '<S3>/MATLAB Function' */
      delta = (rtb_Delay3 - rtb_Delay2_g) / 2.0;
      rtb_omega1_PID = rtb_Sqrt + delta;
      delta = rtb_Sqrt - delta;

      /* MATLAB Function: '<S2>/MATLAB Function' */
      rtb_Delay2_g = rtb_omega1_PID * rtb_omega1_PID + delta * delta;
      Simulink_Simulation_B.omega_R = rtb_Delay2_g / 2.0 - rtb_Sum;
      Simulink_Simulation_B.omega_R = sqrt(Simulink_Simulation_B.omega_R);
      Simulink_Simulation_B.omega_L = rtb_Delay2_g / 2.0 + rtb_Sum;
      Simulink_Simulation_B.omega_L = sqrt(Simulink_Simulation_B.omega_L);
      Simulink_Simulation_B.servo_R = (-rtb_Filter_k - rtb_Integrator_j) +
        1570.0;
      Simulink_Simulation_B.servo_L = (-rtb_Filter_k + rtb_Integrator_j) +
        1570.0;

      /* Gain: '<S68>/Integral Gain' */
      rtb_IntegralGain = Simulink_Simulation_P.PIDController_I *
        Simulink_Simulation_B.q_error;

      /* Gain: '<S117>/Integral Gain' */
      rtb_IntegralGain_g = Simulink_Simulation_P.PIDController_I_m *
        Simulink_Simulation_B.Sum1;

      /* Gain: '<S166>/Integral Gain' */
      rtb_IntegralGain_p = Simulink_Simulation_P.PIDController_I_k *
        Simulink_Simulation_B.r_error;
    }

    if (rtmIsMajorTimeStep(Simulink_Simulation_M) &&
        Simulink_Simulation_M->Timing.TaskCounters.TID[1] == 0) {
    }

    if (rtmIsMajorTimeStep(Simulink_Simulation_M) &&
        Simulink_Simulation_M->Timing.TaskCounters.TID[2] == 0) {
      /* Gain: '<S216>/Integral Gain' */
      rtb_IntegralGain_h = Simulink_Simulation_P.PIDAcceleration_I *
        Simulink_Simulation_B.Sum;
    }
  }

  if (rtmIsMajorTimeStep(Simulink_Simulation_M)) {
    /* Matfile logging */
    rt_UpdateTXYLogVars(Simulink_Simulation_M->rtwLogInfo,
                        (Simulink_Simulation_M->Timing.t));
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(Simulink_Simulation_M)) {
    NeslSimulationData *simulationData;
    NeuDiagnosticManager *diagnosticManager;
    NeuDiagnosticTree *diagnosticTree;
    real_T tmp_0[32];
    real_T time;
    int32_T tmp_2;
    int_T tmp_1[9];
    boolean_T tmp;
    if (rtmIsMajorTimeStep(Simulink_Simulation_M) &&
        Simulink_Simulation_M->Timing.TaskCounters.TID[1] == 0) {
      /* Update for Delay: '<S1>/Delay2' */
      Simulink_Simulation_DW.Delay2_DSTATE[0] =
        Simulink_Simulation_B.OUTPUT_1_0[0];
      Simulink_Simulation_DW.Delay2_DSTATE[1] =
        Simulink_Simulation_B.OUTPUT_1_0[1];
      Simulink_Simulation_DW.Delay2_DSTATE[2] =
        Simulink_Simulation_B.OUTPUT_1_0[2];
      Simulink_Simulation_DW.Delay2_DSTATE[3] =
        Simulink_Simulation_B.OUTPUT_1_0[3];

      /* Update for Delay: '<S1>/Delay1' */
      Simulink_Simulation_DW.Delay1_DSTATE_j = Simulink_Simulation_B.OUTPUT_1_0
        [4];

      /* Update for Delay: '<S1>/Delay' */
      Simulink_Simulation_DW.Delay_DSTATE_c = Simulink_Simulation_B.OUTPUT_1_1;
    }

    if (rtmIsMajorTimeStep(Simulink_Simulation_M) &&
        Simulink_Simulation_M->Timing.TaskCounters.TID[2] == 0) {
      /* Update for Delay: '<Root>/Delay2' */
      Simulink_Simulation_DW.Delay2_DSTATE_k = Simulink_Simulation_B.servo_L;

      /* Update for Delay: '<Root>/Delay3' */
      Simulink_Simulation_DW.Delay3_DSTATE = Simulink_Simulation_B.servo_R;

      /* Update for Delay: '<Root>/Delay' */
      Simulink_Simulation_DW.Delay_DSTATE = Simulink_Simulation_B.omega_L;

      /* Update for Delay: '<Root>/Delay1' */
      Simulink_Simulation_DW.Delay1_DSTATE = Simulink_Simulation_B.omega_R;
    }

    /* Update for SimscapeExecutionBlock: '<S17>/STATE_1' */
    simulationData = (NeslSimulationData *)
      Simulink_Simulation_DW.STATE_1_SimData;
    time = Simulink_Simulation_M->Timing.t[0];
    simulationData->mData->mTime.mN = 1;
    simulationData->mData->mTime.mX = &time;
    simulationData->mData->mContStates.mN = 13;
    simulationData->mData->mContStates.mX =
      &Simulink_Simulation_X.Simulink_SimulationAircraft_Dyn[0];
    simulationData->mData->mDiscStates.mN = 0;
    simulationData->mData->mDiscStates.mX =
      &Simulink_Simulation_DW.STATE_1_Discrete;
    simulationData->mData->mModeVector.mN = 0;
    simulationData->mData->mModeVector.mX =
      &Simulink_Simulation_DW.STATE_1_Modes;
    tmp = false;
    simulationData->mData->mFoundZcEvents = tmp;
    simulationData->mData->mIsMajorTimeStep = rtmIsMajorTimeStep
      (Simulink_Simulation_M);
    tmp = false;
    simulationData->mData->mIsSolverAssertCheck = tmp;
    simulationData->mData->mIsSolverCheckingCIC = false;
    tmp = rtsiIsSolverComputingJacobian(&Simulink_Simulation_M->solverInfo);
    simulationData->mData->mIsComputingJacobian = tmp;
    simulationData->mData->mIsEvaluatingF0 = false;
    simulationData->mData->mIsSolverRequestingReset = false;
    simulationData->mData->mIsModeUpdateTimeStep = rtsiIsModeUpdateTimeStep
      (&Simulink_Simulation_M->solverInfo);
    tmp_1[0] = 0;
    tmp_0[0] = Simulink_Simulation_B.INPUT_1_1_1[0];
    tmp_0[1] = Simulink_Simulation_B.INPUT_1_1_1[1];
    tmp_0[2] = Simulink_Simulation_B.INPUT_1_1_1[2];
    tmp_0[3] = Simulink_Simulation_B.INPUT_1_1_1[3];
    tmp_1[1] = 4;
    tmp_0[4] = Simulink_Simulation_B.INPUT_2_1_1[0];
    tmp_0[5] = Simulink_Simulation_B.INPUT_2_1_1[1];
    tmp_0[6] = Simulink_Simulation_B.INPUT_2_1_1[2];
    tmp_0[7] = Simulink_Simulation_B.INPUT_2_1_1[3];
    tmp_1[2] = 8;
    tmp_0[8] = Simulink_Simulation_B.INPUT_4_1_1[0];
    tmp_0[9] = Simulink_Simulation_B.INPUT_4_1_1[1];
    tmp_0[10] = Simulink_Simulation_B.INPUT_4_1_1[2];
    tmp_0[11] = Simulink_Simulation_B.INPUT_4_1_1[3];
    tmp_1[3] = 12;
    tmp_0[12] = Simulink_Simulation_B.INPUT_5_1_1[0];
    tmp_0[13] = Simulink_Simulation_B.INPUT_5_1_1[1];
    tmp_0[14] = Simulink_Simulation_B.INPUT_5_1_1[2];
    tmp_0[15] = Simulink_Simulation_B.INPUT_5_1_1[3];
    tmp_1[4] = 16;
    tmp_0[16] = Simulink_Simulation_B.INPUT_6_1_1[0];
    tmp_0[17] = Simulink_Simulation_B.INPUT_6_1_1[1];
    tmp_0[18] = Simulink_Simulation_B.INPUT_6_1_1[2];
    tmp_0[19] = Simulink_Simulation_B.INPUT_6_1_1[3];
    tmp_1[5] = 20;
    tmp_0[20] = Simulink_Simulation_B.INPUT_7_1_1[0];
    tmp_0[21] = Simulink_Simulation_B.INPUT_7_1_1[1];
    tmp_0[22] = Simulink_Simulation_B.INPUT_7_1_1[2];
    tmp_0[23] = Simulink_Simulation_B.INPUT_7_1_1[3];
    tmp_1[6] = 24;
    tmp_0[24] = Simulink_Simulation_B.INPUT_8_1_1[0];
    tmp_0[25] = Simulink_Simulation_B.INPUT_8_1_1[1];
    tmp_0[26] = Simulink_Simulation_B.INPUT_8_1_1[2];
    tmp_0[27] = Simulink_Simulation_B.INPUT_8_1_1[3];
    tmp_1[7] = 28;
    tmp_0[28] = Simulink_Simulation_B.INPUT_3_1_1[0];
    tmp_0[29] = Simulink_Simulation_B.INPUT_3_1_1[1];
    tmp_0[30] = Simulink_Simulation_B.INPUT_3_1_1[2];
    tmp_0[31] = Simulink_Simulation_B.INPUT_3_1_1[3];
    tmp_1[8] = 32;
    simulationData->mData->mInputValues.mN = 32;
    simulationData->mData->mInputValues.mX = &tmp_0[0];
    simulationData->mData->mInputOffsets.mN = 9;
    simulationData->mData->mInputOffsets.mX = &tmp_1[0];
    diagnosticManager = (NeuDiagnosticManager *)
      Simulink_Simulation_DW.STATE_1_DiagMgr;
    diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
    tmp_2 = ne_simulator_method((NeslSimulator *)
      Simulink_Simulation_DW.STATE_1_Simulator, NESL_SIM_UPDATE, simulationData,
      diagnosticManager);
    if (tmp_2 != 0) {
      tmp = error_buffer_is_empty(rtmGetErrorStatus(Simulink_Simulation_M));
      if (tmp) {
        char *msg;
        msg = rtw_diagnostics_msg(diagnosticTree);
        rtmSetErrorStatus(Simulink_Simulation_M, msg);
      }
    }

    /* End of Update for SimscapeExecutionBlock: '<S17>/STATE_1' */
    if (rtmIsMajorTimeStep(Simulink_Simulation_M) &&
        Simulink_Simulation_M->Timing.TaskCounters.TID[2] == 0) {
      /* Update for DiscreteIntegrator: '<S120>/Integrator' */
      Simulink_Simulation_DW.Integrator_DSTATE +=
        Simulink_Simulation_P.Integrator_gainval * rtb_IntegralGain_g;

      /* Update for DiscreteIntegrator: '<S115>/Filter' */
      Simulink_Simulation_DW.Filter_DSTATE +=
        Simulink_Simulation_P.Filter_gainval * rtb_FilterCoefficient;

      /* Update for DiscreteIntegrator: '<S71>/Integrator' */
      Simulink_Simulation_DW.Integrator_DSTATE_f +=
        Simulink_Simulation_P.Integrator_gainval_j * rtb_IntegralGain;

      /* Update for DiscreteIntegrator: '<S66>/Filter' */
      Simulink_Simulation_DW.Filter_DSTATE_k +=
        Simulink_Simulation_P.Filter_gainval_j * rtb_FilterCoefficient_a;

      /* Update for DiscreteIntegrator: '<S169>/Integrator' */
      Simulink_Simulation_DW.Integrator_DSTATE_m +=
        Simulink_Simulation_P.Integrator_gainval_c * rtb_IntegralGain_p;

      /* Update for DiscreteIntegrator: '<S164>/Filter' */
      Simulink_Simulation_DW.Filter_DSTATE_l +=
        Simulink_Simulation_P.Filter_gainval_c * rtb_FilterCoefficient_d;

      /* Update for DiscreteIntegrator: '<S219>/Integrator' */
      Simulink_Simulation_DW.Integrator_DSTATE_e +=
        Simulink_Simulation_P.Integrator_gainval_h * rtb_IntegralGain_h;
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(Simulink_Simulation_M)) {
    /* signal main to stop simulation */
    {                                  /* Sample time: [0.0s, 0.0s] */
      if ((rtmGetTFinal(Simulink_Simulation_M)!=-1) &&
          !((rtmGetTFinal(Simulink_Simulation_M)-
             (((Simulink_Simulation_M->Timing.clockTick1+
                Simulink_Simulation_M->Timing.clockTickH1* 4294967296.0)) *
              0.0001)) > (((Simulink_Simulation_M->Timing.clockTick1+
                            Simulink_Simulation_M->Timing.clockTickH1*
                            4294967296.0)) * 0.0001) * (DBL_EPSILON))) {
        rtmSetErrorStatus(Simulink_Simulation_M, "Simulation finished");
      }
    }

    rt_ertODEUpdateContinuousStates(&Simulink_Simulation_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++Simulink_Simulation_M->Timing.clockTick0)) {
      ++Simulink_Simulation_M->Timing.clockTickH0;
    }

    Simulink_Simulation_M->Timing.t[0] = rtsiGetSolverStopTime
      (&Simulink_Simulation_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.0001s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.0001, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       * Timer of this task consists of two 32 bit unsigned integers.
       * The two integers represent the low bits Timing.clockTick1 and the high bits
       * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
       */
      Simulink_Simulation_M->Timing.clockTick1++;
      if (!Simulink_Simulation_M->Timing.clockTick1) {
        Simulink_Simulation_M->Timing.clockTickH1++;
      }
    }

    rate_scheduler();
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void Simulink_Simulation_derivatives(void)
{
  NeslSimulationData *simulationData;
  NeuDiagnosticManager *diagnosticManager;
  NeuDiagnosticTree *diagnosticTree;
  XDot_Simulink_Simulation_T *_rtXdot;
  real_T tmp_0[32];
  real_T time;
  int32_T tmp_2;
  int_T tmp_1[9];
  boolean_T tmp;
  _rtXdot = ((XDot_Simulink_Simulation_T *) Simulink_Simulation_M->derivs);

  /* Derivatives for SimscapeExecutionBlock: '<S17>/STATE_1' */
  simulationData = (NeslSimulationData *)Simulink_Simulation_DW.STATE_1_SimData;
  time = Simulink_Simulation_M->Timing.t[0];
  simulationData->mData->mTime.mN = 1;
  simulationData->mData->mTime.mX = &time;
  simulationData->mData->mContStates.mN = 13;
  simulationData->mData->mContStates.mX =
    &Simulink_Simulation_X.Simulink_SimulationAircraft_Dyn[0];
  simulationData->mData->mDiscStates.mN = 0;
  simulationData->mData->mDiscStates.mX =
    &Simulink_Simulation_DW.STATE_1_Discrete;
  simulationData->mData->mModeVector.mN = 0;
  simulationData->mData->mModeVector.mX = &Simulink_Simulation_DW.STATE_1_Modes;
  tmp = false;
  simulationData->mData->mFoundZcEvents = tmp;
  simulationData->mData->mIsMajorTimeStep = rtmIsMajorTimeStep
    (Simulink_Simulation_M);
  tmp = false;
  simulationData->mData->mIsSolverAssertCheck = tmp;
  simulationData->mData->mIsSolverCheckingCIC = false;
  tmp = rtsiIsSolverComputingJacobian(&Simulink_Simulation_M->solverInfo);
  simulationData->mData->mIsComputingJacobian = tmp;
  simulationData->mData->mIsEvaluatingF0 = false;
  simulationData->mData->mIsSolverRequestingReset = false;
  simulationData->mData->mIsModeUpdateTimeStep = rtsiIsModeUpdateTimeStep
    (&Simulink_Simulation_M->solverInfo);
  tmp_1[0] = 0;
  tmp_0[0] = Simulink_Simulation_B.INPUT_1_1_1[0];
  tmp_0[1] = Simulink_Simulation_B.INPUT_1_1_1[1];
  tmp_0[2] = Simulink_Simulation_B.INPUT_1_1_1[2];
  tmp_0[3] = Simulink_Simulation_B.INPUT_1_1_1[3];
  tmp_1[1] = 4;
  tmp_0[4] = Simulink_Simulation_B.INPUT_2_1_1[0];
  tmp_0[5] = Simulink_Simulation_B.INPUT_2_1_1[1];
  tmp_0[6] = Simulink_Simulation_B.INPUT_2_1_1[2];
  tmp_0[7] = Simulink_Simulation_B.INPUT_2_1_1[3];
  tmp_1[2] = 8;
  tmp_0[8] = Simulink_Simulation_B.INPUT_4_1_1[0];
  tmp_0[9] = Simulink_Simulation_B.INPUT_4_1_1[1];
  tmp_0[10] = Simulink_Simulation_B.INPUT_4_1_1[2];
  tmp_0[11] = Simulink_Simulation_B.INPUT_4_1_1[3];
  tmp_1[3] = 12;
  tmp_0[12] = Simulink_Simulation_B.INPUT_5_1_1[0];
  tmp_0[13] = Simulink_Simulation_B.INPUT_5_1_1[1];
  tmp_0[14] = Simulink_Simulation_B.INPUT_5_1_1[2];
  tmp_0[15] = Simulink_Simulation_B.INPUT_5_1_1[3];
  tmp_1[4] = 16;
  tmp_0[16] = Simulink_Simulation_B.INPUT_6_1_1[0];
  tmp_0[17] = Simulink_Simulation_B.INPUT_6_1_1[1];
  tmp_0[18] = Simulink_Simulation_B.INPUT_6_1_1[2];
  tmp_0[19] = Simulink_Simulation_B.INPUT_6_1_1[3];
  tmp_1[5] = 20;
  tmp_0[20] = Simulink_Simulation_B.INPUT_7_1_1[0];
  tmp_0[21] = Simulink_Simulation_B.INPUT_7_1_1[1];
  tmp_0[22] = Simulink_Simulation_B.INPUT_7_1_1[2];
  tmp_0[23] = Simulink_Simulation_B.INPUT_7_1_1[3];
  tmp_1[6] = 24;
  tmp_0[24] = Simulink_Simulation_B.INPUT_8_1_1[0];
  tmp_0[25] = Simulink_Simulation_B.INPUT_8_1_1[1];
  tmp_0[26] = Simulink_Simulation_B.INPUT_8_1_1[2];
  tmp_0[27] = Simulink_Simulation_B.INPUT_8_1_1[3];
  tmp_1[7] = 28;
  tmp_0[28] = Simulink_Simulation_B.INPUT_3_1_1[0];
  tmp_0[29] = Simulink_Simulation_B.INPUT_3_1_1[1];
  tmp_0[30] = Simulink_Simulation_B.INPUT_3_1_1[2];
  tmp_0[31] = Simulink_Simulation_B.INPUT_3_1_1[3];
  tmp_1[8] = 32;
  simulationData->mData->mInputValues.mN = 32;
  simulationData->mData->mInputValues.mX = &tmp_0[0];
  simulationData->mData->mInputOffsets.mN = 9;
  simulationData->mData->mInputOffsets.mX = &tmp_1[0];
  simulationData->mData->mDx.mN = 13;
  simulationData->mData->mDx.mX = &_rtXdot->Simulink_SimulationAircraft_Dyn[0];
  diagnosticManager = (NeuDiagnosticManager *)
    Simulink_Simulation_DW.STATE_1_DiagMgr;
  diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
  tmp_2 = ne_simulator_method((NeslSimulator *)
    Simulink_Simulation_DW.STATE_1_Simulator, NESL_SIM_DERIVATIVES,
    simulationData, diagnosticManager);
  if (tmp_2 != 0) {
    tmp = error_buffer_is_empty(rtmGetErrorStatus(Simulink_Simulation_M));
    if (tmp) {
      char *msg;
      msg = rtw_diagnostics_msg(diagnosticTree);
      rtmSetErrorStatus(Simulink_Simulation_M, msg);
    }
  }

  /* End of Derivatives for SimscapeExecutionBlock: '<S17>/STATE_1' */
}

/* Model initialize function */
void Simulink_Simulation_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Simulink_Simulation_M, 0,
                sizeof(RT_MODEL_Simulink_Simulation_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Simulink_Simulation_M->solverInfo,
                          &Simulink_Simulation_M->Timing.simTimeStep);
    rtsiSetTPtr(&Simulink_Simulation_M->solverInfo, &rtmGetTPtr
                (Simulink_Simulation_M));
    rtsiSetStepSizePtr(&Simulink_Simulation_M->solverInfo,
                       &Simulink_Simulation_M->Timing.stepSize0);
    rtsiSetdXPtr(&Simulink_Simulation_M->solverInfo,
                 &Simulink_Simulation_M->derivs);
    rtsiSetContStatesPtr(&Simulink_Simulation_M->solverInfo, (real_T **)
                         &Simulink_Simulation_M->contStates);
    rtsiSetNumContStatesPtr(&Simulink_Simulation_M->solverInfo,
      &Simulink_Simulation_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&Simulink_Simulation_M->solverInfo,
      &Simulink_Simulation_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&Simulink_Simulation_M->solverInfo,
      &Simulink_Simulation_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&Simulink_Simulation_M->solverInfo,
      &Simulink_Simulation_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&Simulink_Simulation_M->solverInfo,
                          (&rtmGetErrorStatus(Simulink_Simulation_M)));
    rtsiSetRTModelPtr(&Simulink_Simulation_M->solverInfo, Simulink_Simulation_M);
  }

  rtsiSetSimTimeStep(&Simulink_Simulation_M->solverInfo, MAJOR_TIME_STEP);
  Simulink_Simulation_M->intgData.y = Simulink_Simulation_M->odeY;
  Simulink_Simulation_M->intgData.f[0] = Simulink_Simulation_M->odeF[0];
  Simulink_Simulation_M->intgData.f[1] = Simulink_Simulation_M->odeF[1];
  Simulink_Simulation_M->intgData.f[2] = Simulink_Simulation_M->odeF[2];
  Simulink_Simulation_M->contStates = ((X_Simulink_Simulation_T *)
    &Simulink_Simulation_X);
  rtsiSetSolverData(&Simulink_Simulation_M->solverInfo, (void *)
                    &Simulink_Simulation_M->intgData);
  rtsiSetIsMinorTimeStepWithModeChange(&Simulink_Simulation_M->solverInfo, false);
  rtsiSetSolverName(&Simulink_Simulation_M->solverInfo,"ode3");
  rtmSetTPtr(Simulink_Simulation_M, &Simulink_Simulation_M->Timing.tArray[0]);
  rtmSetTFinal(Simulink_Simulation_M, 10.0);
  Simulink_Simulation_M->Timing.stepSize0 = 0.0001;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = (NULL);
    Simulink_Simulation_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(Simulink_Simulation_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(Simulink_Simulation_M->rtwLogInfo, (NULL));
    rtliSetLogT(Simulink_Simulation_M->rtwLogInfo, "tout");
    rtliSetLogX(Simulink_Simulation_M->rtwLogInfo, "");
    rtliSetLogXFinal(Simulink_Simulation_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(Simulink_Simulation_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(Simulink_Simulation_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(Simulink_Simulation_M->rtwLogInfo, 0);
    rtliSetLogDecimation(Simulink_Simulation_M->rtwLogInfo, 1);
    rtliSetLogY(Simulink_Simulation_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(Simulink_Simulation_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(Simulink_Simulation_M->rtwLogInfo, (NULL));
  }

  /* block I/O */
  (void) memset(((void *) &Simulink_Simulation_B), 0,
                sizeof(B_Simulink_Simulation_T));

  /* states (continuous) */
  {
    (void) memset((void *)&Simulink_Simulation_X, 0,
                  sizeof(X_Simulink_Simulation_T));
  }

  /* states (dwork) */
  (void) memset((void *)&Simulink_Simulation_DW, 0,
                sizeof(DW_Simulink_Simulation_T));

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(Simulink_Simulation_M->rtwLogInfo, 0.0,
    rtmGetTFinal(Simulink_Simulation_M), Simulink_Simulation_M->Timing.stepSize0,
    (&rtmGetErrorStatus(Simulink_Simulation_M)));

  {
    NeModelParameters modelParameters;
    NeModelParameters modelParameters_0;
    NeModelParameters modelParameters_1;
    NeslSimulationData *tmp_1;
    NeslSimulator *tmp;
    NeuDiagnosticManager *diagnosticManager;
    NeuDiagnosticTree *diagnosticTree;
    NeuDiagnosticTree *diagnosticTree_0;
    NeuDiagnosticTree *diagnosticTree_1;
    real_T tmp_2;
    int32_T tmp_3;
    boolean_T tmp_0;

    /* Start for SimscapeExecutionBlock: '<S17>/STATE_1' */
    tmp = nesl_lease_simulator(
      "Simulink_Simulation/Aircraft Dynamics/Solver Configuration_1", 0, 0);
    Simulink_Simulation_DW.STATE_1_Simulator = (void *)tmp;
    tmp_0 = pointer_is_null(Simulink_Simulation_DW.STATE_1_Simulator);
    if (tmp_0) {
      Simulink_Simulation_6a081443_1_gateway();
      tmp = nesl_lease_simulator(
        "Simulink_Simulation/Aircraft Dynamics/Solver Configuration_1", 0, 0);
      Simulink_Simulation_DW.STATE_1_Simulator = (void *)tmp;
    }

    tmp_1 = nesl_create_simulation_data();
    Simulink_Simulation_DW.STATE_1_SimData = (void *)tmp_1;
    diagnosticManager = rtw_create_diagnostics();
    Simulink_Simulation_DW.STATE_1_DiagMgr = (void *)diagnosticManager;
    modelParameters.mSolverType = NE_SOLVER_TYPE_DAE;
    modelParameters.mSolverAbsTol = 0.001;
    modelParameters.mSolverRelTol = 0.001;
    modelParameters.mSolverModifyAbsTol = NE_MODIFY_ABS_TOL_NO;
    modelParameters.mStartTime = 0.0;
    modelParameters.mLoadInitialState = false;
    modelParameters.mUseSimState = false;
    modelParameters.mLinTrimCompile = false;
    modelParameters.mLoggingMode = SSC_LOGGING_NONE;
    modelParameters.mRTWModifiedTimeStamp = 6.69747603E+8;
    tmp_2 = 0.001;
    modelParameters.mSolverTolerance = tmp_2;
    tmp_2 = 0.0001;
    modelParameters.mFixedStepSize = tmp_2;
    tmp_0 = false;
    modelParameters.mVariableStepSolver = tmp_0;
    tmp_0 = false;
    modelParameters.mIsUsingODEN = tmp_0;
    modelParameters.mZcDisabled = true;
    diagnosticManager = (NeuDiagnosticManager *)
      Simulink_Simulation_DW.STATE_1_DiagMgr;
    diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
    tmp_3 = nesl_initialize_simulator((NeslSimulator *)
      Simulink_Simulation_DW.STATE_1_Simulator, &modelParameters,
      diagnosticManager);
    if (tmp_3 != 0) {
      tmp_0 = error_buffer_is_empty(rtmGetErrorStatus(Simulink_Simulation_M));
      if (tmp_0) {
        char *msg;
        msg = rtw_diagnostics_msg(diagnosticTree);
        rtmSetErrorStatus(Simulink_Simulation_M, msg);
      }
    }

    /* End of Start for SimscapeExecutionBlock: '<S17>/STATE_1' */

    /* Start for SimscapeExecutionBlock: '<S17>/OUTPUT_1_0' */
    tmp = nesl_lease_simulator(
      "Simulink_Simulation/Aircraft Dynamics/Solver Configuration_1", 1, 0);
    Simulink_Simulation_DW.OUTPUT_1_0_Simulator = (void *)tmp;
    tmp_0 = pointer_is_null(Simulink_Simulation_DW.OUTPUT_1_0_Simulator);
    if (tmp_0) {
      Simulink_Simulation_6a081443_1_gateway();
      tmp = nesl_lease_simulator(
        "Simulink_Simulation/Aircraft Dynamics/Solver Configuration_1", 1, 0);
      Simulink_Simulation_DW.OUTPUT_1_0_Simulator = (void *)tmp;
    }

    tmp_1 = nesl_create_simulation_data();
    Simulink_Simulation_DW.OUTPUT_1_0_SimData = (void *)tmp_1;
    diagnosticManager = rtw_create_diagnostics();
    Simulink_Simulation_DW.OUTPUT_1_0_DiagMgr = (void *)diagnosticManager;
    modelParameters_0.mSolverType = NE_SOLVER_TYPE_DAE;
    modelParameters_0.mSolverAbsTol = 0.001;
    modelParameters_0.mSolverRelTol = 0.001;
    modelParameters_0.mSolverModifyAbsTol = NE_MODIFY_ABS_TOL_NO;
    modelParameters_0.mStartTime = 0.0;
    modelParameters_0.mLoadInitialState = false;
    modelParameters_0.mUseSimState = false;
    modelParameters_0.mLinTrimCompile = false;
    modelParameters_0.mLoggingMode = SSC_LOGGING_NONE;
    modelParameters_0.mRTWModifiedTimeStamp = 6.69747603E+8;
    tmp_2 = 0.001;
    modelParameters_0.mSolverTolerance = tmp_2;
    tmp_2 = 0.0001;
    modelParameters_0.mFixedStepSize = tmp_2;
    tmp_0 = false;
    modelParameters_0.mVariableStepSolver = tmp_0;
    tmp_0 = false;
    modelParameters_0.mIsUsingODEN = tmp_0;
    modelParameters_0.mZcDisabled = true;
    diagnosticManager = (NeuDiagnosticManager *)
      Simulink_Simulation_DW.OUTPUT_1_0_DiagMgr;
    diagnosticTree_0 = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
    tmp_3 = nesl_initialize_simulator((NeslSimulator *)
      Simulink_Simulation_DW.OUTPUT_1_0_Simulator, &modelParameters_0,
      diagnosticManager);
    if (tmp_3 != 0) {
      tmp_0 = error_buffer_is_empty(rtmGetErrorStatus(Simulink_Simulation_M));
      if (tmp_0) {
        char *msg_0;
        msg_0 = rtw_diagnostics_msg(diagnosticTree_0);
        rtmSetErrorStatus(Simulink_Simulation_M, msg_0);
      }
    }

    /* End of Start for SimscapeExecutionBlock: '<S17>/OUTPUT_1_0' */

    /* Start for SimscapeExecutionBlock: '<S17>/OUTPUT_1_1' */
    tmp = nesl_lease_simulator(
      "Simulink_Simulation/Aircraft Dynamics/Solver Configuration_1", 1, 1);
    Simulink_Simulation_DW.OUTPUT_1_1_Simulator = (void *)tmp;
    tmp_0 = pointer_is_null(Simulink_Simulation_DW.OUTPUT_1_1_Simulator);
    if (tmp_0) {
      Simulink_Simulation_6a081443_1_gateway();
      tmp = nesl_lease_simulator(
        "Simulink_Simulation/Aircraft Dynamics/Solver Configuration_1", 1, 1);
      Simulink_Simulation_DW.OUTPUT_1_1_Simulator = (void *)tmp;
    }

    tmp_1 = nesl_create_simulation_data();
    Simulink_Simulation_DW.OUTPUT_1_1_SimData = (void *)tmp_1;
    diagnosticManager = rtw_create_diagnostics();
    Simulink_Simulation_DW.OUTPUT_1_1_DiagMgr = (void *)diagnosticManager;
    modelParameters_1.mSolverType = NE_SOLVER_TYPE_DAE;
    modelParameters_1.mSolverAbsTol = 0.001;
    modelParameters_1.mSolverRelTol = 0.001;
    modelParameters_1.mSolverModifyAbsTol = NE_MODIFY_ABS_TOL_NO;
    modelParameters_1.mStartTime = 0.0;
    modelParameters_1.mLoadInitialState = false;
    modelParameters_1.mUseSimState = false;
    modelParameters_1.mLinTrimCompile = false;
    modelParameters_1.mLoggingMode = SSC_LOGGING_NONE;
    modelParameters_1.mRTWModifiedTimeStamp = 6.69747603E+8;
    tmp_2 = 0.001;
    modelParameters_1.mSolverTolerance = tmp_2;
    tmp_2 = 0.0001;
    modelParameters_1.mFixedStepSize = tmp_2;
    tmp_0 = false;
    modelParameters_1.mVariableStepSolver = tmp_0;
    tmp_0 = false;
    modelParameters_1.mIsUsingODEN = tmp_0;
    modelParameters_1.mZcDisabled = true;
    diagnosticManager = (NeuDiagnosticManager *)
      Simulink_Simulation_DW.OUTPUT_1_1_DiagMgr;
    diagnosticTree_1 = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
    tmp_3 = nesl_initialize_simulator((NeslSimulator *)
      Simulink_Simulation_DW.OUTPUT_1_1_Simulator, &modelParameters_1,
      diagnosticManager);
    if (tmp_3 != 0) {
      tmp_0 = error_buffer_is_empty(rtmGetErrorStatus(Simulink_Simulation_M));
      if (tmp_0) {
        char *msg_1;
        msg_1 = rtw_diagnostics_msg(diagnosticTree_1);
        rtmSetErrorStatus(Simulink_Simulation_M, msg_1);
      }
    }

    /* End of Start for SimscapeExecutionBlock: '<S17>/OUTPUT_1_1' */
  }

  /* InitializeConditions for Delay: '<S1>/Delay2' */
  Simulink_Simulation_DW.Delay2_DSTATE[0] =
    Simulink_Simulation_P.Delay2_InitialCondition;
  Simulink_Simulation_DW.Delay2_DSTATE[1] =
    Simulink_Simulation_P.Delay2_InitialCondition;
  Simulink_Simulation_DW.Delay2_DSTATE[2] =
    Simulink_Simulation_P.Delay2_InitialCondition;
  Simulink_Simulation_DW.Delay2_DSTATE[3] =
    Simulink_Simulation_P.Delay2_InitialCondition;

  /* InitializeConditions for Delay: '<Root>/Delay2' */
  Simulink_Simulation_DW.Delay2_DSTATE_k =
    Simulink_Simulation_P.Delay2_InitialCondition_f;

  /* InitializeConditions for Delay: '<Root>/Delay3' */
  Simulink_Simulation_DW.Delay3_DSTATE =
    Simulink_Simulation_P.Delay3_InitialCondition;

  /* InitializeConditions for Delay: '<Root>/Delay' */
  Simulink_Simulation_DW.Delay_DSTATE =
    Simulink_Simulation_P.Delay_InitialCondition;

  /* InitializeConditions for Delay: '<Root>/Delay1' */
  Simulink_Simulation_DW.Delay1_DSTATE =
    Simulink_Simulation_P.Delay1_InitialCondition;

  /* InitializeConditions for Delay: '<S1>/Delay1' */
  Simulink_Simulation_DW.Delay1_DSTATE_j =
    Simulink_Simulation_P.Delay1_InitialCondition_h;

  /* InitializeConditions for Delay: '<S1>/Delay' */
  Simulink_Simulation_DW.Delay_DSTATE_c =
    Simulink_Simulation_P.Delay_InitialCondition_a;

  /* InitializeConditions for DiscreteIntegrator: '<S120>/Integrator' */
  Simulink_Simulation_DW.Integrator_DSTATE =
    Simulink_Simulation_P.PIDController_InitialConditio_l;

  /* InitializeConditions for DiscreteIntegrator: '<S115>/Filter' */
  Simulink_Simulation_DW.Filter_DSTATE =
    Simulink_Simulation_P.PIDController_InitialConditionF;

  /* InitializeConditions for DiscreteIntegrator: '<S71>/Integrator' */
  Simulink_Simulation_DW.Integrator_DSTATE_f =
    Simulink_Simulation_P.PIDController_InitialConditio_e;

  /* InitializeConditions for DiscreteIntegrator: '<S66>/Filter' */
  Simulink_Simulation_DW.Filter_DSTATE_k =
    Simulink_Simulation_P.PIDController_InitialConditio_o;

  /* InitializeConditions for DiscreteIntegrator: '<S169>/Integrator' */
  Simulink_Simulation_DW.Integrator_DSTATE_m =
    Simulink_Simulation_P.PIDController_InitialConditio_d;

  /* InitializeConditions for DiscreteIntegrator: '<S164>/Filter' */
  Simulink_Simulation_DW.Filter_DSTATE_l =
    Simulink_Simulation_P.PIDController_InitialConditio_j;

  /* InitializeConditions for DiscreteIntegrator: '<S219>/Integrator' */
  Simulink_Simulation_DW.Integrator_DSTATE_e =
    Simulink_Simulation_P.PIDAcceleration_InitialConditio;
}

/* Model terminate function */
void Simulink_Simulation_terminate(void)
{
  /* Terminate for SimscapeExecutionBlock: '<S17>/STATE_1' */
  neu_destroy_diagnostic_manager((NeuDiagnosticManager *)
    Simulink_Simulation_DW.STATE_1_DiagMgr);
  nesl_destroy_simulation_data((NeslSimulationData *)
    Simulink_Simulation_DW.STATE_1_SimData);
  nesl_erase_simulator("Simulink_Simulation/Aircraft Dynamics/Solver Configuration_1");
  nesl_destroy_registry();

  /* Terminate for SimscapeExecutionBlock: '<S17>/OUTPUT_1_0' */
  neu_destroy_diagnostic_manager((NeuDiagnosticManager *)
    Simulink_Simulation_DW.OUTPUT_1_0_DiagMgr);
  nesl_destroy_simulation_data((NeslSimulationData *)
    Simulink_Simulation_DW.OUTPUT_1_0_SimData);
  nesl_erase_simulator("Simulink_Simulation/Aircraft Dynamics/Solver Configuration_1");
  nesl_destroy_registry();

  /* Terminate for SimscapeExecutionBlock: '<S17>/OUTPUT_1_1' */
  neu_destroy_diagnostic_manager((NeuDiagnosticManager *)
    Simulink_Simulation_DW.OUTPUT_1_1_DiagMgr);
  nesl_destroy_simulation_data((NeslSimulationData *)
    Simulink_Simulation_DW.OUTPUT_1_1_SimData);
  nesl_erase_simulator("Simulink_Simulation/Aircraft Dynamics/Solver Configuration_1");
  nesl_destroy_registry();
}
