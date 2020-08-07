#include <memory>
#include <string>
#include <iomanip>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::make_unique;
using std::unique_ptr;
using std::move;

#ifndef __MYCLASS__
#define __MYCLASS__

class MyClass {
    private:
    public:
        unique_ptr<string> _myptr;

        // Default constructor
        MyClass();

        // Set data in the unique_ptr
        void setData(const string& myStr);

        // Get data from the default constructor
        string getData();
};

#endif
