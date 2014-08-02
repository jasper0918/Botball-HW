// Created on Sun July 27 2014

int main()
{
	set_analog_pullup(1, 0);
	printf("value:\t%d", get_analog_pullup(1));
	msleep(2000);
	int a;
	printf("value:\t%d\t%d\t%d", get_analog_pullup(1), analog_et(1), get_analog_pullup(1));
	msleep(2000);
	while(1){
		int etread = analog_et(1);
		printf("value:\t%d\t%d", get_analog_pullup(1), etread);
		msleep(50);
		display_clear();
	}
	return 0;
}
