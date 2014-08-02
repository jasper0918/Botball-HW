// Created on Wed July 30 2014

//#define TEST
#define CONFIG	"color.conf"

const int OFFSET_X = 75;	// standard x coordinate to catch a ball
const int OFFSET_Y = 68;	// standard y coordinate to catch a ball

// contants:
// motor ports:
const int LM = 1;	// left motor
const int RM = 3;	// right motor
const int FM = 2;	// front motor
const int UM = 0;	// upper motor

// motor constants:
const int LM_SP_STR1 = 87; 
const int RM_SP_STR1 = 100;		// straight speed for motor
const int LM_SP_STR2 = 870;
const int RM_SP_STR2 = 1000;	// straight speed for mrp
const int LM_MINS = 30;
const int RM_MINS = 30;			// minimum motor speed

const int FOURTH_CIRCLE = 183;	// ticks needed to accomplish fourth a circle
const int HALF_CIRCLE = 325;	// ticks needed to accomplish half a circle
const int ONE_CIRCLE = 650;		// ticks needed to accomplish a circle

const int FM_COLLECT = 100;		// front motor speed collects balls
const int FM_RELEASE = -100;	// front motor speed releases balls

// servo ports:
const int BSV = 2;	// box servo
const int ASV = 1;	// arm servo
const int RSV = 3;	// rotator servo
const int SSV = 0;	// small servo

// servo constants:
const int BSV_LEVEL = 1650;			// box servo keeps level
const int BSV_DROP = 0; 		// box servo drops balls
const int BSV_DROP_TIME = 1500;	// box servo time staying to drop balls

const int ASV_BACK = 600;		// arm servo keeps backd
const int ASV_CATCH = 2047;		// arm servo catches ball
const int ASV_CHECK = 835;		// arm servo rises for check

const int RSV_DOWN = 1550;			// rotator servo keeps down
const int RSV_UP = 1150;			// rotator servo rises up
const int RSV_UP_DIS = 2000;		// rotator servo distance keeping up to get over boundary

const int SSV_BACK = 0;			// small servo keeps back
const int SSV_PUSH = 2047;			// small servo pushes ball out
const int SSV_GUARD = 920;          // small servo gurad balls
const int SSV_CHECK_TIME = 2000;    // small servo time staying for checking balls 

// sensor ports:
const int LSS = 0;	// left infrared sensor
const int RSS = 2;	// right infrared sensor
const int SSS = 7;	// start light sensor
const int FSS = 4;	// front ET sensor
const int BSS = 6;	// back ET sensor
const int TSS = 15;	// touch sensor

// sensor constant:
const int LSS_WHITE = 150;	// white for infrared sensors
const int LSS_BLACK = 900;	// black for infrared sensors
const int LSS_OFFSET = 525;	// mid value of white and black for infrared sensors

const int RSS_WHITE = 150;	// white for infrared sensors
const int RSS_BLACK = 900;	// black for infrared sensors
const int RSS_OFFSET = 5259;	// mid value of white and black for infrared sensors

// color channel:
const int PINK = 0;		// pink ball
const int GREEN = 1;	// green ball
const int PINK_CHECK = 2;	// pink ball check
const int GREEN_CHECK = 3;	// green ball check
const int CHECK_AREA = 1500;// ball area when checking

// vision constant:
const int P_X = 1;
const int P_Y = 1;

// collector constants:
const int BOX = 0;		// box on the back
const int ROTATOR = 1;	// rotator in the front

// move constants:
const int BALL1 = 1;
const int BALL2 = 2;
const int BALL3 = 3;
const int BALL4 = 4;
const int STORAGE1 = 5;
const int STORAGE2 = 6;

// moveLine constants:
const int MOVE_LINE_Kp = 500;
const int MOVE_LINE_Tp = 80;

// move back constants:
const int MOVE_BACK_TP = -82;
const int MOVE_BACK_DIS = 700;	// distance between coke and tube when moving back
const int KDp = 2;
const int RTURN_DIFF = 35;
const int LTURN_DIFF = -20;
const int RLINE = 360;
const int LLINE = 330;

// move for constants:
const int MOVE_FOR_TP = 82;
const int FSS_FOR_Kp = 1200;
const int BSS_FOR_Kp = 1200;

