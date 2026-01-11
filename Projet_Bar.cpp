// =======================
// Bar management
// Antony GIL
// =======================
#include <iostream>
#include <vector>
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

    Ingredient(string n, int q, int t)
        : name(n), quantity(q), threshold(t) {}

    void display()
    {
        cout << "   * " << name << " : " << quantity
             << " (alert level: " << threshold << ")" << endl;

        if (quantity < threshold)
            cout << "     ⚠ Warning: low stock for " << name << "!" << endl;
    }
    
    bool use(int q)
    {
        if (quantity >= q)
        {
            quantity -= q;
            if (quantity < threshold)
                cout << "     ⚠ Warning : low stock for " << name << " !" << endl;
            return true;
        }
        return false;
    }
};

// =======================
// IngredientLine
// =======================
class IngredientLine
{
public:
    string name;
    int quantity_needed;

    IngredientLine(string n, int q)
        : name(n), quantity_needed(q) {}
};

// =======================
// Cocktail
// =======================
class Cocktail
{
public:
    string name;
    vector<IngredientLine> ingredients;

    Cocktail(string n, vector<IngredientLine> ingredients_list)
        : name(n), ingredients(ingredients_list) {}

    void display()
    {
        cout << "   * " << name << ":" << endl;
        for (IngredientLine &li : ingredients)
        {
            cout << "     - " << li.name
                 << " (" << li.quantity_needed << ")" << endl;
        }
    }

    // checks if the cocktail can be prepared
    bool checkIfCanBeDone(vector<Ingredient>& stock)
    {
        bool ingredient_ok;
        bool can_be_cooked = true;

        for (IngredientLine& li : ingredients)
        {
            ingredient_ok = false;

            for (Ingredient& ing : stock)
            {
                if (ing.name == li.name &&
                    ing.quantity >= li.quantity_needed)
                {
                    ingredient_ok = true;
                }
            }

            if (!ingredient_ok)
            {
                cout << "     ⚠ Missing " << li.name
                     << " to prepare " << name << endl;
                can_be_cooked = false;
            }
        }
        
        return can_be_cooked;
    }   
    
    // prepares the cocktail
    // we assume it is possible to prepare it
    void prepare(vector<Ingredient> &stock)
    {
        for (IngredientLine& li : ingredients)
        {
            for (Ingredient& ingr : stock)
            {
                if (ingr.name == li.name)
                {
                    ingr.use(li.quantity_needed);
                }
            }
        }
        cout << name << " is prepared! 🍹🍸" << endl;
    }
};

// =======================
// Bar
// =======================
class Bar
{
public:
    vector<Ingredient> stock;
    vector<Cocktail> carte;

    Bar() {}

    void addStock(const Ingredient &ingr)
    {
        stock.push_back(ingr);
    }

    void addCocktail(const Cocktail &coc)
    {
        carte.push_back(coc);
    }

    void displayStock()
    {
        cout << "Current stock:" << endl;
        for (Ingredient &ingr : stock)
            ingr.display();
    }

    void displayCarte()
    {
        cout << "Cocktail menu:" << endl;
        for (Cocktail &coc : carte)
            coc.display();
    }

    void displayMainMenu()
    {
        cout << "\nChoose an option:" << endl;
        cout << "   0 - Quit" << endl;
        cout << "   1 - Display stock" << endl;
        cout << "   2 - Display cocktail menu" << endl;
        cout << "   3 - Prepare a cocktail" << endl;
        cout << "   4 - Check if a cocktail can be cooked" << endl;
        cout << "Choice: ";
    }
 
    Cocktail* getCocktail(const string& name)
    {
        for (Cocktail& c : carte)
        {
            if (c.name == name)
                return &c;
        }
        return nullptr;
    }
    
    void cookCocktail()
    {
        cout << "Available cocktails:" << endl;

        vector<Cocktail *> available;
        // list all cocktails from the menu
        for (Cocktail& cocktail : carte)
        {
            if (cocktail.checkIfCanBeDone(stock))
            {
                cout << "   " << available.size() + 1
                     << " - " << cocktail.name << endl;
                available.push_back(&cocktail);
            }
        }

        if (available.empty())
        {
            cout << "No cocktails can be prepared with the current stock."
                 << endl;
            return;
        }

        int choice;
        cout << "Select a cocktail to prepare: ";
        cin >> choice;
        choice--;

        if (choice < 0 || choice >= available.size())
        {
            cout << "Invalid choice." << endl;
            return;
        }
        available[choice]->prepare(stock);
    }

    void run()
    {
        int choice = -1;

        while (choice != 0)
        {
            displayMainMenu();
            cin >> choice;

            switch (choice)
            {
            case 1:
                displayStock();
                break;
            case 2:
                displayCarte();
                break;
            case 3:
                cookCocktail();
                break;
            case 4:
            {
                cout << "Enter the name of the cocktail: ";
                string name;
                cin >> name;
                Cocktail *p_coc = getCocktail(name);
                if (p_coc != nullptr)
                {
                    if (p_coc->checkIfCanBeDone(stock))
                    {
                        cout << "Yes, we can prepare " << name << endl;
                        p_coc->display();
                    }
                }
                else
                {
                    cout << name << " is not on the menu!" << endl;
                }
                break;
            }
            case 0:
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "This option does not exist." << endl;
            }
        }
    }
};

// =======================
// Main
// =======================
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