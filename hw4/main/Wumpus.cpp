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

Wumpus::Wumpus(mt19937& e1, const int max_room):
    _asleep(true) {

    _e1 = nullptr;
    _e1 = &e1;

    _currentRoom = chooseRandomRoom(_e1, max_room - 3, max_room); 
};

// Get Current Room
int Wumpus::getCurrentRoom() {
    return _currentRoom;
};

// Change to an adjacent room
void Wumpus::moveToRoom(const int room) {
    _currentRoom = room;
};

// Switch asleep status
void Wumpus::switchStatus() {
    _asleep = !_asleep;
};

private:
// Whether the Wumpus is asleep
// If false, the Wumpus moves on the next turn
bool _asleep;
};

#endif 
