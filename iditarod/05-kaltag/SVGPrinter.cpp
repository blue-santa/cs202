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
using std::to_string;

namespace fs = std::filesystem; 

// Default constructor
SVGPrinter::SVGPrinter(const string& filename, const int& file_size_x, const int& file_size_y, const CityPath& citypath, const CityList& citylist) {

    setFilename(filename, file_size_x, file_size_y);

    if (filename_ == "") {
        cout << "filename_ not set" << endl;
        exit(0);
    }

    ofstream fout(filename_, std::ios::binary);

    if (!fout) {
        cout << "Error creating output SVG file";
        exit(0);
    }

    initiateSVG(fout, filename, file_size_x, file_size_y);


    for (int i = 0; i < (int)citypath.getCount() - 1; i++) {
        const unsigned int currCity = citypath.getNode(i);
        const unsigned int nextCity = citypath.getNode(i + 1);

        int currCityPos = citylist.calcArrayNum(currCity);
        int nextCityPos = citylist.calcArrayNum(nextCity);
        cout << "Printing SVG for: " << currCity << " and " << nextCity << endl;
        addNode(fout, citylist, currCityPos, nextCityPos);
    } 
}

SVGPrinter::~SVGPrinter() { }

void SVGPrinter::addCircle(ofstream& fout, const double& x, const double& y) const {

    fout.seekp(0, std::ios_base::end);
    long pos = fout.tellp();
    fout.seekp(pos - (8 * sizeof(char)));

    fout << "<circle cx=\"" << x1 << "\" cy=\"300\" r=\"25\" fill=\"green\" />" << endl;
    fout << "</svg>" << endl;


}

// Store an SVG for later printing
void SVGPrinter::addNode(ofstream& fout, const CityList& citylist, const int& fir, const int& las) const {

    // (Don't need first, 'cause we go in a circle around the list
    // const double x1 = citylist.getNodeLon(fir);
    // const double y1 = citylist.getNodeLat(fir);

    const double x2 = citylist.getNodeLon(las);
    const double y2 = citylist.getNodeLat(las);

    // TODO Add draw line
    addCircle(fout, x1, y1);
    addCircle(fout, x2, y2);

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

}

// Store an SVG for later printing
void SVGPrinter::initiateSVG(ofstream& fout, const string& filename, const int& file_size_x, const int& file_size_y) {

    fout.seekp(0, std::ios_base::beg);
    
    string initFile = "";
    initFile += "<svg version=\"1.1\"\n";
    initFile += "   baseProfile=\"full\"\n";
    initFile += "   width=\"";
    initFile += to_string(file_size_x);
    initFile += "\" height=\"";
    initFile += to_string(file_size_y);
    initFile += "\"\n";
    initFile += "   xmlns=\"http://www.w3.org/2000/svg\">\n";
    initFile += "<rect width=\"100%\" height=\"100%\" fill=\"white\" />\n";
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
void SVGPrinter::setFilename(const string& filename, const int& file_size_x, const int& file_size_y) {
    filename_ = filename;
    file_size_x_ = file_size_x;
    file_size_y_ = file_size_y;
}
