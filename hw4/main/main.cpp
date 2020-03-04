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
#include <random>
#include <cmath>
#include <stdlib.h>
#include <algorithm>

#include "Miscellaneous.hpp"
#include "Cave.hpp" 
#include "Wumpus.hpp"
#include "Bats.hpp"
#include "Pit.hpp"

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
using std::random_device;
using std::seed_seq;
using std::mt19937;
using std::random_shuffle;

int main(int argc, char* argv[])
{
    // Inform user of the nature of the software
    clearConsole();
    cout << "Welcome to Hunt the Wumpus" << endl;
    cout << "\nInitiate User Destruction" << endl;

    waitForContinue();

	// Create pseudo-random device
	random_device r;
	seed_seq seedObj{r(), r(), r(), r(), r(), r(), r(), r()};
	mt19937 e1(seedObj);

    // Max room; should be higher than at least 10
    int max_room = 18;

    // Declare creature objects
    Wumpus wumpus(e1, max_room);
    Pit pit(e1, max_room);
    Bats bats(e1,max_room);

    // Create initial environment
    clearConsole();
    Cave cave; 

    // Create a string that holds a default cave
    string def_cave = cave.createDefaultCave(max_room);

    // Read in the default cave
    istringstream default_cave(def_cave);
    cave.readRooms(default_cave, max_room);

 
    // Initiate user input while loop
    while (true) {
        clearConsole();

        // Discover current room
        int currentRoom = cave.getCurrentRoom();
        cout << "Current Room: " << currentRoom << endl;

        // TODO: Check if the wumpus is awake
        // If so, move the wumpus and set him to go back to sleep

        // Check for the wumpus
        if (currentRoom == wumpus.getRoom()) {
            cout << "GARMPHHH" << endl;
            cout << "Tasty..." << endl;
            break;
        } else if (currentRoom == pit.getRoom()) {
            // Check for the pit
            cout << "AAARRRGHGGHHHHHhhhhhhhhrrrmmm..........." << endl;
            cout << "... *splat*" << endl;
            break;
        } else if (currentRoom == bats.getRoom()) {
            // Check for bats
            cout << "Wheeeeee!" << endl;
            waitForContinue();
            mt19937 *_e1 = nullptr;
            _e1 = &e1;
            int randomRoom = chooseRandomRoom(_e1, 0, max_room - 1);
            cave.gotoRoom(randomRoom);
            continue;
        }

        // Discover adjacent rooms
        vector<int> adjacent_rooms = cave.getAdjacentRooms(currentRoom);

        // Discover potential dangers
        vector<string> warnings;
        for (int i = 0; i < 3; i++) {
            if (adjacent_rooms.at(i) == wumpus.getRoom()) {
                warnings.push_back("I smell a wumpus");
            }

            if (adjacent_rooms.at(i) == bats.getRoom()) {
                warnings.push_back("I hear a bat");
            }

            if (adjacent_rooms.at(i) == pit.getRoom()) {
                warnings.push_back("I feel a breeze");
            }
        }

        // Scramble warnings
        random_shuffle(warnings.begin(), warnings.end());
        for (size_t i = 0; i < warnings.size(); i++) {
            cout << warnings.at(i) << endl;
        }

        cout << endl;

        cout << "Adjacent Rooms: " << endl;

        // Present user with description of adjacent rooms and choices
        for (int i = 0; i < 3; i++) {
            cout << "Choice ";
           
            switch (i) {
                case 0: 
                    cout << "A";
                    break;
                case 1:
                    cout << "B";
                    break;
                case 2:
                    cout << "C";
                    break;
                default:
                    cout << "X";
                    break;
            }
           
            cout << ") ";
            cave.printShortDescription(adjacent_rooms.at(i));
            cout << endl;
        }

        // Capture user input
        int userInput;
        capture_user_input(userInput);

        // If indicated, shoot arrows or quit
        if (userInput == 3) {
            // TODO: check if bats are in an adjacent room
            // If they are, then remove them
            // And set the wumpus to move
        } else if (userInput == 4) {
            cout << "Weakling" << endl;
            break;
        } else { 

        // Proceed to adjacent room
        cave.gotoAdjacentRoom(adjacent_rooms.at(userInput));
        }
    }

    return 0;
}


