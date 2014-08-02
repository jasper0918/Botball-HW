// Created on Wed July 30 2014

//#define TEST

// constants:
// move:
const long int TURN_90 = 190000;	// distance for create to turn 90o

// motor:
const int LM = 1;	// lift motor

const int LM_UP = 1000;		// motor speed when lifting up
const int LM_DOWN = -500;	// motor speed when dropping down

// servo:
const int BSV = 1;	// bottom servo
const int USV = 0;	// upper servo
const int SSV = 3;	// small servo

const int BSV_OPEN = 1500;		// bottom servo/claw opens
const int BSV_CLOSE = 300;	// bottome servo/claw closes

const int USV_DOWN = 50;
const int USV_UP = 2047;		// upper servo/arm rises up
const int USV_UP2 = 1950;		// upper servo/arm rises up

const int USV_LEVEL = 1100;	// upper servo/arm keeps level

const int SSV_DOWN = 100;	// small servo closes extended arm
const int SSV_UP = 2047;		// small servo opens extended arm
const int SSV_UP2 = 1950;		// small servo opens extended arm

// sensor:
// analog:
const int LSS = 1;	// light sensor
const int FSS = 3;	// front infrared sensor

const int FSS_WHITE = 40;
const int FSS_BLACK = 1000;
const int FSS_MID = 600;	// special values for front sensor
//digital:
const int BSS = 11;	// bottom touch sensor
const int USS = 13;	// upper touch sensor
const int MSS = 12;	// middle touch sensor
const int CSS = 15;	// claw touch sensor
const int TSS = 10;	// TEST touch sensor


const int SS_UNTOUCHED = 0;	// touch sensor untouched
const int SS_TOUCHED = 1;	// touch sensor touched

// other:
const int TIME_LIMIT = 120;	// limited time for competition

// function list:
// TEST:
void test();

// prepare:
void prepare();

// move:
void turnLeft(int speed);
void turnRight(int speed);
void moveStraight(int speed, int distance);

// process:
void setBench();
void getBotguy();
void setHangers();
void setBotguy();

int main()
{
	prepare();
	
	#ifdef TEST
	test();
	#endif
	setBench();
	
	#ifdef TEST
	test();
	#endif
	//getBotguy();
	
	#ifdef TEST
	test();
	#endif
	//setHangers();
	
	#ifdef TEST
	test();
	#endif
	//setBotguy();
	
	return 0;
}

void test(){
	motor(LM, 0);
	create_stop();
	display_clear();
	printf("step finished");
	while(digital(TSS) == 0);
	msleep(1000);
}

void prepare(){
	create_connect();
	//reate_full();
	printf("create connected!\n");
	enable_servos();
	set_servo_position(BSV, BSV_OPEN);
	set_servo_position(USV, USV_DOWN);
	set_servo_position(SSV, SSV_DOWN);
	printf("servos all set");
	wait_for_light(LSS);
	shut_down_in(TIME_LIMIT);
}

void turnLeft(int speed){
	int time = TURN_90 / speed;
	create_spin_CCW(speed);
	msleep(time);
}

void turnRight(int speed){
	int time = TURN_90 / speed;
	create_spin_CW(speed);
	msleep(time);
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

void setBench(){
	clear_motor_position_counter(LM);
	mtp(LM, 1500, 600);
	bmd(LM);
	off(LM);
	// ready to catch
	moveStraight(-200, -130);
	turnLeft(200);
	//test();
	// get out starting box
	while(analog(FSS) < FSS_MID)
	create_drive_direct(300, 300);
	
	moveStraight(200, 185);
	turnLeft(200);
	
	moveStraight(300, 450);
	test();
	turnLeft(150);
	test();
	moveStraight(500, 260);
	// set bench
	create_stop();
	//msleep(5000);
}

void getBotguy(){
	//set_servo_position(USV, USV_UP);
	//msleep(1000);
	// ready for hangers
	
	test();
	while(digital(CSS) == SS_UNTOUCHED)
		create_drive_direct(-200, -200);
	create_stop();
	set_servo_position(BSV, BSV_CLOSE);
	msleep(500);
	create_stop(); 
}

void setBotguy(){
	test();
	moveStraight(300, 400);
	while(digital(USS) == SS_UNTOUCHED)
		motor(LM, LM_UP);
	motor(LM, 0);
	// rise botguy
	turnRight(200);
	turnRight(200);
	test();
	moveStraight(-300, -300);
	
	clear_motor_position_counter(LM);
	mtp(LM, LM_DOWN, -550);
	bmd(LM);
	off(LM);
	// set botguy on bench
	test();
	turnRight(200);
	test();
	moveStraight(-200, -500);
	// move to final position
}

