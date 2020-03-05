/*
 * main.cpp
 * CS 202
 * March 3, 2020
 * Bryan Beus
 * Main file
 */

#include "MyClass.hpp"

int main() {

    // Declare new object
    MyClass a;

    // Create default data
    a.createData();

    // Save default data to file
    a.saveData();

    // Declare new object
    MyClass b;

    // Load default data from object a
    b.loadData();

    // Report data
    b.printData();

    return 0;

}
