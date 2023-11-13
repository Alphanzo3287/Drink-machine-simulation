# Lesson plan
// Chapter 11, Programming Challenge 13: Drink Machine Simulator
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string>
using namespace std;

// Constants for array
const int NUM_DRINKS = 5;

// Drink structure
struct Drink
{
   string name;     // Drink name
   double price;    // Price of the drink
   int num;         // Number of cans in the machine
};

// Function prototypes
int getChoice(Drink []);
void transaction(Drink [], int, double &);

int main()
{
   // Menu choice
   int choice;

   // Drink machine earnings
   double earnings = 0;

   // Array of drinks in the machine
   Drink machine[NUM_DRINKS] = {
                       {"Cola     ", 0.75, 20},
                       {"Root Beer", .75, 20},
                       {"Lemon-Lime", .75, 20},
                       {"Grape Soda", .80, 20},
                       {"Cream Soda", .80, 20}};

   // Set the floating-point output formatting.
   cout << fixed << showpoint << setprecision(2);

   // Display the menu and process the user's choice.
   choice = getChoice(machine);
   while (choice != 5)
   {
      // Process the transaction.
      transaction(machine, choice, earnings);

      // Get the next choice.
      choice = getChoice(machine);
   }

   // Display the machine's total earnings
   cout << "Total earnings: $" << earnings << endl;
   return 0;
}

//****************************************************
// Function getChoice                                *
// This function gets the user's choice and returns  *
// that value minus one. This adjustment is made     *
// because the value will be used as a subscript     *
// into the Drink array by the transaction function. *
//****************************************************
int getChoice (Drink m[])
{
   // The user's choice
   int choice;

   cout << endl;

   // Display a list of drinks preceded by a number.
   // This will be the menu.
   for (int x = 0; x < NUM_DRINKS; x++)
   {
      cout << (x+1) << ") " << m[x].name << "\t\t";
      cout << m[x].price << endl;
   }

   // Display the last menu item, which is to
   // leave the drink machine.
   cout << (NUM_DRINKS + 1) 
        << ") Leave the drink machine\n\n";

   // Get the user's choice.
   cout << "Choose one: ";
   cin >> choice;

   // Validate the choice.
   while (choice < 1 || choice > 6)
   {
      cout << "Bad choice. Choose one: ";
      cin >> choice;
   }

   // Return the choice, as a subscript into
   // the array of drinks.
   return choice - 1;
}

//****************************************************
// Function transaction                              *
// This function processes the user's choice and     *
// updates the eranings variable.                    *
//****************************************************
void transaction(Drink m[], int choice, double &earnings)
{
   // The amount of money tendered
   double money;

   // If the selected drink is sold out, display a
   // message and get out of this function.
   if (m[choice].num == 0)
   {
      cout << "Sorry, that selection is sold out.\n";
      return;
   }

   // Get some money from the customer.
   cout << "Enter an amount of money: ";
   cin >> money;

   // Make sure the customer entered at least enough
   // for the selected drink, and no more than $1.00.
   while(money < m[choice].price || money > 1.0)
   {
      cout << "Enter at least " << m[choice].price;
      cout << " and not more than 1 dollar.\n";
      cin >> money;
   }

   // Process the selection and give back any
   // change that is due.
   if (money >= m[choice].price)
   {
      // Dispense the drink.
      cout << "\nThump, thump, thump, splat!\n"
           << "Enjoy your beverage!\n\n";

      // Calculate any change that is due.
      cout << "Change calculated: " 
           << (money - m[choice].price) 
           << endl;

      // If change is due, give it to the customer.
      if ((money - m[choice].price)>0)
         cout << "Your change, " << (money - m[choice].price)
              << " has just dropped into the Change Dispenser.\n\n";

      // Update our earnings.
      earnings += m[choice].price;

      // Decrease the number of cans of the selected
      // drink currently in the machine.
      m[choice].num--;

      // Display the number of cans of this drink
      // currently in the machine.
      cout << "There are " << m[choice].num 
           << " drinks of that type left.\n";
   }
}
