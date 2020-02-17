/*
 * Value.hpp
 * CS 202
 * February 11, 2020
 * Bryan Beus
 * Header file for Value class
 */

#ifndef __VALUE_HPP_
#define __VALUE_HPP_

#include <string>
#include <fstream>
#include <stdlib.h>

using std::string;

struct Value {

    // Base values for a Value instance
    string title = "";
    int line_count = 0;
    int par_count = 0;
    int word_count = 0;
    int char_count = 0;
    static int total_change_count;

    // Main constructor
    Value(string& filename);

    // Set the title of a Value instance
    void setTitle(string& filename);

    // Count the words in a provided string
    unsigned int countWords(string const& str);

    // Set the counts for values in Value instance
    void setCount(string& filename);

    // Report the values of the counts in this instance of Value
    void reportValue();
};

#endif