// other constants:
const int TIME_LIMIT = 120;		// time limit

// prepare:
void prepare(){
	camera_open(LOW_RES);
	camera_load_config(CONFIG);
	camera_update();
	camera_update();
	camera_update();
	// prepare camera
	
	enable_servos();
	set_servo_position(ASV, ASV_BACK);
	set_servo_position(RSV, RSV_DOWN);
	set_servo_position(SSV, SSV_BACK);
	// prepare servos
	
	display_clear();
	printf("prepare succeeds");
	while(digital(TSS) == 0);
	msleep(500);
	//wait_for_light(SSS);
	//shut_down_in(TIME_LIMIT);
	// show controller that coke is ready
}

void test(){
	ao();
	display_clear();
	printf("test now");
	while(digital(TSS) == 0);
}

void getBalls();
void moveToBall();
void findBall();
void catchBall();
int check();
void collectBalls();

int main()
{
	prepare();
	
	getBalls();
	
	msleep(1000);
	return 0;
}

void getBalls(){
	moveToBall();
	camera_update();
	findBall();
	catchBall();
	camera_update();
	int objNum;
	objNum = get_object_count(GREEN);
	while(objNum > 0){
		findBall();
		catchBall();
		camera_update();
		objNum = get_object_count(GREEN);
	}
	collectBalls();
}

void moveToBall(){
	camera_update();
	int objNum = get_object_count(GREEN);
	while(objNum == 0){
		// no ball in sight
		motor(LM, LM_SP_STR1);
		motor(RM, RM_SP_STR1);
		// move forward
		camera_update();
		objNum = get_object_count(GREEN);
		// recheck
	}
	ao();
}

void findBall(){
	int temptLMSpeed = LM_MINS;			// changeable minimum speed for left motor
	int temptRMSpeed = RM_MINS;			// changeable minimum speed for right morot
	int lastLMSpeed, lastRMSpeed;	// motor speed
	int lastLMPos, lastRMPos;		// motor positions
	// motor constants
	int objNum;
	int errorX = 0, errorY = 0;		// difference of current ball coordinate and target coordinate
	point2 objCen, objCen_Ball1, objCen_Ball2;	// object center coordinate
	// vision constants
	display_clear();
	camera_update();
	objNum = get_object_count(GREEN);
	if(objNum == 0){
		while(objNum == 0){
			camera_update();
			objNum = get_object_count(GREEN);
			motor(LM, 50);
			motor(RM, 50);
			display_clear();
			printf("not found!!!");
		}
		motor(LM, 50);
		motor(RM, 50);
		msleep(200);
	}
	ao();
	// ensure a ball in sight
	while(1){
		camera_update();		
		objCen_Ball1 = get_object_centroid(GREEN, 0);
		// first ball coordinates
		objNum = get_object_count(GREEN);
		if (objNum >= 2 && get_object_area(GREEN, 1) > 100)
		{
			objCen_Ball2 = get_object_centroid(GREEN, 1);
			if (objCen_Ball1.y >= (objCen_Ball2.y + 2))
				objCen = objCen_Ball1;
			else if (objCen_Ball1.x <= objCen_Ball2.x + 2)
				objCen = objCen_Ball1;
			else
				objCen = objCen_Ball2;
		}
		else
			objCen = objCen_Ball1;
		// in case two ball are in sight
		if(get_object_bbox_width(GREEN, 0) >= (1.4 * get_object_bbox_height(GREEN, 0)))
			objCen.x = objCen.x - 7;
		if(get_object_bbox_height(GREEN, 0) >= (1.4 * get_object_bbox_width(GREEN, 0)))
			objCen.y = objCen.y + 5;
		// in case two balls are connected
		errorX = OFFSET_X - objCen.x;
		errorY = OFFSET_Y - objCen.y;
		// find differences between coordinates
		if(errorX > -2 && errorX < 2 && errorY > -2 && errorY < 2)
			break;
		int turnLM = -1 * errorX * P_X + errorY * P_Y;
		int turnRM = errorX * P_X + errorY * P_Y;
		// speed for LM, RM
		if(turnLM == lastLMSpeed && lastLMPos < (get_motor_position_counter(LM) + 10)
			&& lastLMPos > (get_motor_position_counter(LM) - 10))
			temptLMSpeed = temptLMSpeed + 1;
		if(turnLM == lastLMSpeed && lastLMPos != get_motor_position_counter(LM))
			temptLMSpeed = temptLMSpeed - 1;
		if(turnLM == -1 * lastLMSpeed && lastLMPos != get_motor_position_counter(LM))
			temptLMSpeed = temptLMSpeed - 3;
		lastLMSpeed = turnLM;
		lastLMPos = get_motor_position_counter(LM);
		// set and record minimum speed for left motor
		if(turnRM == lastRMSpeed && lastRMPos < (get_motor_position_counter(RM) + 10)
			&& lastRMPos > (get_motor_position_counter(RM) - 10))
			temptRMSpeed = temptRMSpeed + 1;
		if(turnRM == lastRMSpeed && lastRMPos != get_motor_position_counter(RM))
			temptRMSpeed = temptRMSpeed - 1;
		if(turnRM == -1 * lastRMSpeed && lastRMPos != get_motor_position_counter(RM))
			temptRMSpeed = temptRMSpeed - 3;
		lastRMSpeed = turnRM;
		lastRMPos = get_motor_position_counter(RM);
		// set and record minimum speed for right motor
		// check if speed is too high or low, thus make modification to minimum speed
		if(turnLM > -1 * temptLMSpeed && turnLM < 0)
			turnLM = -1 * temptLMSpeed;
		if(turnLM > 0 && turnLM < temptLMSpeed)
			turnLM = temptLMSpeed;
		if(turnRM > -1 * temptRMSpeed && turnRM < 0)
			turnRM = -1 * temptRMSpeed;
		if(turnRM > 0 && turnRM < temptRMSpeed)
			turnRM = temptRMSpeed;
		// set minimum speed: avoid unmoving
		
		motor(LM, turnLM);
		motor(RM, turnRM);
		// move
	}
	
	ao();
	// stop and catch
}

