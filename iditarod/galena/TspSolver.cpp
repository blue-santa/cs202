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

double TspSolver::SolveRandomly(const CityList& citylist, CityPath& citypath) {
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

    while (unchosenCities.getCount() > 0) {
        int unchosen_max = (int)unchosenCities.getCount();
        int currCityPos;
        if (unchosen_max == 1) { 
            currCityPos = 0;
        } else {
            currCityPos = rand() % (unchosen_max - 1);
        }

        unsigned int currCity = citylist.getNodeNum(currCityPos);
        citypath.addCity(currCity); 
        unchosenCities.removeCity(currCity);
    } 

    citypath.addCity(startingCity);

    double current_distance = 0;

    for (int i = 0; i < (int)citypath.getCount() - 1; i++) {
        double val = citylist.distance(i, i + 1);
        current_distance += val;
    }

    return current_distance;

}

double TspSolver::SolveGreedy(const CityList& citylist, CityPath& citypath) { 
    return 0;
}

double TspSolver::SolveMyWay(const CityList& citylist, CityPath& citypath) {
    return 0;
}

