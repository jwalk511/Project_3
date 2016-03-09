#pragma config(Sensor, S4, sonarSensor, sensorSonar)
#include "boilerplate.h"


task main() {
	
	
	

	motor[motorB] = 50;
	motor[motorA] = 20;
	wait1Msec(10000);
}

void resetCount (int motorNum) {
	nMotorEncoder[motorNum] = 0;
}

void waitUntilStopped (int motorNum) {
	while (nMotorRunState[motorNum] == runStateRunning){};
}