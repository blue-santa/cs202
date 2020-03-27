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

#include "Customer.hpp"

using std::cout;
using std::endl;
using std::ostream;
using std::string;

Customer::Customer() { }

void Customer::fetchData() {};

ostream& operator<< (ostream& os, const Customer& customer) {
    return os;
}

