/*
 * CityList.hpp
 * CS 202
 * April 14, 2020
 * Bryan Beus
 * Declaration file for CityList content
 */

#ifndef __CITYLIST_HPP__
#define __CITYLIST_HPP__ 

#include <iomanip>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <filesystem>
#include <stdlib.h>

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

class CityList {
    public:
        CityList() {};
        ~CityList() {};

        void addNode(const CityNode& node);
        size_t getCount(); 
        double getNodeLon(const unsigned int& nodeNum); 
        double getNodeLat(const unsigned int& nodeNum);

    private:
        vector<CityNode> list_; 
};

#endif
