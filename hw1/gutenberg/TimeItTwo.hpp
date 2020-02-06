/*
 * TimeItTwo.hpp
 * CS 202
 * February 5, 2020
 * Bryan Beus
 * Header file for time it ii functions in hw1
 */

#ifndef __TIME_TWO__
#define __TIME_TWO__

#include <vector> 
#include "StopWatch.hpp" 
using std::vector;

// Calculate the time data for the book of the provided title
vector<StopWatch> calcTime(string &book, std::mt19937 &e1);

// Print each individual value in the set of the data series
void printNextSet(vector<StopWatch> obj, int curr_counter);

#endif
