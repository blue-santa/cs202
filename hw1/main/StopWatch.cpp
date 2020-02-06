/*
 * StopWatch.cpp
 * CS 202
 * February 5, 2020
 * Bryan Beus
 * StopWatch member definition file for main in hw1
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

StopWatch::StopWatch() { 
    this->startClock();
};

void StopWatch::startClock() {
    _start_time = std::chrono::high_resolution_clock::now(); 
}
        
void StopWatch::captureFinishTime() {
    _finish_time = std::chrono::high_resolution_clock::now(); 
}

double StopWatch::reportFinishTime() {
    _dur = std::chrono::duration_cast<std::chrono::duration<double>>(_finish_time - _start_time);
    return (double)(_dur.count());
} 

void StopWatch::reportRawTimes() { 
    cout << "_start_time: " << _start_time.time_since_epoch().count() << " _finish_time: " << _finish_time.time_since_epoch().count() << endl;
}



