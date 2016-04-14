//#pragma config(Sensor, S1, Magnetic, sensorAnalog)
#include "init.h"

void findBeacon();

task main() {
    driveStraight (50);
    findBeacon ();
}

    // Find beacons
void findBeacon () {
    while (sensorValue(Magnetic) <= 900 {
        driveStraight (3);
    }
        
    //ALV beeps 3 times
    nVolume = 2;
    PlaySound (soundBeepBeep);
    PlaySound (soundBeepBeep);
    PlaySound (soundBeepBeep);
    
    //Drop bins    
    dropBins();
    wait1MSec (1000);
    
    //Back up to original position
    nMotorEncoderTarget[motorB] = getSLEncoderCount(-50);
    motor[motorB] = -100;
 
    waitUntilStopped(motorB);
}

    