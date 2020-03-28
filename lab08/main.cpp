/*
 * main.cpp
 * CS 202
 * March 27, 2020
 * Bryan Beus
 * Main file for project
 */
#include <iostream>
#include <iomanip>
#include <string>

#include "complex.hpp"

using std::cout;
using std::endl;
using std::ostream;
using std::string;
using std::fixed;

// Desing
// [x] Create Complex class
// [ ] override << operator
// [ ] override + operator
// [ ] override += operator

int main() {

    cout << fixed;

    cout << Complex() << endl;
    cout << Complex(2, 3) << endl;
    // cout << 1 + Complex(2, 3) << endl;

    return 0;
}
