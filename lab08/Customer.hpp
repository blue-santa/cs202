/*
 * complex.hpp
 * CS 202
 * March 27, 2020
 * Bryan Beus
 * Complex declaration file
 */

#include <iostream>
#include <iomanip>
#include <string>

using std::cout;
using std::endl;
using std::ostream;
using std::string;

#ifndef __COMPLEX_HPP__
#define __COMPLEX_HPP__

class Complex { 
    public:
        Complex() {};
        Complex(double real, double imag = 0);

    private:

        double real_{0};
        double imag_{0};
};


#endif
