// Created on Sat July 19 2014, First Version

#define TEST
#define CONFIG "color.config"

// contants:
// motor ports:
const int LM = 3;// left motor
const int RM = 1;// right motor
const int FM = 2;// front motor

// servo ports:
const int BSV = 2;	// box servo
const int ASV = 1;	// arm servo
const int RSV = 3;	// rotator servo
const int SSV = 0;	// small servo

// sensor ports:
const int LSS = 0;	// left infrared sensor
const int RSS = 1;	// right infrared sensor
const int SSS = 2;	// start light sensor
const int LSS_LINE_TIME = 2000; // the time of going along the line

// color channel:
const int PINK = 0;		// pink ball
const int GREEN = 1;	// green ball
const int ORANGE = 2;	// orange cube
const int YELLOW = 3;	// yellow cube
const int RED = 4;		// botguy
const int BLUE = 5;		// blue cube

// motor constants:
const int FM_COLLECT = 100;		// front motor collects balls
const int FM_RELEASE = -100;	// front motor releases balls

// vision constant:
const int OFFSET_X = 74;	// standard x coordinate to catch a ball
const int OFFSET_Y = 63;	// standard y coordinate to catch a ball

// sensor constant:
const int WHITE = 1024;	// white for infrared sensors
const int BLACK = 0;	// black for infrared sensors
const int OFFSET = 512;	// mid value of white and black for infrared sensors

// servo constants:
const int BSV_LEVEL = 1800;			// box servo keeps level
const int BSV_DROP = 900; 		// box servo drops balls
const int BSV_DROP_TIME = 1500;	// box servo time staying to drop balls

const int ASV_BACK = 600;		// arm servo keeps back
const int ASV_CATCH = 2047;		// arm servo catches ball
const int ASV_CHECK = 1000;		// arm servo rises for check

const int RSV_DOWN = 1500;			// rotator servo keeps down
const int RSV_UP = 1150;			// rotator servo rises up
const int RSV_UP_DIS = 2000;	// rotator servo distance keeping up to get over boundary

const int SSV_BACK = 200;			// small servo keeps back
const int SSV_PUSH = 1050;			// small servo pushes ball out
const int SSV_GUARD = 750;          // small servo gurad balls
const int SSV_CHECK_TIME = 2000;    // small servo time staying for checking balls 

// conditions constants:
const int SEE_BALL = 0;		// when camera sees target balls
const int SEE_LINE = 1;		// when a infrared sensor sees a black line

// collector constants:
const int BOX = 0;		// box on the back
const int ROTATOR = 1;	// rotator in the front

// other constants:
const int BUTTON_CLICKED = 1;	// return value when button is clicked
const int TIME_LIMIT = 120;		// time limit

// function list:
// prepare:
void prepare();

// move to:
void moveToFisrtBalls();
void moveToSecondBalls();
void moveToThirdBalls();
void moveToFourthBalls();
void moveToFirstArea();
void moveToSecondArea();

// stop:
void stop();

// move:
void move(int condition);
void moveLine(int lineSS, int condition);
void moveStraight(int distance);

// catch ball:
void catchBalls();

//check color:
int check(int color, int threshold);

// release ball:
void releaseBalls();

// main:
int main()
{
	
	prepare();
	// prepare
	/*
	moveToFisrtBalls();
	catchBalls();
	moveToSecondBalls();
	catchBalls();
	moveToThirdBalls();
	catchBalls();
	moveToFourthBalls();
	catchBalls();
	// catch balls
	
	moveToFirstArea();
	releaseBalls(BOX);
	moveToSecondArea();
	releaseBalls(ROTATOR);
	// release balls
	
	stop();
	// stop
	*/
	return 0;
}

// prepare:
void prepare(){
	enable_servos();
	set_servo_position(BSV, BSV_LEVEL);
	set_servo_position(ASV, ASV_BACK);
	set_servo_position(RSV, RSV_DOWN);
	set_servo_position(SSV, SSV_BACK);
	// set all servos
	
	camera_open_at_res(LOW_RES);
	camera_load_config(CONFIG);
	camera_update();
	// set camera
	
	///////////////////////////////////////////////////////////////////wait_for_light(SSS);
	shut_down_in(TIME_LIMIT);
	// start actions
}

// catch balls:
void moveToFisrtBalls(){
	move(SEE_BALL);
	// move to first balls
}

void moveToSecondBalls(){
	move(SEE_LINE);
	moveLine(LSS, LSS_LINE_TIME);
	move(SEE_BALL);
	// move to second balls
}

void moveToThirdBalls(){
	
}

void moveToFourthBalls(){
	
}

void moveToFirstArea(){
	
}

void moveToSecondArea(){
	
}

// stop:
void stop(){
	camera_close();
	alloff();
	disable_servos();
	// set everything original
}

//check color:
int check(int color, int threshold){
	
}

// catch ball:
void catchBalls(){

	
	
	
}

// release ball:
void releaseBalls(int collector){
	if(collector == BOX){
		set_servo_position(BSV, BSV_DROP);
		msleep(BSV_DROP_TIME);
		set_servo_position(BSV, BSV_LEVEL);
	}else if(collector == ROTATOR){
		set_servo_position(RSV, RSV_UP);
		moveStraight(RSV_UP_DIS);
		motor(FM, FM_RELEASE);
	}
}

// move:
void move(int condition){
	
}

void moveLine(int lineSS, int condition){
	
}

void moveStraight(int distance){
	
}
