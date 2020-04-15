/*
 * CityPath.cpp
 * CS 202
 * April 14, 2020
 * Bryan Beus
 * Definition file for CityPath content
 */

#include <iomanip>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <filesystem>
#include <stdlib.h>
#include <iterator>
#include <cmath>

#include "CityList.hpp"
#include "CityNode.hpp"
#include "CityPath.hpp"
#include "Takotna.hpp"

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

CityPath::addCity(const int& nextCity) {
    connections_.push_back(nextCity);
}
