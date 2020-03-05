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

class MyClass {

    private:
        string _mydata;

    public:

        MyClass();

        void addData(const string& myStr);
        void saveData(const string& filename);
        void loadData(const string& filename);
        void printData();

};

#endif
