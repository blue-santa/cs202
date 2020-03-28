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
#include "MyClass.hpp"

using std::cout;
using std::endl;
using std::ostream;
using std::string;

int main() {

    // Set Money Print Standards
    cout.imbue(std::locale("en_US.UTF-8"));
    cout << std::showbase; 

    // Initial Customer printout
    const Customer customer; 
    cout << customer << endl; 

    // Updated Customer printout
    Customer customer2;
    customer2.setFirstName("Albert"); 
    customer2.setLastName("Einstein"); 
    customer2.setBankBalance(200.0); 
    cout << customer2 << endl;

    // Using the equal (=) operator with printout
    Customer customer3;
    customer3 = customer2; 
    cout << customer3 << endl;

    // MyClass Basic
    MyClass newInstance; 
    cout << newInstance << endl;

    // MyClass with setter
    MyClass newInstance2;
    newInstance2.setMyData(10); 
    cout << newInstance2 << endl;

    // MyClass with equal operator
    MyClass newInstance3;
    newInstance3 = newInstance2; 
    cout << newInstance3 << endl; 

    return 0;
}
