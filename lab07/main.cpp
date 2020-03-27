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

    Customer customer2;
    customer2.setFirstName("Albert");
    customer2.setLastName("Einstein");
    customer2.setBankBalance(200.0);

    cout << customer2 << endl;

    Customer customer3;
    customer3 = customer2;

    cout << customer3 << endl;

    return 0;
}
