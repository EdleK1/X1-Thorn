/*
 * Odometry.h
 *
 *  Created on: Apr 25, 2025
 *      Author: marcv
 */

#ifndef SRC_USER_APP_ODOMETRY_ODOMETRY_H_
#define SRC_USER_APP_ODOMETRY_ODOMETRY_H_
#include <stdint.h>
#define TS 			0.01f


// Define CG and sensor positions in the body frame (in meters)
#define SENSOR_POS_X   0.000f
#define SENSOR_POS_Y   0.000f
#define SENSOR_POS_Z   0.000f

#define CG_POS_X       0.000f
#define CG_POS_Y       0.000f
#define CG_POS_Z       0.000f

// Compute S_CG = CG - Sensor in body frame as a constant array

static const float S_CG[3] = {
    CG_POS_X - SENSOR_POS_X,   // x
    CG_POS_Y - SENSOR_POS_Y,   // y
    CG_POS_Z - SENSOR_POS_Z    // z
};



typedef struct {
	float ax;			  // longitudinal acceleration
    float p, q, r;        // angular rates
    float q0, q1, q2, q3; // attitude quaternion
} odometry_t;


void Odometry_Read(odometry_t *Curr_Read);
void Odometry_Init(void);




#endif /* SRC_USER_APP_ODOMETRY_ODOMETRY_H_ */
