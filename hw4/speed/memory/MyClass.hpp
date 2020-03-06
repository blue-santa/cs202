/*
 * MyClass.hpp
 * CS 202
 * March 3, 2020
 * Bryan Beus
 * Header file for MyClass class
 */

#include <iostream>
#include <iomanip>
#include <memory>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::map;
using std::unique_ptr;
using std::make_unique;

#ifndef __MYCLASS_HPP_
#define __MYCLASS_HPP_

// MyClass class
class MyClass {
    public:
        unique_ptr<string> myPtr;

        // Default constructor
        MyClass();

        // Alter the unique_ptr
        void alterData(const string& mydata);

        // Retrieve stored data
        string retrieveData();
}; 

#endif 
