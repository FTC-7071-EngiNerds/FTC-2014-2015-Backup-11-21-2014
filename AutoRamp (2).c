#pragma config(Hubs,  S1, HTMotor,  HTMotor,  none,     none)
#pragma config(Hubs,  S2, HTServo,  none,     none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     ,               sensorI2CMuxController)
#pragma config(Sensor, S3,     IR,             sensorHiTechnicIRSeeker1200)
#pragma config(Motor,  mtr_S1_C1_1,     LeftR,         tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     RightR,        tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C2_1,     LeftF,         tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     RightF,        tmotorTetrix, openLoop, reversed)
#pragma config(Servo,  srvo_S2_C1_1,    Clamp,                tServoStandard)
#pragma config(Servo,  srvo_S2_C1_2,    IRlift,               tServoStandard)
#pragma config(Servo,  srvo_S2_C1_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S2_C1_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S2_C1_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S2_C1_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{
  waitForStart();		                // Wait for the field to enter autonomous mode
				//Move forward off of ramp
        motor[LeftF] = 70;
 				motor[RightF] = 70;
 				wait10Msec(3000);


}
