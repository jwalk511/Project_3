#pragma config(Sensor, S1, Magnetic, sensorAnalog)
#include "init.h"
#define DIST_TO_SEARCH 1
#define MAGNET_VALUE 483
#define MAX_DRIVE 10

void findBeacon();
void driveUntilBeacon(int maxDrive, int distToSearch);

task main() {
  init();
  findBeacon ();
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
