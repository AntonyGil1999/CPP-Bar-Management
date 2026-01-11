// =======================
// ingredient.cpp
// Bar management - Antony GIL
// =======================
#include "ingredient.h"
#include <iostream>

using namespace std;

// =======================
// Ingredient Implementation
// =======================
Ingredient::Ingredient(string n, int q, int t)
{
    name = n;
    quantity = q;
    threshold = t;
}

void Ingredient::display()
{
    cout << "   * " << name << " : " << quantity
         << " (alert level: " << threshold << ")" << endl;

    if (quantity < threshold)
        cout << "     [!] Warning: low stock for " << name << "!" << endl;
}

bool Ingredient::use(int q)
{
    if (quantity >= q)
    {
        quantity -= q;
        if (quantity < threshold)
            cout << "     [!] Warning: low stock for " << name << "!" << endl;
        return true;
    }
    return false;
}

// =======================
// IngredientLine Implementation
// =======================
IngredientLine::IngredientLine(string n, int q)
{
    name = n;
    quantity_needed = q;
}