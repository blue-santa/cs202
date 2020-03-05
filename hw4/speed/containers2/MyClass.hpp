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

class MyClass {

    private:

        map<int, string> _mydata;

    public:

        MyClass();

        void addData(const string& myStr);

        string getLast();

        int searchData(const string& myStr);

};

#endif
