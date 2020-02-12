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
        int x, y, z;

        Vector3f() {};
        Vector3f(const int userX, const int userY, const int userZ):
            x(userX), y(userY), z(userZ) {};
        Vector3f(const Vector3f& originalVector);

        Vector3f add(const Vector3f& b) {
            Vector3f newVec(x + b.x, y + b.y, z + b.z);
            return newVec;
        }

        Vector3f sub(const Vector3f& b) {
            Vector3f newVec(x - b.x, y - b.zy, z - b.z);
            return newVec;
        }

        // Scale times %
        float scale(const Vector3f& c) {
            float fl;
            return fl;
        }

        Vector3f negate() {
            Vector3f newVec(-x, -y -z);
            return newVec;
        }

        int dot(const Vector3f& b) {
            int res(x * b.x + y * b.y + z * b.z);
            return res;
        }
 
        Vector3f cross(const Vector3f& b) {
            Vector3f res(y * b.z - z * b.y, z * b.x - x * b.z, x * b.y - y * b.x);
            return res;
        }

        double length() {
            double res = sqrt(x * x + y * y + z * z);
        }

        void unit() {
            this.scale(1.0f / this.length());
        }

};

bool operator==(const Vector3f& a, const Vector3f& b) {
    return (a.x == b.x) && (a.y == b.y) && (a.z == b.z);
}

bool operator!=(const Vector3f& a, const Vector3f& b) {
    return (a.x != b.x) && (a.y != b.y) && (a.z != b.z);
}



#endif

