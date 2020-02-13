/*
 * Cave.cpp
 * CS 202
 * February 11, 2020
 * Bryan Beus
 * Definition file for Cave class for spelunking in hw2
 */

#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <memory>

using std::string;

class Cave {

    public:
        // Return number of rooms in the cave
        bool size() const {
            // return caveRooms.size();            
        }

        // Return current room
        int getCurrentRoom() {
            return currentRoom;
        }

        // Go to room in the cave complex
        void gotoRoom(int room) {
            currentRoom = room;
            caveRooms.at(room);
        }

        // Which adjacent room? 0, 1, or 2?
        void gotoAdjacentRoom(int room) {

        }

        // Connect two rooms together
        void connect(int room1, int room2) {

        }

        // Print the short description of the room
        void printShortDescription(int room) const {

        }

        //Print the long description of the room
        void printLongDesc(int room) const {

        }

        // Save rooms to an output stream
        void saveRooms(std::ostream& os) const {

        }

        // Read rooms from an input stream
        void readRooms(std::istream& is) {

        }

    private:
        struct CaveNode {
            std::weak_ptr<CaveNode> rooms[MaxAdjacentRooms];
            std::string shortdesc; // A short description of this room
            std::string longdesc; // A long description of this room

            // Constructor should initialize rooms to nullptr
            CaveNode() {

            };
        };

        using CaveNodePtr = std::shared_ptr<CaveNode>;

        static constexpr int MaxAdjacentRooms = 3;
        std::vector<CaveNodePtr> caveRooms;
        int currentRoom;


};

#endif
