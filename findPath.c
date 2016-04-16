#include "init.h"

task main()
{
	init();

	int coor[2];
	int x, y;

	int dist;

	int xA = ?;
	int yA = ?;
	int xB = ?;
	int yB = ?;
	int xC = ?;
	int yC = ?;
	
	int xTerrain1 = ?;
	
	int yTerrain2 = ?;
	
	int xHome = ?;
	int yHome = ?;
	
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
	
	//findBeacon();
	// go back and forth between 60 and 50 to search for magnets in case couldn't
	// find it on first try. (max 3 times?)
	
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
	
	//findBeacon();
	// go back and forth between 108 and 118 

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
    
    //findBeacon();
	// go back and forth between 277 and 267 
    
    
    // Go back to home base
    turnRight (-90);
    getPos (coor);
    y = coor[1];
    dist = coor[1] - yTerrain2;
    driveStraight (dist);
    wait1Msec(1000:
    
    turnRight (90);
    getPos (coor);
    x = coor[0];
    y = coor[1];
    
    dist = coor[0] - xHome;
    driveStraight(dist);
    wait1Msec(1000);
    
    turnRight(90);
    dist = yHome - coor[1];
    driveStraight(dist);
    wait1Msec(1000);
    
}
