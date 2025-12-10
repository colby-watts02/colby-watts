// CSC 134 
// M6BONUS1 - Project Prototype using Vectors
// Name: Colby Watts
// Date: December 10, 2025

#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // Required for std::find

using namespace std;

// Global Variables (Game State)
// Inventory is now managed by a std::vector, allowing dynamic size and easy search.
vector<string> inventory;

// Function Prototypes (Rooms)
void start_room();
void garden_path();
void watchtower();
void treasury();
void game_win();
void game_over(const string& reason);

/**
 * @brief Checks if an item is in the inventory.
 * @param item The string name of the item to check.
 * @return true if the item is found, false otherwise.
 */
bool check_inventory(const string& item) {
    // Uses the vector's find algorithm for a cleaner check than manual iteration.
    return find(inventory.begin(), inventory.end(), item) != inventory.end();
}

/**
 * @brief Displays the current inventory.
 */
void display_inventory() {
    cout << "\n--- INVENTORY ---" << endl;
    if (inventory.empty()) {
        cout << "Inventory is empty." << endl;
    } else {
        cout << "Items: ";
        for (const string& item : inventory) {
            cout << item << " | ";
        }
        cout << endl;
    }
    cout << "-----------------" << endl;
}

int main()
{
    // Start the game
    start_room();
    
    return 0;
}

// =========================================================================
// ROOM FUNCTIONS (Modified to use check_inventory and vector<string>)
// =========================================================================

void start_room() {
    int choice;
    cout << "\n========================================================" << endl;
    cout << "ROOM: STARTING CHAMBER" << endl;
    cout << "========================================================" << endl;
    
    cout << "You awaken in a damp, stone room. Seek the Sun Token in the tower, and bring it to the Treasury to escape." << endl;

    while (true) {
        cout << "\nYou see two exits: a large iron door to the north and a winding path to the west." << endl;
        cout << "1. Go NORTH (Iron Door)" << endl;
        cout << "2. Go WEST (Winding Path)" << endl;
        cout << "3. Check Inventory" << endl;
        cout << "4. (Debug) Check door lock - Try to pick it" << endl; // Added a new choice for demonstration
        cout << "Enter your choice (1, 2, 3, or 4): ";
        
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input. Please enter a number." << endl;
            continue;
        }

        if (choice == 1) {
            watchtower();
            break;
        } else if (choice == 2) {
            garden_path();
            break;
        } else if (choice == 3) {
            display_inventory();
        } else if (choice == 4) {
            game_over("You attempt to pick the massive iron door. A guard catches you and throws you in the dungeon.");
            break;
        } else {
            cout << "Invalid choice. Try again." << endl;
        }
    }
}

void garden_path() {
    int choice;
    cout << "\n========================================================" << endl;
    cout << "ROOM: GARDEN PATH" << endl;
    cout << "========================================================" << endl;
}