#ifndef boilerplate
#define boilerplate
//#include "init.h"
#define MOTOR_A_POWER 10

//Use with motor synching
#define DRIVE_STRAIGHT +100
#define SPIN_CLOCKWISE -100

//How many ticks motor b needs to turn to make 1 rotation
#define ENCODER_COUNT_PER_ROTATION 1944

//Ticks per Rotation(motor) * (Rotations(motor) / rotations(wheel)) * (Rotations(wheel) / Circumference)
//= Ticks / Distance Travelled
//Best experimental guess = 2000
#define ENCODER_COUNT_PER_CM (360 * 40 / (24 * 100 * 0.255))
//we still need to figure this out

#define DIST_TO_SEARCH 1
#define MAGNET_VALUE 475
#define MAX_DRIVE 25

//reset tick count to 0
void resetCount (int motorNum);

//wait until motor has finished moving.
//Use with nMotorEncoderTarget
void waitUntilStopped(int motorNum);

int getSLEncoderCount (int distance);

void driveStraight(int distance);

int getSpinEncoderCount(int degrees);

void turnRight(int degrees);

void dropBins();

bool findBeacon();

bool driveUntilBeacon(int maxDrive, int distToSearch);

#endif
