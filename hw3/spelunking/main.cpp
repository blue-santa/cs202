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

    // Declare new cave
    Cave cave;

    // Create a string that holds a default cave
    string def_cave = cave.createDefaultCave();

    // Read in the default cave
    istringstream default_cave(def_cave);
    cave.readRooms(default_cave);

 
    // Initiate user input while loop
    while (true) {
        clearConsole();

        // Discover current room
        int currentRoom = cave.getCurrentRoom();
        cout << "Current Room: " << currentRoom << endl;

        // Print the long or short description of the current cave
        if (cave.getVisited(currentRoom)) {
            cave.printShortDescription(currentRoom);
        } else {
            cave.printLongDesc(currentRoom);
        }

        // Discover adjacent rooms
        vector<int> adjacent_rooms = cave.getAdjacentRooms(currentRoom);
        cout << "Adjacent Rooms: " << endl;

        // Present user with description of adjacent rooms and choices
        for (int i = 0; i < 3; i++) {
            cout << "Choice " << i << ") ";
            cave.printShortDescription(adjacent_rooms.at(i));
            cout << endl;
        }

        // Caputre user input
        int userInput;
        capture_user_input(userInput);

        // Quit if user has indicated
        if (userInput == 3) {
            cave.printLongDesc(currentRoom);
        } else if (userInput == 4) {
            break;
        } else { 
        // Proceed to adjacent room
        cave.gotoAdjacentRoom(adjacent_rooms.at(userInput));
        }
    }

    // Save default cave to file (for proof-of-concept)
    ofstream fout("save_file.txt");

    if (!fout) {
        cout << "File save failed" << endl;
        exit(0);
    }
    
    cave.saveRooms(fout);
    fout.close();

    // Read in the saved file, to demonstrate proof of concept
    Cave newCave;

    ifstream fin("save_file.txt");

    if (!fin) {
        cout << "Opening file failed" << endl;
        exit(0);
    }

    newCave.readRooms(fin);

    // Pring short descriptions to prove functionality
    for (int i = 0; i < 18; i++) {
        cave.printShortDescription(i);
    }

    return 0;
}


