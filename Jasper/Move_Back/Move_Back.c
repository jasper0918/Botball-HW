// Created on Sat July 26 2014

#define TEST
#define CONFIG	"color.config"

// contants:
// motor ports:
const int LM = 3;// left motor
const int RM = 1;// right motor
const int FM = 2;// front motor

const int MINS = 35;	// minimum motor speed

// servo ports:
const int BSV = 2;	// box servo
const int ASV = 1;	// arm servo
const int RSV = 3;	// rotator servo
const int SSV = 0;	// small servo

// sensor ports:
const int LSS = 0;	// left infrared sensor
const int RSS = 2;	// right infrared sensor
const int SSS = 7;	// start light sensor
const int FSS = 4;	// front ET sensor
const int BSS = 6;	// back ET sensor
const int TSS = 15;	// touch sensor

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
const int OFFSET_X = 95;	// standard x coordinate to catch a ball
const int OFFSET_Y = 46;	// standard y coordinate to catch a ball
const int P_X = 1;
const int P_Y = 1;

// sensor constant:
const int LSS_WHITE = 300;	// white for infrared sensors
const int LSS_BLACK = 960;	// black for infrared sensors
const int LSS_OFFSET = 630;	// mid value of white and black for infrared sensors

const int RSS_WHITE = 630;	// white for infrared sensors
const int RSS_BLACK = 870;	// black for infrared sensors
const int RSS_OFFSET = 750;	// mid value of white and black for infrared sensors

const int FSS_BACK_DIS = 320;	// distance between coke and tube when moving back
const int FSS_MID_DIS = 300;	// distance between coke and tube when adjusting middle position

const int BSS_BACK_DIS = 320;	// distance between coke and tube when moving back
const int BSS_MID_DIS = 300;	// distance between coke and tube when adjusting middle position

// move back constants:
const int MOVE_BACK_TP = -82;
const int FSS_BACK_Kp = 1200;
const int BSS_BACK_Kp = 1200;

// servo constants:
const int BSV_LEVEL = 2047;			// box servo keeps level
const int BSV_DROP = 900; 		// box servo drops balls
const int BSV_DROP_TIME = 1500;	// box servo time staying to drop balls

const int ASV_BACK = 600;		// arm servo keeps back
const int ASV_CATCH = 2047;		// arm servo catches ball
const int ASV_CHECK = 1200;		// arm servo rises for check

const int RSV_DOWN = 1500;			// rotator servo keeps down
const int RSV_UP = 1150;			// rotator servo rises up
const int RSV_UP_DIS = 2000;	// rotator servo distance keeping up to get over boundary

const int SSV_BACK = 200;			// small servo keeps back
const int SSV_PUSH = 1300;			// small servo pushes ball out
const int SSV_GUARD = 950;          // small servo gurad balls
const int SSV_CHECK_TIME = 2000;    // small servo time staying for checking balls 

// conditions constants:
const int SEE_BALL = 0;		// when camera sees target balls
const int SEE_LINE = 1;		// when a infrared sensor sees a black line

// collector constants:
const int BOX = 0;		// box on the back
const int ROTATOR = 1;	// rotator in the front

// move constants:
const int BALL_1 = 1;
const int BALL_2 = 2;
const int BALL_3 = 3;
const int BALL_4 = 4;
const int STORAGE_1 = 5;
const int STORAGE_2 = 6;

// moveLine constants:
const int Kp = 500;
const int Ki = 1;
const int Kd = 1;
const int Tp = 80;

// other constants:
const int BUTTON_CLICKED = 1;	// return value when button is clicked
const int TIME_LIMIT = 120;		// time limit

// prepare:
void prepare();

// stop:
void stop();

// move back:
void moveBack();

int main()
{
	prepare();
	
	moveBack();
	
	stop();
	return 0;
}

// prepare:
void prepare(){
	camera_open(LOW_RES);
	camera_load_config(CONFIG);
	camera_update();
	camera_update();
	camera_update();
	// prepare camera
	
	enable_servos();
	set_servo_position(BSV, BSV_LEVEL);
	set_servo_position(ASV, ASV_BACK);
	set_servo_position(RSV, RSV_DOWN);
	set_servo_position(SSV, SSV_BACK);
	// prepare servos
	
	set_analog_pullup(FSS, 0);
	set_analog_pullup(BSS, 0);
	// prepare sensors
	
	display_clear();
	printf("prepare succeeds");
	while(digital(TSS) == 0);
	msleep(1500);
	// show controller that coke is ready
}

// stop:
void stop(){
	ao();
	camera_close();
	disable_servos();
	// stop all parts
}

// moveBack:
void moveBack(){
	int frontDis = analog_et(FSS);
	int backDis = analog_et(BSS);
	int errorFront = FSS_BACK_DIS - frontDis;
	int errorBack = BSS_BACK_DIS - backDis;
	int turnLM = MOVE_BACK_TP + errorFront * FSS_BACK_Kp + errorBack * BSS_BACK_Kp;
	int turnRM = MOVE_BACK_TP - errorFront * FSS_BACK_Kp - errorBack * BSS_BACK_Kp;
	
	while(digital(TSS) == 0 && backDis > 295){
		motor(LM, turnLM);
		motor(RM, turnRM - 4);
		frontDis = analog_et(FSS);
		backDis = analog_et(BSS);
		errorFront = FSS_BACK_DIS - frontDis;
		errorBack = BSS_BACK_DIS - backDis;
		turnLM = MOVE_BACK_TP - errorFront * FSS_BACK_Kp / 1000 + errorBack * BSS_BACK_Kp / 1000;
		turnRM = MOVE_BACK_TP + errorFront * FSS_BACK_Kp / 1000 - errorBack * BSS_BACK_Kp / 1000;
	}
	msleep(150);
	while(digital(TSS) == 0 && frontDis > 295){
		frontDis = analog_et(FSS);
		errorFront = FSS_BACK_DIS - frontDis;
		turnLM = MOVE_BACK_TP - errorFront * FSS_BACK_Kp / 1000;
		turnRM = MOVE_BACK_TP + errorFront * FSS_BACK_Kp / 1000;
		motor(LM, turnLM);
		motor(RM, turnRM - 2);
		msleep(50);
	}
	while(analog(RSS) < RSS_OFFSET){
		motor(RM, -82);
		motor(LM, -90);
	}
	while(analog(RSS) > RSS_OFFSET){
		motor(RM, -82);
		motor(LM, -90);
	}
	while(analog(RSS) < RSS_OFFSET){
		motor(RM, -82);
		motor(LM, -90);
	}
}
