#include "Base.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <exception>

// Implementation of the functions declared in Base.hpp.  Everything in
// this file is purposely simple so that the focus remains on how
// dynamic_cast can be used to identify the actual type of an object
// through a base-class pointer or reference.

// Virtual destructor defined out of line. Although it does nothing,
// declaring it here ensures that deleting derived objects through a
// Base pointer invokes the correct destructor.
Base::~Base() {}

// Create and return a new object of a random derived type.
// std::rand() is used here for simplicity; a better program might
// use <random> but that would distract from the main point.
Base* generate(void)
{
    int r = std::rand() % 3; // produce a value in the range [0, 2]
    switch (r)
    {
    case 0:
        std::cout << "Generated A" << std::endl;
        return new A();
    case 1:
        std::cout << "Generated B" << std::endl;
        return new B();
    default:
        std::cout << "Generated C" << std::endl;
        return new C();
    }
}

// Identify the type of the object pointed to by 'p'.
// dynamic_cast returns NULL if the cast fails when used with pointers.
void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
}

// Overload of identify that takes a reference. dynamic_cast on a
// reference throws std::bad_cast when the cast fails, so we use
// try/catch blocks to attempt each cast in turn.
void identify(Base& p)
{
    try {
        A& a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << "A" << std::endl;
        return;
    } catch (std::exception&) {}
    try {
        B& b = dynamic_cast<B&>(p);
        (void)b;
        std::cout << "B" << std::endl;
        return;
    } catch (std::exception&) {}
    try {
        C& c = dynamic_cast<C&>(p);
        (void)c;
        std::cout << "C" << std::endl;
    } catch (std::exception&) {}
}
