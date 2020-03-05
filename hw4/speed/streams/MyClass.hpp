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

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::istream;
using std::ofstream;
using std::istringstream;

#ifndef __MYCLASS_HPP_
#define __MYCLASS_HPP_

class MyClass {
    private:
        string _data;
    public:
        MyClass();
        void createData();
        void saveData();
        void loadData();
        void printData();
}; 

#endif 
