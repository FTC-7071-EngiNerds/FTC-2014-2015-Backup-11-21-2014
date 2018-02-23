#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTServo,  none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S3,     IR,             sensorHiTechnicIRSeeker1200)
#pragma config(Motor,  mtr_S1_C1_1,     LeftR,         tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     RightR,        tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C2_1,     LeftF,         tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     RightF,        tmotorTetrix, openLoop, reversed)
#pragma config(Servo,  srvo_S1_C3_1,    Clamp,                tServoStandard)
#pragma config(Servo,  srvo_S1_C3_2,    IRlift,               tServoStandard)
#pragma config(Servo,  srvo_S1_C3_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "JoystickDriver.c"

//Arcade Joystick;
void ArcadeControl(int move, int turn)  //Setup Left Joystick on Contoller 2 for forward/backward movement.  Right Joystick for left/right
{
	int leftBack = move - turn;
	int rightBack = move + turn;
	int left = -move - turn;
	int right = -move + turn;

	motor[LeftR] = leftBack;
	motor[RightR] = rightBack;
	motor[LeftF] = left;
	motor[RightF] = right;
}

task main()
{
 while (true)
  {
  	getJoystickSettings(joystick);
  	ArcadeControl(joystick.joy1_y1, joystick.joy1_x2);  //y1 is forward/backward.  x2 is left/right.


		if (joy1Btn(2) ==1 )
	{
		motor[LeftF] = 0;
		motor[RightF] = 0;
		motor[LeftR] = 0;
		motor[RightR] = 0;
	}

		if (joy2Btn(4) == 1)
			// turn servo to position 160
			{
				servo[Clamp] = 128;        // changes the position of servo1 to 160
				servoTarget[Clamp] = 128;  // changes the position of servo1 to 160
			}
		else if (joy2Btn(2) == 1)
			// The servo to position 80
			{
				servo[Clamp] = 255;        // changes the position of servo1 to 160
				servoTarget[Clamp] = 255;  // changes the position of servo1 to 160
			}

			// Close Servo IR Lift
			if (joy2Btn(10) == 1)
			{
				servo[IRlift] = 250;        // changes the position of servo1 to 160
				servoTarget[IRlift] = 250;  // changes the position of servo1 to 160
			}

			// slow speed to grab towers
			if (joy1Btn(1) == 1)
			{
				motor[LeftR] = 40;
				motor[RightR] = 40;
				motor[LeftF] = -40;
				motor[RightF] = -40;
			}
	}
}
