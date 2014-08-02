// Created on Sun July 27 2014

#define TEST
#define CONFIG	"color.config"

#define TEST
#define CONFIG	"color.config"

// constants:
// all ports:
const int LM = 0; 		// lift motor
const int RSV = 2; 		// rotating servo
const int BSV = 3; 		// bigger servo claw
const int SSV = 1; 		// smaller servo claw
const int FSS = 7;	 	// front tophat
//const int RSS = 2;		// right tophat
const int SSS = 1; 		// start sensor
const int TSS = 8;		// touch sensor


// servo const:
const int BSV_OPEN = 2047; 
const int BSV_CLOSE = 0;
const int SSV_OPEN = 700; 
const int SSV_CLOSE = 0;
const int RSV_BCUP = 0; 
const int RSV_SCUP = 2047;
const int RSV_LEVEL = 1028;
const int RSV_SET_EXT = 1600;

// sensor const:
const int FSS_WHITE = 400;		// white for infrared sensors
const int FSS_BLACK = 970;		// black for infrared sensors
const int FSS_OFFSET = 685;		// mid value of white and black for infrared sensors

// motor const:
const int LM_START = 800;
const int LM_BOTGUY_UP = 2000;
const int LM_BOTGUY_DOWN = 0;
const int LM_BC_UP = 0;
const int LM_BC_DOWN = 0;
const int LM_SC_UP = 1600;
const int LM_SC_DOWN = 0;
const int LM_EXT_UP = 1700;
const int LM_EXT_DOWN = -100;

// color channel:
const int PINK = 0; 		// pink ball
const int GREEN = 1;		// green ball
const int ORANGE = 2;		// orange cube
const int YELLOW = 3;		// yellow cube
const int RED = 4;			// botguy
const int BLUE = 5;			// blue cube

// function list:
void prepare();
void stop();
void test();

void exeBotguy();
void turnRight();
void turnLeft();
void turnHalfRight();
void turnHalfLeft();
void getCubes();
void setCubes();

int main()
{
	prepare();
	test();
	exeBotguy();
	getCubes();
	setCubes();
	
	stop();
	return 0;
}

void prepare(){
	create_disconnect();
	msleep(1000);
	create_connect();
	msleep(1000);
	printf("create connect successfully!");
	camera_open(LOW_RES);
	camera_load_config(CONFIG);
	camera_update();
	camera_update();
	
	enable_servos();
	set_servo_position(BSV, BSV_CLOSE);
	set_servo_position(SSV, SSV_CLOSE);
	set_servo_position(RSV, RSV_LEVEL);
	
	clear_motor_position_counter(LM);
	mtp(LM, 1500, LM_START);
	bmd(LM);
}

void stop(){
	create_stop();
	create_disconnect();
	disable_servos();
	camera_close();
}
void test(){
	create_stop();
	while(!(a_button_clicked()));
	msleep(500);
}
void exeBotguy(){
	mtp(LM, 1500, LM_EXT_UP);
	while(get_create_lbump() == 0 && get_create_rbump() == 0)
		create_drive_straight(100);
	bmd(LM);
	ao(LM);
	#ifdef TEST
	test();
	#endif
	turnRight();
	create_drive_straight(-100);
	msleep(1000);
	#ifdef TEST
	test();
	#endif
	analog(FSS);
	while(analog(FSS) < FSS_OFFSET)
		create_drive_straight(100);
	create_stop();
	#ifdef TEST
	test();
	#endif
	create_drive_straight(200);
	msleep(900);
	while(analog(FSS) < FSS_OFFSET)
		create_spin_CW(100);
	while(analog(FSS) < FSS_OFFSET)
		create_spin_CCW(80);
	#ifdef TEST
	test();
	#endif
	create_drive_straight(-200);
	msleep(1000);
	#ifdef TEST
	test();
	#endif
	mtp(LM, 1500, LM_EXT_DOWN);
	bmd(LM);
	#ifdef TEST
	test();
	#endif
	create_drive_straight(-200);
	msleep(1000);
	turnHalfLeft();
	#ifdef TEST
	test();
	#endif
	set_servo_position(RSV, RSV_SET_EXT);
	msleep(1000);
	// set extension
	
	#ifdef TEST
	test();
	#endif
	set_servo_position(RSV, RSV_SCUP);
	mtp(LM, 1500, LM_BOTGUY_DOWN);
	bmd(LM);
	#ifdef TEST
	test();
	#endif
	turnHalfRight();
	turnRight();
	#ifdef TEST
	test();
	#endif
	set_servo_position(BSV, BSV_OPEN);
	while(digital(TSS) == 0)
		create_drive_straight(-200);
	#ifdef TEST
	test();
	#endif
	set_servo_position(BSV, BSV_CLOSE);
	msleep(1500);
	#ifdef TEST
	test();
	#endif
	create_drive_straight(200);
	msleep(2000);
	turnLeft();
	turnLeft();
	#ifdef TEST
	test();
	#endif
	set_servo_position(RSV, RSV_LEVEL);
	create_drive_straight(-200);
	msleep(1000);
	#ifdef TEST
	test();
	#endif
	set_servo_position(BSV, BSV_OPEN);
	msleep(2000);
	#ifdef TEST
	test();
	#endif
}
void turnRight(){
	create_spin_CW(100);
	msleep(2000);
}
void turnLeft(){
	create_spin_CCW(100);
	msleep(2000);
}
void turnHalfRight(){
	create_spin_CW(100);
	msleep(1000);
}
void turnHalfLeft(){
	create_spin_CCW(100);
	msleep(1000);
}
void getCubes(){
}
void setCubes(){
}
