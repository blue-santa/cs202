/*
 * Bats.cpp
 * CS 202
 * March 3, 2020
 * Bryan Beus
 * Definition file for Bats class
 */

#include <string>
#include <fstream>
#include <stdlib.h>
#include <memory>
#include <vector>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <stdlib.h>
#include <random>

#include "Bats.hpp"
#include "Miscellaneous.hpp"

using std::string;
using std::weak_ptr;
using std::istringstream;
using std::shared_ptr;
using std::vector;
using std::ostream;
using std::istream;
using std::mt19937;
using std::random_device;
using std::seed_seq;

// Default Constructor
Bats::Bats(mt19937& e1, const int max_room) {
    mt19937 *_e1 = nullptr;

    _e1 = &e1;

    _room = chooseRandomRoom(_e1, max_room / 2 + 3, max_room / 2 + 5);

};

// Get Room
int Bats::getRoom() {
    return _room;
};

// Remove Bats
void Bats::removeBats() {
    _room = -1;
}
