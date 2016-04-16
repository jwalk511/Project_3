//#pragma config(Sensor, S4, sonarSensor, sensorSonar)
#include "boilerplate.h"


#if RUN_MAIN
task main () {
	nSyncedMotors = synchBC;
    driveStraight(100);
    turnRight(90);
    turnRight(-90);

    waitUntilStopped(motorB);
}
#endif

int getSLEncoderCount (int distance) {
   return distance * ENCODER_COUNT_PER_CM;
}

// Encoder counts for degree rotation
int getSpinEncoderCount(int degrees) {
    int ret = ((degrees * ENCODER_COUNT_PER_ROTATION) / 360);
    return ret;
}

void driveStraight(int distance) {
    resetCount(motorB);
    nSyncedTurnRatio = DRIVE_STRAIGHT;
    nMotorEncoderTarget[motorB] = getSLEncoderCount(distance);
    motor[motorB] = 30 * sgn(distance);
    waitUntilStopped(motorB);
    wait1Msec(20);
}

void turnRight(int degrees) {
    resetCount(motorB);
    nSyncedTurnRatio = SPIN_CLOCKWISE;
    nMotorEncoderTarget[motorB] = getSpinEncoderCount(degrees);
    motor[motorB] = 50 * sgn(degrees);
    waitUntilStopped(motorB);
    wait1Msec(20);
}

void resetCount (int motorNum) {
	nMotorEncoder[motorNum] = 0;
}

void waitUntilStopped (int motorNum) {
    while (nMotorRunState[motorNum] == runStateRunning){wait1Msec(20);}
    wait1Msec(500);
}

void dropBins () {
  motor[motorA] = MOTOR_A_POWER;
  wait1Msec(5000);
  motor[motorA] = 0;
}
