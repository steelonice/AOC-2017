/*
 * main.cpp
 *
 *  Created on: December 02, 2017
 *  Author: Hayden Chuter

 */

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <sstream>

#include <vector>
#include <algorithm>

#include <thread>

#include "main.h"

#define MY_POS	(347991-1 )

typedef struct{
	int x_pos;
	int y_pos;
}coord;

typedef enum{
	UP		= 1,
	DOWN	= 3,
	LEFT	= 2,
	RIGHT	= 0
}direction;

int main(int argc, char *argv[])
{
	int step_size = 1;
	int	steps = 0;
	int direction = 0;
	coord position;

	position.x_pos = position.y_pos = 0;

	for(int loop = 0; loop < MY_POS; loop ++)
	{
		switch(direction % 4)
		{
			case RIGHT:
				position.x_pos += 1;
				break;
			case UP:
				position.y_pos += 1;
				break;
			case LEFT:
				position.x_pos -= 1;
				break;
			case DOWN:
				position.y_pos -= 1;
				break;
		}
		steps ++;
		if( steps % step_size == 0)
		{
			direction++;
			steps = 0;
		}
		if(direction % 2 == 0 && steps == 0)
		{
			step_size ++;
		}
	}

	std::cout << "Y Pos: " << position.y_pos
			<< " X Pos:" << position.x_pos
			<< " Total Moves: " << std::abs(position.x_pos) + std::abs(position.y_pos);

	return 0;
}
