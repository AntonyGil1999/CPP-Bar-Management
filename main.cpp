// =======================
// main.cpp
// Bar management - Antony GIL
// =======================
#include <iostream>
#include <vector>
#include "bar.h"
#include "cocktail.h"
#include "ingredient.h"

using namespace std;

int main()
{
    cout << "Welcome to Antony's bar !" << endl;

    Bar bar;

    // ============== STOCK ==============
    bar.addStock(Ingredient("Rhum", 10, 2));
    bar.addStock(Ingredient("Vodka", 10, 2));
    bar.addStock(Ingredient("Juice", 10, 2));
    bar.addStock(Ingredient("Lime Juice", 10, 2));
    bar.addStock(Ingredient("Tequila", 10, 2));

    // ============== LISTES D'INGRÉDIENTS ==============
    vector<IngredientLine> listeIngredient_Mojito = { 
        IngredientLine("Rhum",3), IngredientLine("Juice",2), IngredientLine("Lime Juice",1) 
    };

    vector<IngredientLine> listeIngredient_Martini = { 
        IngredientLine("Vodka",4), IngredientLine("Juice",2), IngredientLine("Lime Juice",1) 
    };

    vector<IngredientLine> listeIngredient_Margarita = { 
        IngredientLine("Tequila",3), IngredientLine("Lime Juice",2), IngredientLine("Juice",1) 
    };

    vector<IngredientLine> listeIngredient_Daiquiri = { 
        IngredientLine("Rhum",3), IngredientLine("Lime Juice",2), IngredientLine("Juice",1) 
    };

    // ============== AJOUT DES COCKTAILS ==============
    bar.addCocktail(new Cocktail("Mojito", listeIngredient_Mojito));
    bar.addCocktail(new Cocktail("Martini", listeIngredient_Martini));
    bar.addCocktail(new Cocktail("Margarita", listeIngredient_Margarita));
    bar.addCocktail(new Cocktail("Daiquiri", listeIngredient_Daiquiri));

    bar.run();
}