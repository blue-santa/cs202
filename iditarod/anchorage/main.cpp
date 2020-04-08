/*
 * main.cpp
 * CS202
 * April 7, 2020
 * Bryan Beus
 * Anchorage station for Iditarod Challenge
 */

#include <iomanip>
#include <vector>
#include <string>
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

// Print the current number and value in a sequence
void printCurrentSetup(const int& current_num, const int& current_value) {
    cout << current_num << "th number: " << current_value << endl;
}

// Calculate and return the factorial value of the provided integer
int factorial_non_recursive(const int& final_num) {
    int current_num = 0; 
    int current_value = 1;
    vector<int> values;

    // First term does not require a calculation
    while ((current_num < final_num) && current_num < 1) {
        printCurrentSetup(current_num, current_value);
        current_num++;
        values.push_back(current_value);
    } 

    // Calculate the factorial value until the final_num is reached
    while (current_num <= final_num) {
        current_value = current_num * values.at(current_num - 1);
        values.push_back(current_value); 
        printCurrentSetup(current_num, current_value);
        current_num++;
    } 

    return current_value; 
}

// Calculate and return the factorial value using recursion
int factorial_recursive(const int& final_num, int& current_num, int& current_value, vector<int>& values) {

    // The first term has a different calculation pattern
    if (current_num == 0 && current_num < final_num) {
        printCurrentSetup(current_num, current_value);
        values.push_back(current_value);
        current_num++;
        printCurrentSetup(current_num, current_value);
        values.push_back(current_value);
        factorial_recursive(final_num, current_num, current_value, values);
    } else { 
        while (current_num < final_num) {
            current_num++;
            current_value = current_num * values.at(current_num - 1);
            printCurrentSetup(current_num, current_value);
            values.push_back(current_value); 
            factorial_recursive(final_num, current_num, current_value, values);
        } 
    } 

    return current_value; 
}

// Calculate and return the Fibonacci value of the provided integer
int fibonacci_non_recursive(const int& final_num) {
    int current_num = 0; 
    int current_value = 0;
    vector<int> values;

    // First term has unique calculation
    if (current_num < final_num) {
        printCurrentSetup(current_num, current_value);
        values.push_back(current_value);
        current_num++;
        current_value++;
        values.push_back(current_value);
    } 

    // Second term has unique calculation
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

// Print the Fibonacci value of the provided integer using recursion
int fibonacci_recursive(const int& final_num, int& current_num, int& current_value, vector<int>& values) {

    // First term has unique calculation
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
    vector<int> values_fibonacci;
    number = fibonacci_recursive(final_num, current_num, current_value, values_fibonacci); 
    cout << "Recursive Fibonacci nth number: " << number << endl;

    // Execute recursive fibonacci number finder
    number = fibonacci_non_recursive(final_num); 
    cout << "Non-recursive Fibonacci nth number: " << number << endl;

    // Execute recursive factorial number finder
    current_num = 0;
    current_value = 1;
    vector<int> values_factorial;
    number = factorial_recursive(final_num, current_num, current_value, values_factorial); 
    cout << "Recursive Factorial nth number: " << number << endl;

    // Execute recursive factorial number finder
    number = factorial_non_recursive(final_num); 
    cout << "Non-recursive Factorial nth number: " << number << endl;

    return 0;
}

