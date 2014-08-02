// Created on Sun July 27 2014

#define TEST
#define CONFIG	"color.config"

// constants: --------------------------------------------------

// all ports:
const int LM = 0; 		// lift motor
const int RSV = 2; 		// rotating servo
const int BSV = 1; 		// bigger servo claw
const int SSV = 3; 		// smaller servo claw
const int FSS = 7;	 /*// front tophat
const int RSS = 2 ;	*/	// right tophat
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
const int RSV_SET_EXT = 1400;

// sensor const:
const int FSS_WHITE = 300;		// white for infrared sensors
const int FSS_BLACK = 960;		// black for infrared sensors
const int FSS_OFFSET = 630;	// mid value of white and black for infrared sensors

// motor const:
const int LM_BOTGUY_UP = 2000;
const int LM_BOTGUY_DOWN = 250;
const int LM_BC_UP = 0;
const int LM_BC_DOWN = 0;
const int LM_SC_UP = 1750;
const int LM_SC_DOWN = 0;
const int LM_EXT_UP = 400;
const int LM_EXT_DOWN = 0;

// color channel:
const int PINK = 0; 		// pink ball
const int GREEN = 1;	// green ball
const int ORANGE = 2;	// orange cube
const int YELLOW = 3;	// yellow cube
const int RED = 4;			// botguy
const int BLUE = 5;		// blue cube

// function list:
void prepare();
void test();
void exeBotguy();
void turnRight();
void findLine();
void turnLeft();
void findBench();
void setBench();
void wait1();
void findBotguy();
void getBotguy();
void setBotguy();
void moveBotguy();
void wait2();


// mainbody: --------------------------------------------------

int main()
{
	prepare();
	
	exeBotguy();
	
	return 0;
}

void exeBotguy(){
	
	turnRight();
	test();
	
	findLine();
	test();
	
	turnLeft();
	test();
	
	findBench();
	test();
	
	setBench();
	test();
	
	wait1();/*
	findBotguy();
	getBotguy();
	setBotguy();
	moveBotguy();
	wait2();*/
	
}


// functions:  --------------------------------------------------
 
// prepare:
void prepare(){
	create_disconnect();
	msleep(1000);
	create_connect();
	msleep(1000);
	printf("create connect successfully!");
	camera_open(LOW_RES);
	camera_load_config(CONFIG);
	clear_motor_position_counter(LM);
}

// turn right:
void turnRight(){
	mtp(LM, 1500,LM_EXT_UP);
	create_clear_serial_buffer();
	while(get_create_normalized_angle() > 269){
		create_spin_CW(150);
	}
	bmd(LM);
}

// find the line:
void findLine(){
	while(analog(FSS) < FSS_OFFSET){
		create_drive_straight(350);
	}
	create_drive_straight(350);
	msleep(500);
	create_stop();
}

// turn left:
void turnLeft(){
	create_clear_serial_buffer();
	while(get_create_normalized_angle() > -90){
		create_spin_CW(150);
	}
}

// find the bench:
void findBench(){
	create_clear_serial_buffer();
	while(get_create_distance() < 1700){
		create_drive_straight(-350);
	}
}

// set the bench:
void setBench(){
	mtp(LM, 1000,LM_EXT_DOWN);
	msleep(500);
}

// wait the first:
void wait1(){
	create_clear_serial_buffer();
	while(get_create_normalized_angle() > -45){
		create_spin_CW(150);
	}
	create_clear_serial_buffer();
	while(get_create_distance() < 1700){
		create_drive_straight(-350);
	}
	ao();
}

// find the BOTGUY:
void findBotguy(){
	
}

// get the BOTGUY:
void getBotguy(){
	
}

// set the BOTGUY:
void setBotguy(){
	
}

// move the BOTGUY:
void moveBotguy(){
	
}

// wait the second:
void wait2(){
	
}

// test:
void test(){
	ao();
	create_stop();
	create_clear_serial_buffer();
	msleep(3000);
}













