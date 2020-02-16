/*
 * main.cpp
 * CS 202
 * February 14, 2020
 * Bryan Beus
 * Main file for main project in hw2
 */

#define CATCH_CONFIG_MAIN

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
// #include <list>
// #include <iterator>
// #include <sstream>
#include <fstream>
#include <utility>

#include "Miscellaneous.hpp"
#include "Value.hpp" 
#include "StopWatch.hpp"
#include "TokenizerFunctions.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
using std::pair;
// using std::right;
using std::ifstream;
using std::ofstream;

bool getLineInput(int &argv, char** argc) {

    bool res = false;

    if (argv < 2) {
        return res;
    }
    
    string isLineOnly = s(argc[2]);

    if (isLineOnly == "--line-only") {
        res = true;
    } else {
        cout << "The value provided {" << isLineOnly << "} is not a valid input." << endl;
        exit(0);
    }

    return res;

}

// Provides main() using Catch2.hpp
int main(int argv, char** argc) {

    bool isLineOnly = checkInput(argv, argc);
    string fileToRead = s(argc[2]);

    ifstream fin(fileToRead);

    if (!fin) {
        cout << "Error reading input file." << endl;
        exit(0);
    }

    ofstream fout("report.txt");

    if (!fout) {
        cout << "Error creating report." << endl;
        exit(0);
    }

    vector<string> tokens;
    vector<pair<int, int>> linecols;

    // There are two tests:
    // 1 for processing
    // 1 for both processing and outputting 
    StopWatch processing_only; 
    StopWatch and_outputting; 

    bool linesRead = ReadLine(fin, tokens, linecols);
    processing_only.captureFinishTime(); 

    if (!linesRead) {
        cout << "File is not readable." << endl;
        exit(0);
    }

    cout << setw(25) << "Processing only: " << processing_only.reportFinishTime() << endl;

    if (isLineOnly) {
        return 0;
    }

    printTokens(fout, tokens, linecols);
    and_outputting.captureFinishTime();

    cout << setw(25) << "With output: " << and_outputting.reportFinishTime() << endl;
    cout << setw(25) << "Time difference: " << (and_outputting.reportFinishTime() - processing_only.reportFinishTime()) << endl;

    return 0; 
} 
