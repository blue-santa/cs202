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

// MyClass class default constructor
MyClass::MyClass() {};

// Set data in the unique_ptr
void MyClass::setData(const string& myStr) {
    _myptr = make_unique<string>(myStr);
}

// Get data from the unique_ptr
string MyClass::getData() {
    return *_myptr;
}
