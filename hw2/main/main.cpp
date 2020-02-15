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

// Report the values for each list item in mylist
void reportValues(list<Value>& mylist) {

    list<Value>::iterator it = mylist.begin();

    for (unsigned int i = 0; i < mylist.size(); i++) {
        it->reportValue();
        it++;
    }

}

// Provides main() using Catch2.hpp
TEST_CASE( "Linked List/Stack tests", "[list]" ) {

    // Create vector to hold each filename
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

    // Demonstration of mylist.push_front() for three values
    cout << endl;
    cout << setw(35 + 12 * 4) << right << "Push three values to the front of the list" << endl;
    for (unsigned int i = 0; i < 3; i++) {
        Value newValue(filenames[i]);
        mylist.push_front(newValue);
    } 
    reportValues(mylist);
    cout << endl;

    // Demonstration for popping a value from mylist
    cout << setw(35 + 12 * 4) << right <<  "Pop a value from the front of the list" << endl;
    mylist.pop_front(); 
    reportValues(mylist);
    cout << endl;

    // Demonstration of pushing to the back of the lsit
    cout << setw(35 + 12 * 4) << right <<  "Push three values to the back of the list" << endl;
    for (unsigned int i = 2; i < 5; i++) {
        Value newValue(filenames[i]);
        mylist.push_back(newValue);
    } 
    reportValues(mylist);
    cout << endl;

    // Demonstration of popping from the back of the list
    cout << setw(35 + 12 * 4) << right <<  "Pop a value from the back of the list" << endl;
    mylist.pop_back(); 
    reportValues(mylist);
    cout << endl;

    // Demonstration of sorting the list
    list<Value>::iterator it = mylist.begin(); 
    cout << setw(35 + 12 * 4) << right <<  "Search for Solomon and Saturn" << endl; 
    while (it->title != "solomon-and-saturn.txt") it++; 
    it->reportValue();

    // Demonstration of inserting sorted values into the list
    cout << endl;
    cout << setw(35 + 12 * 4) << right <<  "Insert sorted values behind Solomon and Saturn" << endl;
    for (int i = 0; mylist.size() < filenames.size(); i++) {
        Value newValue(filenames[(int)(mylist.size())]);
        mylist.insert(it, newValue);
        it++;
    }
    reportValues(mylist);

    // If each action performed properly, tests should be positive
    list<Value>::iterator it_test = mylist.begin();
    REQUIRE( it_test->title == "the-fate-of-the-apostles.txt" ); 
    std::advance(it_test, 1);
    REQUIRE( it_test->title == "dream-of-the-rood.txt" ); 

    std::advance(it_test, 1);
    REQUIRE( it_test->title == "the-wanderer.txt" ); 

    std::advance(it_test, 1);
    REQUIRE( it_test->title == "wulf-and-eadwacer.txt" ); 

    std::advance(it_test, 1);
    REQUIRE( it_test->title == "solomon-and-saturn.txt" ); 

    std::advance(it_test, 1);
    REQUIRE( it_test->title == "the-menologium.txt" ); 

    std::advance(it_test, 1);
    REQUIRE( it_test->title == "the-phoenix.txt" ); 

    std::advance(it_test, 1);
    REQUIRE( it_test->title == "the-order-of-the-world.txt" ); 

    cout << endl;
    cout << "Total number of file changes: " << Value::total_change_count << endl;

} 

