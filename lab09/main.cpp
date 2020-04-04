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

#include "myclass.hpp"

using std::cout;
using std::endl;
using std::ostream;
using std::string;
using std::fixed;

// [x] Static local variable
// [x] Static global variable
// [ ] Static member variable
// [ ] Static member function

static int test_static_count = 0;

class TestStatic {
    public:
        TestStatic() :
            instanceNum_(test_static_count) {
            cout << __FUNCTION__ << " " << instanceNum_ << " initialized" << endl;
            test_static_count++;
        }

        ~TestStatic() {
            cout << __FUNCTION__ << " " << instanceNum_ << " destroyed" << endl;
        }

    private:
        int instanceNum_;
};

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


}

int main() {

    cout << "Starting main" << endl;
    foo_static();
    foo_static();
    foo_static();
    cout << "Leaving main" << endl;

    return 0;
}
