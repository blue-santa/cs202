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
    _mydata.insert(make_pair(len, myStr));
}

string MyClass::getLast() {
    int len = (int)_mydata.size();

    return _mydata[len - 1];
}

int MyClass::searchData(const string& myStr) {
    auto it = _mydata.begin();

    while (it != _mydata.end()) {

        if (it->second == myStr) {

            cout << "Found it" << endl;
            return it->first;

        }

        it++;

    }

    return -1;

}

