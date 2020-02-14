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

using std::istringstream;
using std::string;
using std::to_string;

class Cave {

    public:
        // Return number of rooms in the cave
        bool size() const {
            unsigned int s = caveRooms.size();            
            return (bool)s;
        }

        // Return current room
        int getCurrentRoom() {
            return currentRoom;
        }

        // Go to room in the cave complex
        void gotoRoom(int room) {
            currentRoom = room;
        }

        // Which adjacent room? 0, 1, or 2?
        void gotoAdjacentRoom(int room) {
            int destination = caveRooms.at(currentRoom)->rooms[room]->id;
            currentRoom = destination;
        }

        // Need a vector that has each integer for each room number three times
        // Jumble up the list at random
        // Then, make each weak pointer point to the next item, and pop that item 
        // Connect two rooms together
        void connect(int room1, int room2) {

            std::weak_ptr<CaveNode> room1_ptr = caveRooms.at(room1);
            std::weak_ptr<CaveNode> room2_ptr = caveRooms.at(room2);

            int i;
            while (auto wpt = caveRooms.at(room1)->rooms[i].lock() && i < 3) {
                i++;
            }

            caveRooms.at(room1)[i] = room2_ptr;

            i = 0;
            while (auto wpt = caveRooms.at(room2)->rooms[i].lock() && i < 3) {
                i++;
            }

            caveRooms.at(room2)[i] = room1_ptr;
        }

        // Print the short description of the room
        void printShortDescription(int room) const {
            cout << caveRooms.at(room)->shortdesc << endl;
        }

        //Print the long description of the room
        void printLongDesc(int room) const {
            cout << caveRooms.at(room)->longdesc << endl; 
        }

        // Save rooms to an output stream
        void saveRooms(std::ostream& os) const {
            for (int i = 0; i < caveRooms.size(); i++) {
                os << caveRooms.at(i)->longdesc << "\n";
                os << caveRooms.at(i)->shortdesc << "\n";
                os << caveRooms.at(i)->rooms[0] << "\n";
                os << caveRooms.at(i)->rooms[1] << "\n";
                os << caveRooms.at(i)->rooms[2] << "\n";
            }

        }

        // Read rooms from an input stream
        void readRooms(std::istream& is) { 

            int room_count = 0;
            string s = "";
            while(true) {
                ss >> s;
                room_count++;
            }

            is.seekg(0); 

            int id;
            for (int i = 0; i < room_count; i++) {
                CaveNode nextRoom;

                is >> s; 
                nextRoom.longdesc = s; 
                is >> s; 
                nextRoom.shortdesc = s;

                is >> id; 
                nextRoom.id = id;

                is >> s;
                is >> s;

                std::shared_ptr<CaveNode> nextRoomPtr = make_shared(nextRoom);
                caveRooms.push_back(nextRoomPtr); 
            }

            is.seekg(0);

            int room_s;
            for (int i = 0; i < room_count; i++) {
                is >> s;
                is >> s;
                is >> id;
                for (int j = 0; j < 3; j++) {
                    is >> room_s;
                    caveRooms.at(id)->rooms[j] = room_s;
                } 
            }
            
            for (int i = 0; i < room_count; i++) {
                for (int j = 0; i < 3; j++) {
                    connect(i, caveRooms.at(i)->rooms[j]->id)
                }
            }

            currentRoom = 0;

        }

        string createDefaultCave() {
            int currRoom = 0;
            string res;

            for (int i = 0; i < 18; i++) {
               res += "long description\n";
               res += "short description\n";
               res += to_string(currRoom);
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

    private:
        struct CaveNode {
            std::weak_ptr<CaveNode> rooms[MaxAdjacentRooms];
            std::string shortdesc; 
            std::string longdesc;
            int id;

            CaveNode() {
                for (int i = 0; i < MaxAdjacentRooms; i++) {
                    rooms[i] = nullptr;
                }

            };
        };

        using CaveNodePtr = std::shared_ptr<CaveNode>;

        static constexpr int MaxAdjacentRooms = 3;
        std::vector<CaveNodePtr> caveRooms;
        int currentRoom;


};

#endif


