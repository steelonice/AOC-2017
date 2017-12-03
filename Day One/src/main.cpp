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
#include <sstream>

#include <vector>

#include <thread>

#include "main.h"

#define ASCII_TO_NUM	48

int main(int argc, char *argv[])
{
	std::string			user_input;
	std::string 		delimeter = "\n";
	std::stringstream	single_line;
	std::vector<int>	single_line_vec;
	int temp;

	/* Get all user input */
	while(std::cin.eof())std::cin >> user_input;

	do{
		/* Parse out one row */
		single_line.str() = user_input.substr(0, user_input.find(delimeter));

		while(single_line.str().empty() != true)
		{
			single_line >> temp;
			single_line_vec.push_back(temp);
			std::cout << temp;
		}
		std::cout << '\n';
		/* Delete row from input */
		user_input.erase(0, user_input.find(delimeter) + delimeter.length());
	}while(user_input.empty() != true);

    return 0;
}


