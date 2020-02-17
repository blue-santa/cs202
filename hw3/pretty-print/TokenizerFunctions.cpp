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
#include <stdlib.h>
#include <vector>
#include <utility>
#include <iterator>
#include <algorithm>
#include <bits/stdc++.h>
#include <cctype>
#include <locale>

#include "Miscellaneous.hpp"
#include "TokenizerFunctions.hpp"
#include "StopWatch.hpp" 

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::getline;
using std::string;
using std::make_pair;
using std::pair;
using std::to_string;
using std::left;
using std::right;
using std::setw;
using std::advance;
using std::count;
using std::find_if;
using std::isspace;
using std::distance;

// (The three commands below were copied nearly verbatim from Stackoverflow) 

// Trim from the left 
static inline void ltrim(string &line) {
    line.erase(line.begin(), find_if(line.begin(), line.end(), [](int ch) {
        return !isspace(ch);
    }));
}

// Trim from the right
static inline void rtrim(string &line) {
    line.erase(find_if(line.rbegin(), line.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), line.end());
}

// Trim both ends
static inline void trim(string &line) {
    ltrim(line);
    rtrim(line);
}

// Convert lines to tokens
bool LineToTokens(const std::string& line, std::vector<std::string>& tokens) {

    // Declare initial variables
    string delimiter = " ";
    size_t pos = 0;
    size_t prev_pos = 0;
    string token;

    // Count white spaces
    int count_del = count(line.begin(), line.end(), ' ');

    // If the line is blank, return false
    if (line.size() == 0 || (line.find_first_not_of(' ') == std::string::npos)) {
        return false;
    }

    // Process line to individual tokens
    for (int i = 0; i < count_del + 1; i++) {
        
        // Move pos to next whitespace
        pos = line.find(delimiter, prev_pos);

        // If there's no distance between the previous position and the next pos
        // That indicates that there are two whitespaces together
        // Move prev_pos forward one notch and restart loop
        if (pos - prev_pos == 0) {
            prev_pos = pos + delimiter.length();
            continue;
        }

        // Process line to token to tokens
        token = line.substr(prev_pos, pos - prev_pos);
        tokens.push_back(token);

        // Move prev_pos forward one notch
        prev_pos = pos + delimiter.length();
    } 

    return true;
}

// Read lines
bool ReadLine(std::istream& is, std::vector<std::string>& tokens, std::vector<std::pair<int, int>>& linecols) {

    // The linecols variable comes with a dummy pair for processing
    // and needs to be set
    // Initiate bool variable to track when linecols is fixed
    bool lineColsSet = false;

    while (true) {
        string line;
        vector<string> temp_tokens;
        getline(is, line);

        if (is.eof()) {
            return true;
        }

        if (!is) {
            cout << "Stream failed to load" << endl;
            return false;
        }

        // Trim the line first to get rid of extra white spaces
        trim(line);

        // Process the line and check whether it is blank 
        bool lineNotBlank = LineToTokens(line, temp_tokens); 

        // Capture current line and column index values
        vector<pair<int, int>>::iterator linecols_it = linecols.end(); 
        linecols_it--; 
        int current_line = linecols_it->first;
        int col_index = linecols_it->second;

        // Erase the dummy pair from linecols, if necesary
        if (lineColsSet == false) {
            linecols.erase(linecols.begin());
            lineColsSet = true;
        }

        // Create a blank line token for processing
        if (!lineNotBlank) { 
            linecols.push_back(make_pair(current_line, col_index));
            tokens.push_back("=blank line=");
            continue;
        }

        // Process tokens and linecols values
        for (unsigned int i = 0; i < temp_tokens.size(); i++) {
            linecols.push_back(make_pair(current_line, col_index));
            col_index += temp_tokens.at(i).size();
            current_line++;
            tokens.push_back(temp_tokens.at(i));
        } 
    } 
}

// Print tokens
void PrintTokens(std::ostream& os, const std::vector<std::string>& tokens, const std::vector<std::pair<int, int>>& linecols) {

    // To prevent segfault, check that linecols has values
    if (linecols.size() == 0) {
        cout << "No lines and columns to print." << endl;
        exit(0);
    }

    // For print processing, capture string length of max column and line values
    std::vector<std::pair<int, int>>::const_iterator linecols_it = linecols.end();
    linecols_it--;

    int line_size_int = linecols_it->first; 
    string line_size_str = to_string(line_size_int);
    int line_col_length = line_size_str.length();

    int col_size_int = linecols_it->second;
    string col_size_str = to_string(col_size_int);
    int col_col_length = col_size_str.length();

    // Print report to output stream
    for (unsigned int i = 0; i < tokens.size(); i++) {

        os << "Line" << right << setw(line_col_length + 1) << linecols.at(i).first << ", Column " << right << setw(col_col_length + 1) << linecols.at(i).second << ": ";
        if (tokens.at(i) == "=blank line=") {
            os << "blank line" << endl;
            continue;
        }

        os << "\"" << tokens.at(i) << "\"" << endl;
    } 
}

