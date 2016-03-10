#pragma config(Sensor, S4, sonarSensor, sensorSonar)
#include "boilerplate.h"


#if RUN_MAIN
task main () {
    nSyncedMotors = synchBC;
    nSyncedTurnRatio = DRIVE_STRAIGHT;
    nMotorEncoderTarget[motorB] = getSLEncoderCount(30);
    motor[motorB] = 50;

    waitUntilStopped(motorB);
}
#endif

int getSLEncoderCount (int distance) {
   return distance * ENCODER_COUNT_PER_M;
}


void resetCount (int motorNum) {
	nMotorEncoder[motorNum] = 0;
}

void waitUntilStopped (int motorNum) {
	while (nMotorRunState[motorNum] == runStateRunning){};
}
