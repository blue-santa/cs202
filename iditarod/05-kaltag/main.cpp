/*
 * main.cpp
 * CS202
 * April 14, 2020
 * Bryan Beus
 * Galena station for Iditarod Challenge
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
#include "CityPath.hpp"
#include "CityList.hpp"
#include "Miscellaneous.hpp"
#include "TspSolver.hpp"

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

    // Parse File
    for (size_t i = 0; i < fileNames.size(); i++) {
    // for (size_t i = 0; i < 1; i++) {
        cout << "Parsing file: " << fileNames.at(i) << endl;
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

    // SolveRandomly() 
    double bestDistanceRandom = 1000000000000; 
    for (size_t i = 0; i < citylist.size(); i++) {
    // for (size_t i = 0; i < 1; i++) {
        CityPath citypath; 
        TspSolver tsp;
        double randomDistance = tsp.SolveRandomly(citylist.at(i), citypath);
        if (bestDistanceRandom > randomDistance) bestDistanceRandom = randomDistance;
    } 
    cout << "Best Distance for SolveRandomly: " << bestDistanceRandom << endl;

    // SolveMyWay() 
    double bestDistanceMyWay = 1000000000000; 
    for (size_t i = 0; i < citylist.size(); i++) {
    // for (size_t i = 0; i < 1; i++) {
        CityPath citypath; 
        TspSolver tsp;
        double MyWayDistance = tsp.SolveMyWay(citylist.at(i), citypath);
        if (bestDistanceMyWay > MyWayDistance) bestDistanceMyWay = MyWayDistance;
    } 
    cout << "Best Distance for SolveMyWay: " << bestDistanceMyWay << endl;

    // SolveGreedy() 
    // (This is too long to actually complete!
    double bestDistanceGreedy = 1000000000000; 
    for (size_t i = 0; i < citylist.size(); i++) {
    // for (size_t i = 0; i < 1; i++) {
        CityPath citypath; 
        TspSolver tsp;
        double greedyDistance = tsp.SolveGreedy(citylist.at(i), citypath);
        if (bestDistanceGreedy > greedyDistance) bestDistanceGreedy = greedyDistance;
    } 
    cout << "Best Distance for SolveGreedy: " << bestDistanceGreedy << endl;

    return 0;
}

