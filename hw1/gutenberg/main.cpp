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

#include "Miscellaneous.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::round;

class StopWatch {

    private:
        std::chrono::high_resolution_clock::time_point _start_time;
        std::chrono::high_resolution_clock::time_point _finish_time;
        std::chrono::duration<double> _dur;

    public:

        StopWatch() { 
            this->startClock();
        };

        void startClock() {
            _start_time = std::chrono::high_resolution_clock::now(); 
        }
        
        void captureFinishTime() {
            _finish_time = std::chrono::high_resolution_clock::now(); 
        }

        double reportFinishTime() {
            _dur = std::chrono::duration_cast<std::chrono::duration<double>>(_finish_time - _start_time);
            return (double)(_dur.count());
        } 

        void reportRawTimes() { 
            cout << "_start_time: " << _start_time.time_since_epoch().count() << " _finish_time: " << _finish_time.time_since_epoch().count() << endl;
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
int main()
{
	// Declare pseudo-random device for creating seeds
	std::random_device r;

	// Create a seed sequence to feed to the generator
	std::seed_seq seedObj{r(), r(), r(), r(), r(), r(), r(), r()};

	// Declare random-number generator and provide with seedObj sequence
	std::mt19937 e1(seedObj);

    // Import each book
    string legends_of_the_middle_ages = std::fin(legends-of-the-middle-ages.txt);

    

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

    clearConsole();

    double curr_counter = 10.0;
    for (auto i: results) {

        for (int j = 0; j < 4; j++) {
            printNextFive(j, i, curr_counter);
        } 
        cout << endl;
        curr_counter *= 10;

    }

	return 0;
}


/*
 * iostream.cpp
 * CS 201
 * Bryan Beus
 * November 8, 2019
 * Stream to a file
 *


#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>

using std::vector;
using std::pair;
using std::string;
using std::cout;
using std::endl;
using std::ofstream;

int main() {

	ofstream fout("file");
	if (!fout) {
		cout << "Error opening file" << endl;
		return 0;
	}

	for (int i = 1; i <= 100; i++) {
		fout << std::setw(3) << std::right;
		if (i != 100)
			fout << i;
		else
			fout << std::setw(1) << " " << std::setw(3) << i;
		if (i % 10 == 0)
			fout << endl;
	}

	return 0;
}

*/
