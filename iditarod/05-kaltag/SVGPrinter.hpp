/*
 * SVGPrinter.hpp
 * CS 202
 * April 21, 2020
 * Bryan Beus
 * Declaration file for SVGPrinter content
 */

#ifndef __SVGPRINTER_HPP__
#define __SVGPRINTER_HPP__ 

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
#include "TspSolver.hpp"
#include "Takotna.hpp"
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

// SVGPrinter class
class SVGPrinter {
    public:
        // Default constructor
        SVGPrinter();
        ~SVGPrinter();

        // Store an SVG for later printing
        void addNode(const CityList& citylist, const int& fir, const int& las) const;

        // Store an SVG for later printing
        void printSVG();

        // Clear SVG
        void flushSVG();

        // Initiate SVG
        void initiateSVG(const string& filename);

        // Set SVG Filename
        void setFilename(const string& filename);

    private:
        string filename_;
        vector<CityNode> SVGlist_; 

};

#endif
