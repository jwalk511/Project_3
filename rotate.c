#pragma config(Sensor, S4, sonarSensor, sensorSonar)
//#include "boilerplate.c"
#include "init.c"
int getSpinEncoderCount(int degrees);

task main() {
	init();

	// Rotate 30 degrees
	nSyncedTurnRatio = SPIN_CLOCKWISE;

    nMotorEncoderTarget[motorB] = getSpinEncoderCount(30);
	motor[motorB] = 50;

    waitUntilStopped(motorB);
   getSLEncoderCount(10);
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
