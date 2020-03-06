/*
 * main.cpp
 * CS 202
 * March 3, 2020
 * Bryan Beus
 * Main file
 */

#include <string>
#include <iostream>
#include <iomanip>
#include <map>
#include <memory>

#include "MyClass.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::map;

int main() {

    // Declare new MyClass instance
    MyClass a;

    // Add data
    string myData = "mydata"; 
    a.alterData(myData);

    // Retrieve data
    string d = a.retrieveData();
    cout << d << endl;

    // Test that data is loadable and alterable
    string otherData = "otherdata";

    a.alterData(otherData);
    string b = a.retrieveData();
    cout << b << endl;


    return 0;

}
