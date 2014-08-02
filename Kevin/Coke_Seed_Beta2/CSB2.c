// Created on Sun July 27 2014, first whole programming on seeding round, Daiming Yang

#define TEST
#define CONFIG	"color.config"

// contants:
// motor ports:
const int LM = 1;// left motor
const int RM = 3;// right motor
const int FM = 2;// front motor

// motor constants:
const int LM_SP_STR1 = 87; 
const int RM_SP_STR1 = 100;		// straight speed for motor
const int LM_SP_STR2 = 870;
const int RM_SP_STR2 = 1000;	// straight speed for mrp
const int LM_MINS = 35;
const int RM_MINS = 35;			// minimum motor speed

const int FOURTH_CIRCLE = 750;	// ticks needed to accomplish fourth a circle
const int HALF_CIRCLE = 1500;	// ticks needed to accomplish half a circle
const int ONE_CIRCLE = 3000;	// ticks needed to accomplish a circle
const int FM_COLLECT = 100;		// front motor collects balls
const int FM_RELEASE = -100;	// front motor releases balls

// servo ports:
const int BSV = 2;	// box servo
const int ASV = 1;	// arm servo
const int RSV = 3;	// rotator servo
const int SSV = 0;	// small servo

// servo constants:
const int BSV_LEVEL = 2047;			// box servo keeps level
const int BSV_DROP = 900; 		// box servo drops balls
const int BSV_DROP_TIME = 1500;	// box servo time staying to drop balls

const int ASV_BACK = 600;		// arm servo keeps back
const int ASV_CATCH = 2047;		// arm servo catches ball
const int ASV_CHECK = 900;		// arm servo rises for check

const int RSV_DOWN = 1600;			// rotator servo keeps down
const int RSV_UP = 1150;			// rotator servo rises up
const int RSV_UP_DIS = 2000;	// rotator servo distance keeping up to get over boundary

const int SSV_BACK = 200;			// small servo keeps back
const int SSV_PUSH = 1300;			// small servo pushes ball out
const int SSV_GUARD = 950;          // small servo gurad balls
const int SSV_CHECK_TIME = 2000;    // small servo time staying for checking balls 

// sensor ports:
const int LSS = 0;	// left infrared sensor
const int RSS = 2;	// right infrared sensor
const int SSS = 7;	// start light sensor
const int FSS = 4;	// front ET sensor
const int BSS = 6;	// back ET sensor
const int TSS = 15;	// touch sensor

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

// color channel:
const int PINK = 0;		// pink ball
const int GREEN = 1;	// green ball
const int ORANGE = 2;	// orange cube
const int YELLOW = 3;	// yellow cube
const int RED = 4;		// botguy
const int BLUE = 5;		// blue cube

// vision constant:
const int OFFSET_X = 72;	// standard x coordinate to catch a ball
const int OFFSET_Y = 77;	// standard y coordinate to catch a ball
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
const int FSS_BACK_Kp = 1200;
const int BSS_BACK_Kp = 1200;

// move for constants:
const int MOVE_FOR_TP = 82;
const int FSS_FOR_Kp = 1200;
const int BSS_FOR_Kp = 1200;

// other constants:
const int BUTTON_CLICKED = 1;	// return value when button is clicked
const int TIME_LIMIT = 120;		// time limit

// function list:
// TEST:
void test();

// prepare:
void prepare();

// move:
void move(int order);
void findLine();
void turnLeftLine();
void moveLine();
void moveBack1();
void turnLeft();
void moveBack2();
void turnBack();
void moveFor();
void turnRight();
void moveToStorage();

// getBalls:
void getBalls();
void moveToBalls();
void findBall();
void catchBall(int color);
void collectBall();
int check(int color);

// releaseBall:
void releaseBalls(int collector);

// stop:
void stop();

int main()
{
	prepare();
	#ifdef	TEST
	test();
	#endif
	move(BALL1);
	#ifdef	TEST
	test();
	#endif
	getBalls();
	#ifdef	TEST
	test();
	#endif
	move(BALL2);
	#ifdef	TEST
	test();
	#endif
	getBalls();
	#ifdef	TEST
	test();
	#endif
	move(BALL3);
	#ifdef	TEST
	test();
	#endif
	getBalls();
	#ifdef	TEST
	test();
	#endif
	move(BALL4);
	#ifdef	TEST
	test();
	#endif
	getBalls();
	#ifdef	TEST
	test();
	#endif
	move(STORAGE1);
	#ifdef	TEST
	test();
	#endif
	releaseBalls(ROTATOR);
	#ifdef	TEST
	test();
	#endif
	move(STORAGE2);
	#ifdef	TEST
	test();
	#endif
	releaseBalls(BOX);
	#ifdef	TEST
	test();
	#endif
	stop();
	
	return 0;
}

