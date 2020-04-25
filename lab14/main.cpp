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

// [x] Write a function template "twice"
// [x] Test it with an int and a double
// [x] Test it with a C++ string
// [x] Fix it to work with a C string
// [x] Write a TVector3 class that uses template functions for dot and cross
// [ ] Write dot, cross, normalize, and length functions for TVector3 class


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
};

template <typename T>
ostream& operator<<(ostream& os, TVector3<T>& v) {
    os << "(" << v.x << ", " << v.y << ", " << v.z << ")";
    return os;
}
int main()
{
    clearConsole();

    cout << twice(2) << endl;
    cout << twice(2.3) << endl;
    cout << twice(string("Hello")) << endl;
    cout << twice("Hello") << endl;

    TVector3<float> v1;
    cout << v1 << endl;

    return 0;
}