// Pretty print the provided tokens
void PrettyPrint(ostream& os, const vector<string>& tokens, bool& isHtml, int& wrapCount) {

    // Variable to skip
    string blank = "=blank line=";

    // Create vector of string, as per assignment
    vector<string> paragraphs;

    // Capture titles for Stories of the Wagner Opera
    vector<string> titles;
    titles.push_back("RIENZI, THE LAST OF THE TRIBUNES.");
    titles.push_back("THE FLYING DUTCHMAN.");
    titles.push_back("TANNHÄUSER.");
    titles.push_back("LOHENGRIN.");
    titles.push_back("TRISTAN AND YSOLDE.");
    titles.push_back("THE MASTER-SINGERS OF NUREMBERG.");
    titles.push_back("THE NIBELUNG'S RING.--RHEINGOLD.");
    titles.push_back("THE WALKYRIE.");
    titles.push_back("SIEGFRIED.");
    titles.push_back("DUSK OF THE GODS.");
    titles.push_back("PARSIFAL.");

    // Iterators for while loop progresiong
    vector<string>::const_iterator tokens_it_next = tokens.begin();
    vector<string>::const_iterator tokens_it_prev = tokens_it_next;
    vector<string>::const_iterator tokens_it_current = tokens_it_next;

    // Check that there are actual tokens in variable
    if (tokens_it_next == tokens.end()) {
        cout << "Empty tokens" << endl;
        exit(0);
    }

    while (true) { 

        // Search for next blank line
        tokens_it_next = find(tokens_it_prev, tokens.end(), blank);

        // Measure distance between previous spot and next blank line
        int dist_prev_next = (int)(distance(tokens_it_prev, tokens_it_next));

        // Account for adjacent blank lines
        if (dist_prev_next == 1) {
            tokens_it_prev = tokens_it_next;
            tokens_it_prev++;
            tokens_it_current = tokens_it_prev;
            continue;
        } else if (dist_prev_next == 0) {
            tokens_it_prev++;
            tokens_it_current = tokens_it_prev;
            continue;
        }

        if (isHtml) {

            // Compile all tokens between iterators into one unit
            // The first one does not need a space before it
            string res = *tokens_it_current; 
            for (int i = 0; i < dist_prev_next - 1; i++) {
                res += " ";
                tokens_it_current++;
                res += *tokens_it_current;
            } 
            paragraphs.push_back(res); 

            // Check to see if the current paragraph is actually a title
            // If it is, surround it in <h1> headings instead of <p>
            vector<string>::const_iterator search_titles_it = find(titles.begin(), titles.end(), res); 
            if (search_titles_it != titles.end()) {
                res = "<h1>" + res + "</h1>\n";
            } else {
                res = "<p>" + res + "</p>\n";
            }

            // Check to see if the end of the file is reached
            if (tokens_it_next == tokens.end()) {
                break;
            }

            // Reset iterators
            tokens_it_prev = tokens_it_next;
            tokens_it_prev++;
            tokens_it_current = tokens_it_prev;

            // Send all content from this loop to the output stream
            os << res << endl; 

        } else { 

            // Compile all tokens between iterators into one unit
            // The first one does not need a space before it 

            string res = *tokens_it_current; 
            int current_line_length = res.length();

            if (current_line_length > wrapCount) {
                cout << "Wrap count cannot accomodate length of the word " << *tokens_it_current << " in the text file.\nPlease try a larger wrap count." << endl;
                exit(0);
            }

            for (int i = 0; i < dist_prev_next - 1; i++) {
                tokens_it_current++;
                string tempStr = *tokens_it_current;
                if ((current_line_length + (int)(tempStr.length()) + 1) >= wrapCount) {
                    current_line_length = tempStr.length();
                    res += "\n";
                } else { 
                    res += " ";
                    current_line_length += tempStr.length() + 1;
                }
                res += *tokens_it_current;
            } 

            paragraphs.push_back(res); 
            res += "\n";

            // Reset iterators
            tokens_it_prev = tokens_it_next;
            tokens_it_prev++;
            tokens_it_current = tokens_it_prev;

            // Send all content from this loop to the output stream
            os << res << endl; 

            // Check to see if the end of the file is reached
            if (tokens_it_next == tokens.end()) {
                break;
            }

        }
    } 
}
