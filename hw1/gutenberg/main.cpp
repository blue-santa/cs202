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
#include <fstream>
#include <deque>
#include <list>

#include "Miscellaneous.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::round;
using std::ofstream;
using std::ifstream;
using std::string;

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

vector<StopWatch> calcTime(string &book, std::mt19937 &e1) {

    // Create vector to hold results
    vector<StopWatch> tests;

    /****************************************
    ******* Time with List Container  *******
    ****************************************/

    // Create stream for list
    ifstream book_container_for_list(book);

	if (!book_container_for_list) {
		cout << "Error opening file" << endl;
		return tests;
	}

    std::list<string> list_container;
    StopWatch timer_for_list_load; 
	while (!book_container_for_list.eof()) {
		string s;
		getline(book_container_for_list, s);
        list_container.push_back(s);
	}
    timer_for_list_load.captureFinishTime(); 
    tests.push_back(timer_for_list_load); 

    /****************************************
    * Save Random Book Location  ************
    ****************************************/

    string random_str_from_list_load = "Corrected EDITIONS of our eBooks repl";

    /***************************************************
    * Find Random String in List Container  ************
    ***************************************************/ 

    StopWatch timer_for_find_random_str_in_list; 
    std::list<std::string>::iterator it_list_container_string;
    it_list_container_string = std::find(list_container.begin(), list_container.end(), random_str_from_list_load);
    timer_for_find_random_str_in_list.captureFinishTime(); 
    tests.push_back(timer_for_find_random_str_in_list); 

    /****************************************
    * Sort List Container  ******************
    ****************************************/ 

    StopWatch timer_for_sort_list; 
    list_container.sort();
    timer_for_sort_list.captureFinishTime(); 
    tests.push_back(timer_for_sort_list); 

    /****************************************
    * Time with Vector Container  *************
    ****************************************/

    // Create stream for vector
    ifstream book_container_for_vector(book);

	if (!book_container_for_vector) {
		cout << "Error opening file" << endl;
		return tests;
	}

    std::vector<string> vector_container;
    StopWatch timer_for_vector_load; 
	while (!book_container_for_vector.eof()) {
		string s;
		getline(book_container_for_vector, s);
        vector_container.push_back(s);
	}
    timer_for_vector_load.captureFinishTime(); 
    cout << "load: " << timer_for_vector_load.reportFinishTime() << endl;
    tests.push_back(timer_for_vector_load); 

    /****************************************
    * Save Random Book Location  ************
    ****************************************/

    string random_str_from_vector_load = "Corrected EDITIONS of our eBooks repl";

    /***************************************************
    * Find Random String in Vector Container  ************
    ***************************************************/ 

    StopWatch timer_for_find_random_str_in_vector; 
    std::vector<std::string>::iterator it_vector_container_string;
    it_vector_container_string = std::find(vector_container.begin(), vector_container.end(), random_str_from_vector_load);
    timer_for_find_random_str_in_vector.captureFinishTime(); 
    tests.push_back(timer_for_find_random_str_in_vector); 

    /****************************************
    * Sort Vector Container  ******************
    ****************************************/ 

    StopWatch timer_for_sort_vector; 
    std::sort(vector_container.begin(),vector_container.end());
    timer_for_sort_vector.captureFinishTime(); 
    tests.push_back(timer_for_sort_vector); 


    /****************************************
    * Time with Deque Container  *************
    ****************************************/

    // Create stream for deque
    ifstream book_container_for_deque(book);

	if (!book_container_for_deque) {
		cout << "Error opening file" << endl;
		return tests;
	}

    std::deque<string> deque_container;
    StopWatch timer_for_deque_load; 
	while (!book_container_for_deque.eof()) {
		string s;
		getline(book_container_for_deque, s);
        deque_container.push_back(s);
	}
    timer_for_deque_load.captureFinishTime(); 
    cout << "load: " << timer_for_deque_load.reportFinishTime() << endl;
    tests.push_back(timer_for_deque_load); 

    /****************************************
    * Save Random Book Location  ************
    ****************************************/

    string random_str_from_deque_load = "Corrected EDITIONS of our eBooks repl";

    /***************************************************
    * Find Random String in Deque Container  ************
    ***************************************************/ 

    StopWatch timer_for_find_random_str_in_deque; 
    std::deque<std::string>::iterator it_deque_container_string;
    it_deque_container_string = std::find(deque_container.begin(), deque_container.end(), random_str_from_deque_load);
    timer_for_find_random_str_in_deque.captureFinishTime(); 
    tests.push_back(timer_for_find_random_str_in_deque); 

    /****************************************
    * Sort Deque Container  ******************
    ****************************************/ 

    StopWatch timer_for_sort_deque; 
    std::sort(deque_container.begin(), deque_container.end());
    timer_for_sort_deque.captureFinishTime(); 
    tests.push_back(timer_for_sort_deque); 

    return tests; 
}

void printNextSet(vector<StopWatch> obj, int curr_counter) { 
    for (unsigned long i = 0; i < obj.size(); ++i) {
        cout << std::fixed << std::setprecision(10) << obj[i].reportFinishTime() << "," << endl; 
    }
    cout << endl << endl;
}

int main()
{
    /*****************************
    *   Create a Random Device   *
    *****************************/
	std::random_device r;
	std::seed_seq seedObj{r(), r(), r(), r(), r(), r(), r(), r()};
	std::mt19937 e1(seedObj);

    /*********************************
    *   Initiate Project Variables   *
    *********************************/

    // Create list of results
    vector< vector<StopWatch>> results;

    // Names of books
    vector<string> book_names;

    book_names.push_back("legends-of-the-middle-ages.txt");
    book_names.push_back("myths-of-greece-and-rome.txt");
    book_names.push_back("myths-of-the-norse-men.txt");
    book_names.push_back("stories-of-the-wagner-opera.txt");
    book_names.push_back("story-of-the-greeks.txt");

    // To track number of books scanned
    unsigned long i = 0;

    while(i < book_names.size()) {
        
        cout << "Proceeding to book:  " << book_names[i] << endl;
        
        vector<StopWatch> current_result = calcTime(book_names[i], e1);

        results.push_back(current_result);

        i++;

    }

    clearConsole();

    for (unsigned long i = 0; i < results.size(); i++) {
        cout << book_names[i] << endl;
        printNextSet(results[i], i);
        cout << endl; }

	return 0;
}

