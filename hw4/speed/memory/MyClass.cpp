/*
 * MyClass.cpp
 * CS 202
 * March 3, 2020
 * Bryan Beus
 * Definition file for MyClass class
 */

#include <iostream>
#include <iomanip>
#include <map>
#include <iterator>
#include <memory>

#include "MyClass.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::map;
using std::unique_ptr;
using std::make_unique;

// MyClass class default constructor
MyClass::MyClass() {};

// Alter the unique_ptr data
void MyClass::alterData(const string& s) {
    myPtr = make_unique<string>(s);
}

// Retrieve the default data
string MyClass::retrieveData() {
    return *myPtr;
};

