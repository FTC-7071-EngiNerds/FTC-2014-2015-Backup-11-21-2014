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

task main()
{
// initial reading
int degreesToTurn = 90;
float degreesSoFar = 0;
int initialTurnReading = SensorValue[Gyro];

// start turn
				motor[LeftF] = -50;
 				motor[RightF] = 50;
 				motor[LeftR] = 50;
 				motor[RightR] = -50;


// check if we have turned enough
while (abs(degreesSoFar) < abs(degreesToTurn))
	{
	//update degreesSoFar
	wait1Msec(10);
	int currentGyroReading = SensorValue[Gyro] - initialTurnReading;
	degreesSoFar = degreesSoFar + currentGyroReading*.01;
	}

// stop turning
				motor[LeftF] = 0;
 				motor[RightF] = 0;
 				motor[LeftR] = 0;
 				motor[RightR] = 0;

}
