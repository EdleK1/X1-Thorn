/**
  ******************************************************************************
  * @file           : AttitudeMPC.c
  * @brief          : Receive the commands from the esp32 and convert them to the reference to follow
  *
  *
  * Odometry, Ref, Omega, prevServoL prevServoR -> ServoL ServoR OmegaL OmegaR, sol_time
  ******************************************************************************
*/

// standard C headers
#include <stdio.h>
#include <stdlib.h>

// User modules
#include "AttitudeMPC.h"
#include "../Odometry/Odometry.h"

// acados runtime APIs
#include "acados/utils/math.h"               // for MIN/MAX, etc.
#include "acados_c/ocp_nlp_interface.h"      // core OCP NLP interface
#include "acados_c/external_function_interface.h"
#include "acados_c/ocp_nlp_interface.h"

// the generated solver for your Aircraft_Attitude problem
#include "CGeneratedCode/acados_solver_Aircraft_Attitude.h"

// blasfeo helper (only needed if your solver calls BLASFEO d_aux routines)
#include "blasfeo_d_aux_ext_dep.h"


// alias dimensions from the generated header
#define NX     AIRCRAFT_ATTITUDE_NX      // # of states
#define NU     AIRCRAFT_ATTITUDE_NU      // # of controls
#define N      AIRCRAFT_ATTITUDE_N      // # of shooting intervals


static Aircraft_Attitude_solver_capsule *ocp_capsule;

// pointers into the OCP data structures
static ocp_nlp_config  *nlp_config;
static ocp_nlp_dims    *nlp_dims;
static ocp_nlp_in      *nlp_in;
static ocp_nlp_out     *nlp_out;
static ocp_nlp_solver  *nlp_solver;

// Storage for warm start: x_traj and u_traj from the last solve
static double x_warm[NX * (N+1)];
static double u_warm[NU * N];



/**
 * Attitude_MPC_Init
 * -----------------
 * Create the solver capsule and all internal data structures.
 * Must be called once before any calls to Get_AttitudeMPC_Result().
 */

int Attitude_MPC_Init(void)

{
    int status;

    // 1) allocate and initialize solver capsule
    ocp_capsule = Aircraft_Attitude_acados_create_capsule();

    // 2) create solver instance with default discretization. NULL means use the N and time grid you generated with codegen
    status = Aircraft_Attitude_acados_create_with_discretization(ocp_capsule, N, NULL);
    if (status != ACADOS_SUCCESS)
    {
        return status;
    }

    // 3) extract pointers to the config, dims, in, out, solver
    nlp_config = Aircraft_Attitude_acados_get_nlp_config(ocp_capsule);
    nlp_dims   = Aircraft_Attitude_acados_get_nlp_dims  (ocp_capsule);
    nlp_in     = Aircraft_Attitude_acados_get_nlp_in    (ocp_capsule);
    nlp_out    = Aircraft_Attitude_acados_get_nlp_out   (ocp_capsule);
    nlp_solver = Aircraft_Attitude_acados_get_nlp_solver(ocp_capsule);

    // 4) initialize warm‐start guesses to zero
    for (int i = 0; i < NX*(N+1); i++) x_warm[i] = 0.0;
    for (int i = 0; i < NU*N;     i++) u_warm[i] = 0.0;

    return ACADOS_SUCCESS;
}



/**
 * Get_AttitudeMPC_Result
 * ----------------------
 * Solve the MPC given a current initial state and a reference. Uses warm‐start from the previous call for all stages.
 * Inputs:
 *   Aircraft_Initial_State->x0     : pointer to NX×1 array
 *   Aircraft_Reference->[... etc]  : fill in your reference into nlp_in
 *
 * Returns:
 *   curr_MPC_sol  : struct containing x0..xN and u0..u_{N-1}
 */



