// Created on Sun July 27 2014, first whole programming on seeding round, Daiming Yang

#define TEST
#define CONFIG	"color.config"

const int OFFSET_X = 85;	// standard x coordinate to catch a ball
const int OFFSET_Y = 71;	// standard y coordinate to catch a ball

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
const int GREEN = 2;	// green ball
const int ORANGE = 2;	// orange cube
const int YELLOW = 3;	// yellow cube
const int RED = 4;		// botguy
const int BLUE = 5;		// blue cube

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

// function list:
// TEST:
void test();

// prepare:
void prepare();

// move:
void move(int order);
void findLine();
void turnLeftLine();
void turnRightLine();
void moveLine();
void moveBack1();
void turnLeft();
void moveBack2();
void turnBack();
void moveFor();
void turnRight();
void moveToStorage();
void moveBack();

// getBalls:
void getBalls();
void moveToBalls();
void findBall();
void catchBall(int color);
void collectBall();
int checkBall(int color);

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
	releaseBalls(BOX);
	#ifdef	TEST
	test();
	#endif
	move(STORAGE2);
	#ifdef	TEST
	test();
	#endif
	releaseBalls(ROTATOR);
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
	if(order == STORAGE1){
		turnBack();
		moveBack();
		turnLeft();
		}
	if(order == STORAGE2){
		findLine();
		turnRight();
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

void turnRightLine(){
	while(analog10(LSS) < LSS_OFFSET){
		motor(LM, 100);
		motor(RM, -100);
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
	int disDiff = frontDis - backDis;
	int turnLM = MOVE_BACK_TP - disDiff * KDp;
	int turnRM = MOVE_BACK_TP + disDiff * KDp;
	
	while(backDis > 295){
		motor(LM, turnLM);
		motor(RM, turnRM);
		frontDis = analog_et(FSS);
		backDis = analog_et(BSS);
		printf("%d\t%d\n", frontDis, backDis);
		disDiff = frontDis - backDis;
		turnLM = MOVE_BACK_TP - disDiff * KDp;
		turnRM = MOVE_BACK_TP + disDiff * KDp;
	}
	clear_motor_position_counter(LM);
	clear_motor_position_counter(RM);
	mtp(LM, -800, -480);
	mtp(RM, -800, -480);
	bmd(LM);
	bmd(RM);
	clear_motor_position_counter(LM);
	clear_motor_position_counter(RM);
	mtp(LM, -800, -250);
	mtp(RM, 800, 250);
	bmd(LM);
	bmd(RM);
	while(analog(RSS) < RSS_OFFSET){
		motor(RM, -85);
		motor(LM, -90);
	}
	while(analog(RSS) > RSS_OFFSET){
		motor(RM, -85);
		motor(LM, -90);
	}
	while(analog(RSS) < RSS_OFFSET){
		motor(RM, -85);
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
	int disDiff = frontDis - backDis;
	int turnLM = MOVE_BACK_TP - disDiff * KDp;
	int turnRM = MOVE_BACK_TP + disDiff * KDp;
	double timeStart = seconds();
	double timeEnd = seconds();
	
	while((timeEnd - timeStart) < 1.5){
		motor(LM, turnLM);
		motor(RM, turnRM);
		frontDis = analog_et(FSS);
		backDis = analog_et(BSS);
		printf("%d\t%d\n", frontDis, backDis);
		disDiff = frontDis - backDis;
		turnLM = MOVE_BACK_TP - disDiff * KDp;
		turnRM = MOVE_BACK_TP + disDiff * KDp;
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
	int disDiff = frontDis - backDis;
	int turnLM = MOVE_FOR_TP - disDiff * KDp;
	int turnRM = MOVE_FOR_TP + disDiff * KDp;
	
	while(frontDis > 295){
		motor(LM, turnLM);
		motor(RM, turnRM);
		frontDis = analog_et(FSS);
		backDis = analog_et(BSS);
		printf("%d\t%d\n", frontDis, backDis);
		disDiff = frontDis - backDis;
		turnLM = MOVE_BACK_TP - disDiff * KDp;
		turnRM = MOVE_BACK_TP + disDiff * KDp;
	}
	clear_motor_position_counter(LM);
	clear_motor_position_counter(RM);
	mtp(LM, 800, 500);
	mtp(RM, 800, 500);
	bmd(LM);
	bmd(RM);
	clear_motor_position_counter(LM);
	clear_motor_position_counter(RM);
	mtp(LM, 800, 260);
	mtp(RM, -800, -260);
	bmd(LM);
	bmd(RM);
	while(analog(RSS) < RSS_OFFSET){
		motor(RM, 82);
		motor(LM, 90);
	}
	while(analog(RSS) > RSS_OFFSET){
		motor(RM, 82);
		motor(LM, 90);
	}
	while(analog(RSS) < RSS_OFFSET){
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

void moveBack(){
	int timeStart = seconds();
	int timeEnd = seconds();
	while(timeEnd < (timeStart + 2)){
		motor(LM, -100);
		motor(RM, -100);
	}
}

// getBalls:
void getBalls(){
	moveToBalls();
	findBall();
	collectBall();
}// get a group of balls

void moveToBalls(){
	ao();
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
	ao();
}// move forward; stop when sees a target ball

void findBall(){
	display_clear();
	int temptLMSpeed = LM_MINS;			// changeable minimum speed for left motor
	int temptRMSpeed = RM_MINS;			// changeable minimum speed for right morot
	int lastLMSpeed, lastRMSpeed;	// motor speed
	int lastLMPos, lastRMPos;		// motor positions
	int countLM, countRM;			// count for speed increase
	
	int errorX = 0, errorY = 0;		// difference of current ball coordinate and target coordinate
	point2 objCen, objCen_Ball1, objCen_Ball2;	// object center coordinate
	
	camera_update();
	int objNum = get_object_count(GREEN);
	while(objNum == 0){
		camera_update();
		objNum = get_object_count(GREEN);
	}
	// find a ball in sight
	while(1){
		camera_update();		
		objCen_Ball1 = get_object_centroid(GREEN, 0);
		if (objNum >= 2 && get_object_area(GREEN, 1) > 200)
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
		
		if(get_object_bbox_width(GREEN, 0) >= (1.5 * get_object_bbox_height(GREEN, 0)))
			objCen.x = objCen.x - 5;
		if(get_object_bbox_height(GREEN, 0) >= (1.5 * get_object_bbox_width(GREEN, 0)))
			objCen.y = objCen.y + 5;
		// in case two balls are connected
		
		errorX = OFFSET_X - objCen.x;
		errorY = OFFSET_Y - objCen.y;
		// find differences between coordinates
		
		if(errorX > -2 && errorX < 2 && errorY > -2 && errorY < 3)
			break;
		int turnLM = -1 * errorX * P_X + errorY * P_Y;
		int turnRM = errorX * P_X + errorY * P_Y;
		// turn for LM, RM
		
		if(turnLM == lastLMSpeed && lastLMPos == get_motor_position_counter(LM))
			countLM++;
		if(countLM >= 3){
			temptLMSpeed = temptLMSpeed + 2;
			countLM = 0;
		}
		if(turnLM == lastLMSpeed && lastLMPos != get_motor_position_counter(LM))
			temptLMSpeed = temptLMSpeed - 1;
		if(turnLM == -1 * lastLMSpeed && lastLMPos != get_motor_position_counter(LM))
			temptLMSpeed = temptLMSpeed - 2;
		lastLMSpeed = turnLM;
		lastLMPos = get_motor_position_counter(LM);
		// set and record minimum speed for left motor
		
		if(turnRM == lastRMSpeed && lastRMPos == get_motor_position_counter(RM))
			temptRMSpeed = temptRMSpeed + 2;
		if(turnRM == lastRMSpeed && lastRMPos != get_motor_position_counter(RM))
			temptRMSpeed = temptRMSpeed - 1;
		if(turnRM == -1 * lastRMSpeed && lastRMPos != get_motor_position_counter(RM))
			temptRMSpeed = temptRMSpeed - 2;
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
	catchBall(GREEN);
	// stop and catch
}

void catchBall(int color){
	int count;
	int num;
	
	set_servo_position(ASV, ASV_CATCH);
	set_servo_position(SSV, SSV_GUARD);
	msleep(800);
	// catch ball on ground
	
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
	
	checkBall(color);
	// set any ball into its right position
	
	num = 0;
	for(count = 0; count <= 5; count++){
		camera_update();
		if(get_object_count(GREEN) > 0)
			num++;
	}
	if(num > 0)
		findBall();
	// find other balls if any in sight
}

int checkBall(int color){ // finish the ball
	int count = 0;
	int otherColor = 2 - color;
	
	for(count = 0; count <= 10; count++){
		camera_update();
		if(get_object_area(color, 0) > 1100)
			break;
		if(get_object_area(otherColor, 0) > 1100)
			break;
	}
	
	if(get_object_area(color, 0) > 800){
		set_servo_position(ASV, ASV_BACK);
		msleep(400);
		// throw ball back into box
		
		/*set_servo_position(SSV, SSV_GUARD);
		set_servo_position(ASV, ASV_CHECK);
		msleep(300);
		set_servo_position(SSV, SSV_BACK);
		msleep(200);
		/*camera_update();
		if(get_object_area(GREEN, 0) > 1100)
			set_servo_position(ASV, ASV_BACK);
		// avoid ball stuck in claw
		msleep(400);*/
		return 1;
	}else if(get_object_area(otherColor, 0) > 1100){
		set_servo_position(SSV, SSV_PUSH);
		msleep(400);
		set_servo_position(SSV, SSV_BACK);
		set_servo_position(ASV, ASV_BACK);
		msleep(400);
		return 0;
	}// wrong ball is pushed out
	else{
		set_servo_position(ASV, ASV_BACK);
		return 2;
	}// no ball is in claw
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
	// move and collect rest balls
}

// releaseBall:
void releaseBalls(int collector){
	if(collector == ROTATOR){
		set_servo_position(RSV, RSV_UP);
		msleep(300);
		motor(FM, FM_RELEASE);
		msleep(2500);
	}else if(collector == BOX){
		turnRight();
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
