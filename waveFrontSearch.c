void WaveFrontSearch () { 
    int goal_x, goal_y;
    bool foundWave = true;
    int currentWave = 40;
    
    while (foundWave == true) {
        foundWave = false;
        for (int y = 0; y < y_side; y++_) {
            for (int x = 0; x < x_side; x++) {
                if (map[x][y] == currentWave) {  //beacon A
                    foundWave = true;
                    goal_x = x;
                    goal_y = y;
                    
                    //checks WEST
                    if (goal_x > 0)
                        if (map[goal_x-1][goal_y] == 0
                            map[goal_x-1][goal_y] = currentWave + 1;
    				// checks EAST                        
                    if (goal_x < (x_size - 1))
                        if (map[goal_x+1][goal_y] == 0
                            map[goal_x+1][goal_y] = currentWave + 1;
    
    				// checks SOUTH                        
                    if (goal_y > 0)
                        if (map[goal_x][goal_y-1] == 0
                            map[goal_x][goal_y-1] = currentWave + 1;
    
    				// checks NORTH                     
                    if (goal_y < (y_size - 1)
                        if (map[goal_x][goal_y+1] == 0
                            map[goal_x][goal_y+1] = currentWave + 1;
                }
            }
        }
        currentWave++;
        wait1Msec(500);
    }
}
                     