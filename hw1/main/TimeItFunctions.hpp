/*
 * TimeItFunctions.hpp
 * CS 202
 * February 5, 2020
 * Bryan Beus
 * Header definition file for time-it functions
 */

#ifndef __TIMEIT_FUNC__
#define __TIMEIT_FUNC__

#include <random>
#include <vector>

#include "StopWatch.hpp"

using std::vector;

// Create an object of random values for testing purposes
vector<int> calcObj(const int iteration_number, std::mt19937 &e1);

// Perform the tests to calculate the times
vector<StopWatch> calcTime(vector<int> calcObj, const vector<int> searchObj);

// Print the next five individual values in the data series
void printNextFive(int start_point, vector<StopWatch> obj, int curr_counter);

#endif
