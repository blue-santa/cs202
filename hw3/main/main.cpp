/*
 * main.cpp
 * CS 202
 * February 14, 2020
 * Bryan Beus
 * Main file for main project
 */

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

int main(int argv, char** argc) {

    // Check user has input the correct number of arguments
    if (argv < 2 || argv > 3) {
        cout << "Input error" << endl;
        exit(0);
    }

    // Discover whether user desires to skip the report creation
    bool isLineOnly = getLineInput(argv, argc);

    // Declare file to read
    string fileToRead(argc[1]); 
    ifstream fin(fileToRead);

    // Check that the file is valid
    if (!fin) {
        cout << "Error reading input file." << endl;
        exit(0);
    }

    // Create a report file name
    // Be sure to not overwrite an existing report if the user indicated --line-only
    string outputname; 
    if (!isLineOnly) {
        outputname = "report.txt";
    } else {
        outputname = "temporary_report_file.txt";
    }

    // Create an output stream for the report
    ofstream fout(outputname);

    if (!fout) {
        cout << "Error creating report." << endl;
        exit(0);
    }

    // Initiate variables
    vector<string> tokens;
    vector<pair<int, int>> linecols;
    linecols.push_back(make_pair(1, 1));

    // There are two tests:
    // 1 for processing
    // 1 for both processing and outputting 
    // (The second test must start, but if the user has indicated
    // --line-only, it will be ignored later)
    StopWatch processing_only; 
    StopWatch and_outputting; 

    // Read the lines from the file
    bool linesRead = ReadLine(fin, tokens, linecols);

    // Stop the first StopWatch
    processing_only.captureFinishTime(); 

    if (!linesRead) {
        cout << "File is not readable." << endl;
        exit(0);
    }

    // If the user has not indicated --line-only, create the report
    if (!isLineOnly) {
        PrintTokens(fout, tokens, linecols);
    }

    // Stop the second StopWatch
    and_outputting.captureFinishTime();

    fin.close();

    // Discover input file size
    ifstream f_size(fileToRead, std::ifstream::ate | std::ifstream::binary);
    int byte_size = (int)(f_size.tellg()); 
    float MB_size = (float)(byte_size) / (float)1048576;

    // Discover speed of processing for first StopWatch
    float MB_sec_process_only = (float)MB_size / (float)(processing_only.reportFinishTime());


    // Print information to console
    cout << setw(25) << "File size is: " << MB_size << " Mbs." << endl;
    cout << setw(25) << "Processing only time: " << processing_only.reportFinishTime() << endl;
    cout << setw(25) << "Speed is: " << MB_sec_process_only << " Mbs/sec." << endl;

    if (!isLineOnly) { float MB_sec_with_proc = (float)MB_size / (float)(and_outputting.reportFinishTime()); cout << endl;
        cout << setw(25) << "With report output time: " << and_outputting.reportFinishTime() << endl;
        cout << setw(25) << "Time difference: " << (and_outputting.reportFinishTime() - processing_only.reportFinishTime()) << endl; 
        cout << setw(25) << "Speed is: " << MB_sec_with_proc << " Mbs/sec." << endl;
        cout << setw(25) << "Speed diff is: " << (MB_sec_process_only - MB_sec_with_proc) << " Mbs/sec." << endl;
    }

    // Delete the temporary report file, if needed
    if (isLineOnly) {
        remove("temporary_report_file.txt");
    }

    return 0; 
} 
