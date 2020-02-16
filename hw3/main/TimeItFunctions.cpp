/*
 * TimeItFunctions.cpp
 * CS 202
 * February 5, 2020
 * Bryan Beus
 * 
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

// Perform the timer tests
vector<StopWatch> calcTime(vector<int> calcObj, const vector<int> searchObj) {

    // Create vector to hold results
    vector<StopWatch> tests;

    /*****************************************
    * Sort Method ****************************
    *****************************************/

    for (int i = 0; i < 5; i++) {
        StopWatch test; 
        std::sort(calcObj.begin(), calcObj.end()); 
        test.captureFinishTime(); 
        tests.push_back(test); 
        // cout << "Completed test (" << i + 1 << ") with a final time of: " << test.reportFinishTime() << endl << endl;;
    }

    /****************************************
    * Search Method *************************
    ****************************************/
    for (int i = 0; i < 5; i++) {
        vector<int>::iterator it; 
        StopWatch test; 
        it = std::search(calcObj.begin(), calcObj.end(), searchObj.begin(), searchObj.end()); 
        test.captureFinishTime(); 
        tests.push_back(test); 
        // cout << "Completed Search method test (" << i + 1 << ") with a final time of: " << test.reportFinishTime() << endl << endl;;
    }

    /****************************************
    * Binary Search Method ******************
    ****************************************/
    for (int i = 0; i < 5; i++) { 
        StopWatch test; 
        std::binary_search(calcObj.begin(), calcObj.end(), searchObj[0]); 
        test.captureFinishTime(); 
        tests.push_back(test); 
        // cout << "Completed Binary Search method test (" << i + 1 << ") with a final time of: " << test.reportFinishTime() << endl << endl;;
    }

    /****************************************
    * Reverse Method ************************
    ****************************************/
    for (int i = 0; i < 5; i++) {
        StopWatch test; 
        std::reverse(calcObj.begin(), calcObj.end()); 
        test.captureFinishTime(); 
        tests.push_back(test); 
        // cout << "Completed Search method test (" << i + 1 << ") with a final time of: " << test.reportFinishTime() << endl << endl;;
    }
    return tests; 
}
