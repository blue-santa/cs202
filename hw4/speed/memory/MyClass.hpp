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

class MyClass {
    private:
        map<int, string> _mydata;
    public:
        MyClass();
        void addData(const string& s);
        string getData(const int& pos);
        int findData(const string& s);
}; 

#endif 
