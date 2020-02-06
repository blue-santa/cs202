/*
 * main.cpp
 * CS 202
 * January 19, 2020
 * Bryan Beus
 * Main file for temperature main project in hw0
 */

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <random>
#include <cmath>
#include <stdlib.h>
#include <chrono>
#include <vector>
#include <algorithm>
#include <time.h>

#include "Miscellaneous.hpp"
#include "TimeItFunctions.hpp"
#include "StopWatch.hpp" 

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::round;

int main()
{
	// Declare pseudo-random device for creating seeds
	std::random_device r;

	// Create a seed sequence to feed to the generator
	std::seed_seq seedObj{r(), r(), r(), r(), r(), r(), r(), r()};

	// Declare random-number generator and provide with seedObj sequence
	std::mt19937 e1(seedObj);

    // Declare number of times to multiply list size
    int num_lists = 9;

    // Create list of results
    vector< vector<StopWatch>> results;

    // Create random number that will serve as the search marker
    vector<int> searchObj = calcObj(1, e1);

    // Perform each round
    int i = 1;

    while(i < num_lists + 1) {
        
        vector<int> objList = calcObj(pow(10, i), e1);

        cout << "objList " << i << " created" << endl;
        
        vector<StopWatch> current_result = calcTime(objList, searchObj);

        results.push_back(current_result);

        i++;

    }

    clearConsole();

    double curr_counter = 10.0;
    for (auto i: results) {

        for (int j = 0; j < 4; j++) {
            printNextFive(j, i, curr_counter);
        } 
        cout << endl;
        curr_counter *= 10;

    }

	return 0;
}


