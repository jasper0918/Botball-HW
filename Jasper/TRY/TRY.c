// Created on Sun July 27 2014


const int LM = 3;
const int RM = 1;
int main()
{
	clear_motor_position_counter(LM);
	clear_motor_position_counter(RM);
	mtp(LM, -800, -500);
	mtp(RM, 800, 500);
	bmd(LM);
	bmd(RM);
	return 0;
}
