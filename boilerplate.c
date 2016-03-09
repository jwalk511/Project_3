#pragma config(Sensor, S4, sonarSensor, sensorSonar)

#ifndef boilerplate
#define boilerplate
//#include "init.h"
#define MOTOR_A_POWER 17

#define RUN_MAIN 0

//Use with
#define DRIVE_STRAIGHT +100
#define SPIN_CLOCKWISE -100

#define ENCODER_COUNT_PER_ROTATION 1975

#define ENCODER_COUNT_PER_CM 50
//we still need to figure this out

//reset tick count to 0
void resetCount (int motorNum);

//wait until motor has finished moving.
//Use with nMotorEncoderTarget
void waitUntilStopped(int motorNum);



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

    waitUntilStopped(motorB);
}
#endif


int getSLEncoderCount (int distance) {
   int ret;
   ret = distance * ENCODER_COUNT_PER_ROTATION;

   return ret;
}

#endif
