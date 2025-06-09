#include "Base.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
    std::srand(static_cast<unsigned int>(std::time(NULL)));
    for (int i = 0; i < 10; ++i)
    {
        Base* p = generate();
        std::cout << "identify(p): ";
        identify(p);
        std::cout << "identify(*p): ";
        identify(*p);
        delete p;
    }
    return 0;
}
