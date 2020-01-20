/*
 * main.cpp
 * CS 201
 * December 6, 2019
 * Bryan Beus
 * Main file for themostat main project in hw8
 */

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cstdlib>
#include <stdexcept>
#include <stdio.h>
#include <stdlib.h>

// #include "Environment.hpp"
// #include "Agent.hpp"
// #include "Simulator.hpp"
#include "Miscellaneous.hpp"

using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::getline;
using std::istringstream;
using std::setw;
using std::left;
using std::size_t;
using std::atoi;
using std::stoi;
using std::cerr;

double cpp_ftoc(const char* str) {
    // Check for the appropriate number of command prompts
    string userInput = str;
    double x;
    try {
        char* end;
        x = strtod(str, &end);
        if (*end != '\0') {
            cerr << "Trailing characters after number: " << userInput << endl;
            exit(EXIT_FAILURE);
        }
    } catch (std::invalid_argument const &ex) {
        cerr << "Invalid number: " << userInput << endl;
        exit(EXIT_FAILURE);
    } catch (std::out_of_range const &ex) {
        cerr << "Number out of range: " << userInput << endl;
        exit(EXIT_FAILURE);
    }

    if (x < -273) {
        cout << "Please provide a temperature value higher than absolute zero." << endl;
        exit(EXIT_FAILURE);
    }

    x = (x - 32.00) * 5/9;
    return x; 
}

double c_ctof(const char* str) {
    // Check for the appropriate number of command prompts
    string userInput = str;
    double x;
    try {
        char* end;
        x = strtod(str, &end);
        if (*end != '\0') {
            cerr << "Trailing characters after number: " << userInput << endl;
            exit(EXIT_FAILURE);
        }
    } catch (std::invalid_argument const &ex) {
        cerr << "Invalid number: " << userInput << endl;
        exit(EXIT_FAILURE);
    } catch (std::out_of_range const &ex) {
        cerr << "Number out of range: " << userInput << endl;
        exit(EXIT_FAILURE);
    }

    if (x < -273) {
        cout << "Please provide a temperature value higher than absolute zero." << endl;
        exit(EXIT_FAILURE);
    }

    x = (x - 32.00) * 5/9;
    return x; 
}

int main(int argc, char** argv) { 

    // Inform user of the nature of the software 
    clearConsole(); 
    cout << "Welcome to the temperature conversion engine" << endl; 

    double x = c_ctof(argv[1]);

    cout << "Works: " << std::setprecision(4) << x << endl;

    return 0;
}


