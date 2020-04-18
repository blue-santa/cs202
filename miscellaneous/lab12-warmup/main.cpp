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

class Base {
    public:
        Base() { cout << "Base::Base()" << endl; }
        virtual ~Base() { cout << "Base::~Base()" << endl; }
        virtual void print() { cout << "Base::print()" << endl; }
};

class Derived : public Base {
    public:
        using Base::Base;
        ~Derived() { cout << "Derived::~Derived()" << endl; };
        void print() override { cout << "Derived::print()" << endl; }
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

int main()
{
    clearConsole();
    cout << "---------------" << endl;

    { Base b; }
    cout << "---------------" << endl;

    { 
        Base* bd = new Derived(); 
        delete bd;
    }

    cout << "---------------" << endl;

    std::vector<std::unique_ptr<Base>> objects;
    objects.push_back(Factory::CreateBase());
    objects.push_back(Factory::CreateBase());
    objects.push_back(Factory::Create(ObjectType::Derived));
    objects.push_back(Factory::CreateDerived());
    objects.push_back(Factory::CreateDerived());
    objects.push_back(Factory::CreateBase());

    cout << "---------------" << endl;

    for (auto& o: objects) {
        o->print();
    }
    
    return 0;
}
