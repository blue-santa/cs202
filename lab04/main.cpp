/*
 * main.cpp
 * CS 202
 * February 3, 2020
 * Bryan Beus
 * Main file for lab 02
 */

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <stdexcept>
#include <stdio.h>
#include <stdlib.h>
#include <memory>
#include <fstream>
#include <sstream>
#include <iterator>

#include "header.hpp"

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::getline;
using std::left;
using std::right;
using std::size_t;
using std::stod;
using std::cerr;
using std::stringstream;
using std::distance;
using std::istream_iterator;
using std::setw;
using std::istringstream;
using std::ofstream;
using std::ifstream;
using std::istringstream;

// Test whether the user's input is a valid response
bool testUserInput(string &userInput) {

    // Assume user input is valid
    bool res = true;

    // Use a istringstream to convert user input to an integer within the appropriate range
    int testVal;
    istringstream iss (userInput);
    iss >> testVal;

    // If the string is not a valid reponse, return false
    if (iss.fail())
        res = false;

    // If the user entered an integer that cannot be converted to a proper integer, end the program
    if (testVal > 10000 || testVal < 0)
        res = false;

    // Return the result
    return res;
}

unsigned int countWords(string const& str) {
    stringstream ss(str);
    return distance(istream_iterator<string>(ss), istream_iterator<string>());
}

int main(int argc, char** argv) { 

    ofstream ofs;

    ofs.open("the-wanderer.txt", std::ofstream::app);

    if (!ofs) {
        cout << "No file" << endl;
        return 0;
    }

    if (ofs.eof()) {
        cout << "No file" << endl;
        return 0;
    }

    cout << "Please enter a number: ";

    string userInput;
    getline(cin, userInput);

    int numLines;

    bool res = testUserInput(userInput);
    if (res) {
        istringstream iss (userInput); 

        iss >> numLines;

    }

    cout << "Please enter a line of test: " << endl;
    getline(cin, userInput);

    for (int i = 0; i < numLines; i++) { 
        ofs << userInput << '\n';
    }

    ofs.close();

    ifstream fin("the-wanderer.txt");

    if (!fin) {
        cout << "No file opened" << endl;
        return 0;
    }

    if (fin.eof()) {
        cout << "End of file" << endl;
        return 0;
    }

    int line_count;
    int par_count;
    int word_count;
    int char_count;

    while (fin) {
        string s;
        getline(fin, s);
        line_count++;
        word_count += (int)(countWords(s));
        char_count += (int)(s.length());
        if (s == "") {
            par_count++;
        }
        cout << s << endl;
    }

    cout << setw(12) << right << "Paragraphs";
    cout << setw(12) << right << "Lines";
    cout << setw(12) << right << "Words";
    cout << setw(12) << right << "Characters" << endl;

    cout << setw(12) << right << par_count;
    cout << setw(12) << right << line_count;
    cout << setw(12) << right << word_count;
    cout << setw(12) << right << char_count << endl;


    return 0;
} 
