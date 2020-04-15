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

#include "Takotna.hpp"
#include "CityNode.hpp"
#include "CityList.hpp"

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

    vector<string> fileNames;

    callFileNames(fileNames);

    return 0;
}

