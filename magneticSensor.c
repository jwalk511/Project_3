#pragma config(Sensor, S1, Magnetic, sensorAnalog)
#define MAGNET_VALUE 483

task main () {
    while (sensorValue(Magnetic) < MAGNET_VALUE) {
        printf ("Magnetic sensor value: %f\n", sensorValue(Magnetic)();
        nVolume = 2;
        PlaySound (soundBeepBeep);
        PlaySound (soundBeepBeep);
        PlaySound (soundBeepBeep);
        wait1Msec(1000);
    }
        