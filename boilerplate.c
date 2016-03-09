#pragma config(Sensor, S4, sonarSensor, sensorSonar)
#include "boilerplate.h"
#define RUN_MAIN 0

void resetCount (int motorNum) {
	nMotorEncoder[motorNum] = 0;
}

void waitUntilStopped (int motorNum) {
	while (nMotorRunState[motorNum] == runStateRunning){};
}
int getSLEncoderCount (int distance);

#if RUN_MAIN
task main () {
    nSyncedMotors = synchBC;
    nSyncedTurnRatio = DRIVE_STRAIGHT;
    nMotorEncoderTarget[motorB] = getSLEncoderCount(30);
    motor[motorB] = 50;

    waitUntilMotorStop(motorB);
}
#endif

int getSLEncoderCount (int distance) {
   int ret;
   ret = distance * ENCODER_COUNT_PER_ROTATION;

   return ret;
 }
