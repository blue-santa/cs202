/*
 * source_file.cpp
 * CS 202
 * February 11, 2019
 * Bryan Beus
 * Definition file
 */

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

#include "header.hpp"
#include "Catch.hpp"

using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::getline;
using std::istringstream;
using std::setw;
using std::left;

Vector3f::Vector3f(): 
    x(0), y(0), z(0) {}; 

Vector3f::Vector3f(const float userX, const float userY, const float userZ): 
    x(userX), y(userY), z(userZ) {}; 

Vector3f::Vector3f(const Vector3f& originalVector): 
    x(originalVector.x), y(originalVector.y), z(originalVector.z) {}; 

Vector3f Vector3f::add(const Vector3f& b) { 
    Vector3f newVec(x + b.x, y + b.y, z + b.z); 
    return newVec; 
} 

Vector3f Vector3f::sub(const Vector3f& b) { 
    Vector3f newVec(x - b.x, y - b.y, z - b.z); 
    return newVec; 
} 

Vector3f Vector3f::scale(const float c) { 
    Vector3f newVec(x * c, y * c, z * c); 
    return newVec; 
} 

Vector3f Vector3f::negate() { 
    Vector3f newVec(-x, -y, -z); 
    return newVec; 
} 

float Vector3f::dot(const Vector3f& b) { 
    float res(x * b.x + y * b.y + z * b.z); 
    return res; 
} 

Vector3f Vector3f::cross(const Vector3f& b) { 
    Vector3f newVec(y * b.z - z * b.y, z * b.x - x * b.z, x * b.y - y * b.x); 
    return newVec; 
} 

double Vector3f::length() { 
    double res = sqrt(x * x + y * y + z * z); 
    return res; 
} 

Vector3f Vector3f::unit() { 
    Vector3f newVec(this->scale(1.0f / this->length())); 
    return newVec; 
} 

bool operator==(const Vector3f& a, const Vector3f& b) { 
    return (a.x == b.x) && (a.y == b.y) && (a.z == b.z); 
} 

bool operator!=(const Vector3f& a, const Vector3f& b) { 
    return (a.x != b.x) && (a.y != b.y) && (a.z != b.z); 
} 


