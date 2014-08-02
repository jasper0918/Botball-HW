// Created on Fri August 1 2014

int main()
{
	create_connect();
	create_full();
	while(!(a_button_clicked())){
		display_clear();
		printf("cw:%d\nlw:%d\nrw:%d\n", get_create_cwdrop(), get_create_lwdrop(), get_create_rwdrop());
		msleep(20);
	}
	return 0;
}
