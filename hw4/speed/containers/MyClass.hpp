/*
 * MyClass.hpp
 * CS 202
 * March 3, 2020
 * Bryan Beus
 * Header file for MyClass class
 */

#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::map;

#ifndef __MYCLASS_HPP_
#define __MYCLASS_HPP_

// MyClass class
class MyClass {
    private:
        // Member data
        map<int, string> _mydata;
    public:
        // Default constructor
        MyClass();

        // Add data to default map variable
        void addData(const string& s);

        // Retrieve data from the indicated position
        string getData(const int& pos);
        
        // Find string data (second member variable)
        int findData(const string& s);
}; 

#endif 
