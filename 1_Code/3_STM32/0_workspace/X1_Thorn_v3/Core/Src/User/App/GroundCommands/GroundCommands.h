/*
 * GroundCommands.h
 *
 *  Created on: May 1, 2025
 *      Author: marcv
 */

#ifndef SRC_USER_APP_GROUNDCOMMANDS_GROUNDCOMMANDS_H_
#define SRC_USER_APP_GROUNDCOMMANDS_GROUNDCOMMANDS_H_

#include "../../Lib/Algebra/Algebra.h"
#include "../../Peripheral/ESP32/ESP32.h"
#include <stdint.h>

typedef struct {
	float thrust_ref;			  				// longitudinal acceleration
    float p_ref, pitch_ref, yaw_ref;        		// body rates
} reference_t;

void GroundCommands_Init(void);
void get_reference(quaternion_t curr_attitude, reference_t *curr_reference);

#endif /* SRC_USER_APP_GROUNDCOMMANDS_GROUNDCOMMANDS_H_ */