// TEST:
void test(){
	ao();
	display_clear();
	printf("test now");
	while(digital(TSS) == 0);
	msleep(1000);
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
	//wait_for_light(SSS);
	//shut_down_in(TIME_LIMIT);
	// show controller that coke is ready
}

// move:
void move(int order){
	if(order == BALL1);
	if(order == BALL2){
		findLine();
		turnLeftLine();
		moveLine();
	}
	if(order == BALL3){
		moveBack1();
		turnLeft();
	}
	if(order == BALL4){
		moveBack2();
		turnBack();
	}
	if(order == STORAGE1);
	if(order == STORAGE2){
		turnBack();
		moveFor();
		turnRight();
		moveLine();
	}
}

void findLine(){
	int LSS_CHECK = 0;
	int RSS_CHECK = 0;
	while(LSS_CHECK == 0 || RSS_CHECK == 0){
		if (analog10(LSS) > LSS_OFFSET)
			LSS_CHECK = 1;
		if (analog10(RSS) > RSS_OFFSET)
			RSS_CHECK = 1;
		motor(LM, LM_SP_STR1);
		motor(RM, RM_SP_STR1);
	}
	mrp(LM, LM_SP_STR2, 300);
	mrp(RM, RM_SP_STR2, 300);
	bmd(LM);
	bmd(RM);
	ao();
}

void turnLeftLine(){
	while(analog10(LSS) < LSS_OFFSET){
		motor(LM, -100);
		motor(RM, 100);
	}
}
void moveLine(){
	double timeStart = seconds();
	double timeEnd = seconds();
	while((timeEnd - timeStart) < 1){
		int error = analog10(LSS) - LSS_OFFSET;
		int turn = error * MOVE_LINE_Kp;
		turn = turn / 10000;
		motor(LM, MOVE_LINE_Tp - turn);
		motor(RM, MOVE_LINE_Tp + turn);
		timeEnd = seconds();
	}
}

