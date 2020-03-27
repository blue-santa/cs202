/*
 * Class.hpp
 * CS 202
 * March 27, 2020
 * Bryan Beus
 * Class declaration file
 */

#include <iostream>
#include <iomanip>
#include <string>

using std::cout;
using std::endl;
using std::string;

#ifndef __CLASS_HPP__
#define __CLASS_HPP__

class Foo { 
    public:
        Foo(string data);

    private:
        string my_data; 

};

#endif
