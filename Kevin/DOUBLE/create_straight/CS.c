// Created on Fri August 1 2014

int main()
{
	create_connect();
	create_full();
	while(digital(15) == 0);
	msleep(1000);
	create_drive_direct(-1500, -1500);
	while(1 == 1);
	//while(digital(15) == 0);
	create_stop();
	return 0;
}
