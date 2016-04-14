#include "init.h"

task main()
{
	init();

	int coor[2];
	int x = 20;
	int y = 20;
	int dist = 0;
	int distone = 0;
	int disttwo = 0;
	int distthree = 0;

	turnRight(90);

	do {
		getPos(coor);
		x = coor[0];
		nxtDisplayTextLine(4, "%d", x);
		wait1Msec(1000);
		y = coor[1];
		dist = coor[1] - 15;
		nxtDisplayTextLine(5, "dist = %d", dist);
		wait1Msec(1000);
		driveStraight(dist);
		distone = distone + dist;
	} while (coor[1] >= 15);

	wait1Msec(1000);
	turnRight(-90);
	wait1Msec(1000);

	do {
		getPos(coor);
		x = coor[0];
		y = coor[1];
		dist = 135 - x;
		driveStraight(dist);
		disttwo = disttwo + dist;
	} while (coor[0] <= 135);

	turnRight(-90);

	do {
		getPos(coor);
		x = coor[0];
		y = coor[1];
		dist = 75 - x;
		driveStraight(dist);
		distthree = distthree + dist;
	} while (y <= 75);

	// Do whatever needs to be done at goal

	turnRight(180);
	driveStraight(distthree);
	turnRight(90);
	driveStraight(disttwo);
	turnRight(90);
	driveStraight(distone);

}
