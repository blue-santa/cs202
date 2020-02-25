/*
 * TokenizerFunctions.hpp
 * CS 202
 * February 15, 2020
 * Bryan Beus
 * Header definition file
 */

#ifndef __TIMEIT_FUNC__
#define __TIMEIT_FUNC__

#include <random>
#include <vector>

#include "StopWatch.hpp"

using std::vector;
using std::string;
using std::istream;
using std::pair;
using std::ostream;

// Convert lines to tokens
bool LineToTokens(const string& line, vector<string>& tokens);

// Read lines
bool ReadLine(istream& is, vector<string>& tokens, vector<pair<int, int>>& linecols);

// Print tokens
void PrintTokens(ostream& os, const vector<string>& tokens, const vector<pair<int, int>>& linecols);

#endif
