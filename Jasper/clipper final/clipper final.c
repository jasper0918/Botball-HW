// Created on 7/4/2013
// abbreviations: c_: constant; SS: sensor; SV: servo; al: along line Avd: avoiding; LV: light value; LC: left chain; RC: right chain
const int c_ioffsetX = 81;
const int c_ioffsetY = 112;
// X, Y offsets of green balls when place modification

const int c_ileftSS = 1;
const int c_irightSS = 2;
const int c_idownSS = 0;
const int c_itouchSS = 15;
const int c_imicroSV = 1;
const int c_ibackSV = 3;
const int c_ifrontSV = 2;
const int c_iupperSV = 0;
const int c_ileftMotor = 2;
const int c_irightMotor = 3;
//ports

const int c_ibuttonClicked = 1;
// preparation

const int c_iupperSVLevel = 0;				// set box level
const int c_iupperSVDown = 1400;			// lean box 

const int c_ifrontSVSet = 1800;			// position for ball throwing or robot moving
const int c_ifrontSVJudge = 850;			// position to judge the ball color
const int c_ifrontSVArmDown = 50;			// position to shake the ball
const int c_ifrontSVBallCatch = 0;		// position to catch the ball
const int c_ifrontSVBallHold = 280;		// position to set robot level

const int c_imicroSVSet = 0;				// position for robot moving
const int c_imicroSVAwaken = 2047;			// position to shake orange balls
const int c_imicroSVRelease = 1700;		// position for next orange ball shaking

const int c_ibackSVOpen = 2047;			// position to open back hook
const int c_ibackSVClose = 0;				// position to close back hook
// servo position

const int c_itouchSSTouched = 1;
const int c_itouchSSBare = 0;
// touch sensor

const int c_ileftSSBlack = 800;			// light value of black for left sensor
const int c_ileftSSWhite = 50;				// light value of white for left sensor
const int c_ileftSSOffset = 425;			// light value of mid(black, white) for left sensor

const int c_irightSSBlack = 800;			// light value of black for right sensor
const int c_irightSSWhite = 50;			// light value of white for right sensor
const int c_irightSSOffset = 425;			// light value of mid(black, white) for right sensor

const int c_idownSSOffset = 700;			// light value of mid(transport, nothing) for down sensor
// light values

const int c_ip = 70;						// p value
const int c_ii = 14;						// i value
const int c_id = 26;						// d value
const int c_iTpower = 100;					// true power of motors
const int c_iacWhite = 50;					// additonal constant for white
const int c_iacBlack = 50;					// additonal constant for black

const int c_ibotguyTpower = 60;			// special true power of motors for botguy
// constants of "move along line"

const int c_ipX = 1; 						// p value of X
const int c_ipY = 1;						// p value of Y
		//const int c_iiX = 6;				// i value of X
		//const int c_iiY = 6;				// i value of Y
		//const int c_idX = 10;				// d value of X
		//const int c_idY = 10;				// d value of Y
const int c_iLCPowerMinWithoutGuy = 3;		// minimum power of motors
const int c_iLCPowerMinWithGuy = 5;
const int c_iLCPowerMinSteayGuy = 4;
const int c_ipowerMax = 80;				// maximum power of motors
const int c_ideviationX = 2;
const int c_ideviationY = 2;				// appropriate difference from exact ball coordinates
// constants of place modification

// function contents:
		// void delay();
		// trial

void ready();
// preparation

void leftTurn();
void rightTurn();
// turn to line

void LCheimiLeftTurn();					// only left sensor sees line is ok
void LCheimiRightTurn();					// only left sensor sees line is ok
// LC 'ballGet' turn

void RCheimiLeftTurn();					// only right sensor sees line is ok
void RCheimiRightTurn();					// only right sensor sees line is ok
// RC 'ballGet' turn

void rightSpin();							// right turn to backward; used for botguy catching

void rightCornerTurn(); 					// right turn when corner detected
void leftCornerTurn();						// left turn when corner detected

void leftTurnToBall();						// left turn to ball
void rightTurnToBall();					// right turn to ball
// turn related:

void moveStraight(int distance);			// move straight to target distance
// move straight

void moveLeftLineLeftSS();					// LL
void moveLeftLineRightSS();				// LR
void moveRightLineLeftSS();				// RL
void moveRightLineRightSS();				// RR

void moveRLToSkycrane();					// to sckycrane // right line left sensor

void moveRLToBall();						// until seeing balls; used in left chain
void moveLRToBall();						// until seeing balls; used in right chain

void moveRLToTransport();					// until detecting transport; used in left chain
void moveLRToTransport();					// until detecting transport; uset in right chain

void moveRLToLine(); 						// until the other sensor detecting line (corner); used in left chain
void moveLRToLine();						// until the other sensor detecting line (corner); used in right chain

void moveRRToGuy();						// until camera finding 'guy' at proper position
void botguyMove();							// special  for botguy detecting
// move along line related

void botguyGet();
// botguy related

void pushRedCube();
void moveRRToRedCube();

void LCBallGuySet();						// used in left chain
void LCBallGuySet();						// used in right chain
// balls and botguy set

void LCBallGetWithoutGuy();				// without botguy; used in left chain
void RCBallGetWithoutGuy();				// without botguy; used in right chain
void LCBallGetWithGuy(); 					// with fresh catched botguy; used in left chain
void RCBallGetWithGuy(); 					// with fresh catched botguy; used in right chain
void LCBallGetSteadyGuy(); 				// with botguy in proper position; used in left chain
void RCBallGetSteadyGuy(); 				// with botguy in proper position; used in right chain
// get balls on both sides and get back to line

void placeModificationWithoutGuy();		// without botguy
void placeModificationWithGuy();			// with botguy
void placeModificationSteadyGuy();			// with botguy in proper position
// place modification

void ballCatch();							// throwing ball into box
void armDownUp();							// move arm down and up to shake stucked ball
// ball catching

void PMBCWithoutGuy();						// without botguy and ball catching
void PMBCWithGuy();						// with botguy and ball catching
void PMBCSteadyGuy();						// with botguy in proper position
// place modification and ball catching


void skycraneAvd();						// skycrane avoiding
// skycraneAvd related

void leftChain();
void rightChain();
// chains


/*void delay()
{
	ao();
	beep();
	msleep(1000);
}*/
// trial

