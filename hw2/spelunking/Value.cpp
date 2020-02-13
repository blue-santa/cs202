/*
 * Value.cpp
 * CS 202
 * February 11, 2020
 * Bryan Beus
 * Value member definition file for main in hw2
 */

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <stdlib.h>
#include <vector>
#include <sstream>
#include <fstream>
#include <iterator>

#include "Miscellaneous.hpp"
#include "Value.hpp" 

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::getline;
using std::string;
using std::endl;
using std::ifstream;
using std::stringstream;
using std::istream_iterator;
using std::right;

Value::Value(string& filename) {
    setTitle(filename);
    setCount(filename);
}

void Value::setTitle(string& filename) {
    title = filename;
    total_change_count += 1;
}

unsigned int Value::countWords(string const& str) {
    stringstream ss(str);
    return distance(istream_iterator<string>(ss), istream_iterator<string>());
} 

void Value::setCount(string& filename) {

    ifstream fin(filename);

    if (!fin) {
        cout << "No file opened" << endl;
        exit(0);
    }

    if (fin.eof()) {
        cout << "End of file" << endl;
        exit(0);
    }

    while (fin) {
        string s;
        getline(fin, s);
        line_count++;
        word_count += (int)(countWords(s));
        char_count += (int)(s.length());
        if (s == "") {
            par_count++;
        }
    }
}

void Value::reportValue() {

    for (int i = 0; i < 35 + 4 * 12; i++) cout << "=";
    cout << endl;
    cout << setw(35) << right << "Filename";
    cout << setw(12) << right << "Paragraphs";
    cout << setw(12) << right << "Lines";
    cout << setw(12) << right << "Words";
    cout << setw(12) << right << "Characters" << endl;

    cout << setw(35) << right << title;
    cout << setw(12) << right << par_count;
    cout << setw(12) << right << line_count;
    cout << setw(12) << right << word_count;
    cout << setw(12) << right << char_count << endl;
} 

int Value::total_change_count = 0;


