/*
 * main.cpp
 * CS 202
 * February 11, 2020
 * Bryan Beus
 * Main file for spelunking project hw2
 */

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <list>
#include <iterator>
#include <memory>
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
     Cave cave;
     string def_cave = cave.createDefaultCave();
 
     istringstream default_cave(def_cave);
     cave.readRooms(default_cave);
 
 
    while (true) {
        clearConsole();
        int currentRoom = cave.getCurrentRoom();
        cout << "Current Room: " << currentRoom << endl;
        if (cave.getVisited(currentRoom)) {
            cave.printShortDescription(currentRoom);
        } else {
            cave.printLongDesc(currentRoom);
        }

        vector<int> adjacent_rooms = cave.getAdjacentRooms(currentRoom);
        cout << "Adjacent Rooms: " << endl;
        for (int i = 0; i < 3; i++) {
            cout << "Choice " << i << ") ";
            cave.printShortDescription(adjacent_rooms.at(i));
            cout << endl;
        }
        int userInput;
        capture_user_input(userInput);
        
        cave.gotoAdjacentRoom(adjacent_rooms.at(userInput));
    }

    // ofstream fout("save_file.txt");

    // if (!fout || fout.eof()) {
        // cout << "File save failed" << endl;
        // exit(0);
    // }
    
    // cave.saveRooms(fout);
    // fout.close();

    // Cave newCave;

    // ifstream fin("save_file.txt");

    // if (!fin) {
        // cout << "Opening file failed" << endl;
        // exit(0);
    // }

    // newCave.readRooms(fin);

    // cout << "First cave room id: " << newCave.caveRooms.at(0)->id << endl;

    return 0;
}


