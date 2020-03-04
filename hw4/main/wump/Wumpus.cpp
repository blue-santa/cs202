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

using std::string;
using std::weak_ptr;
using std::istringstream;
using std::shared_ptr;
using std::vector;
using std::ostream;
using std::istream;

Wumpus::Wumpus(const int firstRoom):
    _asleep(true),
    _currentRoom(firstRoom) {};

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
