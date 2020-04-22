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
using std::to_string;
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
double TspSolver::SolveRandomly(CityList& citylist, CityPath& citypath, const string& filepath) {

    // Declare SVG variables
    string filename = "./output_images/randomly/" + filepath + "img.svg";
    const int file_size_x = 500;
    const int file_size_y = 500; 
    // Pick a random starting city
    int max = (int)citylist.getCount(); 
    int startingCityPos = rand() % (max - 1);
    unsigned int startingCity = citylist.getNodeNum(startingCityPos);
    citypath.addCity(startingCity);

    // Populate the unchosen cities list
    CityPath unchosenCities;
    for (int i = 0; i < max; i++) {
        unsigned int currCity = citylist.getNodeNum(i); 
        unchosenCities.addCity(currCity);
    } 
    unchosenCities.removeCity(startingCity);
    
    // Populate the citypath object using random selections from the unchosen city list
    while (unchosenCities.getCount() > 0) {
        int unchosen_max = (int)unchosenCities.getCount();
        int currCityPos;
        if (unchosen_max == 1) { 
            currCityPos = 0;
        } else {
            currCityPos = rand() % (unchosen_max - 1);
        }

        if (unchosenCities.getCount() % 20 == 0 && unchosenCities.getCount() < 500) {
            string temp = filename + to_string(unchosenCities.getCount());
            SVGPrinter svg(temp, file_size_x, file_size_y, citypath, citylist);
        }

        // Add the random node to the citypath object
        unsigned int currCity = unchosenCities.getNode(currCityPos);
        citypath.addCity(currCity); 
        unchosenCities.removeCity(currCity);
    } 

    // Make sure to add one additional startingcity node
    citypath.addCity(startingCity);

    // Calculate the distance between each node and find the sum
    double current_distance = 0; 
    for (int i = 0; i < (int)citypath.getCount() - 1; i++) {
        unsigned int currCity = citypath.getNode(i);
        unsigned int nextCity = citypath.getNode(i + 1);

        int currCityPos = citylist.calcArrayNum(currCity);
        int nextCityPos = citylist.calcArrayNum(nextCity);
        cout << "Solve Randomly: Calculating distance between nodes: " << currCity << " and " << nextCity << endl;
        double val = citylist.distance(currCityPos, nextCityPos);
        current_distance += val;
    } 

    // Create SVG
    SVGPrinter svg(filename, file_size_x, file_size_y, citypath, citylist);

    return current_distance;

}

// Create a highly accurate solution using greedy algorithms
double TspSolver::SolveGreedy(CityList& citylist, CityPath& citypath, const string& filepath) { 

    // Declare variables for SVG files
    string filename = "./output_images/greedy/" + filepath + "img.svg";
    const int file_size_x = 500;
    const int file_size_y = 500; 

    // Find a random starting city
    int max = (int)citylist.getCount(); 
    int startingCityPos = rand() % (max - 1);
    unsigned int startingCity = citylist.getNodeNum(startingCityPos);
    citypath.addCity(startingCity);

    // Populate the unchosen city object
    CityPath unchosenCities;
    unsigned int currCity;
    for (int i = 0; i < max; i++) {
        currCity = citylist.getNodeNum(i); 
        unchosenCities.addCity(currCity);
    } 

    // (Don't remove the startingCity from unchosenCities; we do that later) 
    currCity = startingCity; 
    int currCityPos = startingCityPos;

    // Calculate each nearest city value
    while (unchosenCities.getCount() > 0) {

        // if (unchosenCities.getCount() % 5 == 0) {
            // string temp = filename + to_string(unchosenCities.getCount());
            // SVGPrinter svg(temp, file_size_x, file_size_y, citypath, citylist);
        // }

        int unchosen_max = (int)unchosenCities.getCount();
        if (unchosen_max != 1) { 

            // While there are still more than one city in the chosen cities list
            // Iterate through each city pair and calculate the shortest route for each
            double dist1 = 1000000000000;
            size_t p = 0;

            // Get the array value of the current city
            currCityPos = citylist.calcArrayNum(currCity);
            for (int i = 0; i < unchosen_max; i++) {
                // currcity is already here
                // Capture the next node to test the distance
                unsigned int nextCity = unchosenCities.getNode(i);

                // Get the array value of the next city to test
                int nextCityPos = citylist.calcArrayNum(nextCity);
                cout << "Solve Greedy: Calculating distance between nodes: " << currCity << " and " << nextCity << endl; 

                // Calculate the distance between current and next city positions
                double val = citylist.distance(currCityPos, nextCityPos);
                // if this value is less than the current lowest value, switch the target
                if (val < dist1) {
                    dist1 = val;
                    p = i;
                }
            }

            // Take the lowest captured city node
            currCity = unchosenCities.getNode(p); 
            // Add the target currCity to the citypath list
            citypath.addCity(currCity); 
            // Remove the currCity from the unchosen cities
            unchosenCities.removeCity(currCity); 
        } else {
            currCity = unchosenCities.getNode(0);
            citypath.addCity(currCity);
            unchosenCities.removeCity(currCity); 
        }
    } 

    // Add the final reciprocal city to the list
    citypath.addCity(startingCity);

    // Calculate the total distance of the list
    double current_distance = 0; 
    for (int i = 0; i < (int)citypath.getCount() - 1; i++) {
        currCity = citypath.getNode(i);
        unsigned int nextCity = citypath.getNode(i + 1);

        currCityPos = citylist.calcArrayNum(currCity);
        int nextCityPos = citylist.calcArrayNum(nextCity);
        cout << "Solve Greedy: Calculating distance between nodes: " << currCity << " and " << nextCity << endl;
        double val = citylist.distance(currCityPos, nextCityPos);
        current_distance += val;
    }

    // Create SVG
    SVGPrinter svg(filename, file_size_x, file_size_y, citypath, citylist);

    return current_distance;
}

