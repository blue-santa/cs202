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

#include "MyClass.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::map;

// Default constructor
MyClass::MyClass() {};

// Add data to the _mydata map variable
void MyClass::addData(const string& s) {
    int len = (int)_mydata.size();
    _mydata.insert(make_pair(len, s));
}

// Retrieve data from the given position
string MyClass::getData(const int& pos) {
    auto it = _mydata.find(pos);
    if (it != _mydata.end()) {
        return it->second;
    } else {
        cout << "Not found" << endl;
        exit(0);
    }
};

// Find the provided data (second member variable)
int MyClass::findData(const string& s) {
    auto it = _mydata.begin();

    while (it != _mydata.end()) {
        if (it->second == s) {
            return it->first;
        }
    }

    return -1;
}
