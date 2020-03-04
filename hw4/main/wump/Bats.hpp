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

using std::string;
using std::weak_ptr;
using std::istringstream;
using std::shared_ptr;
using std::vector;
using std::ostream;
using std::istream;

class Bats {

    public:
        // Default Constructor
        Bats(const int room):
            _room(room);

        // Get Room
        int getRoom();

    private:
        // Room
        int _room;
};

#endif 
