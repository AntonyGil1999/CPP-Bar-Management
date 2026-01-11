// =======================
// cocktail.cpp
// Bar management - Antony GIL
// =======================
#include "cocktail.h"
#include <iostream>

using namespace std;

// =======================
// Cocktail Implementation
// =======================
Cocktail::Cocktail(string n, vector<IngredientLine> ingredients_list)
    : name(n), ingredients(ingredients_list) {}

void Cocktail::display()
{
    cout << "   * " << name << ":" << endl;
    for (IngredientLine &li : ingredients)
    {
        cout << "     - " << li.name
             << " (" << li.quantity_needed << ")" << endl;
    }
}

bool Cocktail::checkIfCanBeDone(vector<Ingredient>& stock)
{
    bool ingredient_ok;
    bool can_be_cooked = true;

    for (IngredientLine& li : ingredients)
    {
        ingredient_ok = false;

        for (Ingredient& ing : stock)
        {
            if (ing.name == li.name &&
                ing.quantity >= li.quantity_needed)
            {
                ingredient_ok = true;
            }
        }

        if (!ingredient_ok)
        {
            cout << "     ⚠ Missing " << li.name
                 << " to prepare " << name << endl;
            can_be_cooked = false;
        }
    }
    
    return can_be_cooked;
}

void Cocktail::prepare(vector<Ingredient> &stock)
{
    for (IngredientLine& li : ingredients)
    {
        for (Ingredient& ingr : stock)
        {
            if (ingr.name == li.name)
            {
                ingr.use(li.quantity_needed);
            }
        }
    }
    cout << name << " is prepared! 🍹🍸" << endl;
}