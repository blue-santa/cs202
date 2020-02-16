/*
 * TimeItFunctions.hpp
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

// Convert lines to tokens
bool LineToTokens(const std::string& line, std::vector<std::string>& tokens);

// Read lines
bool ReadLine(std::istream& is, std::vector<std::string>& tokens, std::vector<std::pair<int, int>>& linecols);

// Print tokens
void PrintTokens(std::ostream& os, const std::vector<std::string>& tokens, const std::vector<std::pair<int, int>>& linecols);

#endif
