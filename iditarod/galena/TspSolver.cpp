/*
 * TspSolver.cpp
 * CS 202
 * April 14, 2020
 * Bryan Beus
 * Definition file for TspSolver content
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
#include <stdlib.h>

#include "CityList.hpp"
#include "CityNode.hpp"
#include "TspSolver.hpp"
#include "CityPath.hpp"
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

unsigned long long int TspSolver::SolveRandomly(const CityList& citylist, CityPath& citypath) {
    int max = (int)citylist.getCount();

    int startingCityPos = rand() % (max - 1);
    unsigned int startingCity = citylist.getNodeNum(startingCityPos);
    citypath.addCity(startingCity);

    CityPath unchosenCities;
    for (int i = 0; i < max; i++) {
        unsigned int currCity = citylist.getNodeNum(i);

        if (currCity == startingCity) continue;

        unchosenCities.addCity(currCity);
    } 

    while (unchosenCities.getCount() > ) {

        unchosenCities.removeCity(currCity);
    }




}

void TspSolver::SolveGreedy(const CityList& citylist, CityPath& citypath) {}

void TspSolver::SolveMyWay(const CityList& citylist, CityPath& citypath) {}

