/*
 * Globals.h
 *
 *  Created on: Jun 20, 2025
 *      Author: marcv
 */

#ifndef SRC_USER_LIB_GLOBALS_GLOBALS_H_
#define SRC_USER_LIB_GLOBALS_GLOBALS_H_

#include <stdint.h>

extern volatile uint8_t g_Status;			// Status of the drone, can be 0 (disarmed), 1 (landing), 2 (nominal)
extern volatile uint8_t g_ESC_Active; 		// Status of the ESC, can be 0 (rpms and throttle are 0) or 1 (otherwise)

#endif /* SRC_USER_LIB_GLOBALS_GLOBALS_H_ */
