// INCLUDE INIT.H
// FUNCTION follow path
void NavigateToGoal() 
{
	// Robots Current Position
	int robot_x, robot_y;
	
	// Find goal and target locations
	for (int x = 0; x < x_size; x++)
	{
		for (int y = 0; y < y_size; y++)
		{
			if (map[x][y] == 99)
			{
				robot_x = x;
				robot_y = y;
			}
		}
	}

	int current_x = robot_x;
	int current_y = robot_y;
	int current_facing = 0;
	int next_direction = 0;
	int current_low = 99;
	
	while (current_low > 2)
	{
		cyrrent_low = 99;
		next_direction = current_facing;
		int next_x = 0;
		int next_y = 0;
		
		// Check west
		if (current_x > 0) {
			if(map[current_x - 1][current_y] < current_low && map[current_x -
			1][current_y] == 0) // Is space occupied?
			{ 
				current_low = map[current_x - 1][current_y];
				next_direction = 3;
				next_x = current_x - 1;
				next_y = current_y;
			}
			
		if (current_x < (x_size - 1)) {
			if (map[current_x + 1][current_y] < current_low &&
			map[current_x + 1][current_y] == 0) {
					
				current_low = map[current_x + 1][current_y];
				next_direction = 1;
				next_x = current_x + 1;
				next_y = current_y;
					
			}
		}
		if (current_y > 0) {
			if(map[current_x][current_y - 1] < current_low && map[current_x]
			[current_y - 1] == 0) // Is space occupied?
			{ 
				current_low = map[current_x][current_y - 1];
				next_direction = 2;
				next_x = current_x;
				next_y = current_y - 1;
			}
		}
		if (current_y < (y_size - 1)) {
			if(map[current_x][current_y + 1] < current_low && map[current_x]
			[current_y + 1] == 0) // Is space occupied?
			{ 
				current_low = map[current_x][current_y + 1];
				next_direction = 0;
				next_x = current_x;
				next_y = current_y + 1;
			}
		}
		current_x = next_x;
		current_y = next_y;
		map[current_x][current_y] = '~';
		
		// Track the robot's heading
		while (current_facing != next_direction) 
		{
			if (current_facing > next_direction)
			{
				turnLeft90(); // Turn left function
				current_facing--;
			}
			else if (current_facing < next_direction)
			{
				turnRight90();
				current_facing++;
			}
		}
		moveForward(1);
		wait1Msec(500);
	}
	
}
		