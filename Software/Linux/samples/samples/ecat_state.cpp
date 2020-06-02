#include "libnrlab02.h"

int main(void)
{
	char addr[20] = {"192.168.1.100"};
	if( SUCCESS != NWrite_EnableNetwork(addr))
	{
		printf("Connection failed.");
		return 0;
	}

	usleep(100000);

	NRLAB_State r;
	unsigned char num = 0, state = 0;
	int accel = 0;
	float maxls = 0;

	printf("---------------------------------\n");
	float setSpeed = 0.3;
	r = RWrite_SetMaxLineSpeed(setSpeed);
	if(r == SUCCESS)
		printf("set max line speed : %f\n",setSpeed);
	else
		printf("set max line speed error : %d\n",r);
	

	int setAccel = 2000;
	MWrite_SetProfileAcceleration(setAccel);
	if(r == SUCCESS)
		printf("set accel : %d\n",setAccel);
	else
		printf("set accel error : %d\n",r);

	usleep(50000);
	int count = 5;
	while(count--)
	{
		printf("---------------------------------\n");
		num = 0;
		r = NRead_RobotDeviceNum(num);
		if(r == SUCCESS)
			printf("[Test #%d] ecat num : %d\n", count, num);
		else
		{
			printf("[Test #%d] ecat num error : [%d] %d\n",count, r, num);
			return 0;
		}

		state = 0;
		r = NRead_RobotDeviceState(state);
		if(r == SUCCESS)
			printf("[Test #%d] ecat state : %d\n",count, state);
		else
		{
			printf("[Test #%d] ecat state error : [%d] %d\n",count, r, state);
			return 0;
		}

		accel = 0;
		r = MRead_GetProfileAcceleration(accel);
		if(r == SUCCESS)
			printf("[Test #%d] accel  : %d\n",count, accel);
		else
			printf("[Test #%d] accel  error : [%d] %d\n",count, r, accel);

		maxls = 0;	
		r = RRead_GetMaxLineSpeed(maxls);
		if(r == SUCCESS)
			printf("[Test #%d] maxls  : %f\n",count, maxls);
		else
			printf("[Test #%d] maxls  error : [%d] %f\n",count, r, maxls);

		usleep(10000);
	}

	printf("end\n");
	return 0;
}