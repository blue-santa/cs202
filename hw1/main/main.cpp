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

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::round;

class StopWatch {

    private:
        std::time_t _start_time = (time_t)(-1);
        std::time_t _finish_time = (time_t)(-1);
        int iter = 0;

    public:

        StopWatch() { 
            this->startClock();
        };

        void startClock() {
            auto s = std::chrono::high_resolution_clock::now(); 
            _start_time = std::chrono::high_resolution_clock::to_time_t(s);
        }
        
        void captureFinishTime() {
            auto f = std::chrono::high_resolution_clock::now(); 
            _finish_time = std::chrono::high_resolution_clock::to_time_t(f);
            this->reportRawTimes();
        }

        double reportFinishTime() {
            this->reportRawTimes();
            double _val = difftime(_finish_time, _start_time);
            cout << "difftime: " << _val << endl;
            this->reportRawTimes();
            return _val;
        } 

        void reportRawTimes() { 
            cout << "_start_time: " << _start_time << " _finish_time: " << _finish_time << endl;
            ++iter;
            cout << "iter: " << iter << endl;
        }
};

vector<int> calcObj(const int iteration_number, std::mt19937 &e1) {

    vector<int> obj;
    std::normal_distribution<> normal_dist(1500, 500), min(1), max(9);

    for (int i = 0; i < iteration_number; i++) {
        int val = normal_dist(e1);
        obj.push_back(val);
    }

    return obj;

}

vector<StopWatch> calcTime(const vector<int> calcObj, const vector<int> searchObj) {

    // Create vector to hold results
    vector<StopWatch> tests;

    // Declare moment testing
    cout << "Initiating Search method test" << endl;

    // Search method tests 
    for (int i = 0; i < 5; i++) {
        // Declare and initiate StopWatch variables for search method
        vector<int>::const_iterator it; 
        StopWatch test; 
        it = std::search(calcObj.begin(), calcObj.end(), searchObj.begin(), searchObj.end()); 
        test.captureFinishTime(); 
        tests.push_back(test); 
        cout << "Completed Search method test (" << i << ") with a final time of: " << test.reportFinishTime() << endl;
        test.reportRawTimes();
    }

    return tests; 
}

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

	return 0;
}


