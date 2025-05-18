/**
  ******************************************************************************
  * @file           : Algebra.c
  * @brief          : Provides various functions involving matrixes and quaternions
  ******************************************************************************
*/

#include <stddef.h>
#include <math.h>
#include "Algebra.h"

void vector_cross(const Vec3 a, const Vec3 b, Vec3 result)
{
    result[0] = a[1]*b[2] - a[2]*b[1];
    result[1] = a[2]*b[0] - a[0]*b[2];
    result[2] = a[0]*b[1] - a[1]*b[0];
}


void quaternion_correction(const quaternion_t *q1, quaternion_t *q2) // flips q2 if the dot product is negative to avoid sign ambiguity
{
	float dot = q1->w*q2->w + q1->x*q2->x + q1->y*q2->y + q1->z*q2->z;
	if (dot < 0.0f)
	{
		q2->w = -q2->w;
		q2->x = -q2->x;
		q2->y = -q2->y;
		q2->z = -q2->z;
	}
}


void rot_x_mat(Mat3 R, float angle_rad)
{

    float c = cosf(angle_rad);
    float s = sinf(angle_rad);

    R[0][0] = 1; R[0][1] = 0; R[0][2] = 0;
    R[1][0] = 0; R[1][1] = c; R[1][2] = -s;
    R[2][0] = 0; R[2][1] = s; R[2][2] = c;

}

void rot_y_mat(Mat3 R, float angle_rad)
{

    float c = cosf(angle_rad);
    float s = sinf(angle_rad);

    R[0][0] = c; R[0][1] = 0; R[0][2] = s;
    R[1][0] = 0; R[1][1] = 1; R[1][2] = 0;
    R[2][0] = -s; R[2][1] = 0; R[2][2] = c;

}

void rot_z_mat(Mat3 R, float angle_rad)
{

    float c = cosf(angle_rad);
    float s = sinf(angle_rad);

    R[0][0] = c; R[0][1] = -s; R[0][2] = 0;
    R[1][0] = s; R[1][1] = c; R[1][2] = 0;
    R[2][0] = 0; R[2][1] = 0; R[2][2] = 1;

}



void matrixToQuat(const Mat3 R, quaternion_t *q) {
    float trace = R[0][0] + R[1][1] + R[2][2];
    if (trace > 0.0f) {
        float s = 2.0f * sqrtf(trace + 1.0f);
        q->w = 0.25f * s;
        q->x = (R[2][1] - R[1][2]) / s;
        q->y = (R[0][2] - R[2][0]) / s;
        q->z = (R[1][0] - R[0][1]) / s;
    } else {
        if (R[0][0] > R[1][1] && R[0][0] > R[2][2]) {
            float s = 2.0f * sqrtf(1.0f + R[0][0] - R[1][1] - R[2][2]);
            q->w = (R[2][1] - R[1][2]) / s;
            q->x = 0.25f * s;
            q->y = (R[0][1] + R[1][0]) / s;
            q->z = (R[0][2] + R[2][0]) / s;
        } else if (R[1][1] > R[2][2]) {
            float s = 2.0f * sqrtf(1.0f - R[0][0] + R[1][1] - R[2][2]);
            q->w = (R[0][2] - R[2][0]) / s;
            q->x = (R[0][1] + R[1][0]) / s;
            q->y = 0.25f * s;
            q->z = (R[1][2] + R[2][1]) / s;
        } else {
            float s = 2.0f * sqrtf(1.0f - R[0][0] - R[1][1] + R[2][2] );
            q->w = (R[1][0] - R[0][1]) / s;
            q->x = (R[0][2] + R[2][0]) / s;
            q->y = (R[1][2] + R[2][1]) / s;
            q->z = 0.25f * s;
        }
    }
}



void mat3Multiply(const Mat3 A, const Mat3 B, Mat3 C) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            C[i][j] = 0;
            for (int k = 0; k < 3; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}
