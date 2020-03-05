#include <memory>
#include <string>
#include <iomanip>
#include <iostream>

#include "MyClass.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::make_unique;
using std::unique_ptr;
using std::move;

MyClass::MyClass() {};

void MyClass::setData(const string& myStr) {
    _myptr = make_unique<string>(myStr);
}

string MyClass::getData() {
    return *_myptr;
}
