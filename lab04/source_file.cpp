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

int MyClass::getX() const {
    return _x;
}

int MyClass::getY() const {
    return _y;
}

void MyClass::setX(int newX) {
    _x = newX;
}

void MyClass::setY(int newY) {
    _y = newY;
}

MyClass::~MyClass() {
    cout << "destructed" << endl;

};

void passByValue(MyClass obj) {

    cout << "passByValue: " <<  obj.getX() << " " << obj.getY() << endl;
}

void passByReference(MyClass &obj) {

    obj.setX(42);
    obj.setY(53);

    cout << "passByReference: " <<  obj.getX() << " " << obj.getY() << endl;

}

void passByRefToConst(const MyClass &obj) {

    cout << "passByValue: " <<  obj.getX() << " " << obj.getY() << endl; 

}

MyClass returnNewObj() { 
    MyClass obj;
    return obj; 
}

vector<MyClass> myVec() {

    MyClass obj;

    vector<MyClass> myVec (5, obj);

    return myVec;

}


