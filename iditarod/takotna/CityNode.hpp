/*
 * CityNode.hpp
 * CS 202
 * April 14, 2020
 * Bryan Beus
 * Declaration file for CityNode content
 */

#ifndef __CITYNODE_HPP__
#define __CITYNODE_HPP__ 

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

class CityNode {
    public:
        CityNode(const unsigned int num, const double lat, const double lon); 

        double getLon(); 
        double getLat();

    private:
        unsigned int num_;
        double lat_;
        double lon_;
        double x_;
        double y_;
};

#endif
