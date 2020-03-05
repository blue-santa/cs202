/*
 * Bats.hpp
 * CS 202
 * March 3, 2020
 * Bryan Beus
 * Header file for Bats class
 */

#ifndef __BATS_HPP_
#define __BATS_HPP_

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

// Bats class 
class Bats {

    public:
        // Default Constructor
        Bats(mt19937& e1, const int max_room);

        // Get Room
        int getRoom();

        // Remove bats
        void removeBats();

    private:
        // Room
        int _room;
};

#endif 
