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
#include <vector>
#include <sstream>

#include "Cave.hpp"
#include "Miscellaneous.hpp"

#define DEFAULT_CAVE_ROOM_SIZE 18

using std::istringstream;
using std::string;
using std::to_string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::shared_ptr;
using std::make_shared;
using std::getline;

// Return number of rooms in the cave
bool Cave::size() const {
    unsigned int s = caveRooms.size();            
    return (bool)s;
}

// Return current room
int Cave::getCurrentRoom() {
    return currentRoom;
}

// Get current visited state
bool Cave::getVisited(const int &currRoom) {
    return caveRooms.at(currRoom)->visited;
}

// Go to room in the cave complex
void Cave::gotoRoom(int room) {
    currentRoom = room;
}

// Which adjacent room? 0, 1, or 2?
void Cave::gotoAdjacentRoom(int room) {
    int destination = room;
    caveRooms.at(currentRoom)->visited = true;
    gotoRoom(destination);
}

// Connect two rooms together
void Cave::connect(int room1, int room2) {

    std::weak_ptr<CaveNode> room2_ptr = caveRooms.at(room2);

    for (int i = 0; i < 3; i++) {
        if (caveRooms.at(room1)->rooms[i].expired()) {
            caveRooms.at(room1)->rooms[i] = room2_ptr;
            break;
        } 
    } 
}

// Print the short description of the room
void Cave::printShortDescription(int room) const {
    cout << caveRooms.at(room)->shortdesc << " for room id " << caveRooms.at(room)->id << endl;
}

//Print the long description of the room
void Cave::printLongDesc(int room) const {
    cout << caveRooms.at(room)->longdesc << " for room id " << caveRooms.at(room)->id << endl; 
}

// Save rooms to an output stream
void Cave::saveRooms(std::ostream& os) const {
    for (unsigned int i = 0; i < caveRooms.size(); i++) {
        os << caveRooms.at(i)->longdesc << "\n";
        os << caveRooms.at(i)->shortdesc << "\n";
        os << caveRooms.at(i)->id << "\n";
        for (int j = 0; j < 3; j++) {
            if (auto wp = caveRooms.at(i)->rooms[j].lock()) {
                int tempAdjRoomId = wp->id;
                os << tempAdjRoomId << "\n";
            } else {
                cout << "File save failed" << endl;
                exit(0);
            }
        }
    }

}

// Read rooms from an input stream
void Cave::readRooms(std::istream& is) {

    int room_count = DEFAULT_CAVE_ROOM_SIZE;
    vector<int> room_connections;

    for (int i = 0; i < room_count; i++) {
        bool visited = false;
        string long_desc;
        string short_desc;
        int id;
        getline(is, long_desc);
        getline(is, short_desc);
        string tempId;
        getline(is, tempId);
        id = stoi(tempId);
        for (int j = 0; j < 3; j++) {
            int tempR = 0;
            getline(is, tempId);
            tempR = stoi(tempId);
            room_connections.push_back(tempR);
        }

        Cave::CaveNode nextRoom(visited, long_desc, short_desc, id);

        shared_ptr<CaveNode> nextRoomPtr = make_shared<CaveNode>(nextRoom);
        caveRooms.push_back(nextRoomPtr); 
    }

    // Something happening to room connections in here
    int counter = 0;
    for (int i = 0; i < room_count; i++) {
        for (int j = 0; j < 3; j++) {
            cout << "Connecting room: " << i << " with room: " << room_connections.at(counter) << endl;
            connect(i, room_connections.at(counter));
            counter++;
        }
    }
    currentRoom = 0; 
}

vector<int> Cave::getAdjacentRooms(int &current_room) { 
    vector<int> res;
    for (int i = 0; i < 3; i++) {
        if (auto wp = caveRooms.at(current_room)->rooms[i].lock()) {
            res.push_back(wp->id);
        }
    } 
    return res;
}


string Cave::createDefaultCave() {
    string res = "";

    for (int i = 0; i < DEFAULT_CAVE_ROOM_SIZE; i++) {
       res += "long description\n";
       res += "short description\n";
       res += to_string(i);
       res += "\n";

       switch (i) {
           case 0:
               res += "1\n2\n3\n";
               break;
           case 1:
               res += "0\n2\n3\n";
               break;
           case 2:
               res += "1\n3\n4\n";
               break;
           case 15:
               res += "14\n16\n17\n";
               break;
           case 16:
               res += "14\n15\n17\n";
               break;
           case 17:
               res += "14\n15\n16\n";
               break;
           default:
               res += to_string(i - 1);
               res += "\n";
               res += to_string(i + 1);
               res += "\n";
               res += to_string(i + 2);
               res += "\n";
               break; 
       } 
    } 

    return res;
}

Cave::CaveNode::CaveNode(bool& visited_given, string& long_desc, string& short_desc, int& id_given) {
    visited = visited_given;
    longdesc = long_desc;
    shortdesc = short_desc;
    id = id_given; 
};
