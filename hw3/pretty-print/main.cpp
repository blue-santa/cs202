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
#include <fstream>
#include <utility>
#include <bits/stdc++.h>
#include <stdio.h>

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
using std::ifstream;
using std::ofstream;
using std::make_pair;

// Check whether the user has indicated to only do the processing and not the report
void getLineInput(int &argv, char** argc, bool &isHtml, int &wrapCount) {

    string tempStr(argc[2]); 

    istringstream is(tempStr);
    wrapCount = stoi(tempStr);

    if (tempStr == "--html") {
        isHtml = true;
    } else if (wrapCount != 0 && wrapCount < 30) {
        cout << "Wrap count should be at least 30 columns." << endl;
        exit(0);
    } else if (wrapCount != 0) {
        isHtml = false;
    } else { 
        cout << "The value provided {" << isHtml << "} is not a valid input." << endl;
        exit(0);
    }

}

int main(int argv, char** argc) {

    // Check user has input the correct number of arguments
    if (argv != 3) {
        cout << "Input error" << endl;
        exit(0);
    }

    int wrapCount = 0;
    bool isHtml;

    // Discover whether user desires to skip the report creation
    getLineInput(argv, argc, isHtml, wrapCount);

    // Declare file to read
    string fileToRead(argc[1]); 
    ifstream fin(fileToRead);

    // Check that the file is valid
    if (!fin) {
        cout << "Error reading input file." << endl;
        exit(0);
    }

    // Initiate variables
    vector<string> tokens;
    vector<pair<int, int>> linecols;
    linecols.push_back(make_pair(1, 1));

    // Read the lines from the file
    bool linesRead = ReadLine(fin, tokens, linecols);

    if (!linesRead) {
        cout << "File is not readable." << endl;
        exit(0);
    }

    fin.close();

    // Create new ostream 
    string prettyFilename = "pretty-print.txt"; 
    ofstream fout;
    fout.open(prettyFilename);

    if (!(fout.is_open())) {
        cout << "Error creating pretty output file" << endl;
        exit(0);
    } 

    // Pretty print the files
    PrettyPrint(fout, tokens, isHtml, wrapCount);

    fout.close(); 

    return 0; 
} 
