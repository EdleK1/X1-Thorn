/**
  ******************************************************************************
  * @file           : GroundCommands.c
  * @brief          : Receive the commands from the esp32 and convert them to the reference to follow
  *
  *
  * ax, p, q, r, q0, q1, q2, q3
  ******************************************************************************
*/

#include "GroundCommands.h"
#include "../../Peripheral/ESP32/ESP32.h"
#include "../../Lib/Globals/Globals.h"


static const Vec3 VEC_X_WORLD = { 0.0f, 0.0f, 1.0f };


void GroundCommands_Init(void)
{
	ESP32_Init();
}


void get_reference(quaternion_t initial_attitude, esp32_commands_t *curr_esp32_commands, reference_t *curr_reference)
{
	Vec3 vec_y_world, vec_z_world, vec_z_aircraft;

	quaternion_t q_ref;
	Mat3 Rz, Ry, R0;

	vec_z_aircraft[0] = 2.0f*(initial_attitude.x*initial_attitude.z + initial_attitude.w*initial_attitude.y);
	vec_z_aircraft[1] = 2.0f*(initial_attitude.y*initial_attitude.z - initial_attitude.w*initial_attitude.x);
	vec_z_aircraft[2] = 1.0f - 2.0f*(initial_attitude.x*initial_attitude.x + initial_attitude.y*initial_attitude.y);

	vector_cross(vec_z_aircraft, VEC_X_WORLD, vec_y_world);
	vector_cross(VEC_X_WORLD, vec_y_world, vec_z_world);

	R0[0][0] = VEC_X_WORLD[0];
	R0[1][0] = VEC_X_WORLD[1];
	R0[2][0] = VEC_X_WORLD[2];

	R0[0][1] = vec_y_world[0];
	R0[1][1] = vec_y_world[1];
	R0[2][1] = vec_y_world[2];

	R0[0][2] = vec_z_world[0];
	R0[1][2] = vec_z_world[1];
	R0[2][2] = vec_z_world[2];

	if (g_Status != 2) // Landing / Off mode
	{
		curr_reference->thrust_ref = curr_reference->thrust_ref - 9e5;		// new thrust controller architecture, it should take aprox 10 seconds to go from 22000 RPMS to 0
		curr_esp32_commands->p_command = 0;
		curr_esp32_commands->pitch_command = 0;
		curr_esp32_commands->yaw_command = 0;
	}
	else
	{
		curr_reference->thrust_ref = curr_esp32_commands->thrust_command;
	}

	if (curr_reference->thrust_ref < 0)
	{
		curr_reference->thrust_ref = 0;
	}

	rot_z_mat(Rz, curr_esp32_commands->yaw_command);
	rot_y_mat(Ry, curr_esp32_commands->pitch_command);

	// R_ref = R0 * Ry * Rz;

	Mat3 temp_mat, R_ref;

	mat3Multiply(R0, Ry, temp_mat);
	mat3Multiply(temp_mat, Rz, R_ref);

	matrixToQuat(R_ref, &q_ref);
	quaternion_correction(&initial_attitude, &q_ref);

	quaternion_t dq; // dq = q_ref - q_curr

	dq.w = q_ref.w - initial_attitude.w;
	dq.x = q_ref.x - initial_attitude.x;
	dq.y = q_ref.y - initial_attitude.y;
	dq.z = q_ref.z - initial_attitude.z;


	// esentially using that dq = M(omega) * q, it can be also done with deviation but this is faster to implement

	float p_delta, q_delta, r_delta;

	p_delta = 2 * (-initial_attitude.x * dq.w + initial_attitude.w * dq.x + initial_attitude.z * dq.y - initial_attitude.y * dq.z);
	q_delta = 2 * (-initial_attitude.y * dq.w - initial_attitude.z * dq.x + initial_attitude.w * dq.y + initial_attitude.x * dq.z);
	r_delta = 2 * (-initial_attitude.z * dq.w + initial_attitude.y * dq.x - initial_attitude.x * dq.y + initial_attitude.w * dq.z);

	curr_reference->p_ref = p_delta + curr_esp32_commands->p_command;
	curr_reference->pitch_ref = q_delta;
	curr_reference->yaw_ref = r_delta;
}
