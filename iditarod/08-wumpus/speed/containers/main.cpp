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

#include "MyClass.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::map;

int main() {

    // Declare new object
    MyClass a;

    // Declare data to store
    string myData = "mydata";

    // Create default data
    a.addData(myData);

    // Retrieve data
    string myReturnedData = a.getData(0);

    // Print data here 
    for (auto s: myReturnedData) {
        cout << s;
    }
    cout << endl;

    // Find position
    int pos = a.findData(myData);
    cout << pos << endl;

    return 0;

}
