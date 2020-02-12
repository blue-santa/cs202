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
#include <memory>

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

    MyClass *obj = new MyClass;

    //delete obj;

    auto objPtr = std::make_unique<MyClass>(10, 20);
    cout << "objPtr: " << objPtr->getX() << " " << objPtr->getY() << endl;

    auto newPtr = std::move(objPtr); 
    // *objPtr = *obj;
    // cout << objPtr->getX() << endl;

    cout << "newPtr: " << newPtr->getX() << " " << newPtr->getY() << endl;
 
    auto nextPtr = std::make_shared<MyClass>(8,12);

    auto sharedPtr = nextPtr;

    cout << "sharedPtr: " << sharedPtr->getX() << " " << sharedPtr->getY() << endl;

    //

    auto anotherPtr = nextPtr;

    cout << "anotherPtr: " << anotherPtr->getX() << " " << anotherPtr->getY() << endl;

    return 0;
}


