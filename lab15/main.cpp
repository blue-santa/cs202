/*
 * main.cpp
 * CS202 Dr. Metzgar
 * Bryan Beus
 * April 24, 2020
 * Main file for lab15
 */

#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <cmath>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <numeric>

#include <bit>
#include <bitset>
#include <cstdint>
#include <initializer_list>

#include "Miscellaneous.hpp"

using std::cout;
using std::endl;
using std::string;
using std::ostream;
using std::sqrt;

vector<int> copyBackwards(const vector<int>& my_vec) {
    size_t s = my_vec.size();
    vector<int> res(s + 10);
    std::copy_backward(my_vec.begin(), my_vec.end(), res.end());
    return res;
}

int main()
{
    clearConsole();

    vector<int> a;
    for (int i = 0; i < 100; i++) {
        a.push_back(i);
    }

    vector<int> b = copyBackwards(a);

    for (auto i: b) {
        cout << i << " ";
    }

    cout << endl;

    for (std::uint8_t i : { 0, 0b11111111, 0b00011100 }) {
        cout << "countl_zero(0b" << std::bitset<8>(i) << ") = "
            << std::countl_zero(i) << '\n';
    }


    return 0;
}

