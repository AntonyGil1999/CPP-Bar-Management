// ======================= 
// Gestion d'un BAR 
// Antony GIL 
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
    vector<LigneIngredient> mojitoIngredients = { LigneIngredient("Rhum",3), LigneIngredient("Juice",2) };
    vector<LigneIngredient> martiniIngredients = { LigneIngredient("Vodka",4), LigneIngredient("Juice",2) };
    vector<LigneIngredient> margaritaIngredients = { LigneIngredient("Tequila",3), LigneIngredient("Triple Sec",2), LigneIngredient("Lime Juice",2) };
    vector<LigneIngredient> pinaColadaIngredients = { LigneIngredient("Rhum",3), LigneIngredient("Coconut Cream",2), LigneIngredient("Pineapple Juice",3) };
    vector<LigneIngredient> cosmopolitanIngredients = { LigneIngredient("Vodka",3), LigneIngredient("Triple Sec",2), LigneIngredient("Cranberry Juice",3), LigneIngredient("Lime Juice",1) };
    vector<LigneIngredient> bloodyMaryIngredients = { LigneIngredient("Vodka",4), LigneIngredient("Tomato Juice",4), LigneIngredient("Lime Juice",1), LigneIngredient("Tabasco",1) };
    vector<LigneIngredient> daiquiriIngredients = { LigneIngredient("Rhum",3), LigneIngredient("Lime Juice",2), LigneIngredient("Sugar Syrup",1) };
    vector<LigneIngredient> tequilaSunriseIngredients = { LigneIngredient("Tequila",3), LigneIngredient("Orange Juice",4), LigneIngredient("Grenadine",1) };
    vector<LigneIngredient> whiskeySourIngredients = { LigneIngredient("Whiskey",4), LigneIngredient("Lime Juice",2), LigneIngredient("Sugar Syrup",1) };
    vector<LigneIngredient> longIslandIngredients = { LigneIngredient("Vodka",1), LigneIngredient("Rhum",1), LigneIngredient("Tequila",1), LigneIngredient("Gin",1), LigneIngredient("Triple Sec",1), LigneIngredient("Cola",2) };
    vector<LigneIngredient> sexOnBeachIngredients = { LigneIngredient("Vodka",3), LigneIngredient("Peach Schnapps",2), LigneIngredient("Orange Juice",2), LigneIngredient("Cranberry Juice",2) };
    vector<LigneIngredient> maiTaiIngredients = { LigneIngredient("Rhum",3), LigneIngredient("Orange Curacao",2), LigneIngredient("Lime Juice",2), LigneIngredient("Orgeat Syrup",1) };
    vector<LigneIngredient> caipirinhaIngredients = { LigneIngredient("Cachaça",3), LigneIngredient("Lime Juice",2), LigneIngredient("Sugar Syrup",1) };
    vector<LigneIngredient> moscowMuleIngredients = { LigneIngredient("Vodka",3), LigneIngredient("Ginger Beer",4), LigneIngredient("Lime Juice",1) };
    vector<LigneIngredient> ginTonicIngredients = { LigneIngredient("Gin",4), LigneIngredient("Tonic Water",3) };
    vector<LigneIngredient> rumPunchIngredients = { LigneIngredient("Rhum",3), LigneIngredient("Orange Juice",3), LigneIngredient("Pineapple Juice",2), LigneIngredient("Grenadine",1) };
    vector<LigneIngredient> blueLagoonIngredients = { LigneIngredient("Vodka",3), LigneIngredient("Blue Curacao",2), LigneIngredient("Lemonade",3) };
    vector<LigneIngredient> whiteRussianIngredients = { LigneIngredient("Vodka",3), LigneIngredient("Kahlua",2), LigneIngredient("Cream",1) };
    vector<LigneIngredient> espressoMartiniIngredients = { LigneIngredient("Vodka",3), LigneIngredient("Kahlua",2), LigneIngredient("Espresso",1) };
    vector<LigneIngredient> aperolSpritzIngredients = { LigneIngredient("Aperol",3), LigneIngredient("Prosecco",3), LigneIngredient("Soda Water",1) };

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
    bar.addStock(Ingredient("Cachaça",10,2));
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
    
    return 0;
}