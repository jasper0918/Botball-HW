// Created on Fri August 1 2014

int main()
{
	create_connect();
	create_full();
	create_drive_direct(200, 200);
	while(get_create_lbump() == 0 || get_create_rbump() == 0);
	create_stop();
	create_disconnect();
	return 0;
}
