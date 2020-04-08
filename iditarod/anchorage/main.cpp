#include <iomanip>
#include <vector>
#include <string>
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

void printCurrentSetup(const int& current_num, const int& current_value) {
    cout << current_num << "th number: " << current_value << endl;
}

int fibonacci_non_recursive(const int& final_num) {
    int current_num = 0; 
    int current_value = 0;
    vector<int> values;

    if (current_num < final_num) {
        printCurrentSetup(current_num, current_value);
        values.push_back(current_value);
        current_num++;
        current_value++;
        values.push_back(current_value);
    } 

    if (current_num < final_num) {
        printCurrentSetup(current_num, current_value);
        current_num++;
        values.push_back(current_value);
    } 
    
    
    while (current_num < final_num) {
        printCurrentSetup(current_num, current_value);
        current_num += 1;
        current_value = values.at(current_num - 1) + values.at(current_num - 2);
        values.push_back(current_value); 
    } 

    return current_value; 
}

int fibonacci_recursive(const int& final_num, int& current_num, int& current_value, vector<int>& values) {

    if (current_num == 0 && current_num < final_num) {
        printCurrentSetup(current_num, current_value);
        values.push_back(current_value);
        current_num++;
        current_value++;
        printCurrentSetup(current_num, current_value);
        values.push_back(current_value);
        fibonacci_recursive(final_num, current_num, current_value, values);
    } else { 
        while (current_num < final_num) {
            current_num += 1;
            current_value = values.at(current_num - 1) + values.at(current_num - 2);
            printCurrentSetup(current_num, current_value);
            values.push_back(current_value); 
            fibonacci_recursive(final_num, current_num, current_value, values);
        } 
    } 
    return current_value; 
}

int main() {

    // Execute recursive fibonacci number finder
    int number;
    int final_num = 10;
    int current_num = 0;
    int current_value = 0;
    vector<int> values_recursive;
    number = fibonacci_recursive(final_num, current_num, current_value, values_recursive); 
    cout << "Recursive Fibonacci nth number: " << number << endl;

    // Execute recursive fibonacci number finder
    number = fibonacci_non_recursive(final_num); 
    cout << "Non-recursive Fibonacci nth number: " << number << endl;

    return 0;
}

