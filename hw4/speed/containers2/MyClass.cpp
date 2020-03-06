#include <iomanip>
#include <iostream>
#include <map>
#include <string>
#include <iterator>

#include "MyClass.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::map;
using std::string;
using std::make_pair;

// MyClass class
MyClass::MyClass() {};

// Add data to the default data store
void MyClass::addData(const string& myStr) {
    int len = (int)_mydata.size();
    _mydata.insert(make_pair(len, myStr));
}

// Get the most recent addition
string MyClass::getLast() {

    // Check that the map isn't empty
    int len = (int)_mydata.size();

    if (len < 1) { 
        cout << "Map is empty" << endl;
        exit(0); 
    }

    // Get last position
    auto it = _mydata.end();
    it--; 
    return it->second;
}

// Search the map for the provided string
int MyClass::searchData(const string& myStr) {
    auto it = _mydata.begin();

    while (it != _mydata.end()) {

        if (it->second == myStr) {

            cout << "found it" << endl;
            return it->first;

        }

    }

    // If it's not found, return -1
    return -1;
}

