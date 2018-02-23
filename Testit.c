#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTServo,  none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S3,     IR,             sensorHiTechnicIRSeeker1200)
#pragma config(Sensor, S4,     Gyro,           sensorI2CHiTechnicGyro)
#pragma config(Motor,  mtr_S1_C1_1,     LeftF,         tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     RightF,        tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C2_1,     LeftR,         tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     RightR,        tmotorTetrix, openLoop, reversed)
#pragma config(Servo,  srvo_S1_C3_1,    Clamp,                tServoStandard)
#pragma config(Servo,  srvo_S1_C3_2,    IRLift,               tServoStandard)
#pragma config(Servo,  srvo_S1_C3_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "JoystickDriver.c"

// Testit was Created by Noah Halstead for the Robot of 2014-2015
// This was created to help use the servos and motors.
// This is supposed to run with one controler and with both joy sticks.

void ArcadeControl(int move, int turn)
//Setup Left Joystick on Contoller 2 for forward/backward movement.  Right Joystick for left/right
{
	int left = move - turn;
	int right = move + turn;

	motor(LeftF+LeftR) = left;
	motor(RightF+LeftR) = right;
}


task main()
{
	while (true)
		eraseDisplay();  // erase the entire NXT LCD display
		int Print2 = Runing Testit// create and Initialize 'Print2' = Running Testit
		nxtDisplayCenteredBigTextLine(1, "%d, %d", Print2);  // displays on line 3 (centered and large): "1, 2"
		nxtDisplayCenteredBigTextLine(2, "%d, %d", left);  // displays on line 3 (centered and large): "1, 2"
		nxtDisplayCenteredBigTextLine(3, "%d, %d", right);
		nxtDisplayCenteredBigTextLine(3, "%d, %d", IR);
		nxtDisplayCenteredBigTextLine(4, "%d, %d", IRLift);
		nxtDisplayCenteredBigTextLine(5, "%d, %d", Clamp);
		nxtDisplayCenteredBigTextLine(6, "%d, %d", Gyro);
		  	getJoystickSettings(joystick);
  	ArcadeControl(joystick.joy1_y1, joystick.joy1_x1);  //y1 is forward/backward.  x1 is left/right.

// Left Side Strike Buttons Left Weels 100% Power forward When Pressed
  if (joy1Btn(5))
  	{
 	 motor(LeftF) = 100;
 	 motor(LeftR) = 100;
 	 }
 	 //Left Side Strike Buttons Left Weels -100% power Backwords When Pressed
  else if (joy1Btn(7))
  	{
	  motor(LeftF) = -100;
	  motor(LeftR) = -100;
		}

		// Stop Motors
	else
		{
	 motor(LeftF) = 0;
 	 motor(LeftR) = 0;
		}

// Right Side motors 100% power when pressed 100% right side forward
  if (joy1Btn(6))
  	{
 	 motor(RightF) = 100;
 	 motor(RightR) = 100;
 	 }
	// Right side motors -100% power when pressed -100% Right side Backwards
  else if (joy1Btn(8))
  	{
	  motor(RightF) = -100;
	  motor(RightR) = -100;
		}
	// Stop Motors
	else
		{
	 motor(RightF) = 0;
 	 motor(RightR) = 0;
		}

//
		if (joy1Btn(2))
			// turn servo to position 160
			{
				servo[servo1] = 160;        // changes the position of servo1 to 160
				servoTarget[servo1] = 160;  // changes the position of servo1 to 160
			}
		else if (joy1Btn(4))
			// The servo to position 80
			{
				servo[servo1] = 80;        // changes the position of servo1 to 80
				servoTarget[servo1] = 80;  // changes the position of servo1 to 80
			}

			// Close Server IR Lift
			if (joy1Btn(10))
			{
				servo[servo2] = 40;        // changes the position of servo1 to 40
				servoTarget[servo2] = 40;  // changes the position of servo1 to 40
			}
	}





}
