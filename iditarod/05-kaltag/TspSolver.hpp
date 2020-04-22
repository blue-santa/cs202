/*
 * TspSolver.hpp
 * CS 202
 * April 14, 2020
 * Bryan Beus
 * Declaration file for TspSolver content
 */

#ifndef __TSPSOLVER_HPP__
#define __TSPSOLVER_HPP__ 

#include <iomanip>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <filesystem>
#include <stdlib.h>

#include "CityNode.hpp"
#include "CityList.hpp"
#include "CityPath.hpp"
#include "Takotna.hpp"
#include "SVGPrinter.hpp"

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

class TspSolver {
    public:

        // Default constructor
        TspSolver() {};
        // Default destructor
        ~TspSolver() {};

        // Create a random solution
        double SolveRandomly(CityList& citylist, CityPath& citypath, const string& filepath);

        // Create a "greedy" (highly accurate) solution
        double SolveGreedy(CityList& citylist, CityPath& citypath, const string& filepath);

        // Create a customized solution
        double SolveMyWay(CityList& citylist, CityPath& citypath, const string& filepath);

    private:
};

#endif
