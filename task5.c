#include "boilerplate.h"

int getSLEncoderCount (int distance);
void dropBins ();
task main()
{
	 init();

	 //nSyncedTurnRatio = DRIVE_STRAIGHT;
	 nMotorEncoderTarget[motorB] = 100; // getSLEncoderCount
	 motor[motorB] = getSLEncoderCount(100);
	 waitUntilMotorStop(motorB);

	 dropBins();

	 motor[motorB] = getSLEncoderCount(-30);
	 waitUntilMotorStop(motorB);

}

int getSLEncoderCount (int distance) {
   int ret;
   ret = distance * ENCODER_COUNT_PER_ROTATION;

   return ret;
 }

void dropBins () {
	motor[motorA] = MOTOR_A_POWER;
  wait1Msec(5000);


}
