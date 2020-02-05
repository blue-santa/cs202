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
        std::time_t _start_time;
        std::time_t _finish_time;

    public:

        StopWatch() { 
            startClock();
            captureFinishTime();
        };

        void startClock() {
            auto s = std::chrono::system_clock::now(); 
            _start_time = std::chrono::system_clock::to_time_t(s);
        }
        
        void captureFinishTime() {
            auto f = std::chrono::system_clock::now(); 
            _finish_time = std::chrono::system_clock::to_time_t(f);
        }

        double reportFinishTime() {
            double _dur = difftime(_start_time, _finish_time);
            return _dur;
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

vector<StopWatch> calcTime(const vector<int> calcObj, const vector<int> seedObj) {

    // Create vector to hold results
    vector<StopWatch> tests;

    // Declare moment testing
    cout << "Initiating Search method test" << endl;

    // Search method tests 
    for (int i = 0; i < 5; i++) {
        // Declare and initiate StopWatch variables for search method
        vector<int>::iterator it; 
        StopWatch test; 
        it = std::search(calcObj.begin(), calcObj.end(), searchObj.begin(), searchObj.end()); 
        test.captureFinishTime(); 
        tests.push_back(test); 
        cout << "Completed Search method test (" << i << ") with a final time of: " << test.reportFinishTime() << endl;
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


