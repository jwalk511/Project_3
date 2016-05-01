//
//  init.c
//
//
//  Created by Joshua on 3/8/16.
//
//

//#include <stdio.h>


//Always call first in main method
void init() {
    //Reset all counts
	resetCount(motorA);
	resetCount(motorB);
	resetCount(motorC);

  //Slave C to B
  nSyncedMotors = synchBC;

    //Start bluetooth talker
  startTask(talk);
  wait1Msec(100);
}
