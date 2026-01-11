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
    cout << "Welcome to the Antony's bar !" << endl;
    
    // ============== COCKTAILS DECLARATION ============== 
    vector<IngredientLine> mojitoIngredients = { IngredientLine("Rhum",3), IngredientLine("Juice",2) };
    vector<IngredientLine> martiniIngredients = { IngredientLine("Vodka",4), IngredientLine("Juice",2) };
    vector<IngredientLine> margaritaIngredients = { IngredientLine("Tequila",3), IngredientLine("Triple Sec",2), IngredientLine("Lime Juice",2) };
    vector<IngredientLine> pinaColadaIngredients = { IngredientLine("Rhum",3), IngredientLine("Coconut Cream",2), IngredientLine("Pineapple Juice",3) };
    vector<IngredientLine> cosmopolitanIngredients = { IngredientLine("Vodka",3), IngredientLine("Triple Sec",2), IngredientLine("Cranberry Juice",3), IngredientLine("Lime Juice",1) };
    vector<IngredientLine> bloodyMaryIngredients = { IngredientLine("Vodka",4), IngredientLine("Tomato Juice",4), IngredientLine("Lime Juice",1), IngredientLine("Tabasco",1) };
    vector<IngredientLine> daiquiriIngredients = { IngredientLine("Rhum",3), IngredientLine("Lime Juice",2), IngredientLine("Sugar Syrup",1) };
    vector<IngredientLine> tequilaSunriseIngredients = { IngredientLine("Tequila",3), IngredientLine("Orange Juice",4), IngredientLine("Grenadine",1) };
    vector<IngredientLine> whiskeySourIngredients = { IngredientLine("Whiskey",4), IngredientLine("Lime Juice",2), IngredientLine("Sugar Syrup",1) };
    vector<IngredientLine> longIslandIngredients = { IngredientLine("Vodka",1), IngredientLine("Rhum",1), IngredientLine("Tequila",1), IngredientLine("Gin",1), IngredientLine("Triple Sec",1), IngredientLine("Cola",2) };
    vector<IngredientLine> sexOnBeachIngredients = { IngredientLine("Vodka",3), IngredientLine("Peach Schnapps",2), IngredientLine("Orange Juice",2), IngredientLine("Cranberry Juice",2) };
    vector<IngredientLine> maiTaiIngredients = { IngredientLine("Rhum",3), IngredientLine("Orange Curacao",2), IngredientLine("Lime Juice",2), IngredientLine("Orgeat Syrup",1) };
    vector<IngredientLine> caipirinhaIngredients = { IngredientLine("Cachaca",3), IngredientLine("Lime Juice",2), IngredientLine("Sugar Syrup",1) };
    vector<IngredientLine> moscowMuleIngredients = { IngredientLine("Vodka",3), IngredientLine("Ginger Beer",4), IngredientLine("Lime Juice",1) };
    vector<IngredientLine> ginTonicIngredients = { IngredientLine("Gin",4), IngredientLine("Tonic Water",3) };
    vector<IngredientLine> rumPunchIngredients = { IngredientLine("Rhum",3), IngredientLine("Orange Juice",3), IngredientLine("Pineapple Juice",2), IngredientLine("Grenadine",1) };
    vector<IngredientLine> blueLagoonIngredients = { IngredientLine("Vodka",3), IngredientLine("Blue Curacao",2), IngredientLine("Lemonade",3) };
    vector<IngredientLine> whiteRussianIngredients = { IngredientLine("Vodka",3), IngredientLine("Kahlua",2), IngredientLine("Cream",1) };
    vector<IngredientLine> espressoMartiniIngredients = { IngredientLine("Vodka",3), IngredientLine("Kahlua",2), IngredientLine("Espresso",1) };
    vector<IngredientLine> aperolSpritzIngredients = { IngredientLine("Aperol",3), IngredientLine("Prosecco",3), IngredientLine("Soda Water",1) };

    Bar bar;
    
    // ============== STOCK ============== 
    bar.addStock(Ingredient("Rhum",10,2));
    bar.addStock(Ingredient("Vodka",10,2));
    bar.addStock(Ingredient("Juice",10,2));
    bar.addStock(Ingredient("Tequila",10,2));
    bar.addStock(Ingredient("Triple Sec",10,2));
    bar.addStock(Ingredient("Lime Juice",10,2));
    bar.addStock(Ingredient("Coconut Cream",10,2));
    bar.addStock(Ingredient("Pineapple Juice",10,2));
    bar.addStock(Ingredient("Cranberry Juice",10,2));
    bar.addStock(Ingredient("Tomato Juice",10,2));
    bar.addStock(Ingredient("Tabasco",5,1));
    bar.addStock(Ingredient("Sugar Syrup",10,2));
    bar.addStock(Ingredient("Orange Juice",10,2));
    bar.addStock(Ingredient("Whiskey",10,2));
    bar.addStock(Ingredient("Gin",10,2));
    bar.addStock(Ingredient("Peach Schnapps",10,2));
    bar.addStock(Ingredient("Orange Curacao",10,2));
    bar.addStock(Ingredient("Orgeat Syrup",10,2));
    bar.addStock(Ingredient("Cachaca",10,2));
    bar.addStock(Ingredient("Ginger Beer",10,2));
    bar.addStock(Ingredient("Tonic Water",10,2));
    bar.addStock(Ingredient("Blue Curacao",10,2));
    bar.addStock(Ingredient("Lemonade",10,2));
    bar.addStock(Ingredient("Kahlua",10,2));
    bar.addStock(Ingredient("Cream",10,2));
    bar.addStock(Ingredient("Espresso",10,2));
    bar.addStock(Ingredient("Aperol",10,2));
    bar.addStock(Ingredient("Prosecco",10,2));
    bar.addStock(Ingredient("Soda Water",10,2));
    bar.addStock(Ingredient("Cola",10,2));
    bar.addStock(Ingredient("Grenadine",10,2));
    
    // ============== COCKTAIL AJOUT ============== 
    bar.addCocktail(Cocktail("Mojito", mojitoIngredients));
    bar.addCocktail(Cocktail("Martini", martiniIngredients));
    bar.addCocktail(Cocktail("Margarita", margaritaIngredients));
    bar.addCocktail(Cocktail("Pina Colada", pinaColadaIngredients));
    bar.addCocktail(Cocktail("Cosmopolitan", cosmopolitanIngredients));
    bar.addCocktail(Cocktail("Bloody Mary", bloodyMaryIngredients));
    bar.addCocktail(Cocktail("Daiquiri", daiquiriIngredients));
    bar.addCocktail(Cocktail("Tequila Sunrise", tequilaSunriseIngredients));
    bar.addCocktail(Cocktail("Whiskey Sour", whiskeySourIngredients));
    bar.addCocktail(Cocktail("Long Island Iced Tea", longIslandIngredients));
    bar.addCocktail(Cocktail("Sex on the Beach", sexOnBeachIngredients));
    bar.addCocktail(Cocktail("Mai Tai", maiTaiIngredients));
    bar.addCocktail(Cocktail("Caipirinha", caipirinhaIngredients));
    bar.addCocktail(Cocktail("Moscow Mule", moscowMuleIngredients));
    bar.addCocktail(Cocktail("Gin Tonic", ginTonicIngredients));
    bar.addCocktail(Cocktail("Rum Punch", rumPunchIngredients));
    bar.addCocktail(Cocktail("Blue Lagoon", blueLagoonIngredients));
    bar.addCocktail(Cocktail("White Russian", whiteRussianIngredients));
    bar.addCocktail(Cocktail("Espresso Martini", espressoMartiniIngredients));
    bar.addCocktail(Cocktail("Aperol Spritz", aperolSpritzIngredients));

    bar.run();
}