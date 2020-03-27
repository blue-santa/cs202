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

#include "Class.hpp"

using std::cout;
using std::endl;

operator<< (ostream& cout, Foo& hello) {
    cout << my_data;
    return &cout;
}

int main() {

    Foo hello("Hello");

    cout << hello << endl;

    return 0;
}
