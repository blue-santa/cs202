/*
 * myclass.hpp
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
        MyClass() {};
        MyClass(float data1, float data2 = 0);

        float firstData() const { return first_; };
        float secondData() const { return second_; };

        void setFirst(float data);
        void setSecond(float data);

        MyClass operator-(const MyClass myclass);
        MyClass& operator-=(const MyClass myclass);

    private:
        float first_ {1.1f};
        float second_ {3.5f};


};

inline MyClass operator-(float lhs, const MyClass rhs) {
    return MyClass(lhs - rhs.firstData(), rhs.secondData());
}

ostream& operator<<(ostream& os, const MyClass& myclass);

#endif
