/*
 * main.cpp
 *
 *  Created on: Oct 29, 2017
 *  Author: Hayden Chuter
 *
 *  \notes 	A simple server in the internet domain using TCP
 *   	  	The port number is passed as an argument
 *
 */

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>

#include <thread>

#include "main.h"

#define ASCII_TO_NUM	48

int main(int argc, char *argv[])
{
	std::string	user_input;
	int sum = 0;
	int * input;

	std::cin >> user_input;

	input = new int[user_input.size()];

	for(int loop = 0; loop < user_input.size(); loop++)
	{
		input[loop] = user_input.at(loop) - ASCII_TO_NUM;
		//std::cout << input[loop] << '\n';
	}

	for(int loop = 0; loop < user_input.size(); loop++)
	{

		if(input[(loop)%user_input.size()] == input[(loop+1)%user_input.size()])
		{
			sum += input[(loop)%user_input.size()];
		}
	}
	std::cout << "Sum: " << sum << '\n';

	delete[] input;
    return 0;
}
