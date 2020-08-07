#include <memory>
#include <string>
#include <iomanip>
#include <iostream>

#include "MyClass.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::make_unique;
using std::unique_ptr;
using std::move;

int main() {

    // Declare class
    MyClass a;

    // Create data to store
    string mydata = "mydata";

    // Set internal data
    a.setData(mydata);

    // Create second data
    string otherdata;

    // Get internal data
    otherdata = a.getData();

    // Print internal data
    cout << otherdata << endl;

    return 0;
}
