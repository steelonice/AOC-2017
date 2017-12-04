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

int get_num_valid(std::vector<std::string> input_vector);
int get_num_valid_w_anagram(std::vector<std::string> input_vector);


int main(int argc, char *argv[])
{
	/* Input file stream */
	std::ifstream ifs("Input", std::ifstream::in);

	/* Single line input string */
	std::string 		input_line;
	std::stringstream	input_line_stream;

	/* Vector to store values in */
	std::vector<std::string>	input_line_string;
	std::string					number_add;

	int sum = 0;
	int sum_anagram = 0;

	do
	{
		std::getline(ifs, input_line, '\n');
		if(input_line.empty() != true)
		{
			input_line_string.clear();
			input_line_stream.clear();
			input_line_stream.str(input_line);
			do{
				input_line_stream >> number_add;
				input_line_string.push_back(number_add);
			}while(!input_line_stream.eof());

			sum += get_num_valid(input_line_string);
			sum_anagram += get_num_valid_w_anagram(input_line_string);
		}

	}while(ifs.eof() != true);

	std::cout << "Num Valid Passwords: " << sum << "\n";
	std::cout << "Num Valid Passwords w/ Anagram Check: " << sum_anagram;
    return 0;
}

int get_num_valid(std::vector<std::string> input_vector)
{
	for(int i = 0; i < input_vector.size(); i++)
	{
		for(int j = 0; j < input_vector.size(); j++)
		{
			if(i == j)
			{

			}
			else if(input_vector.at(i) == input_vector.at(j))
			{
				return 0;
			}
		}
	}
	return 1;
}

int get_num_valid_w_anagram(std::vector<std::string> input_vector)
{
	std::string sorted_i;
	std::string sorted_j;

	for(int i = 0; i < input_vector.size(); i++)
	{
		sorted_i = input_vector.at(i);
		std::sort(sorted_i.begin(), sorted_i.end());

		for(int j = 0; j < input_vector.size(); j++)
		{

			if(i == j)
			{

			}
			else
			{
				sorted_j = input_vector.at(j);
				std::sort(sorted_j.begin(), sorted_j.end());
				if(sorted_i == sorted_j)
				{
					return 0;
				}
			}

		}
	}
	return 1;
}