void ready()
{
	int side;
	camera_open(LOW_RES);
	enable_servos();									// everything is all on
	set_servo_position(c_ifrontSV, c_ifrontSVSet);
	set_servo_position(c_imicroSV, c_imicroSVSet);
	set_servo_position(c_iupperSV, c_iupperSVLevel);	// set servos
	set_servo_position(c_ibackSV, c_ibackSVClose);
	
	set_a_button_text("left");
	set_b_button_text("");
	set_c_button_text("right");							// choose which chain to run
	sleep(2);
	while (1)
	{
		if (a_button_clicked() == c_ibuttonClicked)
		{
			side = 1;
			break;
		}
		if (a_button_clicked() == c_ibuttonClicked)
		{
			side = 2;
			break;
		}
	}
	wait_for_light(5);
	shut_down_in(120);
	while (1)
	{
		if (side == 1)
		{
			leftChain();
			break;
		}
		if (side == 2)
		{
			rightChain();
			break;
		}
	}
}
// preparation

void leftTurn() 							// left turn to line
{
	int irightSSLV;
	int ileftSSLV;
	int imotorPosition, ilastMotorPosition;
	
	ileftSSLV = analog10(c_ileftSS);
	while (ileftSSLV < c_ileftSSBlack)		// while left sensor has not got to line
	{
		motor(c_ileftMotor, -90);
		motor(c_irightMotor, 80);
		ileftSSLV = analog10(c_ileftSS);
	}										// fast left turn
	
	// after the left sensor sees black
	imotorPosition = get_motor_position_counter(c_ileftMotor);
	irightSSLV = analog10(c_irightSS);
	while (irightSSLV < c_irightSSBlack)	// while right sensor has not got to line
	{
		imotorPosition = get_motor_position_counter(c_ileftMotor);
		if (abs(imotorPosition - ilastMotorPosition) < 10)		// the robot does not move
		{
			motor(c_ileftMotor, -80);
			motor(c_irightMotor, 70);
		}
		else
		{
			motor(c_ileftMotor, -70);
			motor(c_irightMotor, 60);
		}
		ilastMotorPosition = imotorPosition;
		irightSSLV = analog10(c_irightSS);
	}										// slow left turn
	//printf("leftTurn done!\n");
}
void rightTurn()							// right turn to line
{
	int ileftSSLV;
	int irightSSLV;
	int imotorPosition, ilastMotorPosition;
	
	irightSSLV = analog10(c_irightSS);
	while (irightSSLV < c_irightSSBlack)	// while right sensor has not got to line
	{
		motor(c_ileftMotor, 80);
		motor(c_irightMotor, -90);
		irightSSLV = analog10(c_irightSS);
	}										// fast right turn
	
	// after the right sensor sees black
	ileftSSLV = analog10(c_ileftSS);
	while (ileftSSLV < c_ileftSSBlack)		// while left sensor sees white
	{
		imotorPosition = get_motor_position_counter(c_ileftMotor);
		if (abs(imotorPosition - ilastMotorPosition) < 50)		// the robot does not move
		{
			motor(c_ileftMotor, 70);
			motor(c_irightMotor, -80);
		}									// fast turn
		else
		{
			motor(c_ileftMotor, 60);
			motor(c_irightMotor, -70);
		}
		ilastMotorPosition = imotorPosition;
		ileftSSLV = analog10(c_ileftSS);
	}										// slow right turn
	//printf("rightTurn done!\n");
	motor(c_ileftMotor, 0);
	motor(c_irightMotor, 0);
}
// turn to line

void LChemiLeftTurn() 						// left turn and only left sensor getting to line is ok
{
	int ileftSSLV;
	int imotorPosition, ilastMotorPosition;
	
	ileftSSLV = analog10(c_ileftSS);
	while (ileftSSLV < c_ileftSSBlack)		// while left sensor has not got to line
	{
		imotorPosition = get_motor_position_counter(c_ileftMotor);
		if (abs(imotorPosition - ilastMotorPosition) < 10)		// the robot does not move
		{
			motor(c_ileftMotor, -80);
			motor(c_irightMotor, 80);
		}									// fast turn
		else
		{
			motor(c_ileftMotor, -70);
			motor(c_irightMotor, 70);
		}
		ilastMotorPosition = imotorPosition;
		ileftSSLV = analog10(c_ileftSS);
	}										// slow right turn
	motor(c_ileftMotor, 0);
	motor(c_irightMotor, 0);
	//printf("hemiRightTurn done!\n");
}
void LChemiRightTurn()						// right turn and only right sensor getting to line is ok
{
	int ileftSSLV;
	int imotorPosition, ilastMotorPosition;
	
	ileftSSLV = analog10(c_ileftSS);
	while (ileftSSLV < c_ileftSSBlack) 	// if left sensor sees white
	{
		imotorPosition = get_motor_position_counter(c_ileftMotor);
		if (abs(imotorPosition - ilastMotorPosition) < 10)	// if the robot does not move
		{
			motor(c_ileftMotor, 80);
			motor(c_irightMotor, -80);
		}									// fast turn
		else
		{
			motor(c_ileftMotor, 70);
			motor(c_irightMotor, -70);
		}
		ilastMotorPosition = imotorPosition;
		ileftSSLV = analog10(c_ileftSS);
	}										// slow right turn
	motor(c_ileftMotor, 0);
	motor(c_irightMotor, 0);
	//printf("hemiRightTurn done!\n");
}
// LC 'balGet' turn

void rightCornerTurn()
{
	moveStraight(300);
	rightTurn();
	//printf("rightCornerTurn done!");
}
void leftCornerTurn()
{
	moveStraight(300);
	leftTurn();
}
// corner turn

void rightSpin()							// right turn to backward; to get botguy
{
	clear_motor_position_counter(c_ileftMotor);
	clear_motor_position_counter(c_irightMotor);
	mtp(c_ileftMotor, 1500, 480);
	mtp(c_irightMotor, -1500, -480);
	bmd(c_ileftMotor);
	bmd(c_irightMotor);						// right turn to dodge line
	
	rightTurn();							// keep right turn to line
	//printf("rightSpin done!\n");
}
// botguy get turn

