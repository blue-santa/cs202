#include <map>
#include <iterator>
#include <iostream>
#include <iomanip>
#include <string>

#include "MyClass.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::map;
using std::string;

int main() {

    // Create new instance of class
    MyClass a;

    // Create new instance of data to store
    string mydata = "mydata";

    // Store data
    a.addData(mydata);

    // Retrieve data from class object and set to new variable
    string retrievedData = a.getLast();

    // Print this data to verify
    cout << retrievedData << endl;

    // Search within class for this data and print key
    int pos = a.searchData(retrievedData);

    // Print pos
    cout << pos << endl;

    return 0;
}
