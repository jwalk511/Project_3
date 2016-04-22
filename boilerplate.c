//#pragma config(Sensor, S4, sonarSensor, sensorSonar)
#pragma config(Sensor, S1, Magnetic, sensorAnalog)
#include "boilerplate.h"

//RUN_MAIN defined in boilerplate.h
//Allows testing of low-level functions
#if RUN_MAIN
task main () {
	nSyncedMotors = synchBC;
    driveStraight(100);
    turnRight(90);
    turnRight(-90);

    waitUntilStopped(motorB);
}
#endif

//Returns number of ticks motorB should travel
int getSLEncoderCount (int distance) {
   return distance * ENCODER_COUNT_PER_MM;
}

// Encoder counts for degree rotation
int getSpinEncoderCount(int degrees) {
    int ret = ((degrees * ENCODER_COUNT_PER_ROTATION) / 360);
    return ret;
}

//Moves the motor forward for the specified number of centimeters
void driveStraight(int distance) {
    
    //Reset encoder count to zero so we just have to move to
    resetCount(motorB);
    
    //make motors b and c move at the same rate
    nSyncedTurnRatio = DRIVE_STRAIGHT;
    
    //Set target distance for motor b
    nMotorEncoderTarget[motorB] = getSLEncoderCount(distance);
    
    //Turn motor b on, give negative power for negative distance
    motor[motorB] = 30 * sgn(distance);
    
    //Do nothing until motor b has finished moving
    waitUntilStopped(motorB);
    
    //Wait 20 ms to let robot settle.
    wait1Msec(20);
}


//Spin the robot in place
//Works the same as drivestraight, but tells motor c to do the opposite of motor b
void turnRight(int degrees) {
    resetCount(motorB);
    nSyncedTurnRatio = SPIN_CLOCKWISE;
    nMotorEncoderTarget[motorB] = getSpinEncoderCount(degrees);
    motor[motorB] = 50 * sgn(degrees);
    waitUntilStopped(motorB);
    wait1Msec(20);
}

//Wrapper function for turning the current encoder count to zero.
//Just makes life easier
void resetCount (int motorNum) {
	nMotorEncoder[motorNum] = 0;
}

//Block current task until motor has stopped moving, then wait 1/2 s longer
void waitUntilStopped (int motorNum) {
    while (nMotorRunState[motorNum] == runStateRunning){wait1Msec(20);}
    wait1Msec(500);
}

//TODO tune how long turned on
void dropBins () {
  nMotorEncoderTarget[motorA] = getSLEncoderCount(50);
  motor[motorA] = MOTOR_A_POWER;
  wait1Msec(5000);
  motor[motorA] = 0;
}

// Find beacons
void findBeacon () {
	bool foundBeacon = FALSE;

    driveUntilBeacon (MAX_DRIVE, DIST_TO_SEARCH);

    //If ALV couldn't find beacon, go back once more
    if (foundBeacon = FALSE) {
    	driveUntilBeacon (-MAX_DRIVE, - DIST_TO_SEARCH);

    	//Go forward to find beacon once more if still couldn't find it
    	if (foundBeacon = FALSE) {
    		driveUntilBeacon (MAX_DRIVE, DIST_TO_SEARCH);

    		//Go to next location to still couldn't find beacon
    		if (foundBeacon = FALSE){
				// Go to B/C

    		}
    	}
    }

    else {

    //ALV beeps 3 times and drop antennas off
        nVolume = 2;
        PlaySound (soundBeepBeep);
        PlaySound (soundBeepBeep);
        PlaySound (soundBeepBeep);

   	    dropBins();
   	    wait1Msec (1000);
    }
}


//Drive until finding beacons
void driveUntilBeacon (int maxDrive, int distToSearch) {
    bool foundBeacon = FALSE;

    //Reset encoder count to zero
    resetCount (motorB);

    //Motor B and C move at the same time
    nSyncedTurnRatio = DRIVE_STRAIGHT;

    nMotorEncoderTarget[motorB] = getSLEncoderCount(maxDrive);

    while (sensorValue(Magnetic) < MAGNET_VALUE) {
    	motor[motorB] = 30 * sgn(distToSearch);

    	if (abs(nMotorEncoder[motorB]) > abs(nMotorEncoderTarget[motorB])) {
    		break;
    	}

    }

    if (sensorValue(Magnetic) < MAGNET_VALUE) {
        foundBeacon = FALSE;
    }
    else {
        foundBeacon = TRUE;
    }

    motor[motorB] = 0;
    nMotorEncoderTarget[motorB] = 0;
    waitUntilStopped (motorB);
    resetCount (motorB);

}
