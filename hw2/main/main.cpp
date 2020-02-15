/*
 * main.cpp
 * CS 202
 * January 19, 2020
 * Bryan Beus
 * Main file for temperature main project in hw0
 */

#define CATCH_CONFIG_MAIN

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
using std::right;

void reportValues(list<Value>& mylist) {

    list<Value>::iterator it = mylist.begin();

    for (unsigned int i = 0; i < mylist.size(); i++) {
        it->reportValue();
        it++;
    }

}

TEST_CASE( "Linked List/Stack tests", "[list]" ) {

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
    cout << setw(35 + 12 * 4) << right << "Push three values to the front of the list" << endl;
    for (unsigned int i = 0; i < 3; i++) {
        Value newValue(filenames[i]);
        mylist.push_front(newValue);
    } 
    reportValues(mylist);
    cout << endl;

    list<Value>::iterator it_test1 = mylist.begin();

    REQUIRE( it_test1->title == "solomon-and-saturn.txt" ); 

    cout << setw(35 + 12 * 4) << right <<  "Pop a value from the front of the list" << endl;
    mylist.pop_front(); 
    reportValues(mylist);
    cout << endl;

    // cout << setw(35 + 12 * 4) << right <<  "Push three values to the back of the list" << endl;
    // for (unsigned int i = 2; i < 5; i++) {
        // Value newValue(filenames[i]);
        // mylist.push_back(newValue);
    // } 
    // reportValues(mylist);
    // cout << endl;


    // cout << setw(35 + 12 * 4) << right <<  "Pop a value from the back of the list" << endl;
    // mylist.pop_back(); 
    // reportValues(mylist);
    // cout << endl;

    // list<Value>::iterator it = mylist.begin();

    // cout << setw(35 + 12 * 4) << right <<  "Search for Solomon and Saturn" << endl;

    // while (it->title != "solomon-and-saturn.txt") it++;

    // it->reportValue();

    // cout << endl;
    // cout << setw(35 + 12 * 4) << right <<  "Insert sorted values behind Solomon and Saturn" << endl;
    // for (int i = 0; mylist.size() < filenames.size(); i++) {
        // Value newValue(filenames[(int)(mylist.size())]);
        // mylist.insert(it, newValue);
        // it++;
    // }
    // reportValues(mylist);

    // cout << endl;
    // cout << "Total number of file changes: " << Value::total_change_count << endl;
}



