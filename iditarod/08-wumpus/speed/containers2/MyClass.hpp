#include <map>
#include <iterator>
#include <iostream>
#include <iomanip>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::map;
using std::string;

#ifndef __MYCLASS__
#define _MYCLASS__

// MyClass class
class MyClass {

    private:

        map<int, string> _mydata;

    public:

        // Default constructor for MyClass
        MyClass();

        // Add data to MyClass map
        void addData(const string& myStr);

        // Get the last addition to the map
        string getLast();

        // Search data for the provided string
        int searchData(const string& myStr);

};

#endif
