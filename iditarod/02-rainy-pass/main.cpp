/*
 * main.cpp
 * CS202
 * April 7, 2020
 * Bryan Beus
 * Rainy Pass station for Iditarod Challenge
 */

#include <iomanip>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>

#include "StopWatch.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::ofstream;

// Calculate Ackerman's value
long long int ack(const long long int& m, const long long int& n) {
    if (m == 0) {
        return n + 1;
    } else if (m > 0 && n == 0) {
        return ack(m - 1, 1);
    } else if (m > 0 && n > 0) { 
        return ack(m - 1, ack(m, n - 1));
    } else {
        return 0;
    } 
}

int main() {

    // Save output to local file
    ofstream fout("./values.txt");

    if (!fout) {
        cout << "Error loading output file" << endl;
    }

    // Initiate StopWatch instance
    StopWatch totalTime;

    long long int val;

    cout << "Calculating Ackerman's Values" << endl;
    int max = 0;

    // Iterations for n
    for (long long int n = 0; n < 5; n++) { 

        // Set highest level for m at each level n
        switch (n) {
            case 0: 
                max = 5;
                break;
            case 1:
                max = 4;
                break;
            case 2:
                max = 3;
                break;
            case 3:
                max = 3;
                break;
            case 4:
                max = 3;
                break;
            default:
                break; 
        }

        // Iteration level for m
        for (long long int m = 0; m <= max; m++) {

            cout << endl;
            cout << "m: " << m << endl;
            cout << "n: " << n << endl; 
            StopWatch currSw; 
            val = ack(m, n); 
            currSw.captureFinishTime();
            cout << "v: " << val << endl;
            cout << "t: " << currSw.reportFinishTime() << endl;
            fout << m << ", " << n << ", " << val << ", " << currSw.reportFinishTime() << "," << endl;
            cout << endl; 
            cout << endl;
        }
    }

    cout << "Final Time: ";
    totalTime.captureFinishTime();
    cout << totalTime.reportFinishTime() << endl << endl;


    return 0;
}

