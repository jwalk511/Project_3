#pragma config(Sensor, S1, Magnetic, sensorAnalog)
#include "init.h"
#define DIST_TO_SEARCH 2
void findBeacon();

task main() {
		init();
    driveStraight (50);
    findBeacon ();
}

    // Find beacons
void findBeacon () {
	int counter = 0;
    while (sensorValue(Magnetic) <= 500) {
        driveStraight (DIST_TO_SEARCH);
        counter += DIST_TO_SEARCH;
        nxtDisplayTextLine(3, "magsensor= %d", sensorValue(Magnetic));
    }

    //ALV beeps 3 times
    nVolume = 2;
    PlaySound (soundBeepBeep);
    PlaySound (soundBeepBeep);
    PlaySound (soundBeepBeep);


		//driveStraight(-4);
		//Drop bins
    dropBins();
    wait1Msec (1000);

    //Back up to original position
    driveStraight(-49 - counter);

    waitUntilStopped(motorB);
}
