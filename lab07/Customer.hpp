/*
 * Customer.hpp
 * CS 202
 * March 27, 2020
 * Bryan Beus
 * Customer declaration file
 */

#include <iostream>
#include <iomanip>
#include <string>

using std::cout;
using std::endl;
using std::ostream;
using std::string;

#ifndef __CUSTOMER_HPP__
#define __CUSTOMER_HPP__

class Customer { 
    public:
        Customer();
        
        void fetchData(); 

    private:
        string firstName_ = { "Grace" };
        string lastName_ = { "Hopper" };
        double bankbalance_ = { 100.0 };

};

ostream& operator<< (ostream& os, const Customer& customer);

#endif
