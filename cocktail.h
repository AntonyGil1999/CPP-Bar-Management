
#ifndef COCKTAIL_H
#define COCKTAIL_H

#include <string>
#include <vector>
#include "ingredient.h"
using namespace std;

class Cocktail {
public:
    string name;
    vector<LigneIngredient> ingredients;
    
    Cocktail(string n, vector<LigneIngredient> ingredients_list);
    void display();
    bool checkIfCanBeDone(vector<Ingredient>& stock);
    void prepare(vector<Ingredient>& stock);
};

#endif