/*
 * MyClass.cpp
 * CS 202
 * March 27, 2020
 * Bryan Beus
 * MyClass definition file
 */

#include <iostream>
#include <iomanip>
#include <string>

#include "MyClass.hpp"

using std::cout;
using std::endl;
using std::ostream;
using std::string;
using std::setw;
using std::left;
using std::right;

MyClass::MyClass() { }

void MyClass::setMyData(const int& newData) {
    myData_ = newData;
}

MyClass& MyClass::operator=(const MyClass& other) {

    myData_ = other.myData();

    return *this;
}

ostream& operator<< (ostream& os, const MyClass& myClass) {
    os << left << setw(15) << "My Data: " << right << setw(15) <<  myClass.myData() << endl;
    return os;
}

