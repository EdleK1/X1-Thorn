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


static const Vec3 VEC_X_WORLD = { 0.0f, 0.0f, 1.0f };
static uint8_t active;
esp32_commands_t curr_esp32_commands;

void GroundCommands_Init(void)
{
	esp32_Init();
}


uint8_t get_reference(const quaternion_t *curr_attitude, reference_t *curr_reference)
{
	Vec3 vec_y_world, vec_z_world, vec_y_aircraft;

	quaternion_t q_ref;
	Mat3 Rx, Ry, Rz, R0;

	vec_y_aircraft[0] = 2.0f*(curr_attitude->x*curr_attitude->y - curr_attitude->w*curr_attitude->z);
	vec_y_aircraft[1] = 1.0f - 2.0f*(curr_attitude->x*curr_attitude->x + curr_attitude->z*curr_attitude->z);
	vec_y_aircraft[2] = 2.0f*(curr_attitude->y*curr_attitude->z + curr_attitude->w*curr_attitude->x);

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

	active = get_esp32_commands(&curr_esp32_commands);


	if (active != 1)
	{
		matrixToQuat(R0, &q_ref);

		curr_reference->ax_ref = -0.5;
		curr_reference->p_ref = 0;
		curr_reference->q0_ref = q_ref.w;
		curr_reference->q1_ref = q_ref.x;
		curr_reference->q2_ref = q_ref.y;
		curr_reference->q3_ref = q_ref.z;
	}

	else
	{
		rot_x_mat(Rx, -curr_esp32_commands.roll_command);
		rot_y_mat(Ry, curr_esp32_commands.pitch_command);
		rot_z_mat(Rz, curr_esp32_commands.p_command/2); // el 2 s'ha de tunejar

		// R_ref = Ry * Rx * Rz * R0;

		Mat3 temp_mat1, temp_mat2, R_ref;

		mat3Multiply(Ry, Rx, temp_mat1);
		mat3Multiply(R0, temp_mat1, temp_mat2);
		mat3Multiply(Rz, temp_mat2, R_ref);

		matrixToQuat(R_ref, &q_ref);
		quaternion_correction(curr_attitude, &q_ref);

		curr_reference->ax_ref = curr_esp32_commands.ax_command;
		curr_reference->p_ref = curr_esp32_commands.p_command;
		curr_reference->q0_ref = q_ref.w;
		curr_reference->q1_ref = q_ref.x;
		curr_reference->q2_ref = q_ref.y;
		curr_reference->q3_ref = q_ref.z;
	}

	return active;

}
