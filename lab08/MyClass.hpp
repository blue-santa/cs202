/*
 * MyClass.hpp
 * CS 202
 * March 27, 2020
 * Bryan Beus
 * MyClass declaration file
 */

#include <iostream>
#include <iomanip>
#include <string>

using std::cout;
using std::endl;
using std::ostream;
using std::string;

#ifndef __MYCLASS_HPP__
#define __MYCLASS_HPP__

class MyClass { 
    public:
        MyClass();
        MyClass& operator=(const MyClass& other);
        
        const int& myData() const { return myData_; }; 

        void setMyData(const int& newData); 

    private:
        int myData_ = 1;

};

ostream& operator<< (ostream& os, const MyClass& myClass); 

#endif
