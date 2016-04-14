void moveForward(int blocks);

// Global Variables

const int x_size = 40;
const int y_size = 30;

// 0 = open space
// 1 = hazards
// 40 = special location
// 99 = robot

const int beacon_A[2] = //{20, 20}
const int beacon_B[2] = //{20, 20}
const int beacon_C[2] = //{20, 20}


//int map[x_size][y_size] =
	// HARDCODE MAP

// FUNCTION move forward
void moveForward(int blocks) {
	// one rotation = 15.8 cm
  // one block = 1.0 cm
	int countsToTravel = (1.0/15.8)*(360)*blocks;

	// Encoder target for countsToTravel
	nMotorEncoder[motorB] = 0;
	nMotorEncoder[motorC] = 0;
	nMotorEncoderTarget[motorB] = countsToTravel;
	nMotorEncoderTarget[motorA] = countsToTravel;
	motor[motorB] = 50;
	motor[motorA] = 50;

	while (nMotorRunState[motorB] != runStateIdel && nMotorRunState[motorC] !=
runStateIdle) {}

	// Stop for half second at end of movement
	motor[motorB] = 0;
	motor[motorA] = 0;
	wait1Msec(500);

}
