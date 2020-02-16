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
#include <bits/stdc++.h>

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
using std::make_pair;

bool getLineInput(int &argv, char** argc) {

    bool res = false;

    if (argv < 3) {
        return res;
    }

    string isLineOnly(argc[2]);

    cout << endl;

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

    if (argv < 2) {
        cout << "Input error" << endl;
        exit(0);
    }

    bool isLineOnly = getLineInput(argv, argc);
    string fileToRead(argc[1]);

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
    linecols.push_back(make_pair(1, 1));

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

    PrintTokens(fout, tokens, linecols);
    and_outputting.captureFinishTime();

    fin.close();

    ifstream f_size(fileToRead, std::ifstream::ate | std::ifstream::binary);
    int byte_size = (int)(f_size.tellg());
    

    float MB_size = (float)(byte_size) / (float)1048576;
    float MB_sec_size = MB_size / (and_outputting.reportFinishTime() - processing_only.reportFinishTime());


    cout << setw(25) << "With output: " << and_outputting.reportFinishTime() << endl;
    cout << setw(25) << "Time difference: " << (and_outputting.reportFinishTime() - processing_only.reportFinishTime()) << endl;
    cout << setw(25) << "File size is: " << MB_size << " Mbs." << endl;
    cout << setw(25) << "Speed is: " << MB_sec_size << " Mbs/sec." << endl;

    return 0; 
} 
