#define HEIGHT 5

void coords(int height, int * coordinates);
void Read(int* x, int* y);

task main()
{
	int coord[] = {0, 0};

	sendMessage(0);
	ClearMessage();

	while (1) {
		ClearMessage();
		coords(HEIGHT, coord);
		wait1Msec(500);
	}
}
void coords(int height, int * coordinates) {
	int x, y;
	int error;
	sendMessage(HEIGHT);
	do {
		error = messageParm[0];
		nxtDisplayBigTextLine(2, "%d", error);
		if (error == 0) {
			nxtDisplayTextLine(2, "Waiting for message...");
			wait1Msec(100);
		} else if (error == 1 || error == 2) {
			Read(&x, &y);
			nxtDisplayBigTextLine(2, "%d, %d", x, y);
			coordinates[0] = x;
			coordinates[1] = y;
		} else {
		  coordinates[0] = 0;
		  coordinates[1] = 0;
		}
	} while (error == 0);
}
void Read(int* x, int* y) {
	*x = messageParm[1];
	*y = messageParm[2];
}
