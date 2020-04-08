/*
 * main.cpp
 * CS202
 * April 7, 2020
 * Bryan Beus
 * Rainy Pass station for Iditarod Challenge
 */

#include <iomanip>
#include <vector>
#include <string>
#include <iostream>

#include "StopWatch.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

long long int ack(const long long int& m, const long long int& n) {
    if (m == 0) {
        return n + 1;
    } else if (m > 0 && n == 0) {
        return ack(m - 1, 1);
    } else if (m > 0 && n > 0) { 
        return ack(m - 1, ack(m, n - 1));
    } else {
        return 0;
    } 
}

int main() {

    StopWatch sw;

    long long int m = 0;
    long long int n = 0;
    long long int val;

    val = ack(m, n);

    cout << endl;
    cout << val << endl;

    sw.captureFinishTime();
    cout << sw.reportFinishTime() << endl;

    cout << endl;

    return 0;
}

