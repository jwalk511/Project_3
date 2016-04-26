// TO DO: calibrate offset

const tSensors GyroSensor = (tSensors) S2;   // gyro sensor
#define RUNMAIN 1
#define LIMIT 4
float Gyro_value;


float getGyro();
void resetGyro();
float findOffset();

task gyro()
{
	float offset;
	offset = findOffset();
	Gyro_value = 0;
	while(true) {
  	Gyro_value = (SensorValue(GyroSensor) - offset) * (1.0/50.0);  //read the gyro sensor
  	wait1Msec(20);
  }
}

float getGyro() {
	return (Gyro_value);
}

void resetGyro() {
	Gyro_value = 0;
}

float findOffset() {
	int i = 0;
	int sum = 0;
	for (i = 0; i < 30; i++) {
		sum += SensorValue(GyroSensor);
		wait1Msec(20);
	}
	float offset = 1.0 * sum / 30;
	nxtDisplayTextLine(4, "%f", offset);
	return offset;
}


#if RUNMAIN
task main {

	startTask(gyro);
	wait1Msec(700);
	while(true) {

		float gyro = getGyro();
		nxtDisplayTextLine(2, "gyro = %f", gyro);
		wait10Msec(500);

		//motor[motorA] = 10;
		//while(getGyro() >
	}
}

#endif
