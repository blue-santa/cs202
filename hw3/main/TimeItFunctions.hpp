/*
 * TimeItFunctions.hpp
 * CS 202
 * February 15, 2020
 * Bryan Beus
 * Header definition file
 */

#ifndef __TIMEIT_FUNC__
#define __TIMEIT_FUNC__

#include <random>
#include <vector>

#include "StopWatch.hpp"

using std::vector;

// Perform the tests to calculate the times
vector<StopWatch> calcTime(vector<int> calcObj, const vector<int> searchObj);

#endif
