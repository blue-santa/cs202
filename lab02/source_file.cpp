/*
 * source_file.cpp
 * CS 202
 * February 3, 2019
 * Bryan Beus
 * Definition file for MyClass
 */

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

#include "header.hpp"

using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::getline;
using std::istringstream;
using std::setw;
using std::left;

MyClass::MyClass() {
    _x = 1;
    _y = 2;
}

MyClass::MyClass(const MyClass &origPtr) {
    _x = origPtr._x;
    _y = origPtr._y;
}

MyClass::MyClass(const int &subX, const int &subY): 
    _x(subX), 
    _y(subY) 
{}

int MyClass::getX() {
    return _x;
}

int MyClass::getY() {
    return _y;
}

MyClass::~MyClass() {};
