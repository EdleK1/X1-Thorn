/*
 * AttitudeMPC.h
 *
 *  Created on: May 7, 2025
 *      Author: marcv
 */

#ifndef SRC_USER_APP_ATTITUDEMPC_ATTITUDEMPC_H_
#define SRC_USER_APP_ATTITUDEMPC_ATTITUDEMPC_H_


typedef struct {
    float ServoR, ServoL;        	// Servos
    float OmegaR, OmegaL; 			// EDF RPM
} MPC_Solution_t;


typedef struct {
	float p, q ,r;			  		// angular rates
    float qW, qX, qY, qZ;        	// Attitude
    float OmegaR, OmegaL; 			// EDF RPMs
    float ServoR, ServoL;			// Servos
    float DeltaServoR, DeltaServoL, DeltaOmega;
} MPC_Ref_t;


typedef struct {
	float p, q ,r;			  		// angular rates
    float qW, qX, qY, qZ;        	// Attitude
    float OmegaR, OmegaL; 			// EDF RPMs
    float ServoR, ServoL;			// Servos
} MPC_Initial_State_t;

double Get_AttitudeMPC_Result(const MPC_Initial_State_t *Aircraft_Initial_State, const MPC_Ref_t  *Aircraft_Reference, MPC_Solution_t *curr_MPC_sol);
int Attitude_MPC_Init(void);


#endif /* SRC_USER_APP_ATTITUDEMPC_ATTITUDEMPC_H_ */
