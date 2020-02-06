/*
 * StopWatch.hpp
 * CS 202
 * February 5, 2020
 * Bryan Beus
 * Header file for StopWatch class for main in hw1
 */

#ifndef __STOPWATCH_HPP_
#define __STOPWATCH_HPP_

#include <chrono>

class StopWatch {

    private:
        std::chrono::high_resolution_clock::time_point _start_time;
        std::chrono::high_resolution_clock::time_point _finish_time;
        std::chrono::duration<double> _dur;

    public:

        StopWatch();
        void startClock();       
        void captureFinishTime();
        double reportFinishTime();
        void reportRawTimes();
};

#endif

