/*
 * Value.hpp
 * CS 202
 * February 11, 2020
 * Bryan Beus
 * Header file for Value class for main in hw2
 */

#ifndef __VALUE_HPP_
#define __VALUE_HPP_

#include <string>
#include <fstream>
#include <stdlib.h>

using std::string;

struct Value {

    string title;
    int line_count;
    int par_count;
    int word_count;
    int char_count; 
    static int total_count;

    Value(string& filename);
    void setTitle(string& filename);
    unsigned int countWords(string const& str);
    void setCount(string& filename);
};

#endif

