// Created on Sun July 20 2014

#define TEST
#define CONFIG	"color.config"

// contants:
// motor ports:
const int LM = 3;// left motor
const int RM = 1;// right motor
const int FM = 2;// front motor

const int MINS = 30;	// minimum motor speed

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
const int OFFSET_X = 72;	// standard x coordinate to catch a ball
const int OFFSET_Y = 63;	// standard y coordinate to catch a ball
const int P_X = 1;
const int P_Y = 1;

// sensor constant:
const int WHITE = 1024;	// white for infrared sensors
const int BLACK = 0;	// black for infrared sensors
const int OFFSET = 512;	// mid value of white and black for infrared sensors

// servo constants:
const int BSV_LEVEL = 1800;			// box servo keeps level
const int BSV_DROP = 900; 		// box servo drops balls
const int BSV_DROP_TIME = 1500;	// box servo time staying to drop balls

const int ASV_BACK = 700;		// arm servo keeps back
const int ASV_CATCH = 2047;		// arm servo catches ball
const int ASV_CHECK = 1000;		// arm servo rises for check

const int RSV_DOWN = 1500;			// rotator servo keeps down
const int RSV_UP = 1150;			// rotator servo rises up
const int RSV_UP_DIS = 2000;	// rotator servo distance keeping up to get over boundary

const int SSV_BACK = 200;			// small servo keeps back
const int SSV_PUSH = 1400;			// small servo pushes ball out
const int SSV_GUARD = 1000;          // small servo gurad balls
const int SSV_CHECK_TIME = 2000;    // small servo time staying for checking balls 

// conditions constants:
const int SEE_BALL = 0;		// when camera sees target balls
const int SEE_LINE = 1;		// when a infrared sensor sees a black line

// collector constants:
const int BOX = 0;		// box on the back
const int ROTATOR = 1;	// rotator in the front
int BALL_NUM_BOX = 0;
int BALL_NUM_ROTATOR = 0;

// other constants:
const int BUTTON_CLICKED = 1;	// return value when button is clicked
const int TIME_LIMIT = 120;		// time limit

void prepare();

void findBall(int color);
void catchBalls(int color);
int check(int color);

void stop();

int main()
{
	prepare();
	findBall(GREEN);
	stop();
	
	return 0;
}

void prepare()
{
	camera_open(LOW_RES);
	camera_load_config(CONFIG);
	camera_update();
	
	enable_servos();
	set_servo_position(BSV, BSV_LEVEL);
	set_servo_position(ASV, ASV_BACK);
	set_servo_position(RSV, RSV_DOWN);
	set_servo_position(SSV, SSV_BACK);
	
	display_clear();
	printf("prepare succeeds");
	while(!(a_button_clicked()));
}

void findBall(int color)
{
	camera_update();
	display_clear();
	int count = 1;
	int objNum = get_object_count(color);
	while(objNum == 0)
	{
		camera_update();
		objNum = get_object_count(color);
	}
	printf("%d time finding a ball", count);
	point2 objCen = get_object_center(color, 0);
	int errorX = 0, errorY = 0;
	errorX = OFFSET_X - objCen.x;
	errorY = OFFSET_Y - objCen.y;
	while(!(a_button_clicked()))
	{
		if(BALL_NUM_BOX >= 2)
			break;
		if(errorX > -4 && errorX < 4 && errorY > -4 && errorY < 4)
			break;
		int turnLM = -1 * errorX * P_X + errorY * P_Y;
		int turnRM = errorX * P_X + errorY * P_Y;
		if(turnLM > -1 * MINS && turnLM < 0)
			turnLM = -1 * MINS;
		if(turnLM > 0 && turnLM < MINS)
			turnLM = MINS;
		if(turnRM > -1 * MINS && turnRM < 0)
			turnRM = -1 * MINS;
		if(turnRM > 0 && turnRM < MINS)
			turnRM = MINS;
		motor(LM, turnLM);
		motor(RM, turnRM);
		camera_update();
		int objArea = get_object_area(color, 0);
		while(objArea < 200)
		{
			ao();
			camera_update();
			objArea = get_object_area(color, 0);
		}
		count++;
		display_clear();
		printf("%d time finding a ball   ", count);
		printf("%d NUM", BALL_NUM_BOX);
		objCen = get_object_center(color, 0);
		errorX = OFFSET_X - objCen.x;
		errorY = OFFSET_Y - objCen.y;
	}
	ao();
	catchBalls(color);
	
}

void catchBalls(int color)
{
	set_servo_position(ASV, ASV_CATCH);
	set_servo_position(SSV, SSV_GUARD);
	msleep(1000);
	set_servo_position(ASV, ASV_CHECK);
	msleep(1100);
	set_servo_position(SSV, SSV_BACK);
	msleep(100);
	if(check(color) == 1)
	{
		BALL_NUM_BOX++;
		set_servo_position(ASV, ASV_BACK);
		msleep(500);
		findBall(color);
	}
	else if (check(PINK) == 1)
	{
		set_servo_position(SSV, SSV_PUSH);
		msleep(500);
		set_servo_position(SSV, SSV_BACK);
		msleep(500);
		set_servo_position(ASV, ASV_BACK);
		msleep(500);
		findBall(color);
	}
	else
	{
		set_servo_position(ASV, ASV_BACK);
		msleep(500);
		findBall(color);
	}
}

int check(int color)
{
	int recheck = 0;
	int i = 0;
	for (i = 0; i < 8; i++)
	{
		camera_update();
		if(get_object_area(color, 0) > 1200)
			recheck++;
	}
	//display_clear();
	//printf("%d recheck", recheck);
	//while(!(c_button_clicked()));
	if(recheck >= 1)
		return 1;
	else
		return 0;
}

void stop()
{
	ao();
	camera_close();
	disable_servos();
}
