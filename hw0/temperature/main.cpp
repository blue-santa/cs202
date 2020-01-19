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

#include "Environment.hpp"
#include "Agent.hpp"
#include "Simulator.hpp"
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
    try {
        size_t pos;
        int x = stoi(userInput, &pos);
        if (pos < arg.size()) {
            cerr << "Trailing characters after number: " << userInput << endl;
        }
        return 0;
    } catch (std::invalid_argument const &ex) {
        cerr << "Invalid number: " << userInput << endl;
        return 0;
    } catch (std::out_of_range const &ex) {
        cerr << "Number out of range: " << userInput << endl;
        return 0;
    }

    cout << "Works" << endl;

    return 0;

    // Clear screen and print introduction to console
    clearConsole();
    cout << "Environment created" << endl;
    waitForContinue();

    // Initiate while loop 
    while (!isFinished) { 

        // Clear screen
        clearConsole();

        // Affect the environment
        env.iteration();

        // The agent performs its duties 
        agt.perceive(env);
        agt.think(calibrated);
        agt.act(env);

        // If iteration is divisible by 10, Agent requests user input
        // Test whether user wants to quit 
        if (iter % 10 == 0) {
            sim.askOwner(isFinished, agt, env);
        }

        if (isFinished)
            break;

        // Increase iteration count
        iter++;
    } 

    return 0; 
}


