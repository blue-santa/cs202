/*
 * SVGPrinter.cpp
 * CS 202
 * April 21, 2020
 * Bryan Beus
 * Definition file for SVGPrinter content
 */

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
#include "SVGPrinter.hpp"
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

// Default constructor
SVGPrinter::SVGPrinter() { }
SVGPrinter::~SVGPrinter() { }

// Store an SVG for later printing
void SVGPrinter::addNode(const CityList& citylist, const int& fir, const int& las) const {

}

// Store an SVG for later printing
void SVGPrinter::initiateSVG(const string& filename) {

    this->setFilename(filename);

    if (filename_ == "") {
        cout << "filename_ not set" << endl;
        exit(0);
    }

    ofstream fout(filename_, std::ios::binary);

    if (!fout) {
        cout << "Error creating output SVG file";
        exit(0);
    }
    
    string initFile = "";
    initFile += "<svg version=\"1.1\"\n";
    initFile += "   baseProfile=\"full\"\n";
    initFile += "   width=\"500\" height=\"500\"\n";
    initFile += "   xmlns=\"http://www.w3.org/2000/svg\">\n";
    initFile += "<rect width=\"100%\" height=\"100%\" fill=\"white\" />\n";
    // initFile += "<circle cx=\"150\" cy=\"100\" r=\"80\" fill=\"green\" />\n";
    initFile += "</svg>\n";
    cout << initFile;
    fout << initFile << endl;


    // if (fin.eof()) {
        // cout << "End of data file" << endl;
        // return 0;
    // }

    // fin.seekg(0, std::ios_base::end);

    // int sum = 0;
    // int count = 0;
    // int random = fin.tellg();
    // count = fin.tellg()/sizeof(int);
    // int read = 0;
    // vector<int> holder;

    // fin.seekg(0, std::ios_base::beg);

    // for (int i = 0; i < count; i++) {
        // fin.read(reinterpret_cast<char*>(&read), sizeof(read));
        // cout << read << " ";
        // holder.push_back(read);
        // sum+=holder[i];
    // }

    // cout << endl;

    // cout << count << " integers\nTotal: " << sum << "\nAverage: " << (float)sum/((float)count) << endl;
}

// Clear SVG
void SVGPrinter::flushSVG() {
}

// Set SVG Filename
void SVGPrinter::setFilename(const string& filename) {
    filename_ = filename;
}
