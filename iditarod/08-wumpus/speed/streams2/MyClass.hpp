#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::string;

#ifndef __MYCLASS_HPP__
#define __MYCLASS_HPP__

// MyClass class
class MyClass {

    private:
        string _mydata;

    public:

        // MyClass default constructor
        MyClass();

        // Add data to the MyClass member variable
        void addData(const string& myStr);

        // Save the data to a file
        void saveData(const string& filename);
        
        // Load data from a file
        void loadData(const string& filename);

        // Print member variable data
        void printData();

};

#endif
