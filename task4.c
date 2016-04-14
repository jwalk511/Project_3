#pragma config(Sensor, S1,     Magnetic,       sensorAnalog)
#include "init.h"


task main() {
    void driveStraight(50); 

    //Find beacons
    void  findBeacon () {
    
	    while (sensorValue(Magnetic) != 1000) {
            driveStraight(5);
        }
    
        // ALV stops
        motor[motorB] = 0;
        motor[motorC] = 0;
    
        // ALV beeps
        PlaySound (soundBeepBeep);
        PlaySound (soundBeepBeep);
        PlaySound (soundBeepBeep);
        nVolume = 2;
        wait1Msec(1000);
    }
}
    
    
    

    