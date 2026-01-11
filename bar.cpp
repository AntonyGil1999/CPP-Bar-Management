#include "bar.h"
#include <iostream>
using namespace std;

// ======================= 
// Bar 
// ======================= 
Bar::Bar() {}

void Bar::addStock(const Ingredient& ingr) {
    stock.push_back(ingr);
}

void Bar::addCocktail(const Cocktail& coc) {
    carte.push_back(coc);
}

void Bar::displayStock() {
    cout << "Current stock:" << endl;
    for (Ingredient& ingr : stock)
        ingr.display();
}

void Bar::displayCarte() {
    cout << "Cocktail menu:" << endl;
    for (Cocktail& coc : carte)
        coc.display();
}

void Bar::displayMainMenu() {
    cout << "\nChoose an option:" << endl;
    cout << " 0 - Quit" << endl;
    cout << " 1 - Display stock" << endl;
    cout << " 2 - Display cocktail menu" << endl;
    cout << " 3 - Prepare a cocktail" << endl;
    cout << " 4 - Check if a cocktail can be cooked" << endl;
    cout << "Choice: ";
}

Cocktail* Bar::getCocktail(const string& name) {
    for (Cocktail& c : carte) {
        if (c.name == name)
            return &c;
    }
    return nullptr;
}

void Bar::cookCocktail() {
    cout << "Available cocktails:" << endl;
    vector<Cocktail*> available;
    
    // on énumère tous les cocktails de la carte
    for (Cocktail& cocktail : carte) {
        // si on peut les préparer...
        if (cocktail.checkIfCanBeDone(stock)) {
            // ...alors on affiche un choix avec le nom du cocktail
            cout << " " << available.size() + 1 << " - " << cocktail.name << endl;
            // on stocke le pointeur du cocktail
            available.push_back(&cocktail);
        }
    }
    
    if (available.empty()) {
        cout << "No cocktails can be prepared with the current stock." << endl;
        return;
    }
    
    int choice;
    cout << "Select a cocktail to prepare: ";
    cin >> choice;
    choice--;
    
    if (choice < 0 || choice >= available.size()) {
        cout << "Invalid choice." << endl;
        return;
    }
    
    available[choice]->prepare(stock);
}

void Bar::run() {
    int choice = -1;
    while (choice != 0) {
        displayMainMenu();
        cin >> choice;
        
        switch (choice) {
            case 1:
                displayStock();
                break;
            case 2:
                displayCarte();
                break;
            case 3:
                cookCocktail();
                break;
            case 4: {
                cout << "Enter the name of the cocktail: ";
                string name;
                cin >> name;
                Cocktail* p_coc = getCocktail(name);
                if (p_coc != nullptr) {
                    if (p_coc->checkIfCanBeDone(stock)) {
                        cout << "Yes we can cook " << name << endl;
                        p_coc->display();
                    }
                } else {
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