#pragma config(Sensor, S4, sonarSensor, sensorSonar)
#include "boilerplate.h"


task main() {
	//Slave C to B
	nSyncedMotors = synchBC;
	nSyncedTurnRatio = SPIN_CLOCKWISE;
    nMotorEncoderTarget = 100;
	motor[motorB] = 50;
	//motor[motorA] = 20;
	
	nSyncedTurnRatio = DRIVE_STRAIGHT;
    
}

