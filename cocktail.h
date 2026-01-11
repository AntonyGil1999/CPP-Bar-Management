// =======================
// cocktail.h
// Bar management - Antony GIL
// =======================
#ifndef COCKTAIL_H
#define COCKTAIL_H

#include <string>
#include <vector>
#include "ingredient.h"
#include "drink.h"

using namespace std;

// =======================
// Cocktail (inherits from Drink)
// =======================
class Cocktail : public Drink
{
public:
    vector<IngredientLine> ingredients;

    Cocktail(const string& n, vector<IngredientLine> ingredients_list);
    void display() override;
    bool checkIfCanBeDone(vector<Ingredient>& stock);
    void prepare(vector<Ingredient> &stock);
};

#endif