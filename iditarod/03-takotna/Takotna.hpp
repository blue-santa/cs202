/*
 * Takotna.hpp
 * CS 202
 * April 14, 2020
 * Bryan Beus
 * Declaration file for Takotna content
 */

#ifndef __TAKOTNA_HPP__
#define __TAKOTNA_HPP__ 

#include <iomanip>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <filesystem>
#include <stdlib.h>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::ofstream;
using std::ifstream;
using std::istringstream;
using std::pair;
using std::make_pair;
using std::setw;
using std::right;
using std::left;

namespace fs = std::filesystem; 

// Capture the file names
void callFileNames(vector<string>& fileNames);

#endif
