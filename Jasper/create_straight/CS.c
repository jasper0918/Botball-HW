// Created on Fri August 1 2014

int main()
{
	create_connect();
	create_full();
	create_drive_direct(-500, -500);
	while(!(a_button_clicked()));
	return 0;
}
