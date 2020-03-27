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
using std::setw;
using std::left;
using std::right;

Customer::Customer() { }

ostream& operator<< (ostream& os, const Customer& customer) {
    os << left << setw(35) << customer.firstName() << endl;;
    os << right << setw(35) << customer.lastName() << endl;;
    os << right << setw(30) << std::put_money(customer.bankBalance()) << endl;
    return os;
}

