// Created on Fri August 1 2014

const int LM = 2;
const int RM = 3;

const int CLAW = 0;
const int ARM = 3;
const int BACK = 1;

const int LM_S = 750;
const int RM_S = 1000;

void test();

int main()
{
	enable_servos();
	set_servo_position(CLAW, 1050);
	set_servo_position(ARM, 0);
	set_servo_position(BACK, 1600);
	
//wait_for_light(1);
	shut_down_in(120);
	set_servo_position(ARM, 1750);
	clear_motor_position_counter(LM);
	clear_motor_position_counter(RM);
	mtp(LM, LM_S, 2500);
	mtp(RM, RM_S, 2550);
	bmd(RM);
	ao();
	set_servo_position(BACK, 1800);
	set_servo_position(CLAW, 0);// close claw
	msleep(1);
	clear_motor_position_counter(LM);
	clear_motor_position_counter(RM);
	mtp(LM, LM_S, -300);
	mtp(RM, RM_S,-300);
	bmd(LM);
	bmd(RM);
	set_servo_position(ARM, 0);
	msleep(1500);
	
	//get botguy
	clear_motor_position_counter(LM);
	clear_motor_position_counter(RM);
	mtp(LM, LM_S, -370);
	mtp(RM, RM_S, 325);
	bmd(LM);
	bmd(RM);
	
	//face cube
	clear_motor_position_counter(LM);
	clear_motor_position_counter(RM);
	mtp(LM, LM_S, 4000);
	mtp(RM, RM_S, 4000);
	bmd(LM);
	bmd(RM);
	test();
	//move cube
	set_servo_position(ARM, 1750);
	msleep(32767);
	msleep(32767);
	msleep(32767);
	msleep(32767);
	msleep(32767);
	msleep(32767);
	return 0;
}

void test(){
	ao();
	while(digital(15) == 0);
}
