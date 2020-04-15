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

// Create a TSP solution using random city choices
double TspSolver::SolveRandomly(const CityList& citylist, CityPath& citypath) {
    int max = (int)citylist.getCount();

    int startingCityPos = rand() % (max - 1);
    unsigned int startingCity = citylist.getNodeNum(startingCityPos);
    citypath.addCity(startingCity);

    CityPath unchosenCities;
    for (int i = 0; i < max; i++) {
        unsigned int currCity = citylist.getNodeNum(i); 
        unchosenCities.addCity(currCity);
    } 
    unchosenCities.removeCity(startingCity);

    while (unchosenCities.getCount() > 0) {
        int unchosen_max = (int)unchosenCities.getCount();
        cout << "Unchosen count in current list: " << unchosen_max << endl;
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
        unsigned int currCity = citypath.getNode(i);
        unsigned int nextCity = citypath.getNode(i + 1);

        int currCityPos = citylist.calcArrayNum(currCity);
        int nextCityPos = citylist.calcArrayNum(nextCity);
        cout << "Calculating distance between nodes: " << currCity << " and " << nextCity << endl;
        double val = citylist.distance(currCityPos, nextCityPos);
        current_distance += val;
    }


    return current_distance;

}

// Create a highly accurate solution using greedy algorithms
double TspSolver::SolveGreedy(const CityList& citylist, CityPath& citypath) { 
    int max = (int)citylist.getCount();

    int startingCityPos = rand() % (max - 1);
    unsigned int startingCity = citylist.getNodeNum(startingCityPos);
    citypath.addCity(startingCity);

    CityPath unchosenCities;
    unsigned int currCity;
    for (int i = 0; i < max; i++) {
        currCity = citylist.getNodeNum(i); 
        unchosenCities.addCity(currCity);
    } 

    currCity = startingCity;
    int currCityPos = startingCityPos;
    while (unchosenCities.getCount() > 0) {
        int unchosen_max = (int)unchosenCities.getCount();
        cout << "Unchosen count in current list: " << unchosen_max << endl;
        if (unchosen_max != 1) { 
            double dist1 = 1000000000000;
            size_t p = 0;

            for (int i = 0; i < unchosen_max; i++) {
                unsigned int nextCity = unchosenCities.getNode(i);
                // currcity is already here

                // Get the array value of the current city
                currCityPos = citylist.calcArrayNum(currCity);
                // Get the array value of the next city to test
                int nextCityPos = citylist.calcArrayNum(nextCity);

                double val = citylist.distance(currCityPos, nextCityPos);
                if (val < dist1) {
                    dist1 = val;
                    p = i;
                }
            }
            currCity = unchosenCities.getNode(p); 
            currCityPos = p;
            citypath.addCity(currCity);
            unchosenCities.removeCity(currCity); 
        } else {
            currCity = unchosenCities.getNode(0);
            citypath.addCity(currCity);
            unchosenCities.removeCity(currCity); 
        }
    } 

    citypath.addCity(startingCity);

    double current_distance = 0;

    for (int i = 0; i < (int)citypath.getCount() - 1; i++) {
        currCity = citypath.getNode(i);
        unsigned int nextCity = citypath.getNode(i + 1);

        int currCityPos = citylist.calcArrayNum(currCity);
        int nextCityPos = citylist.calcArrayNum(nextCity);
        double val = citylist.distance(currCityPos, nextCityPos);
        current_distance += val;
    }

    return current_distance;
}

double TspSolver::SolveMyWay(const CityList& citylist, CityPath& citypath) {
    int max = (int)citylist.getCount();

    int startingCityPos = rand() % (max - 1);
    unsigned int startingCity = citylist.getNodeNum(startingCityPos);
    citypath.addCity(startingCity);

    CityPath unchosenCities;
    for (int i = 0; i < max; i++) {
        unsigned int currCity = citylist.getNodeNum(i); 
        unchosenCities.addCity(currCity);
    } 
    unchosenCities.removeCity(startingCity);

    while (unchosenCities.getCount() > 0) {
        int unchosen_max = (int)unchosenCities.getCount();
        cout << "Unchosen count in current list: " << unchosen_max << endl;
        int currCityPos;
        if (unchosen_max == 1) { 
            currCityPos = 0;
        } else {
            currCityPos = rand() % (unchosen_max - 1);
            currCity = citylist.getNodeNum(currCityPos);
            unsigned int prevCity = citypath.getNode(citypath.size() - 1);
            unsigned int currCity = citypath.getNode(i);
            unsigned int nextCity = citypath.getNode(i + 1);

            int currCityPos = citylist.calcArrayNum(currCity);
            int nextCityPos = citylist.calcArrayNum(nextCity);
            cout << "Calculating distance between nodes: " << currCity << " and " << nextCity << endl;
            double val = citylist.distance(currCityPos, nextCityPos);
        }

        unsigned int currCity = citylist.getNodeNum(currCityPos);
        citypath.addCity(currCity); 
        unchosenCities.removeCity(currCity);
    } 

    citypath.addCity(startingCity);

    double current_distance = 0;

    for (int i = 0; i < (int)citypath.getCount() - 1; i++) {
        unsigned int currCity = citypath.getNode(i);
        unsigned int nextCity = citypath.getNode(i + 1);

        int currCityPos = citylist.calcArrayNum(currCity);
        int nextCityPos = citylist.calcArrayNum(nextCity);
        cout << "Calculating distance between nodes: " << currCity << " and " << nextCity << endl;
        double val = citylist.distance(currCityPos, nextCityPos);
        current_distance += val;
    }


    return current_distance;

}

