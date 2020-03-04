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

using std::string;
using std::weak_ptr;
using std::istringstream;
using std::shared_ptr;
using std::vector;
using std::ostream;
using std::istream;

// Default Constructor
Bats::Bats(const int room):
    _room(room) {};

// Get Room
int Bats::getRoom() {
    return _room;
};
