// Created on Fri August 1 2014

int main()
{
	create_connect();
	create_full();
	while(digital(15) == 0);
	create_drive_direct(-1500, -1500);
	while(!(a_button_clicked()));
	return 0;
}
