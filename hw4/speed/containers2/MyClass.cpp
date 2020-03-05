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

MyClass::MyClass() {};

void MyClass::addData(const string& myStr) {
    int len = (int)_mydata.size();
    _mydata[len] = myStr;
}

string MyClass::getLast() {
    int len = (int)_mydata.size();

    return _mydata[len - 1];
}

int MyClass::searchData(const string& myStr) {
    int i = 0;
    int len = (int)_mydata.size();
    while (i < len) {

        cout << _mydata[i] << endl;

        if (_mydata[i] == myStr) {

            cout << "Found it" << endl;
            return i;

        }
        i++;

    }

    return -1;

}

