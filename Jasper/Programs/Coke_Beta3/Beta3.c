// Created on Thu July 24 2014

#define TEST
#define CONFIG	"color.config"

// contants:
// motor ports:
const int LM = 1;// left motor
const int RM = 3;// right motor
const int FM = 2;// front motor
const int LM_SP_STR1 = 87;  //for motor
const int RM_SP_STR1 = 100;
const int LM_SP_STR2 = 870;  //for mrp
const int RM_SP_STR2 = 1000;

const int LM_MINS = 35;
const int RM_MINS = 35;	// minimum motor speed

// servo ports:
const int BSV = 2;	// box servo
const int ASV = 1;	// arm servo
const int RSV = 3;	// rotator servo
const int SSV = 0;	// small servo

// sensor ports:
const int LSS = 0;	// left infrared sensor
const int RSS = 2;	// right infrared sensor
const int SSS = 1;	// start light sensor

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
const int OFFSET_X = 93;	// standard x coordinate to catch a ball
const int OFFSET_Y = 71;	// standard y coordinate to catch a ball
const int P_X = 1;
const int P_Y = 1;

// sensor constant:
const int LSS_WHITE = 470;	// white for infrared sensors
const int LSS_BLACK = 980;	// black for infrared sensors
const int LSS_OFFSET = 725;	// mid value of white and black for infrared sensors

const int RSS_WHITE = 420;	// white for infrared sensors
const int RSS_BLACK = 980;	// black for infrared sensors
const int RSS_OFFSET = 700;	// mid value of white and black for infrared sensors

// servo constants:
const int BSV_LEVEL = 2047;			// box servo keeps level
const int BSV_DROP = 900; 		// box servo drops balls
const int BSV_DROP_TIME = 1500;	// box servo time staying to drop balls

const int ASV_BACK = 600;		// arm servo keeps back
const int ASV_CATCH = 2047;		// arm servo catches ball
const int ASV_CHECK = 1100;		// arm servo rises for check

const int RSV_DOWN = 1600;			// rotator servo keeps down
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
const int BALL_1_DIS = 300;
const int BALL_2 = 2;
const int BALL_3 = 3;
const int BALL_4 = 4;
const int STORAGE_1 = 5;
const int STORAGE_2 = 6;

// moveLine constants:
const int Kp = 600;
const int Ki = 0;
const int Kd = 0;
const int Tp = 50;


// other constants:
const int BUTTON_CLICKED = 1;	// return value when button is clicked
const int TIME_LIMIT = 120;		// time limit

// TEST:
void test();

// prepare:
void prepare();

// move:
void move(int order);
void findLine();
void turnLeftLine();
void moveLine();

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
	// prepare
	
	move(BALL_1);
	getBalls();
	move(BALL_2);
	//getBalls();
	/*move(BALL_3);
	getBalls();
	move(BALL_4);
	getBalls();
	// get all balls
	
	move(STORAGE_1);
	releaseBalls(Box);
	move(STORAGE_2);
	releaseBalls(ROTATOR);*/
	// release all balls
	
	stop();
	// stop
	
	return 0;
}

// TEST:
void test(){
	
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
	while(!(a_button_clicked()));
	// show controller that coke is ready
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
	mrp(LM, 1000, -35);
	mrp(RM, 1000, -35);
	bmd(LM);
	bmd(RM);
	ao();
	//msleep(250);
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
			temptLMSpeed = temptLMSpeed - 1;
		if(turnLM == -1 * lastLMSpeed && lastLMPos != get_motor_position_counter(LM))
			temptLMSpeed = temptLMSpeed - 2;
		if(turnRM == lastRMSpeed && lastRMPos == get_motor_position_counter(RM))
			temptRMSpeed = temptRMSpeed + 1;
		if(turnRM == lastRMSpeed && lastRMPos != get_motor_position_counter(RM))
			temptRMSpeed = temptRMSpeed - 1;
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
	if(get_object_area(color, 0) > 1700){
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
	}else if(get_object_area(otherColor, 0) > 1300){
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

// move:
void move(int order){
	if(order == 1){
		/*mrp(LM, LM_SP_STR2, BALL_1_DIS);
		mrp(RM, RM_SP_STR2, BALL_1_DIS);
		bmd(LM);
		bmd(RM);
		ao();*/
	}
	if(order == 2){
		findLine();
		turnLeftLine();
		moveLine();
	}
	if(order == 3){
		
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
	int error, turn; 
	while((timeEnd - timeStart) < 2){
		error = analog10(LSS) - LSS_OFFSET;
		turn = error * Kp;
		turn = turn / 8000;
		motor(LM, Tp + turn);
		motor(RM, Tp - turn);
		timeEnd = seconds();
	}
}

void stop(){
	ao();
	camera_close();
	disable_servos();
	// stop all parts
}

