#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>

#include "MyClass.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ofstream;
using std::ifstream;

int main() {

    // Create data to store
    string mydata = "my data";

    // Create new instance of class

    MyClass a;

    // Add data to class
    a.addData(mydata);

    // Create filename
    string filename = "myfile.txt";

    // Class object stores data
    a.saveData(filename);

    // Create new instance of class
    MyClass b;

    // New instance loads saved data
    b.loadData(filename);

    // New instance prints data
    b.printData();

    return 0;

}
