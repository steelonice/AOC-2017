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

int part_two_solver(std::vector<int> input_vec);

int main(int argc, char *argv[])
{
	/* Input file stream */
	std::ifstream ifs("Input", std::ifstream::in);

	/* Single line input string */
	std::string 		input_line;
	std::stringstream	input_line_stream;

	/* Vector to store values in */
	std::vector<int>	input_line_int;
	int					number_add;
	int					min = 0;
	int 				max = 0;
	int					sum = 0;
	int					sum_p2 = 0;

	do
	{
		std::getline(ifs, input_line, '\n');
		if(input_line.empty() != true)
		{
			input_line_int.clear();
			input_line_stream.clear();
			input_line_stream.str(input_line);
			do{
				input_line_stream >> number_add;
				input_line_int.push_back(number_add);
			}while(!input_line_stream.eof());
			max = *std::max_element(input_line_int.begin(), input_line_int.end());
			min = *std::min_element(input_line_int.begin(), input_line_int.end());
			sum += std::abs(max - min);
			sum_p2 += part_two_solver(input_line_int);
		}

	}while(ifs.eof() != true);


	std::cout << sum << "\n" << sum_p2;

    return 0;
}

int part_two_solver(std::vector<int> input_vec)
{
	int ret_val;

	for(int i = 0; i < input_vec.size(); i++)
	{
		for(int j = 0; j < input_vec.size(); j++)
		{
			if(i == j)
			{
			}
			else if(input_vec.at(i) >= input_vec.at(j))
			{
				if(input_vec.at(i) % input_vec.at(j) == 0)
				{
					return input_vec.at(i) / input_vec.at(j);
				}
			}
			else if(input_vec.at(i) < input_vec.at(j))
			{
				if(input_vec.at(j) % input_vec.at(i) == 0)
				{
					return input_vec.at(j) / input_vec.at(i);

				}
			}
		}
	}
}




