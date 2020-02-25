/*
 * StopWatch.cpp
 * CS 202
 * February 15, 2020
 * Bryan Beus
 * StopWatch member definition file
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
#include "TokenizerFunctions.hpp"
#include "StopWatch.hpp" 

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::round;

// The default constructor
StopWatch::StopWatch() { 
    this->startClock();
};

// Start the clock by setting _start_time
void StopWatch::startClock() {
    _start_time = std::chrono::high_resolution_clock::now(); 
}
        
// Indicate the finish time by setting _finish_time
void StopWatch::captureFinishTime() {
    _finish_time = std::chrono::high_resolution_clock::now(); 
}

// Return a double value that represents the duration of the clock in miliseconds
double StopWatch::reportFinishTime() {
    _dur = std::chrono::duration_cast<std::chrono::duration<double>>(_finish_time - _start_time);
    return (double)(_dur.count());
} 

// A coding tool to report raw start and finish times
void StopWatch::reportRawTimes() { 
    cout << "_start_time: " << _start_time.time_since_epoch().count() << " _finish_time: " << _finish_time.time_since_epoch().count() << endl;
} 
