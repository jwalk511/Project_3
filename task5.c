#include "init.c"

void dropBins();

task main()
{
	 init();

	 //nSyncedTurnRatio = DRIVE_STRAIGHT;
	 nMotorEncoderTarget[motorB] = getSLEncoderCount(100); // getSLEncoderCount
	 motor[motorB] = 100;
	 //wait1Msec(10000);
	 waitUntilStopped(motorB);
	 motor[motorB] = 0;

	 dropBins();

	 nMotorEncoderTarget[motorB] = getSLEncoderCount(10);
	 motor[motorB] = -100;
	 //wait1Msec(10000);
	 waitUntilStopped(motorB);
	 motor[motorB] = 0;

}

void dropBins () {
  motor[motorA] = MOTOR_A_POWER;
  wait1Msec(5000);
  motor[motorA] = 0;


}
