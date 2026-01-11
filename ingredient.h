#ifndef INGREDIENT_H
#define INGREDIENT_H

#include <string>
using namespace std;

class Ingredient {
public:
    string name;
    int quantity;
    int threshold;
    
    Ingredient(string n, int q, int t);
    void display();
    bool use(int q);
};

class LigneIngredient {
public:
    string name;
    int quantity_needed;
    
    LigneIngredient(string n, int q);
};

#endif