/*
 * main.cpp
 * CS 202
 * February 11, 2020
 * Bryan Beus
 * Main file for spelunking project hw2
 */

// #define CATCH_CONFIG_MAIN

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <list>
#include <iterator>
#include <ifstream>
#include <fstream>
#include <sstream>

#include "Miscellaneous.hpp"
#include "Cave.hpp" 

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
using std::list;
using std::right;
using std::ifstream;
using std::ofstream;
using std::istream;

int main(int argc, char* argv[])
{
    Cave cave;

    istream default_cave(cave.createDefaultCave());
    cave.readRooms(istream);
    




	return 0;
}


