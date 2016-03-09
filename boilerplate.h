#ifndef boilerplate
#define boilerplate
//#include "init.h"
#define MOTOR_A_POWER 17

#define RUN_MAIN 0

//Use with
#define DRIVE_STRAIGHT +100
#define SPIN_CLOCKWISE -100

#define ENCODER_COUNT_PER_ROTATION 1975

#define ENCODER_COUNT_PER_M 2000
//we still need to figure this out

//reset tick count to 0
void resetCount (int motorNum);

//wait until motor has finished moving.
//Use with nMotorEncoderTarget
void waitUntilStopped(int motorNum);

int getSLEncoderCount (int distance);

#endif