void leftTurnToBall()						// left turn to ball
{
	int iobjectNum;							// variable of judgement
	
	camera_load_config("green");
	camera_update();
	camera_update();
	iobjectNum = get_object_count(0);
	while (iobjectNum == 0)				// if there is no ball in sight
	{
		motor(c_ileftMotor, -70);
		motor(c_irightMotor, 70);			// left turn
		camera_update();
		camera_update();
		iobjectNum = get_object_count(0);	// re-detect of judgement
	}
	clear_motor_position_counter(c_ileftMotor);
	clear_motor_position_counter(c_irightMotor);
	mtp(c_ileftMotor, -1050, -80);
	mtp(c_irightMotor, 1050, 80);
	bmd(c_ileftMotor);
	bmd(c_irightMotor);
	//printf("leftTurnToBall done!\n");
}
void rightTurnToBall()						// right turn to ball
{
	int iobjectNum;							// variable of judgement
	
	camera_load_config("green");
	camera_update();
	camera_update();
	iobjectNum = get_object_count(0);
	while (iobjectNum == 0)				// if there is no ball in sight
	{
		motor(c_ileftMotor, 70);
		motor(c_irightMotor, -70);			// right turn
		camera_update();
		camera_update();
		
		iobjectNum = get_object_count(0);	// re-detect of judgement
	}
	clear_motor_position_counter(c_ileftMotor);
	clear_motor_position_counter(c_irightMotor);
	mtp(c_ileftMotor, 1050, 80);
	mtp(c_irightMotor, -1050, -80);
	bmd(c_ileftMotor);
	bmd(c_irightMotor);
	//printf("rightTurnToBall done!\n");
}
// turn to ball
// turn related

void moveStraight(int distance)			// move straight to target distance
{
	clear_motor_position_counter(c_ileftMotor);
	clear_motor_position_counter(c_irightMotor);
	mtp(c_ileftMotor, 1500, distance);
	mtp(c_irightMotor, 1500, distance);
	bmd(c_ileftMotor);
	bmd(c_irightMotor);
	//printf("moveStraight done!\n");
}
// move straight

void moveLeftLineLeftSS()
{
	int ileftSSLV;
	int ierror;
	int iintegral = 0;
	int ilastError;
	int iderivative;
	int iturn;
	int ileftMotorPower, irightMotorPower;								// variables of PID
	
	ileftSSLV = analog10(c_ileftSS);
	ierror = ileftSSLV - c_ileftSSOffset;
	ierror = ierror / 10;
	iintegral = iintegral / 2 + ierror;
	if (iintegral * ierror < 0)
		iintegral = 0;
	iderivative = ierror - ilastError;
	iturn = ierror / c_ip + iintegral / c_ii + iderivative / c_id;
	iturn = iturn * 10;
	ileftMotorPower = c_iTpower - iturn;
	irightMotorPower = c_iTpower + iturn;
	if (ileftSSLV < c_ileftSSWhite)
		irightMotorPower = irightMotorPower - c_iacWhite;
	if (ileftSSLV > c_ileftSSBlack)
		ileftMotorPower = ileftMotorPower - c_iacBlack;
	motor(c_ileftMotor, ileftMotorPower);
	motor(c_irightMotor, irightMotorPower);								// PID series
	ilastError = ierror;
}

void moveLeftLineRightSS()
{
	int irightSSLV;
	int ierror;
	int iintegral = 0;
	int ilastError;
	int iderivative;
	int iturn;
	int ileftMotorPower, irightMotorPower;								// variables of PID
	
	irightSSLV = analog10(c_irightSS);
	ierror = irightSSLV - c_irightSSOffset;
	ierror = ierror / 10;
	iintegral = iintegral / 2 + ierror;
	if (iintegral * ierror < 0)
		iintegral = 0;
	iderivative = ierror - ilastError;
	iturn = ierror / c_ip + iintegral / c_ii + iderivative / c_id;
	iturn = iturn * 10;
	ileftMotorPower = c_iTpower - iturn;
	irightMotorPower = c_iTpower + iturn;
	if (irightSSLV < c_irightSSWhite)
		irightMotorPower = irightMotorPower - c_iacWhite;
	if (irightSSLV > c_irightSSBlack)
		ileftMotorPower = ileftMotorPower - c_iacBlack;
	motor(c_ileftMotor, ileftMotorPower);
	motor(c_irightMotor, irightMotorPower);								// PID series
	ilastError = ierror;
}

void moveRightLineLeftSS()
{
	int ileftSSLV;
	int ierror;
	int iintegral = 0;
	int ilastError;
	int iderivative;
	int iturn;
	int ileftMotorPower, irightMotorPower;								// variables of PID
	
	ileftSSLV = analog10(c_ileftSS);
	ierror = ileftSSLV - c_ileftSSOffset;
	ierror = ierror / 10;
	iintegral = iintegral / 2 + ierror;
	if (iintegral * ierror < 0)
		iintegral = 0;
	iderivative = ierror - ilastError;
	iturn = ierror / c_ip + iintegral / c_ii + iderivative / c_id;
	iturn = iturn * 10;
	ileftMotorPower = c_iTpower + iturn;
	irightMotorPower = c_iTpower - iturn;
	if (ileftSSLV < c_ileftSSWhite)
		ileftMotorPower = ileftMotorPower - c_iacWhite;
	if (ileftSSLV > c_ileftSSBlack)
		irightMotorPower = irightMotorPower - c_iacBlack;
	motor(c_ileftMotor, ileftMotorPower);
	motor(c_irightMotor, irightMotorPower);								// PID series
	ilastError = ierror;
}

void moveRightLineRightSS()
{
	int irightSSLV;
	int ierror;
	int iintegral = 0;
	int ilastError;
	int iderivative;
	int iturn;
	int ileftMotorPower, irightMotorPower;								// variables of PID
	
	irightSSLV = analog10(c_irightSS);
	ierror = irightSSLV - c_irightSSOffset;
	ierror = ierror / 10;
	iintegral = iintegral / 2 + ierror;
	if (iintegral * ierror < 0)
		iintegral = 0;
	iderivative = ierror - ilastError;
	iturn = ierror / c_ip + iintegral / c_ii + iderivative / c_id;
	iturn = iturn * 10;
	ileftMotorPower = c_iTpower + iturn;
	irightMotorPower = c_iTpower - iturn;
	if (irightSSLV < c_irightSSWhite)
		ileftMotorPower = ileftMotorPower - c_iacWhite;
	if (irightSSLV > c_irightSSBlack)
		irightMotorPower = irightMotorPower - c_iacBlack;
	motor(c_ileftMotor, ileftMotorPower);
	motor(c_irightMotor, irightMotorPower);								// PID series
	ilastError = ierror;
}
// base 'move along line'

void moveRLToSkycrane()
{
	int itsState;									// variable of judgement
	
	itsState = digital(c_itouchSS);
	while (itsState == c_itouchSSBare) 			// if the touch sensor has not touched skycrane
	{
		moveRightLineLeftSS();
		itsState = digital(c_itouchSS); 			// re-detect of judgement
	}
	
	//printf("moveRLToSkycrane done!");
}
// to skycrane

