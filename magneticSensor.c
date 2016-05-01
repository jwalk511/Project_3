#pragma config(Sensor, S1, Magnetic, sensorAnalog)
#define MAGNET_VALUE 480

int i = 0;

task main () {
    while (i < 10) {
    	  nxtDisplayTextLine(2, "Magnetic sensor:");
        nxtDisplayCenteredBigTextLine(4, "%.2f", sensorValue(Magnetic));
        wait1Msec(1000);
        nVolume = 2;
        PlaySound (soundBeepBeep);
        wait1Msec(1000);
        i = i++;
    }

}
