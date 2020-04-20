/*
 * main.cpp
 * CS202 Dr. Metzgar
 * Bryan Beus
 * April 19, 2020
 * Main file for lab13
 */

#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <cmath>

#include "Miscellaneous.hpp"

using std::cout;
using std::endl;
using std::string;

// [x] Write wrapper template class
// [x] Get friend to work with operator<<

template <typename WrapType> 
class Wrapper {
    public:
        Wrapper(const WrapType& obj) : obj_(obj) {}
    private:
        WrapType obj_;

        template <typename T>
        friend std::ostream& operator<<(std::ostream& os, const Wrapper<T>& w);
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const Wrapper<T>& w) {
    os << w.obj_;
    return os;
}


// void swap(T& a, T& b) {
    // T t = a;
    // a = b;
    // b = t;
// }

// void swap(float a, float b) {
    // float t = a;
    // a = b;
    // b = t;
// }

// void foo() {
    // float a = 0.0f, b = 0.0f;
    // swap(a, b);

    // int x, y;
    // swap(x , y);
// }

// template <typename T>
// class TVector3 {
    // public:
        // T length();

    // private:
        // T x{};
        // T y{};
        // T z{};
        // template <typename U>
        // friend std::ostream& operator<<(std::ostream& os, TVector3<U> v);

// };

// template <typename T>
// T TVector3<T>::length() {
    // return std::sqrt(x*x + y*y + z*z);
// }

// template <typename T>
// std::ostream& operator<<(std::ostream& os, TVector3<T> v) {
    // os << v.x << " " << v.y << " " << v.z;
    // return os;
// }

int main()
{
    clearConsole();

    Wrapper<int> w{ 2 };
    Wrapper<std::string> s{"Hello, World"};

    cout << w << " " << s << endl;

    return 0;
}

