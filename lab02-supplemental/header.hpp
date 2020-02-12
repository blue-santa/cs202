/*
 * header.hpp
 * CS 202
 * February 11, 2019
 * Bryan Beus
 * Declaration file
 */

#ifndef HEAD_HPP
#define HEAD_HPP 

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <math.h>

using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::getline;
using std::istringstream;
using std::setw;
using std::left;

class Vector3f { 
    public:
        float x, y, z;

        Vector3f();
        Vector3f(const float userX, const float userY, const float userZ);
        Vector3f(const Vector3f& originalVector);

        Vector3f add(const Vector3f& b);

        Vector3f sub(const Vector3f& b);

        Vector3f scale(const float c);

        Vector3f negate();

        float dot(const Vector3f& b);
 
        Vector3f cross(const Vector3f& b);

        double length();

        Vector3f unit();

};

bool operator==(const Vector3f& a, const Vector3f& b);

bool operator!=(const Vector3f& a, const Vector3f& b);

#endif

