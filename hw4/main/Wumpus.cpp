/*
 * Wumpus.cpp
 * CS 202
 * March 3, 2020
 * Bryan Beus
 * Definition file for Wumpus class
 */

#include <string>
#include <fstream>
#include <stdlib.h>
#include <memory>
#include <vector>
#include <sstream>
#include <fstream>
#include <random>
#include <cmath>
#include <stdlib.h> 

#include "Miscellaneous.hpp"
#include "Cave.hpp"
#include "Wumpus.hpp"
#include "Bats.hpp"
#include "Pit.hpp"

using std::string;
using std::weak_ptr;
using std::istringstream;
using std::shared_ptr;
using std::vector;
using std::ostream;
using std::istream;
using std::random_device;
using std::seed_seq;
using std::mt19937;

// Default wumpus constructor
Wumpus::Wumpus(mt19937& e1, const int max_room):
    _asleep(true) {

    // Pass random device as a pointer
    mt19937 *_e1 = nullptr;
    _e1 = &e1;

    // Set current room to room in provided range
    _currentRoom = chooseRandomRoom(_e1, max_room - 3, max_room - 1); 
};

// Get Current Room
int Wumpus::getRoom() {
    return _currentRoom;
};

// Change to an adjacent room
void Wumpus::moveToAdjacentRoom(Pit& pit, const int max_room, mt19937& e1) {
    int upper_limit;

    // The upper and lower limits are designed to push the wumpus towards the pit, but no further
    if (_currentRoom == max_room) {
        upper_limit = max_room;
    } else {
        upper_limit = _currentRoom + 1;
    }

    int lower_limit;
    if (pit.getRoom() == _currentRoom - 1 || pit.getRoom() == _currentRoom - 2 ) {
        lower_limit = pit.getRoom() + 1;
    } else {
        lower_limit = _currentRoom - 2;
    }

    mt19937 *_e1 = nullptr;
    _e1 = &e1;

    _currentRoom = chooseRandomRoom(_e1, lower_limit, upper_limit);

};

// Switch asleep status
void Wumpus::switchStatus() {
    _asleep = !_asleep;
};

bool Wumpus::getStatus() {
    return _asleep;
}
