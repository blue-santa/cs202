/*
 * main.cpp
 * CS 202
 * January 19, 2020
 * Bryan Beus
 * Main file for temperature main project in hw0
 */

// #define CATCH_CONFIG_MAIN

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <list>
#include <iterator>

#include "Miscellaneous.hpp"
#include "Value.hpp" 
#include "Catch.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
using std::list;

void reportValues(list<Value>& mylist) {

    list<Value>::iterator it = mylist.begin();

    for (unsigned int i = 0; i < mylist.size(); i++) {
        it->reportValue();
        it++;
    }

}

int main(int argc, char* argv[])
{

    vector<string> filenames;
    filenames.push_back("the-wanderer.txt");
    filenames.push_back("dream-of-the-rood.txt");
    filenames.push_back("solomon-and-saturn.txt");
    filenames.push_back("the-phoenix.txt");
    filenames.push_back("wulf-and-eadwacer.txt");
    filenames.push_back("the-menologium.txt");
    filenames.push_back("the-order-of-the-world.txt");
    filenames.push_back("the-fate-of-the-apostles.txt"); 

    list<Value> mylist;

    cout << endl;
    cout << "Push values to the back of list" << endl;
    for (unsigned int i = 0; i < 3; i++) {
        Value newValue(filenames[i]);
        mylist.push_back(newValue);
    }

    cout << endl;
    reportValues(mylist);
    cout << endl;


    cout << "Pop a value from the front of list" << endl;
    mylist.pop_front(); 

    cout << endl;
    reportValues(mylist);
    cout << endl;

	return 0;
}


