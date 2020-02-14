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
using std::getline;
using std::istringstream;

int main(int argc, char* argv[])
{
//     Cave cave;
// 
//     istream default_cave(cave.createDefaultCave());
//     cave.readRooms(istream);
// 
// 
//     while (true) {
//         cout << "Current Room: " << cave.currentRoom << endl;
//         if (cave.caveRooms.at(currentRoom)->visited) {
//             cout << cave.caveRooms.at(currentRoom)->shortdesc << endl;
//         } else {
//             cout << cave.caveRooms.at(currentRoom)->longdesc << endl;
//         }
//         cout << "Adjacent Rooms: " << endl;
//         for (int i = 0; i < 3; i++) {
//             cout << cave.caveRooms.at(cave.currentRoom)->rooms[i]->id << " ";
//             cout << cave.caveRooms.at(cave.currentRoom)->rooms[i]->shortdesc << endl;
//         }
//         int userInput;
//         capture_user_input(userInput);
//         
//         gotoAdjacentRoom(userInput);
//     }
// 
//     ofstream fout("save_file.txt");
// 
//     if (!fout || fout.eof()) {
//         cout << "File save failed" << endl;
//         exit(0);
//     }
//     
//     cave.saveRooms(fout);
//     fout.close();
// 
//     Cave newCave;
// 
//     ifstream fin("save_file.txt");
// 
//     if (!fin) {
//         cout << "Opening file failed" << endl;
//         exit(0);
//     }
// 
//     newCave.readRooms(fin);
// 
//     cout << "First cave room id: " << newCave.caveRooms.at(0)->id << endl;
// 
	return 0;
}


