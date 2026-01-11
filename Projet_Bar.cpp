// =======================
// Gestion d'un BAR
// Antony GIL
// =======================
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// int a; 

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
class LigneIngredient
{
public:
    string name;
    int quantity_needed;

    LigneIngredient(string n, int q)
        : name(n), quantity_needed(q) {}
};

// =======================
// Cocktail
// =======================
class Cocktail
{
public:
    string name;
    vector<LigneIngredient> ingredients;

    Cocktail(string n, vector<LigneIngredient> ingredients_list)
        : name(n), ingredients(ingredients_list) {}

    void display()
    {
        cout << "   * " << name << ":" << endl;
        for (LigneIngredient &li : ingredients)
        {
            cout << "     - " << li.name
                 << " (" << li.quantity_needed << ")" << endl;
        }
    }

    // vérifie si le cocktail peut être fait
    bool checkIfCanBeDone(vector<Ingredient>& stock)
    {
        bool ingredient_ok;
        bool can_be_cooked = true;

        for (LigneIngredient& li : ingredients)
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

            if (ingredient_ok == false)  // if (!ingredient_ok)
            {
                cout << "     ⚠ Missing " << li.name
                     << " to prepare " << name << endl;
                can_be_cooked = false;
            }
        }
        
        return can_be_cooked;
    }   
    
    // prepare the cocktail
    // on suppose que c'est possible de le faire
    void prepare(vector<Ingredient> &stock)
    {
        for (LigneIngredient& li : ingredients)
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
        // on enumère tous les cocktails de la carte
        for (Cocktail& cocktail : carte)
        {
            // si on peut les préparer...
            if (cocktail.checkIfCanBeDone(stock))
            {
                // ...alors on affiche un choix avec le nom du cocktail
                cout << "   " << available.size() + 1
                     << " - " << cocktail.name << endl;
                // on stocke le pointeur du cocktail
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
                        cout << "Yes we can cook " << name << endl;
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

    vector<LigneIngredient> mojitoIngredients = {
        LigneIngredient("Rhum", 3),
        LigneIngredient("Jus", 2)};

    vector<LigneIngredient> martiniIngredients = {
        LigneIngredient("Vodka", 4),
        LigneIngredient("Jus", 2)};

    Bar bar;

    bar.addStock(Ingredient("Rhum", 2, 2));
    bar.addStock(Ingredient("Vodka", 10, 2));
    bar.addStock(Ingredient("Jus", 10, 2));

    bar.addCocktail(Cocktail("Mojito", mojitoIngredients));
    bar.addCocktail(Cocktail("Martini", martiniIngredients));

    bar.run();
}