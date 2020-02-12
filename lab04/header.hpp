/*
 * header.hpp
 * CS 202
 * February 3, 2019
 * Bryan Beus
 * Declaration file
 */

#ifndef HEAD_HPP
#define HEAD_HPP 

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::getline;
using std::istringstream;
using std::setw;
using std::left;

class MyClass {

    private:
        int _x, _y;

    public:
        MyClass();
        MyClass(const MyClass &origPtr);
        MyClass(const int &subX, const int &subY); 

        ~MyClass();
        int getX() const;
        int getY() const;

        void setX(int newX);
        void setY(int newY);

};

void passByValue(MyClass obj);
void passByReference(MyClass &obj);
void passByRefToConst(const MyClass &obj);

MyClass returnNewObj();

vector<MyClass> myVec();

#endif

