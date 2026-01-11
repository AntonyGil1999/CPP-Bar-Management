// =======================
// bar.cpp
// Bar management - Antony GIL
// =======================
#include "bar.h"
#include <iostream>

using namespace std;

// =======================
// Bar Implementation
// =======================
Bar::Bar() {}

Bar::~Bar()
{
    for (Drink* d : carte)
        delete d;
}

// FUNCTION OVERLOAD - Version 1 (with Ingredient object)
void Bar::addStock(const Ingredient &ingr) 
{ 
    stock.push_back(ingr); 
}

// FUNCTION OVERLOAD - Version 2 (with separate parameters)
void Bar::addStock(string n, int q, int t)
{
    stock.push_back(Ingredient(n, q, t));
}

void Bar::addCocktail(Cocktail* coc) 
{ 
    carte.push_back(coc); 
}

void Bar::displayStock()
{
    cout << "Current stock:" << endl;
    for (Ingredient &ingr : stock)
        ingr.display();
}

void Bar::displayCarte()
{
    cout << "Cocktail menu:" << endl;
    for (Drink* d : carte)
        d->display();
}

void Bar::displayMainMenu()
{
    cout << "\nChoose an option:" << endl;
    cout << "   0 - Quit" << endl;
    cout << "   1 - Display stock" << endl;
    cout << "   2 - Display cocktail menu" << endl;
    cout << "   3 - Prepare a cocktail" << endl;
    cout << "   4 - Check if a cocktail can be cooked" << endl;
    cout << "Choice: ";
}

Cocktail* Bar::getCocktail(const string& name)
{
    for (Drink* d : carte)
    {
        Cocktail* c = dynamic_cast<Cocktail*>(d);
        if (c && c->name == name)
            return c;
    }
    return nullptr;
}

void Bar::cookCocktail()
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

void Bar::run()
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