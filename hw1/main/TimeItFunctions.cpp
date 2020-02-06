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

vector<int> calcObj(const int iteration_number, std::mt19937 &e1) {

    vector<int> obj;
    std::normal_distribution<> normal_dist(1500, 500), min(1), max(9);

    for (int i = 0; i < iteration_number; i++) {
        int val = normal_dist(e1);
        obj.push_back(val);
    } 

    return obj;

}

vector<StopWatch> calcTime(vector<int> calcObj, const vector<int> searchObj) {

    // Create vector to hold results
    vector<StopWatch> tests;

    /****************************************
    * Begin Sort Method *********************
    ****************************************/
    cout << "Sort method test" << endl;

    // Declare and initiate StopWatch variables for method
    for (int i = 0; i < 5; i++) {
        StopWatch test; 
        std::sort(calcObj.begin(), calcObj.end()); 
        test.captureFinishTime(); 
        tests.push_back(test); 
        cout << "Completed test (" << i + 1 << ") with a final time of: " << test.reportFinishTime() << endl << endl;;
    }

    /****************************************
    * Begin Search Method *******************
    ****************************************/
    cout << "Initiating Search method test\nSearchObj: " << searchObj[0] << endl;

    // Search method tests 
    for (int i = 0; i < 5; i++) {
        // Declare and initiate StopWatch variables for search method
        vector<int>::iterator it; 
        StopWatch test; 
        it = std::search(calcObj.begin(), calcObj.end(), searchObj.begin(), searchObj.end()); 
        test.captureFinishTime(); 
        tests.push_back(test); 
        cout << "Completed Search method test (" << i + 1 << ") with a final time of: " << test.reportFinishTime() << endl << endl;;
    }

    /****************************************
    * Begin Binary Search Method ************
    ****************************************/
    cout << "Binary Search method test" << endl;

    // Search method tests 
    for (int i = 0; i < 5; i++) {

        // Declare and initiate StopWatch variables for method
        StopWatch test; 
        std::binary_search(calcObj.begin(), calcObj.end(), searchObj[0]); 
        test.captureFinishTime(); 
        tests.push_back(test); 
        cout << "Completed Binary Search method test (" << i + 1 << ") with a final time of: " << test.reportFinishTime() << endl << endl;;
    }

    /****************************************
    * Begin Reverse Method ******************
    ****************************************/
    cout << "Reverse method test" << endl;

    // Search method tests 
    for (int i = 0; i < 5; i++) {

        // Declare and initiate StopWatch variables for method
        StopWatch test; 
        std::reverse(calcObj.begin(), calcObj.end()); 
        test.captureFinishTime(); 
        tests.push_back(test); 
        cout << "Completed Search method test (" << i + 1 << ") with a final time of: " << test.reportFinishTime() << endl << endl;;
    }
    return tests; 
}

void printNextFive(int start_point, vector<StopWatch> obj, int curr_counter) { 
    for (int i = 0; i < 5; ++i) {
        cout << curr_counter << "," << std::fixed << std::setprecision(10) << obj[i + start_point].reportFinishTime() << "," << endl; 
    }
    cout << endl << endl;
}
