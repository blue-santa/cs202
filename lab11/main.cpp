/*
 * main.cpp
 * CS202 Dr. Metzgar
 * Bryan Beus
 * April 11, 2020
 * Main file for lab11
 */

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

// [x] Default base class object
// [x] Base class object using two parameter constructors
// [x] Default derived class object
// [x] Derived class object using three parameter constructor

class Base {
    public:
        Base() {
            cout << "Constructing default base object with values: " << audio_level_ << " " << initiated_ << endl;
        };

        Base(int audio_level, bool initiated) 
        : audio_level_{audio_level}, initiated_{initiated} {
            cout << "Constructing base object " << audio_level_ << " " << initiated_ << endl; 
        }

        ~Base() {
            cout << "Destructing base object: " << audio_level_ << " " << initiated_ << endl;
        }

    private:
        int audio_level_ { 8 };
        bool initiated_ { false };

};

// class Derived

class Derived : public Base {
    public:
        Derived() 
            : Base{ 17, true }
        {
            cout << "Constructing a Derived Object with brand: " << brand_ << endl; 
        }

        Derived(const string& brand) 
            : Base{ 17, true }, brand_{ brand }
        {
            cout << "Constructing a Derived Object with brand: " << brand_ << endl; 
        }

        Derived(int audio_level, bool initiated, const string& brand)
            : Base{ audio_level, initiated }, brand_{ brand } 
        {
            cout << "Constructing a derived object of the values: " << brand_ << endl;
        }


        ~Derived() {
            cout << "Destructing a derived object with brand: " << brand_ << endl;
        }
    private: 
        string brand_;
};

int main()
{
    { Base b; }
    cout << endl << endl;

    { Base b{ 5, true }; } 
    cout << endl << endl;

    { Derived d; } 
    cout << endl << endl;

    { Derived d("Sony"); }
    cout << endl << endl;

    { Derived d(30, true, "GCI" ); }
    cout << endl << endl;

    return 0;
}
