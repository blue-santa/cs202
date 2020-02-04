/*
 * main.cpp
 * CS 202
 * February 3, 2020
 * Bryan Beus
 * Main file for lab 02
 */

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <stdexcept>
#include <stdio.h>
#include <stdlib.h>

#include "header.hpp"

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::getline;
using std::left;
using std::size_t;
using std::stod;
using std::cerr;

int main(int argc, char** argv) { 

    MyClass obj;

    cout << obj.getX() << " " << obj.getY() << endl;

    MyClass obj2(obj);

    cout << obj2.getX() << " " << obj.getY() << endl;

    MyClass obj3(10, 15);

    cout << obj3.getX() << " " << obj.getY() << endl;

    passByValue(obj3);
    passByReference(obj3);
    passByRefToConst(obj3);

    MyClass obj4 = returnNewObj();

    vector<MyClass> aVec = myVec();

    cout << "Vector: " << endl;

    for (auto i: aVec) {
        cout << i.getX() << " " << i.getY() << endl;
    }
    
    vector<MyClass> myVec(); 

    return 0;
}


