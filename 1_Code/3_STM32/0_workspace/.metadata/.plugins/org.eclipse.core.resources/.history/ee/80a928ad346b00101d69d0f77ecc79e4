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
esp32_commands_t curr_esp32_commands;

void GroundCommands_Init(void)
{
	ESP32_Init();
}


void get_reference(quaternion_t curr_attitude, reference_t *curr_reference)
{
	Vec3 vec_y_world, vec_z_world, vec_y_aircraft;

	quaternion_t q_ref;
	Mat3 Rz, Ry, R0;

	vec_y_aircraft[0] = 2.0f*(curr_attitude.x*curr_attitude.y - curr_attitude.w*curr_attitude.z);
	vec_y_aircraft[1] = 1.0f - 2.0f*(curr_attitude.x*curr_attitude.x + curr_attitude.z*curr_attitude.z);
	vec_y_aircraft[2] = 2.0f*(curr_attitude.y*curr_attitude.z + curr_attitude.w*curr_attitude.x);

	vector_cross(VEC_X_WORLD, vec_y_aircraft, vec_z_world);
	vector_cross(vec_z_world, VEC_X_WORLD, vec_y_world);

	R0[0][0] = VEC_X_WORLD[0];
	R0[1][0] = VEC_X_WORLD[1];
	R0[2][0] = VEC_X_WORLD[2];

	R0[0][1] = vec_y_world[0];
	R0[1][1] = vec_y_world[1];
	R0[2][1] = vec_y_world[2];

	R0[0][2] = vec_z_world[0];
	R0[1][2] = vec_z_world[1];
	R0[2][2] = vec_z_world[2];


	ESP32_Get_Commands(&curr_esp32_commands);
	ESP32_Send_ESC_Status();

	if (g_Status != 2) // Landing / Off mode
	{
		curr_esp32_commands.ax_command = -0.2;
		curr_esp32_commands.p_command = 0;
		curr_esp32_commands.pitch_command = 0;
		curr_esp32_commands.yaw_command = 0;
	}

	rot_z_mat(Rz, curr_esp32_commands.yaw_command);
	rot_y_mat(Ry, curr_esp32_commands.pitch_command);

	// R_ref = Ry * Rx * R0;

	Mat3 temp_mat, R_ref;

	mat3Multiply(R0, Ry, temp_mat);
	mat3Multiply(temp_mat, Rz, R_ref);

	matrixToQuat(R_ref, &q_ref);
	quaternion_correction(&curr_attitude, &q_ref);

	quaternion_t dq; // dq = q_ref - q_curr
	dq.w = q_ref.w - curr_attitude.w;
	dq.x = q_ref.x - curr_attitude.x;
	dq.y = q_ref.y - curr_attitude.y;
	dq.z = q_ref.z - curr_attitude.z;


	// esentially using that dq = M(omega) * q, it can be also done with deviation but this is faster to implement

	float p_delta, q_delta, r_delta;

	p_delta = 2 * (-curr_attitude.x * dq.w + curr_attitude.w * dq.x + curr_attitude.z * dq.y - curr_attitude.y * dq.z);
	q_delta = 2 * (-curr_attitude.y * dq.w - curr_attitude.z * dq.x + curr_attitude.w * dq.y + curr_attitude.x * dq.z);
	r_delta = 2 * (-curr_attitude.z * dq.w + curr_attitude.y * dq.x - curr_attitude.x * dq.y + curr_attitude.w * dq.z);

	curr_reference->ax_ref = curr_esp32_commands.ax_command;
	curr_reference->p_ref = p_delta + curr_esp32_commands.p_command;
	curr_reference->pitch_ref = q_delta;
	curr_reference->yaw_ref = r_delta;
}
