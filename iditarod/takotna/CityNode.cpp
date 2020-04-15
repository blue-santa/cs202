/*
 * CityNode.cpp
 * CS 202
 * April 14, 2020
 * Bryan Beus
 * Definition file for CityNode content
 */

#include <iomanip>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <filesystem>
#include <stdlib.h>

#include "CityNode.hpp"
#include "CityList.hpp"

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

CityNode::CityNode(const unsigned int num, const double lat, const double lon)
    : num_(num), lat_(lat), lon_(lon) { } 

double CityNode::getLon() {
    return lon_;
}

double CityNode::getLat() {
    return lat_;
}

unsigned int CityNode::getNum() {
    return num_;
}
