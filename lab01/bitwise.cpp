/*
 * bitwise.cpp
 * CS 201
 * December 02, 2019
 * Bryan Beus
 * Main file for lab36
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <iterator>
#include <utility>
#include <vector>
#include <string>
#include <map>

using std::vector;
using std::pair;
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::make_pair;
using std::for_each;
using std::getline;
using std::istringstream;
using std::ostringstream;
using std::to_string;
using std::find;
using std::map;
using std::setw;
using std::left;

void setX(int &x) {
    x = 8;
}

int main() { 

    int x = 0;

    cout << "if (x == 0) x = 1; else x = 2; " << endl;

    if (x == 0) {
        x = 1;
    } else {
        x = 2;
    }

    switch (x) {
        case 0:
            x = 3;
            break;
        case 1:
            x = 4;
            break;
        case 2:
            x = 5;
            break;
        default:
            x = 6;
            break; 
    }

    cout << "x after switch statement: " << x << endl;

    setX(x);

    cout << "x after function call setX()" << x << endl;

    while (x < 20) {
        x++;
        cout << "During while loop, x: " << x << endl;
    }

    for (int i = 0; i < 35; i++) {
        x++;
        cout << "During for loop, x: " << x << endl;
    }

	return 0;

}

