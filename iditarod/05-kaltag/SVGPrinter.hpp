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
        SVGPrinter(const string& filename, const int& file_size_x, const int& file_size_y, const CityPath& citypath, CityList& citylist);

        ~SVGPrinter();

        // Store an SVG for later printing
        void addNode(ofstream& fout, CityList& citylist, const int& fir, const int& las);

        // Store an SVG for later printing
        void printSVG();

        // Clear SVG
        void flushSVG();

        // Add circle
        void addCircle(ofstream& fout, const double& x1, const double& x2) const;

        // Initiate SVG
        void initiateSVG(ofstream& fout, const string& filename, const int& file_size_x, const int& file_size_y);

        // Set SVG Filename
        void setFilename(const string& filename, const int& file_size_x_, const int& file_size_y_);

    private:
        string filename_;
        vector<CityNode> SVGlist_; 
        int file_size_x_;
        int file_size_y_;


};

#endif
