#pragma config(Sensor, S4, sonarSensor, sensorSonar)
#include "boilerplate.h"

int getSpinEncoderCount(int degrees);

task main() {
	//Slave C to B
	nSyncedMotors = synchBC;
	nSyncedTurnRatio = SPIN_CLOCKWISE;
  nMotorEncoderTarget[motorB] = getSpinEncoderCount(30);
	motor[motorB] = 50;
	//motor[motorA] = 20;
  waitUntilMotorStop(motorB);

  nSyncedTurnRatio = DRIVE_STRAIGHT;
  //nMotorEncoderTarget[motorB] =
  motor[motorB] = 100;
  wait1Msec(10000);

}

int getSpinEncoderCount(int degrees) {
	int ret =  ((degrees * ENCODER_COUNT_PER_ROTATION) / 360);
  return ret;
}


