#include "init.h"

task main()
{
	init();

	int coor[2];
	int x, y;

	int dist;

	int xA = 34;
	int yA = 205;
	int xB = 229;
	int yB = 147;
	int xC = 277;
	int yC = 55;
	
	int xTerrain1 = 285;
	
	int xTerrain2 = 220;
	
	bool foundBeacon = FALSE;
	
	 
	//turnRight (0);          // face north
    //turnRight (-45)        // face north east
    //turnRight(-90);       // face east
    //turnRight (-135);    // face south east
    //turnRight(-180);    // face south
    //turnRight(135)     // face south west
    //turnRight(90);    // face west
    //turnRight(45)    // face north west
    
    // Go to A and drop of 1st antenna
    getPos(coor);
	x = coor[0];
	wait1Msec(1000);
	y = coor[1];
	dist = yA - coor[1] - 5 ; 
	wait1Msec(1000);
	driveStraight(dist);  // Move to (A's y coordinate - 5)	
	
	//Get current x coordinate
	getPos(coor);  
	x = coor[0];
	
	//Move to the same x coordinate as A
	dist = xA - coor[0];
	wait1Msec(1000);
	driveStraight(dist);   
	wait1Msec(1000);
	
	// Look for magnetic beacon
	findBeacon();
	
	//If magnetic beacon is found, drop bins off
	if (foundBeacon = TRUE) {
	    
    	//Drop bins
   		dropBins();
    	wait1Msec (1000);
    }
    
    // If couldn't find beacon, move back to A and drop bins off
    else {
    	getPos (coor);
    	dist = coor[1] - yA;
        driveStraight (-dist);
        wait1Msec (1000);
        
        dropBins();
        wait1Msec (1000);
    }
        
        
	
	// Go to B and drop off 2nd antenna
	turnRight(90);
	wait1Msec(1000);
     
    //Get current position
	getPos(coor);
	x = coor[0];
	y = coor[1];
	dist = xB - coor[0]; // Move to the same x coordinate as B
	wait1Msec(1000);
		
	turnRight (90);
	dist = coor[1] - yB - 5; // Move to (B's y coordinate - 5)
	driveStraight(dist);
	wait1Msec(1000);
	
	// Look for magnetic beacon
	findBeacon();
	
	//If magnetic beacon is found, drop bins off
	if (foundBeacon = TRUE) {
	    
    	//Drop bins
   		dropBins();
    	wait1Msec (1000);
    }
    
    // If couldn't find beacon, move back to B and drop bins off
    else {
    	getPos (coor);
    	dist = yB - coor[1];
        driveStraight (-dist);
        wait1Msec (1000);
        
        dropBins();
        wait1Msec (1000);
    }
	
	
	//Go to C and dropp off 3rd antenna
	turnRight(-90);
    wait1Msec(1000);
    
    //Go pass rough terrain 
	getPos(coor);
	x = coor[0];
	y = coor[1];
	
	dist = xTerrain1 - coor[0];
	driveStraight(dist);
	wait1Msec(1000);
	
	//Move to the same y coordinate as C
	turnRight (90);
	getPos (coor);
	y = coor[1];
	dist = coor[1] - yC;
	driveStraight(dist);
	wait1Msec(1000);
	
	// Move to C's x coordinate - 5
    turnRight (90);
	getPos (coor);
	x = coor[0];
	dist = coor[0] - xC - 5; 
    driveStraight(dist);
    wait1Msec(1000);
    
    // Look for magnetic beacon
	findBeacon();
	
	//If magnetic beacon is found, drop bins off
	if (foundBeacon = TRUE) {
	    
    	//Drop bins
   		dropBins();
    	wait1Msec (1000);
    }
    
    // If couldn't find beacon, move back to C and drop bins off
    else {
    	getPos (coor);
    	dist = xC - coor[0];
        driveStraight (-dist);
        wait1Msec (1000);
        
        dropBins();
        wait1Msec (1000);
    }


    // Go back to home base
    driveStraight (220);
    wait1Msec(1000);
    
}