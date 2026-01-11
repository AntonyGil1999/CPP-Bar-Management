#ifndef BAR_H
#define BAR_H

#include <vector>
#include <string>
#include "ingredient.h"
#include "cocktail.h"
using namespace std;

class Bar {
public:
    vector<Ingredient> stock;
    vector<Cocktail> carte;
    
    Bar();
    void addStock(const Ingredient& ingr);
    void addCocktail(const Cocktail& coc);
    void displayStock();
    void displayCarte();
    void displayMainMenu();
    Cocktail* getCocktail(const string& name);
    void cookCocktail();
    void run();
};

#endif