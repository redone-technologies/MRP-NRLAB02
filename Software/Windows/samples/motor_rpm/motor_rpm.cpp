#include <stdio.h>
#include "libnrlab02.h"

#pragma comment(lib, "libnrlab02d.lib")
int main(void)
{
	char addr[25] = { "192.168.1.100" };
	if (SUCCESS != NWrite_EnableNetwork(addr))
	{
		printf("Connection failed.");
		return 0;
	}

	int motor_l = 1000;
	int motor_r = -1000;

	int read_l = 0;
	int read_r = 0;

	int op_time = 1000; //10s = (count 1000) * (sleep 10ms)
	while (op_time--)
	{
		MRead_MotorVelocity(read_l, read_r);
		if (MWrite_MotorVelocity(motor_l, motor_r) == SUCCESS)
		{
			printf("set rpm : %d, %d / get rpm : %d, %d\n", motor_l, motor_r, read_l, read_r);
		}
		else
		{
			printf("MWrite_MotorVelocity() failed\n");
			return 0;
		}
		Sleep(10);
	}
	MWrite_MotorStop();
	NWrite_DisableNetwork();
	printf("end\n");
	return 0;
}
