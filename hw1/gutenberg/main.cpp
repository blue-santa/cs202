/*
 * main.cpp
 * CS 202
 * February 5, 2020
 * Bryan Beus
 * Main file for time-it-ii project in hw1
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

int main()
{
    // Create a Random Device 
	std::random_device r;
	std::seed_seq seedObj{r(), r(), r(), r(), r(), r(), r(), r()};
	std::mt19937 e1(seedObj);

    // Initiate Project Variables 

    // Create list of results
    vector< vector<StopWatch>> results;

    // Names of books
    vector<string> book_names;

    book_names.push_back("legends-of-the-middle-ages.txt");
    book_names.push_back("myths-of-greece-and-rome.txt");
    book_names.push_back("myths-of-the-norse-men.txt");
    book_names.push_back("stories-of-the-wagner-opera.txt");
    book_names.push_back("story-of-the-greeks.txt");

    for(unsigned long i = 0; i < book_names.size(); i++) {
        
        // Calculate the next result
        vector<StopWatch> current_result = calcTime(book_names[i], e1); 

        // Add data to series
        results.push_back(current_result); 
    }

    clearConsole();

    // Print the results to the console using the printNextSet() function
    for (unsigned long i = 0; i < results.size(); i++) {
        cout << book_names[i] << endl;
        printNextSet(results[i], i);
        cout << endl; }

	return 0;
}

