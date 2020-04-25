/*
 * main.cpp
 * CS202 Dr. Metzgar
 * Bryan Beus
 * April 24, 2020
 * Main file for lab14
 */

#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <cmath>
#include <sstream>
#include <fstream>

#include "Miscellaneous.hpp"

using std::cout;
using std::endl;
using std::string;
using std::ostream;
using std::sqrt;

// [x] Write a function template "twice"
// [x] Test it with an int and a double
// [x] Test it with a C++ string
// [x] Fix it to work with a C string
// [x] Write a TVector3 class that uses template functions for dot and cross
// [ ] Write length and normalize, functions for TVector3 class
// [ ] Write dot and cross functions for TVector3 class


template <typename T>
T twice(const T& x) {
    return x + x;
}

string twice(const char* x) {
    return twice(string(x));
}

template <typename T>
class TVector3 {
    public:
        T x{};
        T y{};
        T z{};

        TVector3() {}
        TVector3(T x, T y, T z): x(x), y(y), z(z) {}

        TVector3& operator*=(T s) {
            x *= s;
            y *= s;
            z *= s;
            return *this;
        }
};

template <typename T>
ostream& operator<<(ostream& os, const TVector3<T>& v) {
    os << "(" << v.x << ", " << v.y << ", " << v.z << ")";
    return os;
}

template <typename T>
T length(TVector3<T> v) {
    return sqrt(v.x*v.x + v.y*v.y + v.z*v.z);
}

template <typename T>
TVector3<T> normalize(TVector3<T> v) {
    T l = 1 / length(v);
    TVector3<T> result = v;
    v *= 1 / l;
    return v;
}

template <typename T, typename U>
auto dot(TVector3<T> a, TVector3<U> b) {
    return a.x*b.x + a.y * b.y + a.z * b.z;
}

template <typename T, typename U>
auto cross(TVector3<T> a, TVector3<U> b) {
    return TVector3<decltype(a.x*b.x)>{
        a.y * b.z - a.z * b.y,
        a.z * b.x - a.x * b.z,
        a.x * b.y - a.y * b.x
    };
}

int main()
{
    clearConsole();

    cout << twice(2) << endl;
    cout << twice(2.3) << endl;
    cout << twice(string("Hello")) << endl;
    cout << twice("Hello") << endl;

    TVector3<float> v1 { 1, 2, 3 };
    auto v2 = normalize(v1);
    cout << v1 << endl;
    cout << "length(v1)    = " << length(v1) << endl;
    cout << "normalize(v1) = " << normalize(v1) << endl;
    cout << "length(v2)    = " << normalize(v2) << endl;


    TVector3<double> up(0, 1, 0);
    TVector3<double> right(1, 0, 0);
    cout << "dot(up, right) = " << dot(up, right) << endl; 
    cout << "cross(up, right) = " << cross(up, right) << endl;
    cout << "cross(right, up) = " << cross(right, up) << endl;
    double angle1 = dot(right, v2) * 180.0 / 3.14159;

    cout << "angle between right and v2 = " << angle1 << endl;

    return 0;
}