double Get_AttitudeMPC_Result(const MPC_Initial_State_t *Aircraft_Initial_State, const MPC_Ref_t  *Aircraft_Reference, MPC_Solution_t *curr_MPC_sol)
{
    double elapsed_time;

    double x0[NX];

    x0[0] = Aircraft_Initial_State->p;
    x0[1] = Aircraft_Initial_State->q;
    x0[2] = Aircraft_Initial_State->r;
    x0[3] = Aircraft_Initial_State->qW;
    x0[4] = Aircraft_Initial_State->qX;
    x0[5] = Aircraft_Initial_State->qY;
    x0[6] = Aircraft_Initial_State->qZ;
    x0[7] = Aircraft_Initial_State->OmegaR;
    x0[8] = Aircraft_Initial_State->OmegaL;
    x0[9] = Aircraft_Initial_State->ServoR;
    x0[10] = Aircraft_Initial_State->ServoL;

    // 1) Set the true initial state via bound constraints at stage 0
    ocp_nlp_constraints_model_set(nlp_config, nlp_dims, nlp_in, nlp_out, 0, "lbx", x0);
    ocp_nlp_constraints_model_set(nlp_config, nlp_dims, nlp_in, nlp_out, 0, "ubx", x0);


    // 2) Input the reference into the solver inputs
    double yref[NX + NU];
    double yref_e[NX];

	yref[0] = Aircraft_Reference->p;
	yref[1] = Aircraft_Reference->q;
	yref[2] = Aircraft_Reference->r;
	yref[3] = Aircraft_Reference->qW;
	yref[4] = Aircraft_Reference->qX;
	yref[5] = Aircraft_Reference->qY;
	yref[6] = Aircraft_Reference->qZ;
	yref[7] = Aircraft_Reference->OmegaR;
	yref[8] = Aircraft_Reference->OmegaL;
	yref[9] = Aircraft_Reference->ServoR;
	yref[10] = Aircraft_Reference->ServoL;
	yref[11] = Aircraft_Reference->DeltaOmega;
	yref[12] = Aircraft_Reference->DeltaServoR;
	yref[13] = Aircraft_Reference->DeltaServoL;

	for (int k = 0; k < NX; k++)
	{
	    yref_e[k] = yref[k];
	}

    for (int i = 0; i < N; i++)
    {
        ocp_nlp_cost_model_set(nlp_config, nlp_dims, nlp_in, i, "yref", yref);
    }

    ocp_nlp_cost_model_set(nlp_config, nlp_dims, nlp_in, N, "yref", yref_e);    		// terminal reference


    // 3) Warm‐start all stages with the previous solution
    for (int i = 0; i < N; i++)
    {
        ocp_nlp_out_set(nlp_config, nlp_dims, nlp_out, nlp_in, i, "x", &x_warm[i*NX]);
        ocp_nlp_out_set(nlp_config, nlp_dims, nlp_out, nlp_in, i, "u", &u_warm[i*NU]);
    }

    ocp_nlp_out_set(nlp_config, nlp_dims, nlp_out, nlp_in, N, "x", &x_warm[N*NX]); 			// terminal stage


    // 4) Solve the OCP
    int status = Aircraft_Attitude_acados_solve(ocp_capsule);
    ocp_nlp_get(nlp_solver, "time_tot", &elapsed_time);


    // 5) Extract solution into curr_MPC_sol AND store for next warm-start
    for (int i = 0; i <= N; i++)
    {
        ocp_nlp_out_get(nlp_config, nlp_dims, nlp_out, i,"x", &x_warm[i*NX]);
    }
    for (int i = 0; i < N; i++)
    {
        ocp_nlp_out_get(nlp_config, nlp_dims, nlp_out, i, "u", &u_warm[i*NU]);
    }

    // 6) return the solution struct
    if (status == ACADOS_SUCCESS)
    {

    	double x1[NX];

    	ocp_nlp_out_get(nlp_config, nlp_dims, nlp_out, 1,"x", &x1[0]);

    	curr_MPC_sol->OmegaR = x1[7];
    	curr_MPC_sol->OmegaL = x1[8];
    	curr_MPC_sol->ServoR = x1[9];
    	curr_MPC_sol->ServoL = x1[10];

    	return elapsed_time;
    }
    else
    {
    	return -1;
    }
}
