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
using std::to_string;

namespace fs = std::filesystem; 

// Default constructor
SVGPrinter::SVGPrinter(const string& filename, const int& file_size_x, const int& file_size_y, const Cave& cave, const Bats& bats, const Pit& pit, const Wumpus& wumpus) {

    setFilename(filename, file_size_x, file_size_y);

    if (filename_ == "") {
        cout << "filename_ not set" << endl;
        exit(0);
    }

    ofstream fout(filename_, std::ios::binary);

    if (!fout) {
        cout << "Error creating output SVG file" << endl;
        cout << filename_ << endl;
        exit(0);
    }

    initiateSVG(fout, fout2, filename, file_size_x, file_size_y);

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << "Printing SVG node for: " << i << " and " << j << endl;
            drawRoom(fout, i, j);
        }
    } 

    int cave_room = cave.getCurrentRoom();
    int pit_room = pit.getRoom();
    int wumpus_room = wumps.getRoom();
    int bats_room = bats.getRoom();

    concludeSVG(fout);
    fout.close();
}

// Conlude the SVG
void SVGPrinter::concludeSVG(ofstream& fout) {
    string temp_filename = "./temp_path.txt";
    ifstream fin(temp_filename);

    if (!fin) {
        cout << "Error opening temp path file" << endl;
        exit(0);
    }

    string my_path;
    string line;
    while (true) {
        getline(fin, line);

        if (fin.eof()) {
            break;
        }
        
        my_path += line;
    }

    fout.seekp(0, std::ios_base::end);
    long pos = fout.tellp();
    fout.seekp(pos - (8 * sizeof(char))); 

    fout << my_path << endl;
    fout << "</svg>" << endl;
    fs::remove(temp_filename);
}

SVGPrinter::~SVGPrinter() { }

// Add a circle to provided ofstream
void SVGPrinter::drawRoom(ofstream& fout, const int& i, const int& j) const {

    fout.seekp(0, std::ios_base::end);
    long pos = fout.tellp();
    fout.seekp(pos - (8 * sizeof(char))); 

    int total_cols = 4;
    int total_rows = 4;

    int x_pos = (int) x;
    int y_pos = (int) y;

    fout << "<circle cx=\"" << x_pos << "\" cy=\"" << y_pos << "\" r=\"2\" fill=\"green\" />\n" << endl;
    fout << "</svg>" << endl;


}

// Add a path point to provided ofstream
void SVGPrinter::continuePath(ofstream& fout, const double& x, const double& y, bool& is_first) const {

    string ending = " \nZ\" stroke=\"red\" stroke-width=\"1\" fill=\"transparent\"/>";

    fout.seekp(0, std::ios_base::end);
    long pos = fout.tellp();
    fout.seekp(pos - (sizeof(ending) + 23)); 

    int x_pos = (int) x;
    int y_pos = (int) y;

    string l = "L";

    if (is_first) {
        l = "M";
        is_first = false;
    }

    fout << l << " " << x_pos << " " << y_pos << " \n" << ending << endl;


}

// Store an SVG for later printing
void SVGPrinter::addNode(ofstream& fout1, ofstream& fout2, CityList& citylist, const int& fir, const int& las, bool& is_first) {

    // (Don't need first, 'cause we go in a circle around the list
    // const double x1 = citylist.getNodeLon(fir);
    // const double y1 = citylist.getNodeLat(fir); 
    const double las_lon = citylist.getNodeLon(las);
    const double las_lat = citylist.getNodeLat(las);

    // TODO Add draw line
    // addCircle(fout1, x1, y1);

    if (citylist.getMaxLon() == 0) {
        citylist.setMaxMinVals();
    }

    const double x2 = (las_lon / (citylist.getMaxLon() - citylist.getMinLon())) * file_size_x_;
    const double y2 = (las_lat / (citylist.getMaxLat() - citylist.getMinLat())) * file_size_y_;


    addCircle(fout1, x2, y2);
    continuePath(fout2, x2, y2, is_first);

}

// Store an SVG for later printing
void SVGPrinter::initiateSVG(ofstream& fout1, ofstream& fout2, const string& filename, const int& file_size_x, const int& file_size_y) {

    fout1.seekp(0, std::ios_base::beg);
    
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
    fout1 << initFile << endl;
    
    // fout2.seekp(0, std::ios_base::beg); 
    // initFile = "<path d=\" \nZ\" stroke=\"red\" stroke-width=\"1\" fill=\"transparent\"/>";
    // fout2 << initFile << endl; 
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
