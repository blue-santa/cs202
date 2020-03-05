/*
 * main.cpp
 * CS 202
 * March 3, 2020
 * Bryan Beus
 * Main file
 */

#include <string>
#include <iostream>
#include <iomanip>
#include <map>
#include <memory>

#include "MyClass.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::map;

int main() {

    MyClass a;

    string myData = "mydata";

    a.alterData(myData);

    string d = a.retrieveData();
    cout << d << endl;

    string otherData = "otherdata";

    a.alterData(otherData);
    string b = a.retrieveData();
    cout << b << endl;


    return 0;

}
