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
#include <iterator>

#include "CityList.hpp"
#include "CityNode.hpp"

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

void addNode(const CityNode& node) {
    list_.push_back(node);
}

size_t getCount() {
    return list_.size();
}

double getNodeLon(const unsigned int& nodeNum) {
    vector<string>::iterator it = list_.begin();

    while (it->getNum() != nodeNum && it != list_.end()) {
        it++;
    }

    if (it == list.end()) {
        return 0.0;
    }

    return it->getLon();

}

double getNodeLat(const unsigned int& nodeNum) {
    vector<string>::iterator it = list_.begin();

    while (it->getNum() != nodeNum && it != list_.end()) {
        it++;
    }

    if (it == list.end()) {
        return 0.0;
    }

    return it->getLat();

}
