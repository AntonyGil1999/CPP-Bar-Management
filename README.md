# CPP-Bar-Management
CPP Bar Management pour Politechnika Krakowska

# 🍹 Bar Management System

A C++ object-oriented application for managing a cocktail bar, including inventory tracking, cocktail recipes, and order preparation.

## 📋 Project Description

This project is a command-line application that simulates a bar management system. It allows users to:
- View and manage ingredient inventory with low-stock alerts
- Display available cocktail recipes
- Prepare cocktails with automatic stock deduction
- Check if specific cocktails can be made with current inventory

## 🎯 Features

- **Inventory Management**: Track ingredients with quantity and alert thresholds
- **Cocktail Menu**: Store and display cocktail recipes
- **Smart Preparation**: Automatic ingredient checking and stock updates
- **Low Stock Warnings**: Alerts when ingredients fall below threshold
- **Interactive Menu**: User-friendly command-line interface

## 🛠️ Technologies Used

This project demonstrates the following C++ concepts:
- **Object-Oriented Programming**: Classes and objects
- **Inheritance**: `Cocktail` inherits from abstract `Drink` class
- **Polymorphism**: Virtual functions for dynamic behavior
- **Function Overloading**: Multiple versions of `addStock()`
- **Dynamic Memory Allocation**: Using `new` and managing pointers
- **Pointer Operations**: Access via `->` operator
- **Constructors & Destructors**: Proper resource management
- **Control Structures**: Loops, conditions, switch statements

## 📁 Project Structure

```
.
├── main.cpp          # Main program entry point
├── bar.cpp           # Bar class implementation
├── bar.h             # Bar class header
├── cocktail.cpp      # Cocktail class implementation
├── cocktail.h        # Cocktail class header
├── drink.cpp         # Abstract Drink class
├── drink.h           # Drink class header
├── ingredient.cpp    # Ingredient class implementation
├── ingredient.h      # Ingredient class header
├── Makefile          # Build configuration
└── README.md         # This file
```

## 🚀 Compilation and Execution

### Prerequisites
- g++ compiler
- Make utility
- Linux/Unix environment (or MinGW on Windows)

### Build the project
```bash
make
```

### Run the application
```bash
./Programme
```

### Clean compiled files
```bash
make clean
```

## 💻 Usage

Once the program is running, you will see a menu with the following options:

```
Choose an option:
   0 - Quit
   1 - Display stock
   2 - Display cocktail menu
   3 - Prepare a cocktail
   4 - Check if a cocktail can be cooked
```

### Example Session

1. **View stock**: Check available ingredients and their quantities
2. **View menu**: See all available cocktails and their recipes
3. **Prepare cocktail**: Select a cocktail to prepare (automatically updates stock)
4. **Check availability**: Enter a cocktail name to see if it can be made

## 🍸 Available Cocktails

The default menu includes:
- **Mojito**: Rhum (3), Juice (2), Lime Juice (1)
- **Martini**: Vodka (4), Juice (2), Lime Juice (1)
- **Margarita**: Tequila (3), Lime Juice (2), Juice (1)
- **Daiquiri**: Rhum (3), Lime Juice (2), Juice (1)

## 📊 UML Class Diagram

```
┌─────────────────┐
│   Ingredient    │
├─────────────────┤
│ - name          │
│ - quantity      │
│ - threshold     │
├─────────────────┤
│ + display()     │
│ + use()         │
└─────────────────┘

┌─────────────────┐
│  IngredientLine │
├─────────────────┤
│ - name          │
│ - quantity_need │
└─────────────────┘

        ┌─────────────────┐
        │   Drink         │◄─────────────┐
        │   (abstract)    │              │
        ├─────────────────┤              │
        │ - name          │              │
        ├─────────────────┤              │
        │ + display()*    │              │ inherits
        └─────────────────┘              │
                 △                       │
                 │                       │
                 │                       │
        ┌─────────────────┐              │
        │   Cocktail      │──────────────┘
        ├─────────────────┤
        │ - ingredients   │
        ├─────────────────┤
        │ + display()     │
        │ + checkIfCanBe  │
        │ + prepare()     │
        └─────────────────┘

┌──────────────────────┐
│        Bar           │
├──────────────────────┤
│ - stock              │
│ - carte              │
├──────────────────────┤
│ + addStock()         │ ← overloaded
│ + addStock()         │ ← overloaded
│ + addCocktail()      │
│ + displayStock()     │
│ + displayCarte()     │
│ + cookCocktail()     │
│ + run()              │
└──────────────────────┘
```

## 👨‍💻 Author

**GIL Antony**
- GitHub: [@AntonyGil1999](https://github.com/AntonyGil1999)
- Project Link: [https://github.com/AntonyGil1999/CPP-Bar-Management](https://github.com/AntonyGil1999/CPP-Bar-Management)

## 📅 Development Timeline

- **05.XII.2024**: Project topic submission
- **09.I.2026**: Functional version available on GIT
- **14.I.2026**: Final report submission
- **16.I.2026**: Project presentation

## 📝 License

This project was created as part of the Object-Oriented Programming C++ course at Politechnika Krakowska im. Tadeusza Kościuszki.

## 🙏 Acknowledgments

- Course instructor: Paweł Król
- Object-Oriented Programming C++ course
- Politechnika Krakowska im. Tadeusza Kościuszki
- C++ Standard Library documentation

---

**Note**: This is an educational project demonstrating C++ OOP concepts including inheritance, polymorphism, dynamic memory management, and proper software design patterns.