void moveLRToBall() 								//  until seeing balls
{
	int iobjectNum; 								// variable of judgement
	
	camera_load_config("green");
	camera_update();
	camera_update();
	iobjectNum = get_object_count(0);
	while (iobjectNum == 0) 						// if there is no green ball in sight
	{
		moveLeftLineRightSS();
		
		camera_update();
		camera_update();
		iobjectNum = get_object_count(0); 			// re-detect of judgement
	}
}
void moveRLToBall() 								//  until seeing balls
{
	//printf("RL begin\n");
	int iobjectNum; 								// variable of judgement
	
	camera_load_config("green");
	camera_update();
	camera_update();
	iobjectNum = get_object_count(0);
	while (iobjectNum == 0)						// if there is no green ball in sight
	{
		moveRightLineLeftSS();
		
		camera_update();
		camera_update();
		iobjectNum = get_object_count(0); 			// re-detect of judgement
	}
}

// to ball

void moveRLToTransport() 							//  until seeing transport
{
	int idownLV, irightSSLV; 						// variable of judgement
	
	idownLV = analog10(c_idownSS);
	while (idownLV > c_idownSSOffset) 				// if the down sensor sees nothing
	{
		moveRightLineLeftSS();
		irightSSLV = analog10(c_irightSS);
		if (irightSSLV > c_irightSSOffset)
			LChemiRightTurn;
		idownLV = analog10(c_idownSS); 				// re-detect of judgement
	}
}
void moveLRToTransport() 							//  until seeing transport
{
	int idownLV; 									// variable of judgement
	
	idownLV = analog10(c_idownSS);
	while (idownLV > c_idownSSOffset)				// if the down sensor sees nothing
	{
		moveLeftLineRightSS();
		
		idownLV = analog10(c_idownSS); 				// re-detect of judgement
	}
}
// to transport

void moveLRToLine() 								//  until judge_sensor seeing line
{
	int ileftSSLV; 									// variable of judgement
	
	ileftSSLV = analog10(c_ileftSS);
	while (ileftSSLV < c_irightSSBlack) 			// if the judge sensor sees white
	{
		moveLeftLineRightSS();
		
		ileftSSLV = analog10(c_ileftSS); 			// re-detect of judgement
	}
}
void moveRLToLine() 								//  until judge_sensor seeing line
{
	int irightSSLV; 								// variable of judgement
	
	irightSSLV = analog10(c_irightSS);
	while (irightSSLV < c_irightSSBlack) 			// if the judge sensor sees white
	{
		moveRightLineLeftSS();
		
		irightSSLV = analog10(c_irightSS); 			// re-detect of judgement
	}
	
	//printf("moveRLToLine done\n");
}
// to line(corner)

void moveRRToGuy()
{
	int iobjectNum, iobjectArea;
	point2 iobjectCenter;
	
	iobjectCenter.y = 1;
	camera_load_config("botguy");
	camera_update();
	camera_update();
	iobjectNum = get_object_count(0);
	if (iobjectNum > 0)
	{
		iobjectCenter = get_object_center(0, 0);
		iobjectArea = get_object_area(0, 0);
	}
	while (1)
	{
		botguyMove();
		
		camera_update();
		camera_update();
		iobjectNum = get_object_count(0);
		if (iobjectNum > 0)
		{
			iobjectCenter = get_object_center(0, 0);
			iobjectArea = get_object_area(0, 0);
			if (iobjectCenter.y > 90 && iobjectArea > 200)
				break;
		}
	}
	motor(c_ileftMotor, 0);
	motor(c_irightMotor, 0);
	//printf("moveToGuy done!\n");
}
void botguyMove()
{
	int irightSSLV;
	int ierror;
	int iintegral = 0;
	int ilastError;
	int iderivative;
	int iturn;
	int ileftMotorPower, irightMotorPower; 								// variables of PID
	
	irightSSLV = analog10(c_irightSS);
	ierror = irightSSLV - c_irightSSOffset;
	ierror = ierror / 10;
	iintegral = iintegral / 2 + ierror;
	if (iintegral * ierror < 0)
		iintegral = 0;
	iderivative = ierror - ilastError;
	iturn = ierror / c_ip + iintegral / c_ii + iderivative / c_id;
	iturn = iturn * 10;
	ileftMotorPower = c_ibotguyTpower + iturn;
	irightMotorPower = c_ibotguyTpower - iturn;
	if (irightSSLV < c_irightSSWhite)
		ileftMotorPower = ileftMotorPower - c_iacWhite;
	if (irightSSLV > c_irightSSBlack)
		irightMotorPower = irightMotorPower - c_iacBlack;
	motor(c_ileftMotor, ileftMotorPower);
	motor(c_irightMotor, irightMotorPower); 							// PID series
	ilastError = ierror;
}
// to botguy
// move along line related

void botguyGet()
{
	int leftSSLV;
	set_servo_position(c_ibackSV, c_ibackSVOpen);
	rightSpin();
	moveStraight(-250);
	leftSSLV = analog10(c_ileftSS);
	while (leftSSLV > c_ileftSSBlack)
	{
		motor(c_ileftMotor, 80);
		motor(c_irightMotor, -80);
		leftSSLV = analog10(c_ileftSS);
	}
	set_servo_position(c_ibackSV, c_ibackSVClose);
	msleep(500);
	rightSpin();
}
// botguy get

void moveRRToRedCube()
{
	int idownSSLV = analog10(c_idownSS);;
	while (idownSSLV > c_idownSSOffset)
	{
		moveRightLineRightSS();
		idownSSLV = analog10(c_idownSS);
	}
}
void pushRedCube()
{
	mav(c_irightMotor, 1500);
	msleep(1800);
	motor(c_irightMotor, 0);
	mav(c_irightMotor, -1500);
	msleep(1800);
}
// Red Cube related

void LCBallGuySet()									 // put ball down; used in left chain
{
	clear_motor_position_counter(c_ileftMotor);
	clear_motor_position_counter(c_irightMotor);
	mtp(c_ileftMotor, 1500, 700);
	mtp(c_irightMotor, -1500, -700);
	bmd(c_ileftMotor);
	bmd(c_irightMotor);
	
	set_servo_position(c_iupperSV, c_iupperSVDown);
	msleep(1000);										// set the box down
	
	set_servo_position(c_iupperSV, c_iupperSVLevel);
	msleep(600);										// set the box back up
	
	clear_motor_position_counter(c_ileftMotor);
	clear_motor_position_counter(c_irightMotor);
	mtp(c_ileftMotor, 1500, 2000);
	mtp(c_irightMotor, -1500, 2000);
	bmd(c_ileftMotor);
	bmd(c_irightMotor);
	//printf("bDown done!\n");
}

