/*
 * Cave.hpp
 * CS 202
 * February 11, 2020
 * Bryan Beus
 * Header file for Cave class for spelunking in hw2
 */

#ifndef __CAVE_HPP_
#define __CAVE_HPP_

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

class Cave {

    public:
        // Return number of rooms in the cave
        bool size() const;

        // Return current room
        int getCurrentRoom();

        // Get visited state
        bool getVisited(const int &currRoom);

        // Go to room in the cave complex
        void gotoRoom(int room);

        // Which adjacent room? 0, 1, or 2?
        void gotoAdjacentRoom(int room);

        // Connect two rooms together
        void connect(int room1, int room2);

        // Print the short description of the room
        void printShortDescription(int room) const;

        //Print the long description of the room
        void printLongDesc(int room) const;

        // Save rooms to an output stream
        void saveRooms(ostream& os) const;

        // Read rooms from an input stream
        void readRooms(istream& is);

        // Discover adjacent rooms
        vector<int> getAdjacentRooms(int &current_room);

        // Create a default cave
        string createDefaultCave(const int max_room);

    private:
        // Setting for maximum number of adjacent rooms
        static constexpr int MaxAdjacentRooms = 3;

        // A node in the cave
        struct CaveNode {
            weak_ptr<CaveNode> rooms[MaxAdjacentRooms]; 
            string shortdesc;
            string longdesc;
            int id;
            bool visited;

            // Proper constructor for cave node
            CaveNode(bool& visited_given, string& long_desc, string& short_desc, int& id_given);
        };

        using CaveNodePtr = shared_ptr<CaveNode>;

        vector<CaveNodePtr> caveRooms;
        int currentRoom; 
};

#endif 
