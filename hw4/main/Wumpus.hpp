/*
 * Wumpus.hpp
 * CS 202
 * March 3, 2020
 * Bryan Beus
 * Header file for Wumpus class
 */

#ifndef __WUMPUS_HPP_
#define __WUMPUS_HPP_

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

// Wumpus class
class Wumpus {

    public:
        // Default constructor
        Wumpus(mt19937& e1, const int max_room);

        // Get Current Room
        int getRoom();

        // Get Status
        bool getStatus();

        // Change to an adjacent room
        void moveToAdjacentRoom(Pit& pit, const int max_room, mt19937& _e1);

        // Switch asleep status
        void switchStatus();

    private:
        // Whether the Wumpus is asleep
        // If false, the Wumpus moves on the next turn
        bool _asleep;

        // Current Room
        int _currentRoom;
};

#endif 
