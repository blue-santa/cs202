/*
 * main.cpp
 * CS 202
 * February 11, 2020
 * Bryan Beus
 * Main file for lab Supplemental
 */

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <stdexcept>
#include <stdio.h>
#include <stdlib.h>

#define CATCH_CONFIG_MAIN

#include "Catch.hpp"
#include "header.hpp"

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::getline;
using std::left;
using std::size_t;
using std::stod;
using std::cerr;

unsigned int Factorial(unsigned int number) {
    return number <= 1 ? number : Factorial(number - 1) * number;
}

TEST_CASE( "Factorials are computed", "[factorial]" ) {
    REQUIRE( Factorial(1) == 1 );
    REQUIRE( Factorial(2) == 2 );
    REQUIRE( Factorial(3) == 6 );
    REQUIRE( Factorial(10) == 3628800 );
}

Vector3f vecA;
Vector3f vecB(1, 2, 3);

TEST_CASE( "Vector3f constructs properly", "[vector]" ) {
    REQUIRE( vecA.x == 0 );
    REQUIRE( vecA.y == 0 );
    REQUIRE( vecA.z == 0 );
    REQUIRE( vecB.x == 1 );
    REQUIRE( vecB.y == 2 );
    REQUIRE( vecB.z == 3 );
}

