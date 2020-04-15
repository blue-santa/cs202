/*
 * CityPath.hpp
 * CS 202
 * April 14, 2020
 * Bryan Beus
 * Declaration file for CityPath content
 */

#ifndef __CITYPATH_HPP__
#define __CITYPATH_HPP__ 

#include <iomanip>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <filesystem>
#include <stdlib.h>

#include "CityNode.hpp"
#include "CityList.hpp"
#include "Miscellaneous.hpp"
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

class CityPath {
    public:
        CityPath() {};
        ~CityPath() {};

        void addCity(const int& nextCity);

    private:
        vector<int> connections_;
};

#endif
