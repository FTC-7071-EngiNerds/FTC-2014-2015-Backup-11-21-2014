#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTServo,  none)
#pragma config(Sensor, S3,     IR,             sensorHiTechnicIRSeeker1200)
#pragma config(Sensor, S4,     Gyro,           sensorI2CHiTechnicGyro)
#pragma config(Motor,  mtr_S1_C1_1,     LeftF,         tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     RightF,        tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C2_1,     LeftR,         tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     RightR,        tmotorTetrix, openLoop, reversed)
#pragma config(Servo,  srvo_S1_C3_1,    Clamp,                tServoStandard)
#pragma config(Servo,  srvo_S1_C3_2,    IRlift,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//
#include "JoystickDriver.c"

void rightturn(int rdegreesToTurn)
{
	// initial reading
	float rdegreesSoFar = 0;
	int rinitialTurnReading = SensorValue[Gyro];

	// start turn
				motor[LeftF] = -50;
 				motor[RightF] = 50;
 				motor[LeftR] = -50;
 				motor[RightR] = 50;


	// check if we have turned enough
	while (abs(rdegreesSoFar) < abs(rdegreesToTurn))
	{
	//update degreesSoFar
	wait1Msec(10);
	int rcurrentGyroReading = SensorValue[Gyro] - rinitialTurnReading;
	rdegreesSoFar = rdegreesSoFar + rcurrentGyroReading*.01;
	}

	// stop turning
				motor[LeftF] = 0;
 				motor[RightF] = 0;
 				motor[LeftR] = 0;
 				motor[RightR] = 0;

}

void leftturn(int ldegreesToTurn)
{
	// initial reading
	float ldegreesSoFar = 0;
	int linitialTurnReading = SensorValue[Gyro];

	// start turn
				motor[LeftF] = 50;
 				motor[RightF] = -50;
 				motor[LeftR] = 50;
 				motor[RightR] = -50;


	// check if we have turned enough
	while (abs(ldegreesSoFar) < abs(ldegreesToTurn))
	{
	//update degreesSoFar
	wait1Msec(10);
	int lcurrentGyroReading = SensorValue[Gyro] - linitialTurnReading;
	ldegreesSoFar = ldegreesSoFar + lcurrentGyroReading*.01;
	}

	// stop turning
				motor[LeftF] = 0;
 				motor[RightF] = 0;
 				motor[LeftR] = 0;
 				motor[RightR] = 0;

}

void forward(int ftimemillisecond)  //use until we have encoders
{

	// Move forward
				motor[LeftF] = 40;
 				motor[RightF] = 40;
 				motor[LeftR] = -40;
 				motor[RightR] = -40;
				wait1Msec(ftimemillisecond);
	// stop motors
				motor[LeftF] = 0;
 				motor[RightF] = 0;
 				motor[LeftR] = 0;
 				motor[RightR] = 0;
				wait1Msec(200);
}

void backward(int btimemillisecond)  //use until we have encoders
{

	// Move backward
				motor[LeftF] = -50;
 				motor[RightF] = -50;
 				motor[LeftR] = 50;
 				motor[RightR] = 50;
				wait1Msec(btimemillisecond);
	// stop motors
				motor[LeftF] = 0;
 				motor[RightF] = 0;
 				motor[LeftR] = 0;
 				motor[RightR] = 0;
				wait1Msec(200);
}


task main()
{
  waitForStart();		                // Wait for the field to enter autonomous mode

//Position clamp down
  	servoTarget[IRlift] = 250;
  	servo[IRlift] = 245;
		servo[Clamp] = 245;        // changes the position of servo1 to 160
		servoTarget[Clamp] = 250;  // changes the position of servo1 to 160

//Move forward and grab tower
		forward(3650);
//wait 5 Sec.
//wait1Msec(5000);
//Maneuver to parking zone
		leftturn(135);
		forward(800);
		leftturn(15);
		forward(2500);
		rightturn(20);
		forward(500);

}
