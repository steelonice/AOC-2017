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

#include <thread>

#include "main.h"

#define ASCII_TO_NUM	48

int main(int argc, char *argv[])
{
	std::ifstream ifs("Input", std::ifstream::in);

	std::string input_line;

	std::getline(ifs, input_line, '\n');

	std::cout << input_line;

    return 0;
}
