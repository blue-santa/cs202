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

using std::string;
using std::weak_ptr;
using std::istringstream;
using std::shared_ptr;
using std::vector;
using std::ostream;
using std::istream;

class Pit {

    public:
        // Default Constructor
        Pit(const int room):
            _room(room);

        // Get Room
        int getRoom();

    private:
        // Room
        int _room;
};

#endif 