void RCBallGuySet()									// put ball down; used in right chain
{
	clear_motor_position_counter(c_ileftMotor);
	clear_motor_position_counter(c_irightMotor);
	mtp(c_ileftMotor, 1500, 700);
	mtp(c_irightMotor, -1500, -700);
	bmd(c_ileftMotor);
	bmd(c_irightMotor);
	
	set_servo_position(c_iupperSV, c_iupperSVDown);
	msleep(1000);										// set the box down
	
	set_servo_position(c_iupperSV, c_iupperSVLevel);	// set the box back up
	
	clear_motor_position_counter(c_ileftMotor);
	clear_motor_position_counter(c_irightMotor);
	mtp(c_ileftMotor, 1500, -2000);
	mtp(c_irightMotor, -1500, -2000);
	bmd(c_ileftMotor);
	bmd(c_irightMotor);
	//printf("bDown done!\n");
}
// balls guy set

void LCBallGetSteadyGuy()				// get balls on both sides and get back to line
{
	ao();
	int i;
	int ileftMotorPosition, irightMotorPosition, lineXCenter = 0;
	point2 lineCenter, ballCenter;
	
	camera_load_config("line");
	camera_update();
	camera_update();
	lineCenter = get_object_center(0, 0);
	
	camera_load_config("green");
	camera_update();
	camera_update();
	ballCenter = get_object_center(0, 0);
	
	PMBCSteadyGuy();					// get the left ball
	    //delay();
		
	if (lineCenter.x < ballCenter.x )
	{
		leftTurnToBall();
			//delay();
		PMBCSteadyGuy();
			//delay();
	}
	
	else 
	{
		rightTurnToBall();
			//delay();
		PMBCSteadyGuy();				// get the right ball
			//delay();
		LChemiLeftTurn();
	}
	
	LChemiRightTurn();
}

void LCBallGetWithGuy()				// 
{
	ao();
	int i;
	int ileftMotorPosition, irightMotorPosition, lineXCenter = 0;
	point2 lineCenter, ballCenter;
	
	camera_load_config("line");
	camera_update();
	camera_update();
	lineCenter = get_object_center(0, 0);
	
	camera_load_config("green");
	camera_update();
	camera_update();
	ballCenter = get_object_center(0, 0);
	
	PMBCWithGuy();						// get the left ball
	    //delay();
		
	if (lineCenter.x < ballCenter.x )
	{
		leftTurnToBall();
			//delay();
		PMBCWithGuy();
			//delay();
		LChemiRightTurn();
	}
	
	else 
	{
		rightTurnToBall();
			//delay();
		PMBCWithGuy();					// get the right ball
			//delay();
		LChemiLeftTurn();
	}
}

/*void RCBallGet()						// get balls on both sides and get back to line
{
	ao();
	int i;
	int ileftMotorPosition, irightMotorPosition, lineXCenter = 0;
	point2 lineCenter, ballCenter;
	
	camera_load_config("line");
	camera_update();
	camera_update();
	lineCenter = get_object_center(0, 0);
	
	camera_load_config("green");
	camera_update();
	camera_update();
	ballCenter = get_object_center(0, 0);
	
	PMBC();								// get the left ball
	    //delay();
		
	if (lineCenter.x < ballCenter.x )
	{
		leftTurnToBall();
			//delay();
		PMBC();
			//delay();
		LChemiRightTurn();
	}
	
	else 
	{
		rightTurnToBall();
			//delay();
		PMBC();							// get the right ball
			//delay();
		LChemiLeftTurn();
	}
}*/

void LCBallGetWithoutGuy()
{
	moveStraight(400);					// move a little forward in case both balls in sight
		//delay();
	rightTurnToBall();
		//delay();
	
	PMBCWithoutGuy();					// get the right ball
	    //delay();
	
	leftTurnToBall();
		//delay();
	PMBCWithoutGuy();					// get the left ball
		//delay();
	LChemiRightTurn();
}

