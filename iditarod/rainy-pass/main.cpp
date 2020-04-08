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

    ofstream fout("./values.txt");

    if (!fout) {
        cout << "Error loading output file" << endl;
    }

    StopWatch totalTime;

    // TODO: Get rid of these and just use the for loops below
    long long int m = 0;
    long long int n = 0;
    long long int val;

    cout << "Calculating Ackerman's Values" << endl;
    int max = 0;

    // Iterations for n
    for (int i = 0; i < 4; i++) { 

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
                max = 1;
            default:
                break; 
        }

        // Iteration level for m
        for (int k = 0; k < max; k++) {

            // Within each n, calculate each m starting at 0
            for (int j = 0; j <= n; j++) {
                cout << endl;
                cout << "m: " << m << endl;
                cout << "n: " << n << endl; 
                StopWatch currSw; 
                val = ack(m, n); 
                currSw.captureFinishTime();
                cout << "v: " << val << endl;
                cout << "t: " << currSw.reportFinishTime() << endl;;
                fout << m << ", " << n << ", " << currSw.reportFinishTime() << "," << endl;
                cout << endl; 
                cout << endl;
                m++;
            }
        }
        n++; 
        m = 0;
    }

    cout << "Final Time: ";
    totalTime.captureFinishTime();
    cout << totalTime.reportFinishTime() << endl << endl;


    return 0;
}

