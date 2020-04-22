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

        // Default constructor
        CityPath() {};
        // Default destructor
        ~CityPath() {};

        // Add a city to the connections_ object
        void addCity(const unsigned int& nextCity);

        // Remove a city from the connections_ object
        void removeCity(const unsigned int& removeCity);

        // Get the size of the connections_ object
        const size_t getCount() const;

        // Get the value at a particular array index
        unsigned int getNode(const int& index) const;

    private:
        vector<unsigned int> connections_;
};

#endif
