
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
const int OFFSET_X = 80;	// standard x coordinate to catch a ball
const int OFFSET_Y = 60;	// standard y coordinate to catch a ball

// sensor constant:
const int WHITE = 1024;	// white for infrared sensors
const int BLACK = 0;	// black for infrared sensors
const int OFFSET = 512;	// mid value of white and black for infrared sensors

// servo constants:
const int BSV_LEVEL = 0;			// box servo keeps level
const int BSV_DROP = 0; 		// box servo drops balls
const int BSV_DROP_TIME = 1500;	// box servo time staying to drop balls

const int ASV_BACK = 0;			// arm servo keeps back
const int ASV_CATCH = 0;		// arm servo catches ball
const int ASV_CHECK = 0;		// arm servo rises for check

const int RSV_DOWN = 0;			// rotator servo keeps down
const int RSV_UP = 0;			// rotator servo rises up
const int RSV_UP_DIS = 2000;	// rotator servo distance keeping up to get over boundary

const int SSV_BACK = 0;			// small servo keeps back
const int SSV_PUSH = 0;			// small servo pushes ball out

// conditions constants:
const int SEE_BALL = 0;		// when camera sees target balls
const int SEE_LINE = 1;		// when a infrared sensor sees a black line

// collector constants:
const int BOX = 0;		// box on the back
const int ROTATOR = 1;	// rotator in the front

// other constants:
const int BUTTON_CLICKED = 1;	// return value when button is clicked
const int TIME_LIMIT = 120;		// time limit

// main:
int main()
{
	enable_servo(ASV);
	enable_servo(SSV);
	set_servo_position(ASV,600);
	set_servo_position(SSV,750);
	msleep(500);
	
	set_servo_position(ASV,2047);
	msleep(1000);
	set_servo_position(ASV,ASV_CHECK);
	msleep(500);
	set_servo_position(SSV,200);
	msleep(2000);
	set_servo_position(ASV,600);
	msleep(500);
	
	
	return 0;
}
