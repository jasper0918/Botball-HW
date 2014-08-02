// Created on Fri August 1 2014

const int ASV = 3;

const int TSS = 15;	// TEST touch sensor

const int ASV_UP = 1400;
const int ASV_DOWN = 400;

const int TIME_LIMIT = 120;

void prepare();
void setSlope();
void moveStraight(int speed, int distance);
void test();
int main()
{
	prepare();
	setSlope();
	while(!(a_button_clicked()));
	return 0;
}

void prepare(){
	create_connect();
	create_full();
	printf("create connected!\n");
	enable_servos();
	set_servo_position(ASV, ASV_UP);
	printf("servos all set");
	test();
	//wait_for_light(LSS);
	//shut_down_in(TIME_LIMIT);
}

void setSlope(){
	moveStraight(-500,-350);
	test();
	set_servo_position(ASV, ASV_DOWN);
	msleep(500);
	test();
	moveStraight(500,200);
	test();
	set_servo_position(ASV, ASV_UP);
	msleep(500);
	moveStraight(-500, -300);
	moveStraight(500, 100);
	
	while(get_create_cwdrop() == 0)
			create_drive_direct(-500, -500);
	test();
	moveStraight(-500,-50);
}

void moveStraight(int speed, int distance){
	set_create_distance(0);
	create_drive_direct(speed, speed);
	if(distance > 0)
		while(get_create_distance() < distance);
	else
		while(get_create_distance() > distance);
	create_stop();
}

void test(){
	create_stop();
	display_clear();
	printf("step finished");
	while(digital(TSS) == 0);
	msleep(1000);
}
