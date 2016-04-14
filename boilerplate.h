#ifndef boilerplate
#define boilerplate
//#include "init.h"
#define MOTOR_A_POWER 17

#define RUN_MAIN 1

//Use with
#define DRIVE_STRAIGHT +100
#define SPIN_CLOCKWISE -100

#define ENCODER_COUNT_PER_ROTATION 1975

//Ticks per Rotation(motor) * (Rotations(motor) / rotations(wheel)) * (Rotations(wheel) / Circumference)
//= Ticks / Distance Travelled
//Best experimental guess = 2000
<<<<<<< HEAD
#define ENCODER_COUNT_PER_M (360 * 40 / (24 * 0.255))
=======
#define ENCODER_COUNT_PER_CM (360 * 40 / (24 * 100 * 0.255))
>>>>>>> 712464f7fbc13282d96c354331ec4610292e0028
//we still need to figure this out

//reset tick count to 0
void resetCount (int motorNum);

//wait until motor has finished moving.
//Use with nMotorEncoderTarget
void waitUntilStopped(int motorNum);

int getSLEncoderCount (int distance);

void driveStraight(int distance);

int getSpinEncoderCount(int degrees);

int turnRight(int degrees);

#endif
