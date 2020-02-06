/*
 * TimeItTwo.cpp
 * CS 202
 * February 5, 2020
 * Bryan Beus
 * TimeItTwo function definition file for time it ii in hw1
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
#include "StopWatch.hpp"
#include "TimeItTwo.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::round;
using std::ofstream;
using std::ifstream;
using std::string;

// Calculate the time data for the book of the provided title
vector<StopWatch> calcTime(string &book, std::mt19937 &e1) {

    // Create vector to hold results
    vector<StopWatch> tests;

    /****************************************
    ******* Time with List Container  *******
    ****************************************/
    // Open file stream
    ifstream book_container_for_list(book);

    // Test for ifstream error
	if (!book_container_for_list) {
		cout << "Error opening file" << endl;
		return tests;
	}

    // Initial empty list to hold values
    std::list<string> list_container;

    // Start the timer
    StopWatch timer_for_list_load; 

    // Iterate through the stream and load the list
	while (!book_container_for_list.eof()) {
		string s;
		getline(book_container_for_list, s);
        list_container.push_back(s);
	}

    // End the stop watch
    timer_for_list_load.captureFinishTime(); 

    // Add data to the series
    tests.push_back(timer_for_list_load); 

    /***************************************************
    * Find Random String in List Container  ************
    ***************************************************/ 

    // Choose a random string
    string random_str_from_list_load = "Corrected EDITIONS of our eBooks repl";

    // Start the time for the event
    StopWatch timer_for_find_random_str_in_list; 

    // Iterate through list to find string
    std::list<std::string>::iterator it_list_container_string;
    it_list_container_string = std::find(list_container.begin(), list_container.end(), random_str_from_list_load);

    // Indicate the finish time
    timer_for_find_random_str_in_list.captureFinishTime(); 

    // Add data to series
    tests.push_back(timer_for_find_random_str_in_list); 

    /****************************************
    * Sort List Container  ******************
    ****************************************/ 

    // Start the timer
    StopWatch timer_for_sort_list; 

    // Sort the list
    list_container.sort();

    // Record finisht time
    timer_for_sort_list.captureFinishTime(); 

    // Add data to series
    tests.push_back(timer_for_sort_list); 

    /****************************************
    * Time with Vector Container  *************
    ****************************************/

    // Create stream for vector
    ifstream book_container_for_vector(book);

    // Error testing on ifstream
	if (!book_container_for_vector) {
		cout << "Error opening file" << endl;
		return tests;
	}

    // Create vector to hold loaded boo
    std::vector<string> vector_container;

    // Start the timer
    StopWatch timer_for_vector_load; 

    // Iterate through book and load vector
	while (!book_container_for_vector.eof()) {
		string s;
		getline(book_container_for_vector, s);
        vector_container.push_back(s);
	}

    // End timer
    timer_for_vector_load.captureFinishTime(); 

    // Add data to series
    tests.push_back(timer_for_vector_load); 

    /***************************************************
    * Find Random String in Vector Container  ************
    ***************************************************/ 

    // Choose random string for search
    string random_str_from_vector_load = "Corrected EDITIONS of our eBooks repl";

    // Start the timer
    StopWatch timer_for_find_random_str_in_vector; 

    // Iterate through vector and perform search
    std::vector<std::string>::iterator it_vector_container_string;
    it_vector_container_string = std::find(vector_container.begin(), vector_container.end(), random_str_from_vector_load);

    // Indicate time finish
    timer_for_find_random_str_in_vector.captureFinishTime(); 

    // Add data to series
    tests.push_back(timer_for_find_random_str_in_vector); 

    /****************************************
    * Sort Vector Container  ******************
    ****************************************/ 

    // Start timer
    StopWatch timer_for_sort_vector; 

    // Sort the vector
    std::sort(vector_container.begin(),vector_container.end());

    // Record finish time
    timer_for_sort_vector.captureFinishTime(); 

    // Add data to series
    tests.push_back(timer_for_sort_vector); 


    /****************************************
    * Time with Deque Container  *************
    ****************************************/

    // Create stream for deque
    ifstream book_container_for_deque(book);

    // Error test for ifstream
	if (!book_container_for_deque) {
		cout << "Error opening file" << endl;
		return tests;
	}

    // Create loaded deque
    std::deque<string> deque_container;

    // Start the timer
    StopWatch timer_for_deque_load; 

    // Iterate through ifstream and load deque with boo
	while (!book_container_for_deque.eof()) {
		string s;
		getline(book_container_for_deque, s);
        deque_container.push_back(s);
	}

    // Capture finish time
    timer_for_deque_load.captureFinishTime(); 

    // Add time data to series
    tests.push_back(timer_for_deque_load); 

    /***************************************************
    * Find Random String in Deque Container  ************
    ***************************************************/ 

    // Create random string for search
    string random_str_from_deque_load = "Corrected EDITIONS of our eBooks repl";

    // Start the timer
    StopWatch timer_for_find_random_str_in_deque; 

    // Iterate through deque and find item
    std::deque<std::string>::iterator it_deque_container_string;
    it_deque_container_string = std::find(deque_container.begin(), deque_container.end(), random_str_from_deque_load);

    // Capture finish time
    timer_for_find_random_str_in_deque.captureFinishTime(); 

    // Add data to stac
    tests.push_back(timer_for_find_random_str_in_deque); 

    /****************************************
    * Sort Deque Container  ******************
    ****************************************/ 

    // Start timer
    StopWatch timer_for_sort_deque; 

    // Sort deque
    std::sort(deque_container.begin(), deque_container.end());

    // Capture finish time
    timer_for_sort_deque.captureFinishTime(); 

    // Add time data to series
    tests.push_back(timer_for_sort_deque); 

    return tests; 
}

// Print the individual component of the provided data set
void printNextSet(vector<StopWatch> obj, int curr_counter) { 
    for (unsigned long i = 0; i < obj.size(); ++i) {
        cout << std::fixed << std::setprecision(10) << obj[i].reportFinishTime() << "," << endl; 
    }
    cout << endl << endl;
}

