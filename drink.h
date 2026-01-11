// =======================
// drink.h
// Bar management - Antony GIL
// =======================
#ifndef DRINK_H
#define DRINK_H

#include <string>

using namespace std;

// =======================
// Drink (classe abstraite)
// =======================
class Drink
{
public:
    string name;

    Drink(const string& n);
    virtual void display() = 0; // pure virtual function
    virtual ~Drink();
};

#endif