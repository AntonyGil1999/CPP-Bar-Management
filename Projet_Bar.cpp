// Full Project !!

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
    {
        name = n;
        quantity = q;
        threshold = t;
    }

    void display()
    {
        cout << "   * " << name << " : " << quantity
             << " (alert level: " << threshold << ")" << endl;

        if (quantity < threshold)
            cout << "     [!] Warning: low stock for " << name << "!" << endl;
    }
    
    bool use(int q)
    {
        if (quantity >= q)
        {
            quantity -= q;
            if (quantity < threshold)
                cout << "     [!] Warning: low stock for " << name << "!" << endl;
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
    {
        name = n;
        quantity_needed = q;
    }
};

// =======================
// Drink (abstract class)
// =======================
class Drink
{
public:
    string name;

    Drink(const string& n)
    {
        name = n;
    }

    virtual void display() = 0; // pure virtual function

    virtual ~Drink() {}
};

// =======================
// Cocktail (inherits from Drink)
// =======================
class Cocktail : public Drink
{
public:
    vector<IngredientLine> ingredients;

    Cocktail(const string& n, vector<IngredientLine> ingredients_list) : Drink(n)
    {
        ingredients = ingredients_list;
    }

    void display() override
    {
        cout << "   * " << name << ":" << endl;
        for (IngredientLine &li : ingredients)
        {
            cout << "     - " << li.name
                 << " (" << li.quantity_needed << ")" << endl;
        }
    }

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
                cout << "     [!] Missing " << li.name
                     << " to prepare " << name << endl;
                can_be_cooked = false;
            }
        }
        
        return can_be_cooked;
    }   
    
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
        cout << name << " is prepared!" << endl;
    }
};

// =======================
// Bar (polymorphic)
// =======================
class Bar
{
public:
    vector<Ingredient> stock;
    vector<Drink*> carte;

    Bar() {}

    ~Bar()
    {
        for (Drink* d : carte)
            delete d;
    }

    // FUNCTION OVERLOAD - Version 1 (with Ingredient object)
    void addStock(const Ingredient &ingr) 
    { 
        stock.push_back(ingr); 
    }

    // FUNCTION OVERLOAD - Version 2 (with separate parameters)
    void addStock(string n, int q, int t)
    {
        stock.push_back(Ingredient(n, q, t));
    }

    void addCocktail(Cocktail* coc) { carte.push_back(coc); }

    void displayStock()
    {
        cout << "Current stock:" << endl;
        for (Ingredient &ingr : stock)
            ingr.display();
    }

    void displayCarte()
    {
        cout << "Cocktail menu:" << endl;
        for (Drink* d : carte)
            d->display();
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
        for (Drink* d : carte)
        {
            Cocktail* c = dynamic_cast<Cocktail*>(d);
            if (c && c->name == name)
                return c;
        }
        return nullptr;
    }

    void cookCocktail()
    {
        cout << "Available cocktails:" << endl;

        vector<Cocktail *> available;
        for (Drink* d : carte)
        {
            Cocktail* c = dynamic_cast<Cocktail*>(d);
            if (c && c->checkIfCanBeDone(stock))
            {
                cout << "   " << available.size() + 1
                     << " - " << c->name << endl;
                available.push_back(c);
            }
        }

        if (available.empty())
        {
            cout << "No cocktails can be prepared with the current stock." << endl;
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
    cout << "Welcome to Antony's bar !" << endl;

    Bar bar;

    // ============== STOCK ==============
    bar.addStock(Ingredient("Rhum", 10, 2));
    bar.addStock(Ingredient("Vodka", 10, 2));
    bar.addStock(Ingredient("Juice", 10, 2));
    bar.addStock(Ingredient("Lime Juice", 10, 2));
    bar.addStock(Ingredient("Tequila", 10, 2));

    // ============== INGREDIENT LISTS ==============
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

    // ============== ADD COCKTAILS ==============
    bar.addCocktail(new Cocktail("Mojito", listeIngredient_Mojito));
    bar.addCocktail(new Cocktail("Martini", listeIngredient_Martini));
    bar.addCocktail(new Cocktail("Margarita", listeIngredient_Margarita));
    bar.addCocktail(new Cocktail("Daiquiri", listeIngredient_Daiquiri));

    bar.run();
    
    
}