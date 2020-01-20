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
#include <stdexcept>
#include <stdio.h>
#include <stdlib.h>

#include "Miscellaneous.hpp"

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::getline;
using std::left;
using std::size_t;
using std::stod;
using std::cerr;

// C++ Function to convert command line input from farenheit to celsius
double cpp_ftoc(const char* str) {

    // Initiate variables
    string userInput = str;
    double x;

    try {

        // Attempt to cast the value to the x double
        size_t pos;
        x = stod(userInput, &pos);

        // If the position of the end of the number is less than the total length of the user input, indicate that there are errors and end the program
        if (pos < userInput.size()) {
            cerr << "Trailing characters after number: " << userInput << endl;
            exit(EXIT_FAILURE);
        }

    // If there are any other issues with the attempt, end the program
    } catch (std::invalid_argument const &ex) {
        cerr << "Invalid number: " << userInput << endl;
        exit(EXIT_FAILURE);
    } catch (std::out_of_range const &ex) {
        cerr << "Number out of range: " << userInput << endl;
        exit(EXIT_FAILURE);
    }

    // Ensure that the farenheit value is valid scientifically
    if (x < -273) {
        cout << "Please provide a temperature value higher than absolute zero." << endl;
        exit(EXIT_FAILURE);
    }

    // Perform the conversion
    x = (x - 32.00) * 5/9;
    return x; 
}

double c_ctof(const char* str) {

    // Initiate variables
    string userInput = str;
    double x;

    // Attempt to cast the c string to the double x value
    // If the *end variable has a value other than a null character, there must be trailing characters
    try {
        char* end;
        x = strtod(str, &end);
        if (*end != '\0') {
            cerr << "Trailing characters after number: " << userInput << endl;
            exit(EXIT_FAILURE);
        }

    // End the program, if needed for any other reason
    } catch (std::invalid_argument const &ex) {
        cerr << "Invalid number: " << userInput << endl;
        exit(EXIT_FAILURE);
    } catch (std::out_of_range const &ex) {
        cerr << "Number out of range: " << userInput << endl;
        exit(EXIT_FAILURE);
    }

    // Test that the value is scientifically valid
    if (x < -273) {
        cout << "Please provide a temperature value higher than absolute zero." << endl;
        exit(EXIT_FAILURE);
    }

    // Perform the conversion
    x = (x - 32.00) * 5/9;
    return x; 
}

int main(int argc, char** argv) { 

    // Check for the appropriate number of command prompts
    if (argc < 3) {
        cout << "Please provide a farenheit temperature as a double" << endl;
        exit(EXIT_FAILURE);
    }

    // Inform user of the nature of the software 
    clearConsole(); 
    cout << "Welcome to the temperature conversion engine" << endl; 

    // Iniate values and make calls to functions
    double x = c_ctof(argv[1]);
    double y = cpp_ftoc(argv[1]);

    // Print results
    cout << "Using C Function: " << std::setprecision(8) << x << endl;
    cout << "Using CPP Function: " << std::setprecision(8) << y << endl;

    return 0;
}


