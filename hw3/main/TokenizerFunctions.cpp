/*
 * TimeItFunctions.cpp
 * CS 202
 * February 5, 2020
 * Bryan Beus
 * 
 */

#include <iostream>
#include <iomanip>
#include <string>
// #include <cstdlib>
// #include <random>
// #include <cmath>
// #include <stdlib.h>
// #include <chrono>
#include <vector>
#include <utility>
#include <iterator>
// #include <algorithm>
// #include <time.h>

#include "Miscellaneous.hpp"
#include "TokenizerFunctions.hpp"
#include "StopWatch.hpp" 

using std::cout;
using std::cin;
using std::endl;
using std::vector;
// using std::round;
using std::getline;
using std::string;
using std::make_pair;
using std::to_string;
using std::left;
using std::right;
using std::setw;
using std::advance;

// Convert lines to tokens
bool LineToTokens(const std::string& line, std::vector<std::string>& tokens) {

    string delimiter = " ";
    size_t pos = 0;
    size_t prev_pos = 0;
    string token;

    if (line.size() == 0) {
        return false;
    }

    while ((pos = line.find(delimiter, prev_pos)) != std::string::npos) {
        token = line.substr(prev_pos, pos);
        tokens.push_back(token);
        prev_pos = pos + delimiter.length();
    } 

    return true;
}

// Read lines
bool ReadLine(std::istream& is, std::vector<std::string>& tokens, std::vector<std::pair<int, int>>& linecols) {

    while (true) {
        string line;
        vector<string> temp_tokens;
        getline(is, line);

        if (!is) {
            cout << "stream failed to load" << endl;
            return false;
        }

        bool lineNotBlank = LineToTokens(line, temp_tokens); 

        int col_index = 1;
        int current_line = linecols.end()->first;


        if (!lineNotBlank) { 
            linecols.push_back(make_pair(current_line, col_index));
            tokens.push_back("=blank line=");
            continue;
        }

        for (unsigned int i = 0; i < temp_tokens.size(); i++) {

            linecols.push_back(make_pair(current_line, col_index));
            col_index += temp_tokens.at(i).size();
            tokens.push_back(temp_tokens.at(i));
        } 

        if (is.eof()) {
            break;
        }
    }

    return true;

}

// Print tokens
void PrintTokens(std::ostream& os, const std::vector<std::string>& tokens, const std::vector<std::pair<int, int>>& linecols) {

    int line_size_int = linecols.end()->first; 
    string line_size_str = to_string(line_size_int);
    int line_col_length = line_size_str.length();

    int col_size_int = linecols.end()->second;
    string col_size_str = to_string(col_size_int);
    int col_col_length = col_size_str.length();

    for (unsigned int i = 0; i < tokens.size(); i++) {

        os << "Line" << right << setw(line_col_length + 1) << linecols.at(i).first << ", Column " << right << setw(col_col_length + 1) << linecols.at(i).second << ": ";
        if (tokens.at(i) == "=blank line") {
            os << "blank line" << endl;
            continue;
        }

        os << tokens.at(i) << "\"" << endl;
    } 
}

