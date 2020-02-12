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
#include <math.h>

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
Vector3f vecC(vecB);

Vector3f vecD = vecB.add(vecC);
Vector3f vecE = vecB.sub(vecD);
Vector3f vecF = vecB.scale(10);
Vector3f vecG = vecF.negate();

float a = 5.0f;
float b = 6.0f;
float c = 7.0f;
float d = 8.0f;
float e = 9.0f;
float f = 4.0f;

float resBE = (a * d + b * e + c * f);
Vector3f vecH(a,b,c);
Vector3f vecI(d,e,f); 
float resHI = vecH.dot(vecI);

Vector3f vecJ(b * f - c * e, c * d - a * f, a * e - b * d);

float sqr = sqrt(a * a + b * b + c * c);
Vector3f vecK(a / sqr, b / sqr, c / sqr);

Vector3f vecL = vecH.scale(10);

TEST_CASE( "Vector3f constructs properly", "[vector]" ) {
    REQUIRE( vecA.x == 0 );
    REQUIRE( vecA.y == 0 );
    REQUIRE( vecA.z == 0 );
    REQUIRE( vecB.x == 1 );
    REQUIRE( vecB.y == 2 );
    REQUIRE( vecB.z == 3 );
    REQUIRE( vecC.x == 1 );
    REQUIRE( vecC.y == 2 );
    REQUIRE( vecC.z == 3 );
    REQUIRE( vecB == vecC );
    REQUIRE( vecB != vecA );
    REQUIRE( vecD.x == 2 );
    REQUIRE( vecD.y == 4 );
    REQUIRE( vecD.z == 6 );
    REQUIRE( vecE.x == -1 );
    REQUIRE( vecE.y == -2 );
    REQUIRE( vecE.z == -3 );
    REQUIRE( vecF.x == 10 );
    REQUIRE( vecF.y == 20 );
    REQUIRE( vecF.z == 30 );
    REQUIRE( vecG.x == -10 );
    REQUIRE( vecG.y == -20 );
    REQUIRE( vecG.z == -30 );
    REQUIRE( resHI == resBE );
    REQUIRE( vecH.cross(vecI) == vecJ );
    REQUIRE( vecH.length() == sqr );
//    REQUIRE( vecH.unit() == vecK );
}

