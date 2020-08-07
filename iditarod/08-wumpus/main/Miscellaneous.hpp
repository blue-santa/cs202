/*
 * Miscellaneous.hpp
 * CS 202
 * March 3, 2020
 * Bryan Beus
 * Declaration file for miscellaneous content
 */

#ifndef MISC_HPP
#define MISC_HPP 

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <random>
#include <cmath>
#include <stdlib.h>

using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::getline;
using std::istringstream;
using std::setw;
using std::left;
using std::mt19937;

// Clear the console
void clearConsole();

// Wait for user response
void waitForContinue();

// Capture the user input
void capture_user_input(int& userInput);

// Test whether the user's integer input is a valid response
bool testUserInput(string& user_input_temp, int& userInput);

// Choose a random room
int chooseRandomRoom(mt19937 *e1, const int lower_limit, const int upper_limit);

#endif
