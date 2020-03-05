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

MyClass::MyClass() {};

void MyClass::addData(const string& myStr) {
    _mydata = myStr;
}

void MyClass::saveData(const string& filename) {
    ofstream fout(filename);

    if (!fout) {

        cout << "Error opening file" << endl;
        exit(0);

    }

    fout << _mydata << endl;

}

void MyClass::loadData(const string& filename) {
    ifstream fin(filename);

    if (!fin) {

        cout << "Error opening file" << endl;
        exit(0);

    }
    getline(fin, _mydata);
}

void MyClass::printData() {

    cout << _mydata << endl;
}

