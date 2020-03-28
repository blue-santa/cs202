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
#include "myclass.hpp"

using std::cout;
using std::endl;
using std::ostream;
using std::string;
using std::fixed;

// Design
// [x] Create Complex class
// [x] override << operator
// [x] override + operator
// [x] override += operator

// Design2
// [x] Create new class
// [x] override << operator
// [x] override - operator
// [x] override -= operator

int main() {

    cout << fixed;

    cout << Complex() << endl;
    cout << Complex(2, 3) << endl;
    cout << Complex(4, 5) + Complex(2, 3) << endl;
    cout << 1.0 + Complex(2, 3) << endl;
    cout << Complex(2, 3) + 1.0 << endl;

    Complex complex1(7, 8); 
    Complex complex2(10, 20); 
    cout << complex1 << endl;
    cout << complex2 << endl;
    complex1 += complex2;
    cout << complex1 << endl;

    // Lab
    cout << MyClass() << endl;
    cout << MyClass(2, 3) << endl;
    cout << MyClass(4, 5) - MyClass(2, 3) << endl;
    cout << 1.0 - MyClass(2, 3) << endl;
    cout << MyClass(2, 3) - 1.0f << endl;

    MyClass myclass1(7, 8); 
    MyClass myclass2(10, 20); 
    cout << myclass1 << endl;
    cout << myclass2 << endl;
    myclass1 -= myclass2;
    cout << myclass1 << endl;

    return 0;
}
