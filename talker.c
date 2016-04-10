#define HEIGHT 5
#define DEBUG 1

void coords(int height);
void Read(int* x, int* y);
void parseError(int error);
void printErrors();
int * getPos();
void getDirectionVector(int* x, int* y);
int getDirection();


static int coordinates[2];
static int prevCoordinates[2];
static int errorFlags[] = {1, 2, 4, 8, 16, 32};
static int errors[] = {0, 0, 0, 0, 0, 0};
static int prevDirection;
static int prevVector[2];


task main()
{

	sendMessage(0);
	ClearMessage();

	while (1) {
		ClearMessage();
		coords(HEIGHT);
		wait1Msec(5000);
	}
}

void coords(int height) {
	int error;
    int counter = 0;
	sendMessage(HEIGHT);

	do {
        counter++;
        if (counter > 5000 / 20) {
            counter = 0;
            sendMessage(HEIGHT);
        }
        
		error = messageParm[0];
		parseError(error);
        if (DEBUG) {
            printErrors();
        }

		nxtDisplayBigTextLine(1, "%d", error);
		if (error == 0) {
			nxtDisplayTextLine(2, "Waiting for message...");
			wait1Msec(100);
        } else if (errors[0] || errors[1] || errors[2]) {
			Read(&(coordinates[0]), &(coordinates[1]));
			nxtDisplayBigTextLine(2, "%d, %d", coordinates[0], coordinates[1]);
			int line = 0;
			if (errors[0]) nxtDisplayTextLine(3 + line++, "No Error");
			if (errors[1]) nxtDisplayTextLine(3 + line++, "Manual Override");
			if (errors[2]) nxtDisplayTextLine(3 + line++, "Out of Bounds");
        } else {
			int line = 0;
			if (errors[3]) nxtDisplayTextLine(3 + line++, "No ALV Marker Seen");
			if (errors[4]) nxtDisplayTextLine(3 + line++, "LSTS System Error");
			if (errors[5]) nxtDisplayTextLine(3 + line++, "Busy-Request again later");
		}
        wait1Msec(20);
	} while (error == 0);
}

void Read(int* x, int* y) {
	*x = messageParm[1];
	*y = messageParm[2];
	ClearMessage();
}

void parseError(int error) {
	int i = 0;
	errors[i] = (error & errorFlags[i]) << i; i++;
	errors[i] = (error & errorFlags[i]) << i; i++;
	errors[i] = (error & errorFlags[i]) << i; i++;
	errors[i] = (error & errorFlags[i]) << i; i++;
	errors[i] = (error & errorFlags[i]) << i; i++;
	errors[i] = (error & errorFlags[i]) << i; i++;
}

void printErrors() {
	int i = 0;
	nxtDisplayTextLine(i, "Error %d = %d", errors[i++]);
	nxtDisplayTextLine(i, "Error %d = %d", errors[i++]);
	nxtDisplayTextLine(i, "Error %d = %d", errors[i++]);
	nxtDisplayTextLine(i, "Error %d = %d", errors[i++]);
	nxtDisplayTextLine(i, "Error %d = %d", errors[i++]);
	nxtDisplayTextLine(i, "Error %d = %d", errors[i++]);
	wait1Msec(1000);
}

int * getPos() {
	return coordinates;
}

void getDirectionVector(int* x, int* y) {
	int delX = coordinates[0] - prevCoordinates[0];
	int delY = coordinates[0] - prevCoordinates[0];
	if (delX || delY) {
		prevVector[0] = delX;
		prevVector[1] = delY;
		*x = delX;
		*y = delY;
	} else {
		*x = prevVector[0];
		*y = prevVector[1];
	}
}

int getDirection() {
	int delX, delY;
	getDirectionVector(&delX, &delY);

	if (delX == 0) {
		if (delY == 0) return prevDirection;
		else if (delY > 0) prevDirection = 90;
		else if (delY < 0) prevDirection = 270;
		} else if(delY == 0) {
		if (delX > 0) prevDirection = 0;
		else if (delX < 0) prevDirection = 270;
	}

	return atan(1.0*delY / delX);
}
