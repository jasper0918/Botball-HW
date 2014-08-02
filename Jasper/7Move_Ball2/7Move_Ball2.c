// Created on Wed July 30 2014

#define TEST
#define CONFIG	"color.config"

const int OFFSET_X = 85;	// standard x coordinate to catch a ball
const int OFFSET_Y = 73;	// standard y coordinate to catch a ball

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
const int ONE_CIRCLE = 613;		// ticks needed to accomplish a circle

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
const int FTSS = 13;	// front touch sensor
const int TSS = 15;	// touch sensor

// sensor constant:
const int LSS_WHITE = 150;	// white for infrared sensors
const int LSS_BLACK = 900;	// black for infrared sensors
const int LSS_OFFSET = 525;	// mid value of white and black for infrared sensors

const int RSS_WHITE = 150;	// white for infrared sensors
const int RSS_BLACK = 900;	// black for infrared sensors
const int RSS_OFFSET = 525;	// mid value of white and black for infrared sensors

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
const int KDp = 1200;
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

// TEST:
void test(){
	ao();
	display_clear();
	printf("test now");
	while(digital(TSS) == 0);
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
void moveLevel();
void moveS1();

int main()
{
	prepare();
	
	move(BALL2);
	#ifdef TEST
	test();
	#endif
	move(BALL3);
	#ifdef TEST
	test();
	#endif
	move(BALL4);
	#ifdef TEST
	test();
	#endif
	move(STORAGE1);
	#ifdef TEST
	test();
	#endif
	move(STORAGE2);
	msleep(1000);
	return 0;
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
		turnLeft();
		moveLevel();
		moveS1();
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
	while((timeEnd - timeStart) < 1.25){
		int error = analog10(LSS) - LSS_OFFSET;
		int turn = error * MOVE_LINE_Kp;
		turn = turn / 10000;
		motor(LM, MOVE_LINE_Tp + turn);
		motor(RM, MOVE_LINE_Tp - turn);
		timeEnd = seconds();
	}
}

void moveBack1(){
	int frontDis = analog_et(FSS);
	int backDis = analog_et(BSS);
	int disDiff = frontDis - backDis;
	int turnLM = MOVE_BACK_TP - disDiff * KDp;
	int turnRM = MOVE_BACK_TP + disDiff * KDp;
	double timeStart, timeEnd;
	int normalDis;
	
	timeStart = seconds();
	while((timeEnd - timeStart) < 2){
		motor(LM, turnLM);
		motor(RM, turnRM);
		frontDis = analog_et(FSS);
		backDis = analog_et(BSS);
		printf("%d\t%d\n", frontDis, backDis);
		disDiff = frontDis - backDis;
		turnLM = MOVE_BACK_TP - disDiff * KDp / 1000;
		turnRM = MOVE_BACK_TP + disDiff * KDp / 1000;
		timeEnd = seconds();
	}
	normalDis = (frontDis + backDis) / 2;
	printf("normal dis: %d\n", normalDis);
	while(normalDis < (1.05 * backDis)){
		motor(LM, turnLM);
		motor(RM, turnRM);
		frontDis = analog_et(FSS);
		backDis = analog_et(BSS);
		printf("%d\t%d\n", frontDis, backDis);
		disDiff = frontDis - backDis;
		turnLM = MOVE_BACK_TP - disDiff * KDp / 1000;
		turnRM = MOVE_BACK_TP + disDiff * KDp / 1000;
	}
	ao();
	
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
		turnLM = MOVE_BACK_TP - disDiff * KDp / 1000;
		turnRM = MOVE_BACK_TP + disDiff * KDp / 1000;
		timeEnd = seconds();
	}
}

void turnBack(){
	clear_motor_position_counter(LM);
	clear_motor_position_counter(RM);
	mtp(LM, -1500, -1 * ONE_CIRCLE);
	mtp(RM, 1500, ONE_CIRCLE);
	bmd(LM);
	bmd(RM);
}

void turnRight(){
	clear_motor_position_counter(LM);
	clear_motor_position_counter(RM);
	mtp(LM, 1500,HALF_CIRCLE);
	mtp(RM, -1500, -1 * HALF_CIRCLE);
	bmd(LM);
	bmd(RM);
}

void moveLevel(){
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
		turnLM =  - disDiff * KDp / 120;
		turnRM =  + disDiff * KDp / 120;
		timeEnd = seconds();
	}
}

void moveS1(){
	turnRight();
	while(digital(FTSS) == 0){
		motor(LM, 100);
		motor(RM, 100);
	}
	turnBack();
	clear_motor_position_counter(LM);
	clear_motor_position_counter(RM);
	mtp(LM, -1500, -200);
	mtp(RM, -1500, -200);
	bmd(LM);
	bmd(RM);
}