void placeModificationWithoutGuy()									// when botguy is not catched
{
	point2 objectCenter;
	int iobjectNum = 1;												// variables of camera
	int ileftMotorPower, irightMotorPower;
	int ierrorX, ierrorY;
	int iturnX, iturnY;
	int iintegralX = 0, iintegralY = 0;
	int ilastErrorX = 0, ilastErrorY = 0;
	int iderivativeX = 0, iderivativeY = 0;						// variables of PID
	
	camera_load_config("green");
	camera_update();
	camera_update();
	objectCenter = get_object_center(0, 0);							// identify the position of the green ball
	while (!(abs(objectCenter.x - c_ioffsetX) <= c_ideviationX && abs(objectCenter.y - c_ioffsetY) <= c_ideviationY))
	{
		if (iobjectNum == 0)										// if there is no ball in sight
		{
			motor(c_ileftMotor, c_iLCPowerMinWithoutGuy);
			motor(c_irightMotor, -1 * c_iLCPowerMinWithoutGuy);
			ierrorX = 0;
			ierrorY = 0;
			iturnX = 0;
			iturnY = 0;
			iintegralX = 0;
			iintegralY = 0;
			ilastErrorX = 0;
			ilastErrorY = 0;
			iderivativeX = 0;
			iderivativeY = 0;
		}															// right spin to find ball
		else
		{
			objectCenter = get_object_center(0, 0);
			ierrorX = objectCenter.x - c_ioffsetX;
			ierrorY = objectCenter.y - c_ioffsetY;
					//iintegralX = iintegralX / 2 + ierrorX;
					//if (iintegralX * ierrorX < 0)
					//	iintegralX = 0;
					//if (iintegralY * ierrorY < 0)
					//	iintegralY = 0;
			iderivativeX = ierrorX - ilastErrorX;
			iderivativeY = ierrorY - ilastErrorY;
			iturnX = ierrorX / c_ipX;// + iintegralX / c_iiX + iderivativeX / c_idX;
			iturnY = ierrorY / c_ipY;// + iintegralY / c_iiY + iderivativeY / c_idY;
			ileftMotorPower = -1 * iturnY + iturnX;
			irightMotorPower = -1 * iturnY - iturnX;				// PID series
			
			if (ileftMotorPower > c_ipowerMax)
				ileftMotorPower = c_ipowerMax;
			if (irightMotorPower > c_ipowerMax)
				irightMotorPower = c_ipowerMax;
			if (ileftMotorPower < -1 * c_ipowerMax)
				ileftMotorPower = -1 * c_ipowerMax;
			if (irightMotorPower < -1 * c_ipowerMax)
				irightMotorPower = -1 * c_ipowerMax;				// limit the maximum power of motors in case the robot moves too fast
			
			if (ileftMotorPower < c_iLCPowerMinWithoutGuy && ileftMotorPower > 0)
				ileftMotorPower = c_iLCPowerMinWithoutGuy;
			if (irightMotorPower < c_iLCPowerMinWithoutGuy && irightMotorPower > 0)
				irightMotorPower = c_iLCPowerMinWithoutGuy;
			if (ileftMotorPower > -1 * c_iLCPowerMinWithoutGuy && ileftMotorPower < 0)
				ileftMotorPower = -1 * c_iLCPowerMinWithoutGuy;
			if (irightMotorPower > -1 * c_iLCPowerMinWithoutGuy && irightMotorPower < 0)
				irightMotorPower = -1 * c_iLCPowerMinWithoutGuy;	// limit the minimum power of motors in case the robot does not move
			
			if (ileftMotorPower == 0)
				ileftMotorPower = -1 * irightMotorPower;
			if (irightMotorPower == 0)
				irightMotorPower = -1 * ileftMotorPower;
			
			ileftMotorPower = ileftMotorPower * 1.2;
			irightMotorPower = irightMotorPower * 1.2;
			
			
			if (abs(iderivativeX) < c_ideviationY && abs(iderivativeY) < c_ideviationY)	// the robot did not move
			{
				ileftMotorPower = 1.6 * ileftMotorPower;
				irightMotorPower = 1.6 * irightMotorPower;
			}														// increase the power of motors to get it moved
			motor(c_ileftMotor, ileftMotorPower);
			motor(c_irightMotor, irightMotorPower);					// move motors
			ilastErrorX = ierrorX;
			ilastErrorY = ierrorY;									// PID series
		}
		
		camera_update();
		camera_update();
		iobjectNum = get_object_count(0);							// check if the ball fell from 'hand' or catched a wrong one
	}
	motor(c_ileftMotor, 0);
	motor(c_irightMotor, 0);
	//printf("placeModification done!");
}

void placeModificationWithGuy()									// when botguy is recently catched
{
	int timestart = seconds();
	point2 objectCenter;
	int iobjectNum = 1;												// variables of camera
	int ileftMotorPower, irightMotorPower;
	int ierrorX, ierrorY;
	int iturnX, iturnY;
	int iintegralX = 0, iintegralY = 0;
	int ilastErrorX = 0, ilastErrorY = 0;
	int iderivativeX = 0, iderivativeY = 0;						// variables of PID
	
	camera_load_config("green");
	camera_update();
	camera_update();
	objectCenter = get_object_center(0, 0);							// identify the position of the green ball
	while (!(abs(objectCenter.x - c_ioffsetX) <= c_ideviationX && abs(objectCenter.y - c_ioffsetY) <= c_ideviationY))
	{
		if (iobjectNum == 0)										// if there is no ball in sight
		{
			int currenttime = seconds();
			int time = currenttime - timestart;
			if (time > 3)
				break;
			motor(c_ileftMotor, c_iLCPowerMinWithGuy);
			motor(c_irightMotor, -1 * c_iLCPowerMinWithGuy);
			ierrorX = 0;
			ierrorY = 0;
			iturnX = 0;
			iturnY = 0;
			iintegralX = 0;
			iintegralY = 0;
			ilastErrorX = 0;
			ilastErrorY = 0;
			iderivativeX = 0;
			iderivativeY = 0;
		}															// right spin to find ball
		else
		{
			objectCenter = get_object_center(0, 0);
			ierrorX = objectCenter.x - c_ioffsetX;
			ierrorY = objectCenter.y - c_ioffsetY;
					//iintegralX = iintegralX / 2 + ierrorX;
					//if (iintegralX * ierrorX < 0)
					//	iintegralX = 0;
					//if (iintegralY * ierrorY < 0)
					//	iintegralY = 0;
			iderivativeX = ierrorX - ilastErrorX;
			iderivativeY = ierrorY - ilastErrorY;
			iturnX = ierrorX / c_ipX;// + iintegralX / c_iiX + iderivativeX / c_idX;
			iturnY = ierrorY / c_ipY;// + iintegralY / c_iiY + iderivativeY / c_idY;
			ileftMotorPower = -1 * iturnY + iturnX;
			irightMotorPower = -1 * iturnY - iturnX;				// PID series
			
			if (ileftMotorPower > c_ipowerMax)
				ileftMotorPower = c_ipowerMax;
			if (irightMotorPower > c_ipowerMax)
				irightMotorPower = c_ipowerMax;
			if (ileftMotorPower < -1 * c_ipowerMax)
				ileftMotorPower = -1 * c_ipowerMax;
			if (irightMotorPower < -1 * c_ipowerMax)
				irightMotorPower = -1 * c_ipowerMax;				// limit the maximum power of motors in case the robot moves too fast
			
			if (ileftMotorPower < c_iLCPowerMinWithGuy && ileftMotorPower > 0)
				ileftMotorPower = c_iLCPowerMinWithGuy;
			if (irightMotorPower < c_iLCPowerMinWithGuy && irightMotorPower > 0)
				irightMotorPower = c_iLCPowerMinWithGuy;
			if (ileftMotorPower > -1 * c_iLCPowerMinWithGuy && ileftMotorPower < 0)
				ileftMotorPower = -1 * c_iLCPowerMinWithGuy;
			if (irightMotorPower > -1 * c_iLCPowerMinWithGuy && irightMotorPower < 0)
				irightMotorPower = -1 * c_iLCPowerMinWithGuy;		// limit the minimum power of motors in case the robot does not move
			
			if (ileftMotorPower == 0)
				ileftMotorPower = -1 * irightMotorPower;
			if (irightMotorPower == 0)
				irightMotorPower = -1 * ileftMotorPower;
			
			ileftMotorPower = ileftMotorPower * 1.4;
			irightMotorPower = irightMotorPower * 1.4;
			
			
			if (abs(iderivativeX) < c_ideviationY && abs(iderivativeY) < c_ideviationY)		// the robot did not move
			{
				ileftMotorPower = 1.6 * ileftMotorPower;
				irightMotorPower = 1.6 * irightMotorPower;
			}														// increase the power of motors to get it moved
			motor(c_ileftMotor, ileftMotorPower);
			motor(c_irightMotor, irightMotorPower);					// move motors
			ilastErrorX = ierrorX;
			ilastErrorY = ierrorY;									// PID series
		}
		
		camera_update();
		camera_update();
		iobjectNum = get_object_count(0);							// check if the ball fell from 'hand' or catched a wrong one
	}
	motor(c_ileftMotor, 0);
	motor(c_irightMotor, 0);
	//printf("placeModification done!");
}

