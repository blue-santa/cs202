/*
 * Customer.cpp
 * CS 202
 * March 27, 2020
 * Bryan Beus
 * Customer definition file
 */

#include <iostream>
#include <iomanip>
#include <string>

#include "complex.hpp"

using std::cout;
using std::endl;
using std::ostream;
using std::string;

Complex::Complex(double real, double imag = 0) 
    : real_(real), imag_(imag) 
{
}

std::ostream& operator<<(std::ostream& os, const Complex& complex) {
    os << complex.realPart();
    os << " + i ";
    os << complex.imagPart();
    return os;
}

// class Complex { 
    // public:
        // Complex();

    // private:

// }; 
