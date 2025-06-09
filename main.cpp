#include "Base.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

// Entry point of the program. It repeatedly generates objects of
// random derived types and then identifies them using both pointer
// and reference based functions. The goal is simply to demonstrate
// how dynamic_cast works in practice.

int main()
{
    // Seed the pseudo random number generator. Using time(NULL) means
    // we get different sequences each run.
    std::srand(static_cast<unsigned int>(std::time(NULL)));

    // Create and test ten random objects.
    for (int i = 0; i < 10; ++i)
    {
        Base* p = generate();       // Create a new random instance
        std::cout << "identify(p): ";
        identify(p);                // Identify using a pointer
        std::cout << "identify(*p): ";
        identify(*p);               // Identify using a reference
        delete p;                   // Clean up the allocated object
    }
    return 0;
}