void placeModificationSteadyGuy()									// when botguy is steady
{
	point2 objectCenter;
	int iobjectNum = 1;												// variables of camera
	int ileftMotorPower, irightMotorPower;
	int ierrorX, ierrorY;
	int iturnX, iturnY;
	int iintegralX = 0, iintegralY = 0;
	int ilastErrorX = 0, ilastErrorY = 0;
	int iderivativeX = 0, iderivativeY = 0;						// variables of PID
	
	camera_load_config("green");
	camera_update();
	camera_update();
	objectCenter = get_object_center(0, 0);							// identify the position of the green ball
	while (!(abs(objectCenter.x - c_ioffsetX) <= c_ideviationX && abs(objectCenter.y - c_ioffsetY) <= c_ideviationY))
	{
		if (iobjectNum == 0)										// if there is no ball in sight
		{
			motor(c_ileftMotor, c_iLCPowerMinSteayGuy);
			motor(c_irightMotor, -1 * c_iLCPowerMinSteayGuy);
			ierrorX = 0;
			ierrorY = 0;
			iturnX = 0;
			iturnY = 0;
			iintegralX = 0;
			iintegralY = 0;
			ilastErrorX = 0;
			ilastErrorY = 0;
			iderivativeX = 0;
			iderivativeY = 0;
		}															// right spin to find ball
		else
		{
			objectCenter = get_object_center(0, 0);
			ierrorX = objectCenter.x - c_ioffsetX;
			ierrorY = objectCenter.y - c_ioffsetY;
					//iintegralX = iintegralX / 2 + ierrorX;
					//if (iintegralX * ierrorX < 0)
					//	iintegralX = 0;
					//if (iintegralY * ierrorY < 0)
					//	iintegralY = 0;
			iderivativeX = ierrorX - ilastErrorX;
			iderivativeY = ierrorY - ilastErrorY;
			iturnX = ierrorX / c_ipX;// + iintegralX / c_iiX + iderivativeX / c_idX;
			iturnY = ierrorY / c_ipY;// + iintegralY / c_iiY + iderivativeY / c_idY;
			ileftMotorPower = -1 * iturnY + iturnX;
			irightMotorPower = -1 * iturnY - iturnX;				// PID series
			
			if (ileftMotorPower > c_ipowerMax)
				ileftMotorPower = c_ipowerMax;
			if (irightMotorPower > c_ipowerMax)
				irightMotorPower = c_ipowerMax;
			if (ileftMotorPower < -1 * c_ipowerMax)
				ileftMotorPower = -1 * c_ipowerMax;
			if (irightMotorPower < -1 * c_ipowerMax)
				irightMotorPower = -1 * c_ipowerMax;				// limit the maximum power of motors in case the robot moves too fast
			
			if (ileftMotorPower < c_iLCPowerMinSteayGuy && ileftMotorPower > 0)
				ileftMotorPower = c_iLCPowerMinSteayGuy;
			if (irightMotorPower < c_iLCPowerMinSteayGuy && irightMotorPower > 0)
				irightMotorPower = c_iLCPowerMinSteayGuy;
			if (ileftMotorPower > -1 * c_iLCPowerMinSteayGuy && ileftMotorPower < 0)
				ileftMotorPower = -1 * c_iLCPowerMinSteayGuy;
			if (irightMotorPower > -1 * c_iLCPowerMinSteayGuy && irightMotorPower < 0)
				irightMotorPower = -1 * c_iLCPowerMinSteayGuy;		// limit the minimum power of motors in case the robot does not move
			
			if (ileftMotorPower == 0)
				ileftMotorPower = -1 * irightMotorPower;
			if (irightMotorPower == 0)
				irightMotorPower = -1 * ileftMotorPower;
			
			ileftMotorPower = ileftMotorPower * 1.3;
			irightMotorPower = irightMotorPower * 1.3;
			
			
			if (abs(iderivativeX) < c_ideviationY && abs(iderivativeY) < c_ideviationY)		// the robot did not move
			{
				ileftMotorPower = 1.6 * ileftMotorPower;
				irightMotorPower = 1.6 * irightMotorPower;
			}														// increase the power of motors to get it moved
			motor(c_ileftMotor, ileftMotorPower);
			motor(c_irightMotor, irightMotorPower);					// move motors
			ilastErrorX = ierrorX;
			ilastErrorY = ierrorY;									// PID series
		}
		
		camera_update();
		camera_update();
		iobjectNum = get_object_count(0);							// check if the ball fell from 'hand' or catched a wrong one
	}
	motor(c_ileftMotor, 0);
	motor(c_irightMotor, 0);
	//printf("placeModification done!");
}
// place modification

