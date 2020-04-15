/*
 * Takotna.cpp
 * CS 202
 * April 14, 2020
 * Bryan Beus
 * Definition file for Takotna content
 */

#include <iomanip>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <filesystem>
#include <stdlib.h>

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

void callFileNames(vector<string>& fileNames) { 
    ifstream fin1("./big/list.txt");

    if (!fin1) {
        cout << "Error loading list.txt" << endl;
        exit(0);
    }

    while (true) {

        string line;
        getline(fin1, line);

        if (fin1.eof()) {
            break;
        }

        fileNames.push_back(line); 

    }
}

