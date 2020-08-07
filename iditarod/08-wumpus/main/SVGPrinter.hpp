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

#include "Cave.hpp"
#include "Bats.hpp"
#include "Wumpus.hpp"
#include "Pit.hpp"
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
        SVGPrinter(const string& filename, const int& file_size_x, const int& file_size_y, const Cave& cave, const Bats& bats, const Pit& pit, const Wumpus& wumpus);

        ~SVGPrinter();

        // Store an SVG for later printing
        void addNode(ofstream& fout1, ofstream& fout2, CityList& citylist, const int& fir, const int& las, bool& is_first);

        // Continue the path
        void continuePath(ofstream& fout, const double& x, const double& y, bool& is_first) const;

        // Store an SVG for later printing
        void printSVG();

        // Clear SVG
        void flushSVG();

        // Add circle
        void addCircle(ofstream& fout, const double& x1, const double& x2) const;

        // Initiate SVG
        void initiateSVG(ofstream& fout1, ofstream& fout2, const string& filename, const int& file_size_x, const int& file_size_y);

        // Conclude SVG
        void concludeSVG(ofstream& fout1);

        // Set SVG Filename
        void setFilename(const string& filename, const int& file_size_x_, const int& file_size_y_);

    private:
        string filename_;
        vector<CityNode> SVGlist_; 
        int file_size_x_;
        int file_size_y_;


};

#endif
