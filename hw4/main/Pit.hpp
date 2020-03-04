/*
 * Pit.hpp
 * CS 202
 * March 3, 2020
 * Bryan Beus
 * Header file for Pit class
 */

#ifndef __PIT_HPP_
#define __PIT_HPP_

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
using std::mt19937;
using std::random_device;
using std::seed_seq;

class Pit {

    public:
        // Default Constructor
        Pit(mt19937& e1, const int max_room);

        // Get Room
        int getRoom();

    private:
        // Room
        int _room;
};

#endif 
