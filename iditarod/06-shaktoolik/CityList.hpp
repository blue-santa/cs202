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

        // Set Max Lon and Lat
        void setMaxMinVals();

        // Set Max Lon and Lat
        void setMaxLon(const double& lon);

        // Set Max Lon and Lat
        void setMaxLat(const double& lat);

        // Get Max Lon
        double getMaxLon() const { return max_lon_; };

        // Get Max Lat
        double getMaxLat() const { return max_lat_; };

        // Set Max Lon and Lat
        void setMinLon(const double& lon);

        // Set Min Lon and Lat
        void setMinLat(const double& lat);

        // Get Min Lon
        double getMinLon() const { return min_lon_; };

        // Get Min Lat
        double getMinLat() const { return min_lat_; };

    private:
        vector<CityNode> list_; 
        double max_lon_ = 0.0;
        double max_lat_ = 0.0;
        double min_lon_ = 0.0;
        double min_lat_ = 0.0;
};

#endif
