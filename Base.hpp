#ifndef BASE_HPP
#define BASE_HPP

// This header declares a very small class hierarchy consisting of
// a polymorphic base class and three empty derived classes. It also
// declares helper functions used to generate random objects of these
// classes and identify their dynamic type. The code is intentionally
// simple so that newcomers can focus on understanding dynamic_cast
// and basic inheritance in C++.

// Base is a polymorphic class so that dynamic_cast works correctly.
// It only contains a virtual destructor which allows deleting derived
// objects through a pointer to Base.
class Base {
public:
    virtual ~Base(); // Make the destructor virtual for proper cleanup
};

// These classes do not add any new members; they simply inherit from
// Base so that we have distinct types to work with.
class A : public Base {};
class B : public Base {};
class C : public Base {};

// Generate and return a pointer to a randomly chosen instance of A, B or C.
Base* generate(void);

// Print the actual type of the object pointed to by \p p using dynamic_cast.
void identify(Base* p);

// Same as the function above but taking a reference. This variant shows
// how dynamic_cast behaves with references (it throws on failure).
void identify(Base& p);

#endif // BASE_HPP
