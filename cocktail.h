// =======================
// cocktail.h
// Bar management - Antony GIL
// =======================
#ifndef COCKTAIL_H
#define COCKTAIL_H

#include <string>
#include <vector>
#include "ingredient.h"

using namespace std;

// =======================
// Cocktail
// =======================
class Cocktail
{
public:
    string name;
    vector<IngredientLine> ingredients;

    Cocktail(string n, vector<IngredientLine> ingredients_list);
    void display();
    bool checkIfCanBeDone(vector<Ingredient>& stock);
    void prepare(vector<Ingredient> &stock);
};

#endif