/*
 * Pit.cpp
 * CS 202
 * March 3, 2020
 * Bryan Beus
 * Definition file for Pit class
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

#include "Pit.hpp"
#include "Miscellaneous.hpp"

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

// Default Constructor
Pit::Pit(mt19937& e1, const int max_room) {

    mt19937 *_e1 = nullptr;
    _e1 = &e1;

    _room = chooseRandomRoom(_e1, max_room / 2 - 2, max_room / 2 + 2); 

};

// Get Room
int Pit::getRoom() {
    return _room;
};
