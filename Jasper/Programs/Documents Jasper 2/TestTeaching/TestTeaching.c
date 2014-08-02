// Created on 11/06/2013 Daiming Yang

//#define TEST

// motor port:
const int LM = 0;	// left motor
const int RM = 1;	// right motor

// motor constant:
const int MOTOR_FORWARD = 100;	// motor speed when moves forward

// function list:
// test:
void TEST();	// temporary function for test

// move:
void moveStraight(int distance);	// move straight for a distance

int main()
{
	moveStraight(1500);
	#ifdef TEST
		TEST();
	#endif
	moveStraight(-1500);
	return 0;
}

// test:
void TEST()
{
	ao();
	display_clear();
	printf("next step ready");
	while(!a_button_clicked());
}

// move:
void moveStraight(int distance)
{
	clear_motor_position_counter(c_ileftMotor);
	clear_motor_position_counter(c_irightMotor);
	mtp(c_ileftMotor, c_iforwardSpeed, distance);
	mtp(c_irightMotor, c_iforwardSpeed, distance);
	bmd(c_ileftMotor);
	bmd(c_irightMotor);
}

void moveLeft(int time)
{
	motor(c_ileftMotor, -1 * c_iturnSpeed);
	motor(c_irightMotor, c_iturnSpeed);
	msleep(time);
}

void moveRight(int time)
{
	motor(c_ileftMotor, c_iturnSpeed);
	motor(c_irightMotor, -1 * c_iturnSpeed);
	msleep(time);
}