// Solve TSP using my way
double TspSolver::SolveMyWay(CityList& citylist, CityPath& citypath, const string& filepath) {

    // Declare SVG variables
    string filename = "./output_images/my_way/" + filepath + "img.svg";
    const int file_size_x = 500;
    const int file_size_y = 500; 

    // Choose random starting city
    int max = (int)citylist.getCount(); 
    int startingCityPos = rand() % (max - 1);
    unsigned int startingCity = citylist.getNodeNum(startingCityPos);
    citypath.addCity(startingCity);

    // Populate unchosen cities list
    CityPath unchosenCities;
    for (int i = 0; i < max; i++) {
        unsigned int currCity = citylist.getNodeNum(i); 
        unchosenCities.addCity(currCity);
    } 
    unchosenCities.removeCity(startingCity);

    // Calculate somewhat optimized random chosen path list
    while (unchosenCities.getCount() > 0) {
        int unchosen_max = (int)unchosenCities.getCount();
        int p = 0;
        if (unchosen_max != 1) { 
            // if (unchosenCities.getCount() % 5 == 0) {
                // string temp = filename + to_string(unchosenCities.getCount());
                // SVGPrinter svg(temp, file_size_x, file_size_y, citypath, citylist);
            // }

            // From 5 random cities, pick the lowest distance and only add that one as the next city
            double val = 1000000000000.0;
            for (int i = 0; i < 15; i++) {
                int nextCityPosRandom = rand() % (unchosen_max - 1);
                unsigned int prevCity = citypath.getNode(citypath.getCount() - 1);
                unsigned int nextCity = unchosenCities.getNode(nextCityPosRandom); 
                int prevCityPos = citylist.calcArrayNum(prevCity);
                int nextCityPos = citylist.calcArrayNum(nextCity);
                cout << "Solve My Way: Calculating distance between nodes: " << prevCity << " and " << nextCity << endl; 
                double curr_val = citylist.distance(prevCityPos, nextCityPos);
                if (val > curr_val) {
                    val = curr_val;
                    p = nextCityPos;
                }
            }
        }

        unsigned int nextCity = citylist.getNodeNum(p);
        citypath.addCity(nextCity); 
        unchosenCities.removeCity(nextCity);
    } 

    citypath.addCity(startingCity);

    double current_distance = 0;

    for (int i = 0; i < (int)citypath.getCount() - 1; i++) {
        unsigned int currCity = citypath.getNode(i);
        unsigned int nextCity = citypath.getNode(i + 1);

        int currCityPos = citylist.calcArrayNum(currCity);
        int nextCityPos = citylist.calcArrayNum(nextCity);
        cout << "Solve My Way: Calculating distance between nodes: " << currCity << " and " << nextCity << endl;
        double val = citylist.distance(currCityPos, nextCityPos);
        current_distance += val;
    }

    // Create SVG
    SVGPrinter svg(filename, file_size_x, file_size_y, citypath, citylist);

    return current_distance;

}

