/*
 * main.cpp
 * CS 202
 * April 3, 2020
 * Bryan Beus
 * Main file for project
 */
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

#include "myclass.hpp"

using std::cout;
using std::endl;
using std::ostream;
using std::string;
using std::fixed;
using std::ostringstream;

// [x] Static local variable
// [x] Static global variable
// [x] Static member variable
// [x] Static member function

// My Design
// [x] Static local variable
// [ ] Static member variable
// [ ] Static member function

static int test_static_count = 0;

static string my_static_string = "My Static String";

class TestStatic {
    public:
        TestStatic() :
            instanceNum_(test_static_count) {
            cout << __FUNCTION__ << " " << instanceNum_ << " initialized" << endl;
            test_static_count++;
            ostringstream os;
            os << "TestStatic" << instanceNum_;
            className_ = os.str();
        }

        ~TestStatic() {
            cout << __FUNCTION__ << " " << instanceNum_ << " destroyed" << endl;
        }

        void printClassName() {
            cout << className_ << endl;
        }

        static void writeClassName() {
            cout << "Static " << className_ << endl;
        }

        static void writeClassName(const TestStatic& ts) {
            cout << "Static instance: " << ts.instanceNum_ << endl;
        }
    private:
        int instanceNum_;
        static string className_;
};

string TestStatic::className_{ "test" };

namespace {

    TestStatic ts1;
    TestStatic ts2;
}

void foo_static() {
    static int countInitialized = 0;
    static TestStatic ts;
    if (!countInitialized) {
        cout << __FUNCTION__ << " is not initialized" << endl;;
        countInitialized++;
    } else {
        cout << __FUNCTION__ << " called " << countInitialized << " times." << endl; 
        countInitialized++;
    }

    ts1.printClassName();
    TestStatic::writeClassName(ts1);
    TestStatic::writeClassName(ts2);


}

int main() {

    cout << endl;
    cout << "Starting main" << endl;

    ts1.printClassName();
    ts2.printClassName();

    foo_static();
    foo_static();
    foo_static();

    ts1.printClassName();
    cout << "Leaving main" << endl;

    return 0;
}