void moveBack1(){
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

void turnLeft(){
	clear_motor_position_counter(LM);
	clear_motor_position_counter(RM);
	mtp(LM, -1500, -1 * HALF_CIRCLE);
	mtp(RM, 1500, HALF_CIRCLE);
	bmd(LM);
	bmd(RM);
}

void moveBack2(){
	int frontDis = analog_et(FSS);
	int backDis = analog_et(BSS);
	int errorFront = FSS_BACK_DIS - frontDis;
	int errorBack = BSS_BACK_DIS - backDis;
	int turnLM = MOVE_BACK_TP - errorFront * FSS_BACK_Kp + errorBack * BSS_BACK_Kp;
	int turnRM = MOVE_BACK_TP + errorFront * FSS_BACK_Kp - errorBack * BSS_BACK_Kp;
	double timeStart = seconds(), timeEnd;
	
	while(digital(TSS) == 0 && (timeEnd - timeStart) < 2){
		motor(LM, turnLM);
		motor(RM, turnRM - 4);
		frontDis = analog_et(FSS);
		backDis = analog_et(BSS);
		errorFront = FSS_BACK_DIS - frontDis;
		errorBack = BSS_BACK_DIS - backDis;
		turnLM = MOVE_BACK_TP - errorFront * FSS_BACK_Kp / 1000 + errorBack * BSS_BACK_Kp / 1000;
		turnRM = MOVE_BACK_TP + errorFront * FSS_BACK_Kp / 1000 - errorBack * BSS_BACK_Kp / 1000;
		timeEnd = seconds();
	}
}

void turnBack(){
	clear_motor_position_counter(LM);
	clear_motor_position_counter(RM);
	mtp(LM, 1500, ONE_CIRCLE);
	mtp(RM, -1500, -1 * ONE_CIRCLE);
	bmd(LM);
	bmd(RM);
}

void moveFor(){
	int frontDis = analog_et(FSS);
	int backDis = analog_et(BSS);
	int errorFront = FSS_BACK_DIS - frontDis;
	int errorBack = BSS_BACK_DIS - backDis;
	int turnLM = MOVE_BACK_TP + errorFront * FSS_BACK_Kp + errorBack * BSS_BACK_Kp;
	int turnRM = MOVE_BACK_TP - errorFront * FSS_BACK_Kp - errorBack * BSS_BACK_Kp;
	
	while(digital(TSS) == 0 && frontDis > 295){
		motor(LM, turnLM);
		motor(RM, turnRM);
		frontDis = analog_et(FSS);
		backDis = analog_et(BSS);
		errorFront = FSS_BACK_DIS - frontDis;
		errorBack = BSS_BACK_DIS - backDis;
		turnLM = MOVE_BACK_TP + errorFront * FSS_BACK_Kp / 1000 - errorBack * BSS_BACK_Kp / 1000;
		turnRM = MOVE_BACK_TP - errorFront * FSS_BACK_Kp / 1000 + errorBack * BSS_BACK_Kp / 1000;
	}
	msleep(150);
	while(digital(TSS) == 0 && backDis > 295){
		backDis = analog_et(BSS);
		errorFront = FSS_BACK_DIS - frontDis;
		turnLM = MOVE_FOR_TP + errorBack * BSS_FOR_Kp / 1000;
		turnRM = MOVE_FOR_TP - errorBack * BSS_FOR_Kp / 1000;
		motor(LM, turnLM);
		motor(RM, turnRM);
		msleep(50);
	}
	while(analog(LSS) < LSS_OFFSET){
		motor(RM, 82);
		motor(LM, 90);
	}
	while(analog(LSS) > LSS_OFFSET){
		motor(RM, 82);
		motor(LM, 90);
	}
	while(analog(LSS) < LSS_OFFSET){
		motor(RM, 82);
		motor(LM, 90);
	}
}

void turnRight(){
	clear_motor_position_counter(LM);
	clear_motor_position_counter(RM);
	mtp(LM, 1500,HALF_CIRCLE);
	mtp(RM, -1500, -1 * HALF_CIRCLE);
	bmd(LM);
	bmd(RM);
}

// getBalls:
void getBalls(){
	moveToBalls();
	findBall();
	collectBall();
}// get a group of balls

void moveToBalls(){
	camera_update();
	camera_update();
	camera_update();
	camera_update();
	int objNum = get_object_count(GREEN);
	
	while(objNum == 0){
		motor(LM, LM_SP_STR1);
		motor(RM, RM_SP_STR1);
		camera_update();
		objNum = get_object_count(GREEN);
	}
	mrp(LM, 1000, 35);
	mrp(RM, 1000, 35);
	bmd(LM);
	bmd(RM);
}// move forward; stop when sees a target ball

void findBall(){
	display_clear();
	int temptLMSpeed = LM_MINS;			// changeable minimum speed for left motor
	int temptRMSpeed = RM_MINS;			// changeable minimum speed for right morot
	int lastLMSpeed, lastRMSpeed;	// motor speed
	int lastLMPos, lastRMPos;		// motor positions
	int errorX = 0, errorY = 0;		// difference of current ball coordinate and target coordinate
	int objArea;					// area of the largest object in sight
	point2 objCen, objCen_Ball1, objCen_Ball2;	// object center coordinate
	
	camera_update();
	int objNum = get_object_count(GREEN);
	while(objNum == 0){
		camera_update();
		objNum = get_object_count(GREEN);
	}
	// find a ball in sight
	/*
	objCen = get_object_centroid(GREEN, 0);
	errorX = OFFSET_X - objCen.x;
	errorY = OFFSET_Y - objCen.y;
	*/
	while(!(a_button_clicked())){
		camera_update();
		objArea = get_object_area(GREEN, 0);
		while(objArea < 150){
			ao();
			camera_update();
			objArea = get_object_area(GREEN, 0);
		}
		// make sure really a ball is in sight
		objCen_Ball1 = get_object_centroid(GREEN, 0);
		objCen_Ball2 = get_object_centroid(GREEN, 1);
			
		if (objNum >= 2 && get_object_area(GREEN, 1) > 200)
		{
			if (objCen_Ball1.x <= objCen_Ball2.x)
				objCen = objCen_Ball1;
			else if (objCen_Ball1.y >= objCen_Ball2.y)
				objCen = objCen_Ball1;
			else
				objCen = objCen_Ball2;
		}
		else
			objCen = objCen_Ball1;
		errorX = OFFSET_X - objCen.x;
		errorY = OFFSET_Y - objCen.y;
		// find differences between coordinates
		
		if(errorX > -3 && errorX < 2 && errorY > -3 && errorY < 2)
			break;
		int turnLM = -1 * errorX * P_X + errorY * P_Y;
		int turnRM = errorX * P_X + errorY * P_Y;
		// turn for LM, RM
		
		if(turnLM == lastLMSpeed && lastLMPos == get_motor_position_counter(LM))
			temptLMSpeed = temptLMSpeed + 1;
		if(turnLM == lastLMSpeed && lastLMPos != get_motor_position_counter(LM))
			temptLMSpeed = temptLMSpeed - 2;
		if(turnLM == -1 * lastLMSpeed && lastLMPos != get_motor_position_counter(LM))
			temptLMSpeed = temptLMSpeed - 2;
		if(turnRM == lastRMSpeed && lastRMPos == get_motor_position_counter(RM))
			temptRMSpeed = temptRMSpeed + 1;
		if(turnRM == lastRMSpeed && lastRMPos != get_motor_position_counter(RM))
			temptRMSpeed = temptRMSpeed - 2;
		if(turnRM == -1 * lastRMSpeed && lastRMPos != get_motor_position_counter(RM))
			temptRMSpeed = temptRMSpeed - 2;
		lastLMSpeed = turnLM;
		lastLMPos = get_motor_position_counter(LM);
		lastRMSpeed = turnRM;
		lastRMPos = get_motor_position_counter(RM);
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
	catchBall(GREEN);
	// stop and catch
}

void catchBall(int color){
	set_servo_position(ASV, ASV_CATCH);
	set_servo_position(SSV, SSV_GUARD);
	msleep(800);
	// catch ball on ground
	
	int count = 0;
	for(count = 0; count < 4; count++){
		motor(LM, 100);
		motor(RM, 100);
		msleep(100);
		motor(LM, -100);
		motor(RM, -100);
		msleep(100);
	}
	// tremble ball into the claw
	
	ao();
	set_servo_position(ASV, ASV_CHECK);
	msleep(600);
	set_servo_position(SSV, SSV_BACK);
	msleep(400);
	// set ball before camera for check
	
	if(check(color)){
		// the ball is right
		
		camera_update();
		camera_update();
		camera_update();
		if(get_object_count(GREEN) > 0)
			findBall();
		// check if other balls emerge
	}else
		findBall();
	// ball is elsewhere
}

void collectBall(){
	motor(FM, FM_COLLECT);
	clear_motor_position_counter(LM);
	clear_motor_position_counter(RM);
	mtp(LM, LM_SP_STR2, 800);
	mtp(RM, RM_SP_STR2, 800);
	bmd(LM);
	bmd(RM);
	motor(FM, 0);
	//msleep(2500);
	// move and collect rest balls
}

int check(int color){
	int otherColor = 1 - color;
	
	camera_update();
	camera_update();
	camera_update();
	camera_update();
	camera_update();
	camera_update();
	camera_update();
	camera_update();
	if(get_object_area(color, 0) > 2500){
		set_servo_position(ASV, ASV_BACK);
		msleep(400);
		// throw ball back into box
		
		set_servo_position(ASV, ASV_CHECK);
		set_servo_position(SSV, SSV_GUARD);
		msleep(300);
		if(check(color)){
			set_servo_position(SSV, SSV_BACK);
			set_servo_position(ASV, ASV_BACK);
			msleep(400);
		}else{
			set_servo_position(SSV, SSV_BACK);
			set_servo_position(ASV, ASV_BACK);
			msleep(300);
		}// avoid ball stuck in claw
		return 1;
	}else if(get_object_area(otherColor, 0) > 2500){
		set_servo_position(SSV, SSV_PUSH);
		msleep(400);
		set_servo_position(SSV, SSV_BACK);
		msleep(400);
		set_servo_position(ASV, ASV_BACK);
		return 0;
	}// wrong ball is pushed out
	else{
		set_servo_position(ASV, ASV_BACK);
		return 2;
	}// no ball is in claw
}

// releaseBall:
void releaseBalls(int collector){
	if(collector == ROTATOR){
		set_servo_position(RSV, RSV_UP);
		motor(LM, LM_SP_STR1);
		motor(RM, RM_SP_STR2);
		msleep(3500);
		ao();
		motor(FM, FM_RELEASE);
		msleep(2500);
		off(FM);
		motor(LM, -1 * LM_SP_STR1);
		motor(RM, -1 * RM_SP_STR2);
		msleep(1500);
	}else if(collector == BOX){
		motor(LM, LM_SP_STR1);
		motor(RM, RM_SP_STR2);
		msleep(3500);
		ao();
		clear_motor_position_counter(LM);
		clear_motor_position_counter(RM);
		mtp(LM, -1500, -1 * FOURTH_CIRCLE);
		mtp(RM, 1500, FOURTH_CIRCLE);
		bmd(LM);
		bmd(RM);
		set_servo_position(BSV, BSV_DROP);
		msleep(2000);
		set_servo_position(BSV, BSV_LEVEL);
		msleep(2000);
	}
}

// stop:
void stop(){
	ao();
	camera_close();
	disable_servos();
	// stop all parts
}
