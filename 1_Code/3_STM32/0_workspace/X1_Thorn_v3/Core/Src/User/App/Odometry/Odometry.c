/**
  ******************************************************************************
  * @file           : Odometry.c
  * @brief          : Read data from the BNO055 sensor and convert it to acceleration, orientation and velocity of the CG
  *
  *
  * ax, p, q, r, q0, q1, q2, q3
  ******************************************************************************
*/


#include "../../App/Odometry/Odometry.h"
#include "../../Peripheral/BNO055/BNO055.h"



BNO055_Sensors_t BNO055;
uint8_t OffsetDatas[22];
odometry_t Curr_Read;

void Sensor_Init(void);






void Odometry_Init(void)
{

	Sensor_Init();

}



void Odometry_Read(odometry_t *Curr_Read)
{

	// Read from sensor

	ReadData(&BNO055, SENSOR_LINACC|SENSOR_GYRO|SENSOR_QUATERNION);

	Curr_Read->ax = BNO055.LineerAcc.X;
	Curr_Read->p = BNO055.Gyro.X;
	Curr_Read->q = BNO055.Gyro.Y;
	Curr_Read->r = BNO055.Gyro.Z;
	Curr_Read->q0 = BNO055.Quaternion.W;
	Curr_Read->q1 = BNO055.Quaternion.X;
	Curr_Read->q2 = BNO055.Quaternion.Y;
	Curr_Read->q3 = BNO055.Quaternion.Z;

}



void Sensor_Init(void)
{

	BNO_Status_t Status = {0};

		//Init structure definition section
		BNO055_Init_t BNO055_InitStruct = {0};

		//Reset section
		ResetBNO055();

		/*============================ *BNO055 Initialization* ============================*/

		BNO055_InitStruct.ACC_Range = Range_4G;			//Range_X
		BNO055_InitStruct.Axis = DEFAULT_AXIS_REMAP;			//value will be entered by looking at the data sheet
		BNO055_InitStruct.Axis_sign = 0x3;						//value will be entered by looking at the data sheet - Y and Z must have switched signs
		BNO055_InitStruct.Clock_Source = CLOCK_EXTERNAL;		//CLOCK_EXTERNAL or CLOCK_INTERNAL
		BNO055_InitStruct.Mode = BNO055_NORMAL_MODE;			//BNO055_X_MODE   X:NORMAL, LOWPOWER, SUSPEND
		BNO055_InitStruct.OP_Modes = NDOF;
		BNO055_InitStruct.Unit_Sel = (UNIT_ORI_ANDROID | UNIT_TEMP_CELCIUS | UNIT_EUL_DEG | UNIT_GYRO_RPS | UNIT_ACC_MS2);
										//(UNIT_ORI_X | UNIT_TEMP_X | UNIT_EUL_X | UNIT_GYRO_X | UNIT_ACC_X)
		BNO055_Init(BNO055_InitStruct);

		//------------------BNO055 Calibration------------------

		/*This function allows the sensor offset data obtained after BNO055 is calibrated once to be written
		 *to the registers. In this way, there is no need to calibrate the sensor every time it is powered on.
		 */

		//setSensorOffsets(OffsetDatas);

		/*-=-=-=-=-=-=Calibration Part-=-=-=-=-=-=*/

//		if(Calibrate_BNO055())
//		{
//			getSensorOffsets(OffsetDatas);
//		}
//		else
//		{
//			printf("Sensor calibration failed.\nFailed to retrieve offset data\n");
//		}
//
//		Check_Status(&Status);
//		printf("Selftest Result: %d\t",Status.STresult);
//		printf("System Status: %d\t",Status.SYSStatus);
//		printf("System Error: %d\n",Status.SYSError);

}
