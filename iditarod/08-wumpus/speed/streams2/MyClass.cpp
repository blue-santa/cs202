#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>

#include "MyClass.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::string;

// MyClass default constructor
MyClass::MyClass() {};

// Add data to the member variable
void MyClass::addData(const string& myStr) {
    _mydata = myStr;
}

// Save the data to a file
void MyClass::saveData(const string& filename) {
    ofstream fout(filename);

    if (!fout) {

        cout << "Error opening file" << endl;
        exit(0);

    }

    fout << _mydata << endl;

}

// Load data from a file
void MyClass::loadData(const string& filename) {
    ifstream fin(filename);

    if (!fin) {

        cout << "Error opening file" << endl;
        exit(0);

    }
    getline(fin, _mydata);
}

// Print data
void MyClass::printData() {

    cout << _mydata << endl;
}

