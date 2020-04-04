/*
 * main.cpp
 * CS 202
 * April 3, 2020
 * Bryan Beus
 * Main file for project
 */
#include <iostream>
#include <iomanip>
#include <string>

#include "myclass.hpp"

using std::cout;
using std::endl;
using std::ostream;
using std::string;
using std::fixed;

// [x] Static local variable
// [ ] Static global variable
// [ ] Static member variable
// [ ] Static member function

void foo_static() {
    static int countInitialized = 0;
    if (!countInitialized) {
        cout << __FUNCTION__ << " is not initialized" << endl;;
        countInitialized++;
    } else {
        cout << __FUNCTION__ << " called " << countInitialized << " times." << endl; 
        countInitialized++;
    }


}

int main() {

    foo_static();
    foo_static();
    foo_static();

    return 0;
}
