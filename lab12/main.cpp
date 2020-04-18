/*
 * main.cpp
 * CS202 Dr. Metzgar
 * Bryan Beus
 * April 17, 2020
 * Main file for lab12
 */

#include <iostream>
#include <string>
#include <memory>
#include <vector>

#include "Miscellaneous.hpp" 

using std::cout;
using std::endl;
using std::string;

// [x] Write Base class with two methods (one virtual)
// [x] Write Derived class with two methods (one virtual)
// [ ] Test Base class pointer to base class object
// [ ] Test Base class pointer to derived class object
// [ ] Test Derived class pointer to derived class object
// [ ] Test base class reference to base class object 
// [ ] Test base class reference to derived class object 
// [ ] Test derived class reference to derived class object 

class Base {
    public:
        Base() { cout << "Base::Base() constructor" << endl; }
        virtual ~Base() { cout << "Base::~Base() destructor" << endl; }
        virtual void print() { cout << "Base::print()" << endl; }

        void functionA() { cout << "Base::functionA() non-virtual" << endl; }
        virtual void functionB() { cout << "Base::functionB() virtual" << endl; }
};

class Derived : public Base {
    public:
        using Base::Base;
        Derived() { cout << "Derived::Derived() constructor" << endl; }
        ~Derived() { cout << "Derived::~Derived() destructor" << endl; };
        void print() override { cout << "Derived::print()" << endl; }
        void functionA() { cout << "Derived::functionA() non-virtual" << endl; }
        virtual void functionB() { cout << "Derived::functionB() virtual" << endl; }
};

enum class ObjectType {
    Base,
    Derived
};

class Factory {
    public:
        static std::unique_ptr<Base> CreateBase();
        static std::unique_ptr<Base> CreateDerived();
        static std::unique_ptr<Base> Create(ObjectType o);
};

std::unique_ptr<Base> Factory::CreateBase() {
    return std::make_unique<Base>();
};

std::unique_ptr<Base> Factory::CreateDerived() {
    return std::make_unique<Derived>();
};

std::unique_ptr<Base> Factory::Create(ObjectType o) {
    switch (o) {
        case ObjectType::Base:
            return std::make_unique<Base>();
        case ObjectType::Derived:
            return std::make_unique<Derived>();
        default:
            throw std::runtime_error("Unknown Object Type");
    }
};

void separator() {
    cout << "==================" << endl;
}

int main()
{
    clearConsole();
    separator();

    { 
        Base b; 
        b.functionA();
        b.functionB();
    
    }

    { 
        Derived d; 
        d.functionA();
        d.functionB();
    
    }

    separator();

    { 
        Base* bd = new Derived(); 
        delete bd;
    }

    separator();

    std::vector<std::unique_ptr<Base>> objects;
    objects.push_back(Factory::CreateBase());
    objects.push_back(Factory::CreateBase());
    objects.push_back(Factory::Create(ObjectType::Derived));
    objects.push_back(Factory::CreateDerived());
    objects.push_back(Factory::CreateDerived());
    objects.push_back(Factory::CreateBase());

    separator();

    for (auto& o: objects) {
        o->print();
    }
    
    return 0;
}
