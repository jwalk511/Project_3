#pragma config(Sensor, S1, Magnetic, sensorAnalog)
#include "init.h"
#define DIST_TO_SEARCH 2
void findBeacon();
#define MAGNET_VALUE = 483


task main() {
	init();
    driveStraight (50); //Drive straight for 50 cm
    findBeacon ();
}

// Find beacons
void findBeacon () {
	
    while (sensorValue(Magnetic) <= MAGNET_VALUE) { 
    
        //Drive straight for 2 cm until magnetic beacon is found
        driveStraight (DIST_TO_SEARCH); 
        nxtDisplayTextLine(3, "magsensor= %d", sensorValue(Magnetic));
    }

    //ALV beeps 3 times
    nVolume = 2;
    PlaySound (soundBeepBeep);
    PlaySound (soundBeepBeep);
    PlaySound (soundBeepBeep);

    //Drop bins
    dropBins();
    wait1Msec (1000);
    
}
