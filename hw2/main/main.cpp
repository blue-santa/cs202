/*
 * main.cpp
 * CS 202
 * January 19, 2020
 * Bryan Beus
 * Main file for temperature main project in hw0
 */

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <list>
#include <iterator>

#include "Miscellaneous.hpp"
#include "Value.hpp" 

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
using std::list;

int main()
{

    vector<string> filenames;
    filenames.push_back("the-wanderer.txt");

    list<Value> mylist;

    for (unsigned int i = 0; i < filenames.size(); i++) {
        Value newValue(filenames[i]);
        mylist.push_back(newValue);
    }

    list<Value>::iterator it = mylist.begin();
    for (unsigned int i = 0; i < mylist.size(); i++) {
        cout << it->title << endl;
        it++;
    }

	return 0;
}


