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

#include "Customer.hpp"

using std::cout;
using std::endl;
using std::ostream;
using std::string;

ostream& operator<< (ostream& os, const Customer& customer);

int main() {

    const Customer customer;

    cout << customer << endl; 

    return 0;
}
