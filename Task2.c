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
		coor = getPos();
		x = coor[0];
		y = coor[1];
		dist = y - 10;
		driveStraight(dist);
		distone = distone + dist;
	} while (y >= 10);

	turnRight(-90);

	do {
		coor = getPos();
		x = coor[0];
		y = coor[1];
		dist = 135 - x;
		driveStraight(dist);
		disttwo = disttwo + dist;
	} while (x <= 135);

	turnRight(-90);

	do {
		coor = getPos();
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
