// Created on Sun July 27 2014

#define TEST
#define CONFIG	"color.config"

// constants:

// all ports:
const int LM = 3; 		// lift motor
const int RSV = 0; 		// rotating servo
const int BSV = 1; 		// bigger servo claw
const int SSV = 2; 		// smaller servo claw
const int LSS = 1; 		// left tophat
const int RSS = 2 ;		// right tophat
const int SSS = 3; 		// start sensor

// servo const:
const int BSV_OPEN = 2047; 
const int BSV_CLOSE = 0;
const int SSV_OPEN = 2047; 
const int SSV_CLOSE = 0;
const int RSV_BCUP = 2047; 
const int RSV_SCUP = 0;
const int RSV_LEVEL = 1024;
const int RSV_SET_EXT = 1234;

// motor const:
const int LM_BOTGUY_UP = ; 			//
const int LM_BOTGUY_DOWN = ; 	//
const int LM_BOTGUY_SET = ; 			//
const int LM_BC_UP = ;
const int LM_BC_DOWN = ;
const int LM_SC_UP = ;
const int LM_SC_DOWN = ;

// color channel:
const int PINK = 0; 		// pink ball
const int GREEN = 1;	// green ball
const int ORANGE = 2;	// orange cube
const int YELLOW = 3;	// yellow cube
const int RED = 4;			// botguy
const int BLUE = 5;		// blue cube





// function list:
void prepare();
void stop();
void exeBotguy();
void getCubes();
void setCubes();

int main()
{
	prepare();
	
	turnRight();
	
	exeBotguy();
	getCubes();
	setCubes();
	
	stop();
	return 0;
}

void prepare(){
	create_disconnect();
	msleep(1000);
	create_connect();
	msleep(1000);
	printf("create connect successfully!");
	camera_open(LOW_RES);
	camera_load_config(CONFIG);
}

void turnRight(){
	create_spin_CW(82);
	msleep(500);
	
	
	
	
	
	
	
	
	
}
