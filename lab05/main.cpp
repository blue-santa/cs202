/*
 * main.cpp
 * CS 202
 * February 11, 2020
 * Bryan Beus
 * Main file for lab 05
 */

#include <iostream>
#include <vector>
#include <fstream>

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::ifstream;
using std::vector;

int main(int argc, char** argv) { 

    ifstream fin("data.dat", std::ios::binary);

    if (!fin) {
        cout << "Error loading file";
        return 0;
    }

    if (fin.eof()) {
        cout << "End of data file" << endl;
        return 0;
    }

    fin.seekg(0, std::ios_base::end);

    int sum = 0;
    int count = 0;
    count = fin.tellg()/sizeof(int);
    int read = 0;
    vector<int> holder;

    fin.seekg(0, std::ios_base::beg);

    for (int i = 0; i < count; i++) {
        fin.read(reinterpret_cast<char*>(&read), sizeof(read));
        holder.push_back(read);
        cout << read << " ";
        sum+=holder[i];
    }

    cout << count << " integers,\nTotal: " << sum << "\nAverage: " << sum/count << endl;
    
    return 0;
}


