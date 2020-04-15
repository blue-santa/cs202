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

void CityList::addNode(const CityNode& node) {
    list_.push_back(node);
}

size_t CityList::getCount() {
    return list_.size();
}

double CityList::getNodeLon(const unsigned int& nodeNum) {
    vector<CityNode>::iterator it = list_.begin();

    while (it->getNum() != nodeNum && it != list_.end()) {
        it++;
    }

    if (it == list_.end()) {
        return 0.0;
    }

    return it->getLon();

}

double CityList::getNodeLat(const unsigned int& nodeNum) {
    vector<CityNode>::iterator it = list_.begin();

    while (it->getNum() != nodeNum && it != list_.end()) {
        it++;
    }

    if (it == list_.end()) {
        return 0.0;
    }

    return it->getLat();

}