void catchBall(){
	int count;
	
	set_servo_position(ASV, ASV_CATCH);
	set_servo_position(SSV, SSV_GUARD);
	msleep(800);
	// catch ball on ground
	for(count = 0; count < 4; count++){
		motor(LM, 100);
		motor(RM, 100);
		msleep(80);
		motor(LM, -100);
		motor(RM, -100);
		msleep(80);
	}
	ao();
	// tremble ball into the claw
	set_servo_position(ASV, ASV_CHECK);
	msleep(600);
	set_servo_position(SSV, SSV_BACK);
	msleep(300);
	// set ball before camera for check
	for(count = 0; count <= 3; count++){
		camera_update();
		camera_update();
		camera_update();
		camera_update();
		if(check() == GREEN_CHECK){
			// right ball: ensure ball is back
			set_servo_position(SSV, SSV_GUARD);
			msleep(200);
			set_servo_position(ASV, ASV_CATCH);
			msleep(400);
			set_servo_position(SSV, SSV_BACK);
			msleep(200);
			set_servo_position(ASV, ASV_BACK);
			msleep(400);
			set_servo_position(SSV, SSV_GUARD);
			set_servo_position(ASV, ASV_CHECK);
			msleep(200);
			set_servo_position(SSV, SSV_BACK);
			msleep(200);
		}else if(check() == PINK_CHECK){
			// wrong ball: push out
			set_servo_position(SSV, SSV_PUSH);
			msleep(400);
			set_servo_position(SSV, SSV_BACK);
			msleep(400);
			set_servo_position(ASV, ASV_BACK);
		}else{
			// ball is elsewhere
			set_servo_position(ASV, ASV_BACK);
			msleep(400);
			break;
		}
	}
}

int check(){
	camera_update();
	camera_update();
	if(get_object_area(GREEN_CHECK, 0) > CHECK_AREA)
		return GREEN_CHECK;
	if(get_object_area(PINK_CHECK, 0) > CHECK_AREA)
		return PINK_CHECK;
	else
		return 0;
}

void collectBalls(){
	motor(FM, FM_COLLECT);
	clear_motor_position_counter(LM);
	clear_motor_position_counter(RM);
	mtp(LM, LM_SP_STR2, 800);
	mtp(RM, RM_SP_STR2, 800);
	bmd(LM);
	bmd(RM);
	motor(FM, 0);
	// move and collect rest balls
}
