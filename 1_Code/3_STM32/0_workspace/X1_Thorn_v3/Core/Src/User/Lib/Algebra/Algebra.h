/*
 * math.h
 *
 *  Created on: Apr 25, 2025
 *      Author: marcv
 */

#ifndef SRC_USER_LIB_ALGEBRA_H_
#define SRC_USER_LIB_ALGEBRA_H_

typedef float Mat3[3][3];
typedef float Vec3[3];

typedef struct {
    float w, x, y, z;
} quaternion_t;





void quaternion_correction(const quaternion_t *q1, quaternion_t *q2);
void vector_cross(const float a[3], const float b[3], float result[3]);
void rot_x_mat(Mat3 R, float angle_rad);
void rot_y_mat(Mat3 R, float angle_rad);
void rot_z_mat(Mat3 R, float angle_rad);
void mat3Multiply(const Mat3 A, const Mat3 B, Mat3 C);
void matrixToQuat(const Mat3 R, quaternion_t *q);





#endif /* SRC_USER_LIB_ALGEBRA_H_ */
