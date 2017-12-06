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

int do_jump(std::vector<int> * jump_table, int position);

int main(int argc, char *argv[])
{
	/* Input file stream */
	std::ifstream ifs("Input", std::ifstream::in);

	/* Single line input string */
	std::string 		input_line;
	std::vector<int>	jump_table;

	int position = 0;
	int count	 = 0;
	do
	{
		std::getline(ifs, input_line, '\n');
		jump_table.push_back(std::atoi(input_line.c_str()));
	}while(ifs.eof() != true);

	while(position < jump_table.size())
	{
		position = do_jump(&jump_table, position);
		count++;
	}

	std::cout << "Num Jumps:" << count << "\n";

    return 0;
}

int do_jump(std::vector<int> * jump_table, int position)
{
	int jump = 0;

	jump = jump_table->at(position);
	if(jump >= 3)
	{
		jump_table->at(position)-=1;
	}
	else
	{
		jump_table->at(position)+=1;
	}
	position += jump;

	return position;
}

