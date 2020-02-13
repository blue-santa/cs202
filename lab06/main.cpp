/*
 * main.cpp
 * CS 202
 * February 11, 2020
 * Bryan Beus
 * Main file for lab 05
 */

#include <iostream>
#include <vector>
#include <fstream>

#include "names.hpp"

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::ifstream;
using std::vector;

void foo() {
    cout << "Hello" << endl;
}

void bar() {
    cout << "Nope" << endl;
}

int main(int argc, char** argv) { 

    bryan::foo();

    foo();
    
    return 0;
}


