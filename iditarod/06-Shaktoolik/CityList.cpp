/*
 * CityList.cpp
 * CS 202
 * April 14, 2020
 * Bryan Beus
 * Definition file for CityList content
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
using std::advance;

namespace fs = std::filesystem; 

// Pasre the provided ifstream into a citylist object
void CityList::parseFile(ifstream& is) {

    // Error checking
    if (list_.size() > 0) {
        cout << "Each CityList object should only have one file" << endl;
        exit(0);
    }

    // Skip the introduction of the file
    int i = 0;
    string current_line;
    while (i < 15 && !is.eof() && current_line.find("NODE_COORD_SECTION") == string::npos) {
        getline(is, current_line);
        i++;
    }

    if (i == 15) {
        cout << "Error reading input file" << endl;
        exit(0);
    }

    // Parse each line into the CityNode objects
    while (current_line != "EOF") {
        getline(is, current_line);

        if (current_line.find("EOF") != string::npos || current_line.find_first_not_of(' ') == string::npos) {
            break;
        }

        cout << "Parsing line: " << current_line << endl;
        unsigned int num;
        float latF;
        float lonF;
        istringstream ss(current_line);
        ss >> num;

        if (!ss) {
            cout << "Error parsing num" << endl;
            cout << current_line << endl;
            exit(0);
        }

        ss >> latF;

        if (!ss) {
            cout << "Error parsing latF" << endl;
            exit(0);
        }

        ss >> lonF;

        if (!ss) {
            cout << "Error parsing lonF" << endl;
            exit(0);
        }

        double lat = (double)latF;
        double lon = (double)lonF;

        CityNode newNode(num, lat, lon);
        this->addNode(newNode);
    }

}

// Add a node to the list_ object
void CityList::addNode(const CityNode& node) {
    list_.push_back(node);
}

// Return the size of list_
size_t CityList::getCount() const {
    return list_.size();
}

// Get the longitude value for the indicated node
double CityList::getNodeLon(const unsigned int& nodeNum) const {
    vector<CityNode>::const_iterator it = list_.begin();

    while (it->getNum() != nodeNum && it != list_.end()) {
        it++;
    }

    if (it == list_.end()) {
        return 0.0;
    }

    return it->getLon();

}

// Get the latitude value for the indicated node
double CityList::getNodeLat(const unsigned int& nodeNum) const {
    vector<CityNode>::const_iterator it = list_.begin();

    while (it->getNum() != nodeNum && it != list_.end()) {
        it++;
    }

    if (it == list_.end()) {
        return 0.0;
    }

    return it->getLat();

}

// Get the num_ value of the indicated node
unsigned int CityList::getNodeNum(const int& vectorPos) const { 
    vector<CityNode>::const_iterator it = list_.begin();

    int i = 0; 
    while (it != list_.end() && i < vectorPos) { 
        advance(it, 1);
        i++;
    }

    if (
                (i == vectorPos && it == list_.end())
            ||  (it == list_.end() && i < vectorPos - 1)
        ) 
    {
        cout << "Error check in CityList.cpp" << endl;
        exit(0);
    }

    return it->getNum();

}

// Retrieve the index number of a provided num_ value
int CityList::calcArrayNum(const unsigned int& numVal) const { 
    vector<CityNode>::const_iterator it = list_.begin();

    int i = 0; 
    while (it != list_.end() && it->getNum() != numVal) { 
        advance(it, 1);
        i++;
    }

    if (it == list_.end() && it->getNum() != numVal) {
        cout << "Error finding numVal in calcArrayNum()" << endl;
        exit(0);
    }

    return i;

}

void CityList::setMaxMinVals() {
    size_t count_ = getCount();

    double max_lon = 0.0; 
    double max_lat = 0.0; 

    for (size_t i = 0; i < count_; i++) { 
        if (max_lon < list_.at(i).getLon()) {
            max_lon = list_.at(i).getLon();
            setMaxLon(max_lon);
        }
        if (max_lat < list_.at(i).getLat()) {
            max_lat = list_.at(i).getLat();
            setMaxLat(max_lat);
        }
    }

    double min_lon = 1000000000.0; 
    double min_lat = 1000000000.0; 
    for (size_t i = 0; i < count_; i++) { 
        if (min_lon > list_.at(i).getLon()) {
            min_lon = list_.at(i).getLon();
            setMinLon(min_lon);
        }

        if (min_lat > list_.at(i).getLat()) {
            min_lat = list_.at(i).getLat();
            setMinLat(min_lat);
        }
    }
}

// Set Max Lon and Lat
void CityList::setMaxLon(const double& lon) {
    max_lon_ = lon;
}

// Set Max Lon and Lat
void CityList::setMaxLat(const double& lat) {
    max_lat_ = lat;
}

// Set Max Lon and Lat
void CityList::setMinLon(const double& lon) {
    min_lon_ = lon;
}

// Set Max Lon and Lat
void CityList::setMinLat(const double& lat) {
    min_lat_ = lat;
}

// Calculate the distance between two nodes
double CityList::distance(const int& fir, const int& sec) const {
    const double x2 = getNodeLon(sec);
    const double x1 = getNodeLon(fir);
    const double y2 = getNodeLat(sec);
    const double y1 = getNodeLat(fir);
    return sqrt(pow((x2 - x1), 2.0) + pow((y2 - y1), 2.0)); 
}

