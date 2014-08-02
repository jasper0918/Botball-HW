// Created on Fri August 1 2014

void test();

int main()
{
	enable_servos();
	set_servo_position(0, 1050);
	set_servo_position(3, 0);
	set_servo_position(1, 0);
	//wait_for_light();
	//shut_down_in(120);
	msleep(500);
	set_servo_position(3, 1750);
	clear_motor_position_counter(2);
	clear_motor_position_counter(3);
	mtp(2, 970, 2350);
	mtp(3, 1000, 2350);
	bmd(2);
	bmd(3);
	ao();
	set_servo_position(1, 1800);
	set_servo_position(0, 0);// close claw
	msleep(2000);
	clear_motor_position_counter(2);
	clear_motor_position_counter(3);
	mtp(2, 970, -300);
	mtp(3, 1000,-300);
	bmd(2);
	bmd(3);
	set_servo_position(3, 0);
	msleep(5000);
	test();
	//get botguy
	clear_motor_position_counter(2);
	clear_motor_position_counter(3);
	mtp(2, 880, -300);
	mtp(3, 1000, 325);
	bmd(2);
	bmd(3);
	test();
	//face cube
	clear_motor_position_counter(2);
	clear_motor_position_counter(3);
	mtp(2, 880, 2000);
	mtp(3, 1000, 2000);
	bmd(2);
	bmd(3);
	test();
	//move cube
	clear_motor_position_counter(2);
	clear_motor_position_counter(3);
	mtp(2, 880, 300);
	mtp(3, 1000, -325);
	bmd(2);
	bmd(3);
	test();
	//turn cube
	clear_motor_position_counter(2);
	clear_motor_position_counter(3);
	mtp(2, 880, 1800);
	mtp(3, 1000, 1800);
	bmd(2);
	bmd(3);
	test();
	//place cube
	set_servo_position(3, 1750);
	return 0;
}

void test(){
	ao();
	while(digital(15) == 0);
}
