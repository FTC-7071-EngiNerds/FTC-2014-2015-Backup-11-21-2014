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


task main()
{
  waitForStart();		                // Wait for the field to enter autonomous mode


//  void Display()                                                        // Displays both Servo Position and Encoder Value
//	{
                                                                        //            NXT Display
//  nxtDisplayCenteredTextLine(0, "Servo Position");                      //         __________________
//  nxtDisplayCenteredBigTextLine(2, "%d", e);                            //        |  Servo Position  |
                                                                        //        |      ##  ##      |
//  nxtDisplayCenteredTextLine(5, "%d", nMotorEncoder[motorA]);           //        |      ##  ##      |
//  nxtDisplayCenteredTextLine(7, "Encoder Position");                    //        |                  |
                                                                        //        |        ##        |
//  wait1Msec(25);      // Update screen every 25 milliseconds            //        |__Encoder  Value__|
//	}


servo[IRlift] = 128;        // changes the position of IR sensor to 128(up in the air).  VALUES range from 0 to 255. Need to test so we can set a value.
wait1Msec(500);             // delay to allow for servo to get to position.

//Move forward and take sensor reading
				motor[LeftF] = -50;
 				motor[RightF] = -50;
 				motor[LeftR] = 50;
 				motor[RightR] = 50;
				wait1Msec(1300);
				motor[LeftF] = 0;
 				motor[RightF] = 0;
 				motor[LeftR] = 0;
 				motor[RightR] = 0;
 				wait1Msec(500);


// FOLLOWING CODE USED TO DETERMINE POSITION OF CENTER CONSOLE
	if (SensorValue[S3] == 5)     // center piece is in Position 3 with bar just off to right
   		{
   			nMotorEncoder[LeftF] = 0;  //clear the TETRIX encoders in motors left and right
        nMotorEncoder[RightF] = 0;
        wait1Msec(200);							// Delay before next command
 				//right turn 45 degrees
				motor[LeftF] = -40;
 				motor[RightF] = 40;
 				motor[LeftR] = 50;
 				motor[RightR] = -50;
				wait1Msec(2000);
				motor[LeftF] = 0;
 				motor[RightF] = 0;
 				motor[LeftR] = 0;
 				motor[RightR] = 0;
				//Move straight ahead to avoid center
				motor[LeftF] = -40;
 				motor[RightF] = -40;
 				motor[LeftR] = 50;
 				motor[RightR] = 50;
				wait1Msec(1000);
				motor[LeftF] = 0;
 				motor[RightF] = 0;
 				motor[LeftR] = 0;
 				motor[RightR] = 0;
				wait1Msec(200);
 				//left turn 45 degrees
				motor[LeftF] = 40;
 				motor[RightF] = -40;
 				motor[LeftR] = -50;
 				motor[RightR] = 50;
				wait1Msec(2000);
				motor[LeftF] = 0;
 				motor[RightF] = 0;
 				motor[LeftR] = 0;
 				motor[RightR] = 0;
				wait1Msec(200);
				//Move straight ahead to kick stand
				motor[LeftF] = -40;
 				motor[RightF] = -40;
 				motor[LeftR] = 50;
 				motor[RightR] = 50;
				wait1Msec(1000);
				motor[LeftF] = 0;
 				motor[RightF] = 0;
 				motor[LeftR] = 0;
 				motor[RightR] = 0;
				wait1Msec(200);
				//Move forward off of wall
        //motor[LeftF] = 70;
 				//motor[RightF] = 70;
 				//wait10Msec(1000);
				//Right Turn 15 degrees
        //while (nMotorEncoder[LeftF] > -300) //while the encoder wheel turns one revolution
        //{
	      //  motor[LeftF] = -60; //turn both motors on at 60 percent power
	      //  motor[RightF] = 60;
        //}
        //motor[LeftF] = 0; //turn both motors off
        //motor[RightF] = 0;
        //Move forward to knock off bar
        //motor[LeftF] = 70;
 				//motor[RightF] = 70;
 				//wait10Msec(3000);
     	}

 if ((SensorValue[S3] > 0) & (SensorValue[S3] < 5))    //center piece is in Position 2 with bar straight ahead.  CHARGE!!
     {
				nMotorEncoder[LeftF] = 0;  //clear the TETRIX encoders in motors left and right
        nMotorEncoder[RightF] = 0;
        wait1Msec(200);							// Delay before next command
 				//right turn 45 degrees
				motor[LeftF] = -50;
 				motor[RightF] = 50;
 				motor[LeftR] = 50;
 				motor[RightR] = -50;
				wait1Msec(2000);
				motor[LeftF] = 0;
 				motor[RightF] = 0;
 				motor[LeftR] = 0;
 				motor[RightR] = 0;
				//Move straight ahead to kick stand
				motor[LeftF] = -50;
 				motor[RightF] = -50;
 				motor[LeftR] = 50;
 				motor[RightR] = 50;
				wait1Msec(1200);
				motor[LeftF] = 0;
 				motor[RightF] = 0;
 				motor[LeftR] = 0;
 				motor[RightR] = 0;
				wait1Msec(200);
		}

 if (SensorValue[S3] == 0)     //center piece is in Position 1 with bar straight ahead.
     {
				nMotorEncoder[LeftF] = 0;  //clear the TETRIX encoders in motors left and right
        nMotorEncoder[RightF] = 0;
        wait1Msec(200);							// Delay before next command
				//Move straight ahead
				motor[LeftF] = -50;
 				motor[RightF] = -50;
 				motor[LeftR] = 50;
 				motor[RightR] = 50;
				wait1Msec(400);
				motor[LeftF] = 0;
 				motor[RightF] = 0;
 				motor[LeftR] = 0;
 				motor[RightR] = 0;
				wait1Msec(200);
 				//right turn to hit kick stand
				motor[LeftF] = -50;
 				motor[RightF] = 50;
 				motor[LeftR] = 50;
 				motor[RightR] = -50;
				wait1Msec(3000);
				motor[LeftF] = 0;
 				motor[RightF] = 0;
 				motor[LeftR] = 0;
 				motor[RightR] = 0;

 				}
servo[servo2] = 250;        // changes the position of IR sensor to 128(up in the air).  VALUES range from 0 to 255. Need to test so we can set a value.

}
