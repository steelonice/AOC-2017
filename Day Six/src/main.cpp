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
#include "mem_block.h"

int main(int argc, char *argv[])
{


	/* Input file stream */
	std::ifstream ifs("Input", std::ifstream::in);

	/* Single line input string */
	std::string 		input_line;
	std::stringstream	input_stream;
	int					input_num;
	std::vector<int>	block_table;

	std::getline(ifs, input_line, '\n');
	input_stream.str(input_line.c_str());
	do{
		input_stream >> input_num;
		block_table.push_back(input_num);
	}while(input_stream.eof() != true);

	mem_block aoc_block(block_table);

	int num_dupe = 0;
	int first_dupe = 0;
	int second_dupe = 0;
	bool first_dupe_found = false;
	bool second_dupe_found = false;
	while(aoc_block.check_dupe() < 3)
	{
		int redist_pos = 0;

		redist_pos = aoc_block.get_redist_cand();
		aoc_block.redist(redist_pos);

		num_dupe = aoc_block.check_dupe();
		if(num_dupe == 2 && first_dupe_found == false)
		{
			first_dupe_found = true;
			first_dupe = aoc_block.get_num_redist();
		}
		else if(num_dupe == 3 && second_dupe_found == false)
		{
			second_dupe_found = true;
			second_dupe = aoc_block.get_num_redist();
		}
	}

	std::cout << "Number of Redist for first dupe: " << first_dupe << "\n";
	std::cout << "Number of Redist for second dupe: " << second_dupe - first_dupe << "\n";



    return 0;
}




