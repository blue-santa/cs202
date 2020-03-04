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

using std::string;
using std::weak_ptr;
using std::istringstream;
using std::shared_ptr;
using std::vector;
using std::ostream;
using std::istream;

class Wumpus {

    public:
        Wumpus(const int firstRoom):
            _asleep(true),
            _currentRoom(firstRoom);

        // Get Current Room
        int getCurrentRoom();

        // Change to an adjacent room
        void moveToRoom(const int room);

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