void ballCatch()
{
	int i, iobjectArea, s = 0;
	
	set_servo_position(c_ifrontSV, c_ifrontSVBallCatch);
	msleep(700);													// put arm down lower than the position that keeps the robot level
	
	for (i = 0; i <= 3; i++)
	{
		motor(c_ileftMotor, 40);
		motor(c_irightMotor, 60);
		msleep(130);
		motor(c_ileftMotor, -40);
		motor(c_irightMotor, -60);
		msleep(130);
	}																// move forward and backward to ensure that the ball is in 'hand'
	motor(c_ileftMotor, 0);
	motor(c_irightMotor, 0);										// stop all motors
	
	for (i = c_ifrontSVBallCatch; i <= c_ifrontSVBallHold; i++)
	{
		set_servo_position(c_ifrontSV, i);
		msleep(2);
	}																// put the arm a little up in case harmful impact
	for (i = c_ifrontSVBallHold; i <= c_ifrontSVJudge; i++)
	{
		set_servo_position(c_ifrontSV, i);
		msleep(i / 700);
	}																// put the arm up to judge position ------ 
																	// a proper position to identify the color of ball in 'hand'
	
	camera_load_config("green");
	camera_update();
	camera_update();
	iobjectArea = get_object_area(0, 0);							// identify the color of ball in 'hand'
	
	if (iobjectArea > 800)											// the ball in 'hand' is green
	{
		while (iobjectArea > 800)									// in case the ball staying in 'hand'
		{
			s++;													// if the ball stay in 'hand', count it once
			
			if (s == 5)											// if the ball stay in 'hand' for 5 times
			{
				armDownUp();
				s = 1;
			}														//we need to drop arm to shake it
			
			set_servo_position(c_ifrontSV, c_ifrontSVSet);
			msleep(400);											// shock the ball into the box
			
			for(i = c_ifrontSVSet; i >= c_ifrontSVJudge; i--)
			{
				set_servo_position(c_ifrontSV, i);
				msleep(1);
			}														// put arm back to judge position
			
			camera_update();
			camera_update();
			iobjectArea = get_object_area(0, 0);					// see if the ball was shocked
		}
	}
	else
	{
		camera_load_config("orange");
		camera_update();
		camera_update();
		iobjectArea = get_object_area(0, 0);
		if (iobjectArea > 800)										// the ball in the 'hand' is orange
		{
			set_servo_position(c_imicroSV, c_imicroSVAwaken);
			msleep(800);
			set_servo_position(c_imicroSV, c_imicroSVRelease);
			msleep(100); 
			set_servo_position(c_imicroSV, c_imicroSVAwaken);
			msleep(100);
			set_servo_position(c_imicroSV, c_imicroSVSet);
			msleep(500);
		}															// use microservo (little hand) get rid of the orange ball
																	// it is certain to get rid of the ball with double move of little hand
	}
	set_servo_position(c_ifrontSV, c_ifrontSVSet);
	//printf("ballCatch done!\n");
}
// ball catch

void PMBCWithoutGuy()
{
	int iobjectNum;
	point2 objectCenter;
	
	camera_load_config("green");
	camera_update();
	camera_update();
	iobjectNum = get_object_count(0);
	while (iobjectNum != 0)										// in case the ball falling from the 'hand'
	{
		placeModificationWithoutGuy();
		ballCatch();
		camera_load_config("green");
		camera_update();
		camera_update();
		iobjectNum = get_object_count(0);
	}
	//printf("PMBC done!\n");
}

void PMBCWithGuy()
{
	int iobjectNum;
	point2 objectCenter;
	
	camera_load_config("green");
	camera_update();
	camera_update();
	iobjectNum = get_object_count(0);
	while (iobjectNum != 0)										// in case the ball falling from the 'hand'
	{
		placeModificationWithGuy();
		ballCatch();
		camera_load_config("green");
		camera_update();
		camera_update();
		iobjectNum = get_object_count(0);
	}
	//printf("PMBC done!\n");
}

void PMBCSteadyGuy()
{
	int iobjectNum;
	point2 objectCenter;
	
	camera_load_config("green");
	camera_update();
	camera_update();
	iobjectNum = get_object_count(0);
	while (iobjectNum != 0)										// in case the ball falling from the 'hand'
	{
		placeModificationSteadyGuy();
		ballCatch();
		camera_load_config("green");
		camera_update();
		camera_update();
		iobjectNum = get_object_count(0);
	}
	//printf("PMBC done!\n");
}
// place modification & ball catch; catch a ball

void armDownUp()
{
	int i;
	
	set_servo_position(c_ifrontSV, c_ifrontSVArmDown);
	
	for (i = c_ifrontSVArmDown; i <= c_ifrontSVBallHold; i++)
	{
		set_servo_position(c_ifrontSV, i);
		msleep(2);
	}																// put arm a little up
	for (i = c_ifrontSVBallHold; i <= c_ifrontSVJudge; i++)
	{
		set_servo_position(c_ifrontSV, i);
		msleep(i / 700);
	}																// put arm up to judge position at slowlier speed
																	// in order to keep the ball in the 'hand'
	//printf("armDownUp done!");
}
// ball catch related

void skycraneAvd() 					// skycrane avoiding
{
	int ileftLV;
	
	moveStraight(-250);					// back
	
	clear_motor_position_counter(c_irightMotor);
	mtp(c_ileftMotor, 1500, 200);
	bmd(c_ileftMotor);					// turn to a little right
	
	moveStraight(225);
	
	clear_motor_position_counter(c_irightMotor);
	mtp(c_irightMotor, 1500, 500);
	bmd(c_irightMotor);					// turn to a little left
	
	ileftLV = analog10(c_ileftSS);
	while (ileftLV < c_ileftSSBlack)
	{
		motor(c_ileftMotor, 85);
		motor(c_irightMotor, 100);
		ileftLV = analog10(c_ileftSS);
	}									// go to black line with right motor moving a little faster
	moveStraight(300);
	//printf("skycraneAvd done!\n");
}

void leftChain()
{
	moveRLToLine();
		//delay();
	rightCornerTurn();
		//delay();
	moveRLToBall();
		//delay();
	LCBallGetWithoutGuy();
		//delay();
	moveRRToGuy();
		//delay();
	botguyGet();
		//delay();
	moveRLToBall();
		//delay();
	LCBallGetWithGuy();
		//delay();
	moveRLToSkycrane();
		//delay();
	skycraneAvd();
		//delay();
	rightCornerTurn();
		//delay();
	moveRLToLine();
		//delay();
	rightCornerTurn();
		//delay();
	moveRLToBall();
		//delay();
	LCBallGetSteadyGuy();
		//delay();
	moveRRToRedCube();
		//delay();
	pushRedCube();
		//delay();
	moveRLToBall();
		//delay();
	LCBallGetSteadyGuy();
		//delay();
	moveRLToSkycrane();
		//delay();
	skycraneAvd();
		//delay();
	moveRLToTransport();
		//delay();
	LCBallGuySet();
		//delay();
}

void rightChain()
{
	/*moveLRToBall();
		//delay();
	RCBallGet();
		//delay();*/
	moveRRToGuy();
		//delay();
	/*botguyGet();
		//delay();
	leftTurn();
		//delay();
	moveLRToBall();
		//delay();
	RCBallGet();
		//delay();
	moveLRToLine();
		//delay();
	leftCornerTurn();
		//delay();
	moveLRToBall();
		//delay();
	RCBallGet();
		//delay();
	moveLRToBall();
		//delay();
	RCBallGet();
		//delay();
	moveLRToLine();
		//delay();
	leftCornerTurn();
		//delay();
	moveLRToTransport();
		//delay();
	RCBallGuySet();
		//delay();*/
}

int main()
{
	ready();
	
	//trial:
	//while (1)
		//botguyMove();
	return 0;
}
