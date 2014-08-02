// Created on ?? ?? 20 2013
/*Kp = 1000                             ! REMEMBER we are using Kp*100 so this is really 10 !
Ki = 100                              ! REMEMBER we are using Ki*100 so this is really 1 !
Kd = 10000                            ! REMEMBER we are using Kd*100 so this is really 100!
offset = 400                           ! Initialize the variables
Tp = 50 
integral = 0                          ! the place where we will store our integral
lastError = 0                         ! the place where we will store the last error value
derivative = 0                        ! the place where we will store the derivative
Loop forever
   LightValue = read light sensor     ! what is the current light reading?
   error = LightValue - offset        ! calculate the error by subtracting the offset
   integral = integral + error        ! calculate the integral 
   derivative = error - lastError     ! calculate the derivative
   Turn = Kp*error + Ki*integral + Kd*derivative  ! the "P term" the "I term" and the "D term"
 Turn = Turn/100                      ! REMEMBER to undo the affect of the factor of 100 in Kp, Ki and Kd!
   powerA = Tp + Turn                 ! the power level for the A motor
   powerC = Tp - Turn                 ! the power level for the C motor
   MOTOR A direction=forward power=PowerA   ! actually issue the command in a MOTOR block
   MOTOR C direction=forward power=PowerC   ! same for the other motor but using the other power level
   lastError = error                  ! save the current error so it can be the lastError next time around
end loop forever                      ! done with loop, go back and do it again.*/

int main()
{
	int offset = 500;
	int Tp = 80;
	int Kp = 0.2 * 1000; // constant P
	int Ki = 0.02 * 1000; // constant I
	int Kd = 0.002 * 1000; // constant D
	int LM = 0, RM = 3; // Left Motor; Right Motor
	int lastError = 0;
	int derivative = 0;
	double integral = 0;
	double time1 = seconds();
	while (1)
	{
		double time2 = seconds();
		int light_value = analog10(0);
		int error = light_value - offset;
		double dT = time2 - time1;
		integral = integral + error * dT;
		if ((error / integral) < 0)
			integral = 0;
		derivative = error - lastError;
		double	turn = Kp * error + Ki * integral + Kd * derivative / dT;
		turn = turn / 1000;
		int Lpower = Tp + turn, Rpower = Tp - turn;
		if (light_value < 200)
		{
			motor(RM, 100);
			motor(LM, -100);
		}
		if (light_value > 600)
		{
			motor(RM, -100);
			motor(LM, 100);
		}
		else
		{
			motor(LM, Lpower);
			motor(RM, Rpower);
		}
		time1 = seconds();	
		lastError = error;
		msleep(1);
	}
	return 0;
}
