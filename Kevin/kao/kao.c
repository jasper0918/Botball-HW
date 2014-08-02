
const long int TURN_90 = 190000;	// distance for create to turn 90o

// motor:
const int LM = 1;	// lift motor

const int LM_UP = 1000;		// motor speed when lifting up
const int LM_DOWN = -500;	// motor speed when dropping down

// servo:
const int BSV = 1;	// bottom servo
const int USV = 0;	// upper servo
const int SSV = 3;	// small servo

const int BSV_OPEN = 1500;		// bottom servo/claw opens
const int BSV_CLOSE = 300;	// bottome servo/claw closes

const int USV_DOWN = 50;
const int USV_UP = 2047;		// upper servo/arm rises up
const int USV_UP2 = 1950;		// upper servo/arm rises up

const int USV_LEVEL = 1100;	// upper servo/arm keeps level

const int SSV_DOWN = 100;	// small servo closes extended arm
const int SSV_UP = 2047;		// small servo opens extended arm
const int SSV_UP2 = 1950;		// small servo opens extended arm

// sensor:
// analog:
const int LSS = 1;	// light sensor
const int FSS = 3;	// front infrared sensor

const int FSS_WHITE = 40;
const int FSS_BLACK = 1000;
const int FSS_MID = 600;	// special values for front sensor
//digital:
const int BSS = 11;	// bottom touch sensor
const int USS = 13;	// upper touch sensor
const int MSS = 12;	// middle touch sensor
const int CSS = 15;	// claw touch sensor
const int TSS = 10;	// TEST touch sensor


const int SS_UNTOUCHED = 0;	// touch sensor untouched
const int SS_TOUCHED = 1;	// touch sensor touched

// other:
const int TIME_LIMIT = 120;	// limited time for competition

int main ()
{
	//create_connect();
	clear_motor_position_counter(LM);
	mtp(LM, -500, -500);
	bmd(LM);
	off(LM);
}
