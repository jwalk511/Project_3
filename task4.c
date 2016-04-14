#pragma config(Sensor, S1, Magnetic, sensorAnalog)
#include "init.h"
void findBeacon();
task main() {
	  init();
    driveStraight (50);
    // Find beacons
    findBeacon();
    wait1MSec (1000);
}

void findBeacon () {
    while (sensorValue(Magnetic) <= 1000) {
        driveStraight (3);
		}

        //ALV beeps 3 times
    nVolume = 2;
    PlaySound (soundBeepBeep);
    PlaySound (soundBeepBeep);
    PlaySound (soundBeepBeep);
}
