#include "init.h"

task main()
{
	init();
	turnRight(-30);
	driveStraight(400);

	wait1Msec(100000);
}
