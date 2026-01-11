// =======================
// bar.h
// Bar management - Antony GIL
// =======================
#ifndef BAR_H
#define BAR_H

#include <vector>
#include <string>
#include "ingredient.h"
#include "drink.h"
#include "cocktail.h"

using namespace std;

// =======================
// Bar (polymorphique)
// =======================
class Bar
{
public:
    vector<Ingredient> stock;
    vector<Drink*> carte;

    Bar();
    ~Bar();
    
    // SURCHARGE DE FONCTION - Version 1 (avec objet Ingredient)
    void addStock(const Ingredient &ingr);
    
    // SURCHARGE DE FONCTION - Version 2 (avec paramètres séparés)
    void addStock(string n, int q, int t);
    
    void addCocktail(Cocktail* coc);
    void displayStock();
    void displayCarte();
    void displayMainMenu();
    Cocktail* getCocktail(const string& name);
    void cookCocktail();
    void run();
};

#endif