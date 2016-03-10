//
//  init.c
//
//
//  Created by Joshua on 3/8/16.
//
//

//#include <stdio.h>
#include "boilerplate.c"
//#include "init.h"

void init() {
	resetCount(motorA);
	resetCount(motorB);
	resetCount(motorC);
    //Slave C to B
    nSyncedMotors = synchBC;
    //nSyncedTurnRatio = DRIVE_STRAIGHT;
}
