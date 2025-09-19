/*
 * PID_Settings.h
 *
 *  Created on: Jul 28, 2025
 *      Author: marcv
 */

#ifndef SRC_USER_APP_CONTROL_PID_SETTINGS_H_
#define SRC_USER_APP_CONTROL_PID_SETTINGS_H_


#define TS_PID 							0.01f


// Pitch Controller Parameters

#define KP_PITCH_RATE 					20.0f
#define KI_PITCH_RATE 					7.0f
#define KD_PITCH_RATE 					2.0f
#define KQ_PITCH_RATE 					4.0f
#define TAU_PITCH_RATE  				1.0f/20.0f		// N = 20

#define OUTPUT_MIN_PITCH				-180.0f
#define OUTPUT_MAX_PITCH				+180.0f
#define OUTPUT_MIN_PITCH_INTEGRATOR 	-40.0f
#define OUTPUT_MAX_PITCH_INTEGRATOR 	+40.0f


// Yaw Controller Parameters


#define KP_YAW_RATE 					110e6f
#define KI_YAW_RATE 					100e6f
#define KD_YAW_RATE 					0.0f    		// 10e6
#define KR_YAW_RATE 					7.0f
#define TAU_YAW_RATE    				1.0f/20.0f		// N = 20

#define OUTPUT_MIN_YAW 					-1.5e8f
#define OUTPUT_MAX_YAW 					+1.5e8f
#define OUTPUT_MIN_YAW_INTEGRATOR 		-1.5e7f
#define OUTPUT_MAX_YAW_INTEGRATOR 		+1.5e7f


// Roll Controller Parameters


#define KP_ROLL_RATE 					25.0f
#define KI_ROLL_RATE 					7.0f
#define KD_ROLL_RATE 					3.0f
#define TAU_ROLL_RATE    				1.0f/20.0f		// N = 20

#define OUTPUT_MIN_ROLL 				-120.0f
#define OUTPUT_MAX_ROLL 				+120.0f
#define OUTPUT_MIN_ROLL_INTEGRATOR 		-40.0f
#define OUTPUT_MAX_ROLL_INTEGRATOR 		+40.0f


// Thrust Controller Parameters


#define KP_THRUST 						2e6f
#define KI_THRUST 						200e6f

#define OUTPUT_MIN_THRUST 				0.0f
#define OUTPUT_MAX_THRUST 				+30e8f // Limitat a unes 38800 RPMs (sqrt(30e8/2))


#endif /* SRC_USER_APP_CONTROL_PID_SETTINGS_H_ */
