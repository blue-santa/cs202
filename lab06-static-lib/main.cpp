/*
 * main.cpp
 * CS 202
 * February 27, 2020
 * Bryan Beus
 * Main file
 */

#include <iostream>
#include <vector>
#include <fstream>

#include "LabStaticLibrary.hpp"

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::ifstream;
using std::vector;

int main(int argc, char** argv) { 

    MyClass a;

    cout << a.returnX() << endl;
    a.updateX(2);
    cout << a.returnX() << endl;

    return 0;
}


