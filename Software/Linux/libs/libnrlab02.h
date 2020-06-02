#ifndef __LIBNRLAB02_H_
#define __LIBNRLAB02_H_

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>
#include <sched.h>
#include <string.h>
#include <time.h>
#include <pthread.h>
#include <math.h>
#include <sys/fcntl.h>
#include <sys/stat.h>
#include <termios.h>
#include <sys/un.h>
#include <sys/ioctl.h>
#include <errno.h>
#include <sys/fcntl.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>


#define MODE_OF_JOYSTICK				1
#define MODE_OF_REMOTE_MOTOR_CONTROL	2
#define MODE_OF_REMOTE_MOTION_CONTROL	3
#define MODE_OF_REMOTE_POSITION_CONTROL	4

typedef enum 
{
	SUCCESS						 = 0,
	CONNECTIONSTATE_CONNECTED	 = 1,	
	CONNECTIONSTATE_FAULTED		 = 2,
	OUT_OF_RANGE				 = 3,
	ETHERCAT_FAULTED			 = 4
}NRLAB_State;



typedef struct 
{
	unsigned short 	psd[7];		// [cm] psd distance 
	double 	x;					// Attitude Quaternion x
	double 	y;					// Attitude Quaternion y
	double 	z;					// Attitude Quaternion z
	double 	w;					// Attitude Quaternion w
	double 	ax;					// accel_x
	double 	ay;					// accel_y
	double 	az;					// accel_z
	double 	gx;					// gyro_x
	double 	gy;					// gyro_y
	double 	gz;					// gyro_z
	double 	mx;					// magnet_x
	double 	my;					// magnet_y
	double 	mz;					// magnet_z
	double 	temp;				// temperature
}T_SENSOR_DATA;


NRLAB_State NWrite_EnableNetwork(char* ip);
NRLAB_State NWrite_DisableNetwork();
NRLAB_State NRead_RobotDeviceNum(unsigned char &num);
NRLAB_State NRead_RobotDeviceState(unsigned char &state);


NRLAB_State MWrite_SetProfileAcceleration(int accel);	//+1000 ~ +3000
NRLAB_State MRead_GetProfileAcceleration(int &accel);	
NRLAB_State MWrite_MotorVelocity(int vell, int velr);	//-2500 ~ +2500
NRLAB_State MWrite_MotorStop();

NRLAB_State RWrite_SetMaxLineSpeed(float maxls);		//+0.1 ~ +1.18
NRLAB_State RWrite_2W_Kienmatics(float tv, float rv);
NRLAB_State RWrite_StopDrive();


NRLAB_State RRead_GetMaxLineSpeed(float &maxls);
NRLAB_State MRead_MotorVelocity(int &vell, int &velr);
NRLAB_State MRead_MotorPosition(int &posl, int &posr);
NRLAB_State RRead_2W_Kinematics(float &tv, float &rv);
NRLAB_State SRead_SensorData(T_SENSOR_DATA &data);



#endif