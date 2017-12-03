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

#define MY_POS			( 347991-1 )
#define ARRAY_CENTER 	512


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

int calculate_position_value(int map[][1024], coord current_pos);

int value[1024][1024];


int main(int argc, char *argv[])
{
	int step_size = 1;
	int	steps = 0;
	int direction = 0;
	bool	part_two_done = false;
	coord position;

	memset(value, '\0', sizeof(value));

	position.x_pos = position.y_pos = 0;

	value[ARRAY_CENTER][ARRAY_CENTER] = 1;

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
		value[position.x_pos + ARRAY_CENTER][position.y_pos + ARRAY_CENTER] = calculate_position_value(value, position);
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
		if(value[position.x_pos + ARRAY_CENTER][position.y_pos + ARRAY_CENTER] > MY_POS && part_two_done == false)
		{
			part_two_done = true;
			std::cout << "P2: Value: " << value[position.x_pos + ARRAY_CENTER][position.y_pos + ARRAY_CENTER]
			<< "Y Pos: " << position.y_pos
			<< " X Pos:" << position.x_pos << "\n";
		}
	}

	std::cout << "P1: Y Pos: " << position.y_pos
			<< " X Pos:" << position.x_pos
			<< " Total Moves: " << std::abs(position.x_pos) + std::abs(position.y_pos);

	return 0;
}

int calculate_position_value(int map[][1024], coord current_pos)
{
	int sum = 0;
	sum += map[current_pos.x_pos+1 + ARRAY_CENTER][current_pos.y_pos+1 + ARRAY_CENTER];
	sum += map[current_pos.x_pos+1 + ARRAY_CENTER][current_pos.y_pos + ARRAY_CENTER];
	sum += map[current_pos.x_pos+1 + ARRAY_CENTER][current_pos.y_pos-1 + ARRAY_CENTER];
	sum += map[current_pos.x_pos-1 + ARRAY_CENTER][current_pos.y_pos+1 + ARRAY_CENTER];
	sum += map[current_pos.x_pos-1 + ARRAY_CENTER][current_pos.y_pos + ARRAY_CENTER];
	sum += map[current_pos.x_pos-1 + ARRAY_CENTER][current_pos.y_pos-1 + ARRAY_CENTER];
	sum += map[current_pos.x_pos + ARRAY_CENTER][current_pos.y_pos+1 + ARRAY_CENTER];
	sum += map[current_pos.x_pos + ARRAY_CENTER][current_pos.y_pos-1 + ARRAY_CENTER];
	return sum;
}



