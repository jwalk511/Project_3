#define HEIGHT 5
#define DEBUG 1

void coords(int height);
void Read(int* x, int* y);
void parseError(int error);
void printErrors();
void getPos(int * coords);
void getDirectionVector(int* x, int* y);
int getDirection();
bool gotCoords = false;

static int coordinates[2];
static int prevCoordinates[2];
static int errorFlags[] = {1, 2, 4, 8, 16, 32};
static int errors[] = {0, 0, 0, 0, 0, 0};
static int prevDirection;
static int prevVector[2];


task talk() {
    //Flush buffer
	sendMessage(0);
	ClearMessage();

    //Clear old message, read in new coords, and wait 5s forever
    //In own task, so does not block others
	while (1) {
		ClearMessage();
		coords(HEIGHT);
		wait1Msec(5000);
	}
}

void coords(int height) {
    //Store retrieved error value
	int error;
    
    //Count how long we've gone without a response
    int counter = 0;
    
    //Tell gui how long high beacon is off the ground
	sendMessage(HEIGHT);

	do {
		wait1Msec(20);
        counter++;
        if (counter > (5000 / 40)) {
            counter = 0;
            nxtDisplayTextLine(1, "Sending message");
            //wait1Msec(500);
            sendMessage(HEIGHT);
        }

		error = messageParm[0];
		if (error == 0) {
			nxtDisplayTextLine(1, "Waiting for message");
			wait1Msec(20);
			continue;
		}
        
        //if error is not 0, send them off to be parsed
        //May be more than 1 error
		parseError(error);
#if DEBUG
            printErrors();
#endif

		nxtDisplayTextLine(1, "%d", error);
        
        //If we got coords, this will be set to true. Otherwise, left false
        gotCoords = false;
		if (errors[0] || errors[1] || errors[2]) {
			Read(&(coordinates[0]), &(coordinates[1]));
            
            //Signify whether or not we go valid coords
			gotCoords = (!errors[2]) && true;

            //Display coordinates
			nxtDisplayTextLine(2, "x, y = %d, %d", coordinates[0], coordinates[1]);


#if DEBUG
            int line = 0;
			if (errors[0]) nxtDisplayTextLine(3 + line++, "No Error");
			if (errors[1]) nxtDisplayTextLine(3 + line++, "Manual Override");
			if (errors[2]) nxtDisplayTextLine(3 + line++, "Out of Bounds");
#endif

    } else {
#if DEBUG
            int line = 0;
			if (errors[3]) nxtDisplayTextLine(3 + line++, "No ALV Marker Seen");
			if (errors[4]) nxtDisplayTextLine(3 + line++, "LSTS System Error");
			if (errors[5]) nxtDisplayTextLine(3 + line++, "Busy-Request again later");
#endif

		}
	} while (error == 0);   //Keep going until we get a message
}

//Store x and y coordinates, then delete input buffer
void Read(int* x, int* y) {
	*x = messageParm[1];
	*y = messageParm[2];
	ClearMessage();
}

//Go through error as a bunch of bits
void parseError(int error) {
	int i = 0;
	errors[i] = (error & errorFlags[i]) << i; i++;
	errors[i] = (error & errorFlags[i]) << i; i++;
	errors[i] = (error & errorFlags[i]) << i; i++;
	errors[i] = (error & errorFlags[i]) << i; i++;
	errors[i] = (error & errorFlags[i]) << i; i++;
	errors[i] = (error & errorFlags[i]) << i; i++;
}

//Print all errors
void printErrors() {
	int i = 1;
	nxtDisplayTextLine(1 + i, "Error %d = %d", i, errors[i++]);
	nxtDisplayTextLine(1 + i, "Error %d = %d", i, errors[i++]);
	nxtDisplayTextLine(1 + i, "Error %d = %d", i, errors[i++]);
	nxtDisplayTextLine(1 + i, "Error %d = %d", i, errors[i++]);
	nxtDisplayTextLine(1 + i, "Error %d = %d", i, errors[i++]);
	nxtDisplayTextLine(1 + i, "Error %d = %d", i, errors[i++]);
	//wait1Msec(1000);
}

//Block until new coords have come through
void getPos(int * coords) {
	gotCoords =  false;
	while(!gotCoords) {
		wait1Msec(20);
		//nxtDisplayTextLine(3, "Waiting to get position");
	}

	//nxtDisplayTextLine(4, "Got coordinates %d %d", coordinates[0], coordinates[1]);
	coords[0] = coordinates[0];
	coords[1] = coordinates[1];
}

//Get 2D vector from origin of where we face
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

//Get angle from x axis
int getDirection() {
	int delX, delY;
	getDirectionVector(&delX, &delY);

	if (delX == 0) {
		if (delY == 0) return prevDirection;
		else if (delY > 0) prevDirection = 90;
		else if (delY < 0) prevDirection = 270;
		return prevDirection;
	} else if(delY == 0) {
		if (delX > 0) prevDirection = 0;
		else if (delX < 0) prevDirection = 270;
		return prevDirection;
	}

	prevDirection = atan(1.0*delY / delX);
	return prevDirection;
}
