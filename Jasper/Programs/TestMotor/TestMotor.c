const int LM = 1;// left motor
const int RM = 3;// right motor
const int FM = 2;// front motor

int main()
{
	/*while(!(a_button_clicked())){
		motor (LM,100);
		motor (RM,90);
	}*/
	mrp(LM, 870, 5000);
	mrp(RM, 1000, 5000);
	bmd(LM);
	bmd(RM);
	ao();
	return 0;
}
