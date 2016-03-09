#ifndef boilerplate
#define boilerplate
#include "boilerplate.c"

//Use with
#define DRIVE_STRAIGHT +100
#define SPIN_CLOCKWISE -100

#define ENCODER_COUNT_PER_ROTATION 1975

//reset tick count to 0
void resetCount (int motorNum);

//wait until motor has finished moving.
//Use with nMotorEncoderTarget
void waitUntilStopped(int motorNum);

#endif
