/*
 * GroundCommands.h
 *
 *  Created on: May 1, 2025
 *      Author: marcv
 */

#ifndef SRC_USER_APP_GROUNDCOMMANDS_GROUNDCOMMANDS_H_
#define SRC_USER_APP_GROUNDCOMMANDS_GROUNDCOMMANDS_H_

#include "../../Lib/Algebra/Algebra.h"
#include <stdint.h>

typedef struct {
	float ax_ref;			  				// longitudinal acceleration
    float p_ref;        					// roll rate
    float q0_ref, q1_ref, q2_ref, q3_ref; 	// attitude quaternion
} reference_t;

void GroundCommands_Init(void);
uint8_t get_reference(const quaternion_t *curr_attitude, reference_t *curr_reference);

#endif /* SRC_USER_APP_GROUNDCOMMANDS_GROUNDCOMMANDS_H_ */
