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

#define ASCII_TO_NUM	48

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
		}

	}while(ifs.eof() != true);


	std::cout << sum;

    return 0;
}
