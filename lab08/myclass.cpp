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

#include "complex.hpp"
#include "myclass.hpp"

using std::cout;
using std::endl;
using std::ostream;
using std::string;
using std::left;
using std::right;
using std::setw;

MyClass::MyClass(float data1, float data2)
    : first_(data1), second_(data2) {};

void MyClass::setFirst(float data) {
    first_ = data;
}

void MyClass::setSecond(float data) {
    second_ = data;
}

ostream& operator<<(ostream& os, const MyClass& myclass) {
    os << left << setw(10) << "First: " << right << setw(10) << myclass.firstData() << endl;
    os << left << setw(10) << "Second: " << right << setw(10) << myclass.secondData() << endl;
    return os;
}

MyClass MyClass::operator-(const MyClass myclass) {
    return MyClass(first_ - myclass.firstData(), second_ - myclass.secondData());
}

MyClass& MyClass::operator-=(const MyClass myclass) {
    *this = *this - myclass;
    return *this;
}

