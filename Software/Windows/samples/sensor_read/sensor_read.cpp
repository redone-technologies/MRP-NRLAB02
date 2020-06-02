#include <stdio.h>
#include "libnrlab02.h"

#pragma comment(lib, "libnrlab02d.lib")
int main(void)
{
	NRLAB_State r;
	char addr[25] = { "192.168.1.100" };
	if (SUCCESS != NWrite_EnableNetwork(addr))
	{
		printf("Connection failed.");
		return 0;
	}

	T_SENSOR_DATA sensor;

	int dorun = 10;
	while (dorun--)
	{
		r = SRead_SensorData(sensor);
		if (r != SUCCESS)
		{
			printf("SRead_SensorData() failed : %d\n", r);
			return 0;
		}
		printf("=================\n");
		printf("psd   : %d, %d, %d, %d, %d, %d, %d [cm]\n", sensor.psd[0], sensor.psd[1], sensor.psd[2], sensor.psd[3], sensor.psd[4], sensor.psd[5], sensor.psd[6]);
		printf("accel : %.4f, %.4f, %.4f\n", sensor.ax, sensor.ay, sensor.az);
		printf("gyro  : %.4f, %.4f, %.4f\n", sensor.gx, sensor.gy, sensor.gz);
		printf("mag   : %.4f, %.4f, %.4f\n", sensor.mx, sensor.my, sensor.mz);
		printf("attitude : %.4f, %.4f, %.4f, %.4f\n", sensor.x, sensor.y, sensor.z, sensor.w);

		Sleep(10);
	}

	NWrite_DisableNetwork();
	return 0;
}