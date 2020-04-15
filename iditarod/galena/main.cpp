/*
 * main.cpp
 * CS202
 * April 14, 2020
 * Bryan Beus
 * Takotna station for Iditarod Challenge
 */

#include <iomanip>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <filesystem>
#include <stdlib.h>
#include <memory>

#include "Takotna.hpp"
#include "CityNode.hpp"
#include "CityList.hpp"
#include "Miscellaneous.hpp"

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

int main() {

    clearConsole();

    vector<string> fileNames; 
    callFileNames(fileNames); 
    vector<CityList> citylist;

    for (size_t i = 0; i < fileNames.size(); i++) {
        string file = "./big/" + fileNames.at(i);
        ifstream fin(file); 
        if (!fin) {
            cout << "Error loading file: " << file << endl;
            exit(0);
        }

        CityList newList; 
        newList.parseFile(fin); 
        citylist.push_back(newList);
    }

    CityList test1 = citylist.at(0);
    double testDistance = test1.distance(1,2);
    cout << "The distance between Nodes 1 and 2 of CityList 0 is: " << testDistance << endl;

    return 0;
}

