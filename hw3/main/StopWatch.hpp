/*
 * StopWatch.hpp
 * CS 202
 * February 15, 2020
 * Bryan Beus
 * Header file for StopWatch class
 */

#ifndef __STOPWATCH_HPP_
#define __STOPWATCH_HPP_

#include <chrono>

class StopWatch {

    // Private member values to track time points and duration
    private:
        std::chrono::high_resolution_clock::time_point _start_time;
        std::chrono::high_resolution_clock::time_point _finish_time;
        std::chrono::duration<double> _dur;

    public:

        // The default constructor for StopWatch
        StopWatch();

        // Start the clock by setting _start_time
        void startClock();       

        // Indicate finish time by setting _finish_time
        void captureFinishTime();

        // Return a double value that represents total duration in miliseconds
        double reportFinishTime();

        // A coding tool that reports individual raw times
        void reportRawTimes();

}; 

#endif

