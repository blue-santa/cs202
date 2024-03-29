/*
 * MyClass.cpp
 * CS 202
 * March 3, 2020
 * Bryan Beus
 * Definition file for MyClass class
 */

#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>

#include "MyClass.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::istream;
using std::ofstream;
using std::ifstream;
using std::istringstream;
using std::getline;

// MyClass class default constructor
MyClass::MyClass() { };

// Create data
void MyClass::createData() {
    _data = "My Data";
}

// Save data
void MyClass::saveData() {

    // Open filestream
    string myFile = "my_file.txt";
    ofstream fout (myFile);

    if (!fout) {
        cout << "Error creating file" << endl;
        exit(0);
    }

    // Add some random data
    for (int i = 0; i < 10; i++) {
        fout << i + 1 << " "; 
    }

    fout << endl;
    fout.close();
}

// Load data
void MyClass::loadData() {

    string myFile = "my_file.txt";
    ifstream fin(myFile);
    
    if (!fin) {
        cout << "Error reading in file" << endl;
        exit(0);
    }

    getline(fin, _data);

}

// Print data
void MyClass::printData() {
    cout << _data << endl;
}
