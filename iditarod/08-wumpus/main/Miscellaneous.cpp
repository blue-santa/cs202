/*
 * Miscellaneous.cpp
 * CS 202
 * March 3, 2020
 * Bryan Beus
 * Miscellaneous content definition file
 */

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

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
using std::random_device;
using std::seed_seq;
using std::mt19937;

// Clear the console
void clearConsole() {

    // Clear the console
    cout << "\033[2J\033[1;1H";
}

// Wait for user response
void waitForContinue() {
    cout << endl << "Press enter to continue...";
    getchar();
}

// Capture the user input
void capture_user_input(int& userInput) {

	// Assume user input is invalid until proven otherwise
	bool valid_input = false;

	// Initiate endless loop to wait for valid response
	while (!valid_input) {

		// Receive user input as a string
		string user_input_temp;
        cout << endl;
		cout << "Make a choice for the next room to visit (A, B, C).\nShoot an arrow by entering (S).\nEnter (Q) to quit.\nPrint an SVG of the current room by entering (P)." << endl;

		getline(cin, user_input_temp);

		// Test if the user input is valid, and convert to an integer
		valid_input = testUserInput(user_input_temp, userInput);

		// If invalid, replay the while loop
		if (!valid_input) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << endl;
			cout << "Please try again" << endl;
		} 

		// Add formatting
		cout << endl;
	}
}

// Test whether the user's integer input is a valid response
bool testUserInput(string& user_input_temp, int& userInput) {

    // Assume user input is valid
    bool res = true;

    // For simplicity, set user input to upper case
    for (auto & c: user_input_temp) {
        c = toupper(c);
    }

    if (user_input_temp == "A") {
        userInput = 0;
    } else if (user_input_temp == "B") {
        userInput = 1; 
    } else if (user_input_temp == "C") {
        userInput = 2; 
    } else if (user_input_temp == "S") {
        userInput = 3; 
    } else if (user_input_temp == "Q") {
        userInput = 4; 
    } else if (user_input_temp == "P") {
        userInput = 5; 
    } else {
        res = false; 
    }

    // Return the result
    return res;
}

// Choose a random room
int chooseRandomRoom(mt19937 *_e1, const int lower_limit, const int upper_limit) {

    // Uniform random distribution between provided lower and upper limits
    std::uniform_int_distribution<int> uniform_dist(lower_limit, upper_limit);

    // Set val variable to a random variable in the provided range, using *_e1 as the random device
	int val = uniform_dist(*_e1);

	return val;

}

