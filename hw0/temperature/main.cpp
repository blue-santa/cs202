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

int main(int argc, char** argv) { 

    // Inform user of the nature of the software 
    clearConsole(); 
    cout << "Welcome to the temperature conversion engine" << endl; 

    // Check for the appropriate number of command prompts
    string userInput = argv[1];
    int x;
    try {
        size_t pos;
        x = stoi(userInput, &pos);
        if (pos < userInput.size()) {
            cerr << "Trailing characters after number: " << userInput << endl;
            return 0;
        }
    } catch (std::invalid_argument const &ex) {
        cerr << "Invalid number: " << userInput << endl;
        return 0;
    } catch (std::out_of_range const &ex) {
        cerr << "Number out of range: " << userInput << endl;
        return 0;
    }

    if (x < -273) {
        cout << "Please provide a temperature value higher than absolute zero." << endl;
    }

    cout << "Works: " << x << endl;

    return 0;
}


