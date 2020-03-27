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

int main() {

    cout.imbue(std::locale("en_US.UTF-8"));
    cout << std::showbase;

    const Customer customer;

    cout << customer << endl; 

    return 0;
}
