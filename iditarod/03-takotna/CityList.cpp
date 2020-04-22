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

namespace fs = std::filesystem; 

// Parse a provided ifstream file
void CityList::parseFile(ifstream& is) {

    // Test that citylist object is not already claimed
    if (list_.size() > 0) {
        cout << "Each CityList object should only have one file" << endl;
        exit(0);
    }

    // Skip the introduction
    int i = 0;
    string current_line;
    while (i < 15 && !is.eof() && current_line.find("NODE_COORD_SECTION") == string::npos) {
        getline(is, current_line);
        i++;
    }

    // Error checking
    if (i == 15) {
        cout << "Error reading input file" << endl;
        exit(0);
    }

    // Parse each line into a new city node
    while (current_line != "EOF") {
        getline(is, current_line);

        if (current_line.find("EOF") != string::npos || current_line.find_first_not_of(' ') == string::npos) {
            break;
        }

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

// Return the count
size_t CityList::getCount() const {
    return list_.size();
}

// Get the Node's Lon value
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

// Get the Node's Lat value
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

// Calculate the distance between two nodes
double CityList::distance(const int& fir, const int& sec) const {
    const double x2 = getNodeLon(sec);
    const double x1 = getNodeLon(fir);
    const double y2 = getNodeLat(sec);
    const double y1 = getNodeLat(fir);
    return sqrt(pow((x2 - x1), 2.0) + pow((y2 - y1), 2.0)); 
}

