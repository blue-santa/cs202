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

// CityList class
class CityList {
    public:
        // Default constructor
        CityList() {};

        // Default destructor
        ~CityList() {};

        // Parse the provided ifstream file into a list_ object of CityNodes
        void parseFile(ifstream& is);

        // Add a node to list_
        void addNode(const CityNode& node);

        // Get the size of list_
        size_t getCount() const; 

        // Get the longitude value of the indicated node
        double getNodeLon(const unsigned int& nodeNum) const; 

        // Get the latitude value of the indicated node
        double getNodeLat(const unsigned int& nodeNum) const;

        // Get the num_ value of the indicated node
        unsigned int getNodeNum(const int& vectorPos) const;

        // Calculate the array value from a provided num_
        int calcArrayNum(const unsigned int& numVal) const;

        // Calculate the distance between two nodes
        double distance(const int& fir, const int& sec) const;

    private:
        vector<CityNode> list_; 
};

#endif
