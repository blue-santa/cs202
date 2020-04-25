/*
 * main.cpp
 * CS202 Dr. Metzgar
 * Bryan Beus
 * April 24, 2020
 * Main file for lab14
 */

#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <cmath>

#include "Miscellaneous.hpp"

using std::cout;
using std::endl;
using std::string;

// [ ] Write a function template "twice"
// [ ] Test it with an int and a double
// [ ] Test it with a C++ string
// [ ] Fix it to work with a C string


template <typename T>
T twice(const T& x) {
    return x + x;
}


int main()
{
    clearConsole();



    return 0;
}

