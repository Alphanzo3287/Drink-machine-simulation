// Alphanzo Moore
// CIS-5 Online
// November 5, 2023
// Assignment 12E: Drink Machine Simulator

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Structure to store information about each drink
struct Drink {
    string name;
    double price;
    int quantity;
};

// Function prototypes
void initializeDrinks(Drink[]);
void displayMenu(const Drink[]);
double processTransaction(Drink[], int);

const int NUM_DRINKS = 5;

int main() {
    Drink drinks[NUM_DRINKS];
    double totalEarnings = 0.0;

    initializeDrinks(drinks);

    while (true) {
        displayMenu(drinks);

        int choice;
        cout << "Enter the number of the drink you want (0 to quit): ";
        cin >> choice;

        if (choice < 0 || choice > NUM_DRINKS) {
            cout << "Invalid choice. Please enter a valid drink number.\n";
            continue;
        }

        if (choice == 0) {
            // User chose to quit
            break;
        }

        totalEarnings += processTransaction(drinks, choice);
    }

    cout << fixed << setprecision(2);
    cout << "Total amount earned by the machine: $" << totalEarnings << endl;

    return 0;
}

// Function to initialize the drinks array with data
void initializeDrinks(Drink drinks[]) {
    drinks[0] = {"Cola", 1.25, 5};
    drinks[1] = {"Pepsi", 1.00, 7};
    drinks[2] = {"Sprite", 0.75, 3};
    drinks[3] = {"Water", 0.50, 10};
    drinks[4] = {"Iced Tea", 1.20, 6};
}

// Function to display the drink menu
void displayMenu(const Drink drinks[]) {
    cout << "Drink Machine Menu:\n";
    cout << "---------------------\n";
    for (int i = 0; i < NUM_DRINKS; ++i) {
        cout << i + 1 << ". " << drinks[i].name << " ($" << drinks[i].price << ") - Quantity: " << drinks[i].quantity << endl;
    }
    cout << "0. Quit\n";
}

// Function to process a transaction (user selecting a drink)
double processTransaction(Drink drinks[], int choice) {
    double amount;
    cout << "Enter the amount of money you want to insert (up to $1.00): $";
    cin >> amount;

    // Input validation
    if (amount < 0 || amount > 1.00) {
        cout << "Invalid amount. Please enter a value between 0 and $1.00.\n";
        return 0.0;
    }

    if (drinks[choice - 1].quantity == 0) {
        cout << "Sorry, " << drinks[choice - 1].name << " is sold out.\n";
        return 0.0;
    }

    if (amount < drinks[choice - 1].price) {
        cout << "Insufficient funds. Please insert more money.\n";
        return 0.0;
    }

    double change = amount - drinks[choice - 1].price;
    drinks[choice - 1].quantity--;

    cout << "Dispensing " << drinks[choice - 1].name << ". Change: $" << change << endl;

    return drinks[choice - 1].price;
}
