#pragma config(Sensor, S4, sonarSensor, sensorSonar)
#include "boilerplate.h"

int getSpinEncoderCount(int degrees);

task main() {
	//Slave C to B
	nSyncedMotors = synchBC;

	// Rotate 30 degrees
	nSyncedTurnRatio = SPIN_CLOCKWISE;

    nMotorEncoderTarget[motorB] = getSpinEncoderCount(30);
	motor[motorB] = 50;

    waitUntilMotorStop(motorB);

    // Move in a straight line
    nSyncedTurnRatio = DRIVE_STRAIGHT;
    motor[motorB] = 100;
    wait1Msec(10000);

}

// Encoder counts for 30 degree rotation
int getSpinEncoderCount(int degrees) {
	int ret =  ((degrees * ENCODER_COUNT_PER_ROTATION) / 360);
  return ret;
}
