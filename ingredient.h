// =======================
// ingredient.h
// Bar management - Antony GIL
// =======================
#ifndef INGREDIENT_H
#define INGREDIENT_H

#include <string>

using namespace std;

// =======================
// Ingredient
// =======================
class Ingredient
{
public:
    string name;
    int quantity;
    int threshold;

    Ingredient(string n, int q, int t);
    void display();
    bool use(int q);
};

// =======================
// IngredientLine
// =======================
class IngredientLine
{
public:
    string name;
    int quantity_needed;

    IngredientLine(string n, int q);
};

#endif