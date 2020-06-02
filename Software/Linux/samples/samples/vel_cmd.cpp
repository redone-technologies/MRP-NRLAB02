#include "libnrlab02.h"




int main(void)
{
	NRLAB_State r;
	char addr[25] = {"192.168.1.100"};
	if( SUCCESS != NWrite_EnableNetwork(addr))
	{
		printf("Connection failed.");
		return 0;
	}
	float tv = 0.1;
	float rv = 0;
	float rtv = 0;
	float rrv = 0;

	r = RWrite_SetMaxLineSpeed(1.0);
	if(r == SUCCESS)
		printf("set max line speed \n");
	else
		printf("set max line speed error : %d\n",r);

	int repeat = 5;
	while(repeat)
	{
		tv += 0.0002;
		if(tv > 0.5)
		{
			tv = 0.1;
			repeat--;
		}
		RRead_2W_Kinematics(rtv, rrv);
		if(RWrite_2W_Kienmatics(tv, rv) == SUCCESS)
		{
			printf("set vel : %.4f, %.4f / get vel : %.4f, %.4f\n", tv, rv, rtv, rrv);
		}
		else
		{
			printf("RWrite_2W_Kienmatics() failed\n");
			return 0;
		}
		usleep(10000);
	}
	MWrite_MotorStop();
	NWrite_DisableNetwork();
	printf("end\n");
	return 0;
}
