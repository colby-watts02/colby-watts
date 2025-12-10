// CSC 134 
// M6HW1 - Project Prototype (Gold Tier)
// Name: Colby Watts
// Date: December 10, 2025

#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // Required for std::find

using namespace std;

// Global Variables (Inventory and Game State)
vector<string> inventory;
bool has_key = false;
bool has_token = false; // Item needed for the final puzzle

// Function Prototypes (Rooms)
void start_room();
void garden_path();
void watchtower();
void treasury();
void game_win();

/**
 * @brief Checks if an item is in the inventory.
 * @param item The string name of the item to check.
 * @return true if the item is found, false otherwise.
 */
bool check_inventory(const string& item) {
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
    // Start the game in the first room
    start_room();
    
    return 0;
}

// =========================================================================
// ROOM FUNCTIONS
// =========================================================================

/**
 * @brief Room 1: The Starting Chamber (Decision Point 1)
 * Purpose: Explain the game's objective and offer first choices.
 */
void start_room() {
    int choice;
    cout << "\n========================================================" << endl;
    cout << "ROOM: STARTING CHAMBER" << endl;
    cout << "========================================================" << endl;
    
    // Dialog explaining the point of the game (Silver requirement)
    cout << "You awaken in a damp, stone room. An ancient voice echoes in your mind:" << endl;
    cout << "\"Seek the Sun Token in the tower, and bring it to the Treasury to escape.\"" << endl;

    while (true) {
        cout << "\nYou see two exits: a large iron door to the north and a winding path to the west." << endl;
        cout << "1. Go NORTH (Iron Door)" << endl;
        cout << "2. Go WEST (Winding Path)" << endl;
        cout << "3. Check Inventory" << endl;
        cout << "Enter your choice (1, 2, or 3): ";
        
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input. Please enter a number." << endl;
            continue;
        }

        if (choice == 1) {
            watchtower(); // Go to Watchtower (Lock/Key Destination)
            break;
        } else if (choice == 2) {
            garden_path(); // Go to Garden Path (Key/Token Source)
            break;
        } else if (choice == 3) {
            display_inventory();
        } else {
            cout << "Invalid choice. Try again." << endl;
        }
    }
}

/**
 * @brief Room 2: The Garden Path (Decision Point 2)
 * Purpose: Key interaction and an item pickup.
 */
void garden_path() {
    int choice;
    cout << "\n========================================================" << endl;
    cout << "ROOM: GARDEN PATH" << endl;
    cout << "========================================================" << endl;
    
    cout << "You walk down a lush path. A small fountain bubbles nearby. " << endl;
    
    // Interaction: picking up an item (Silver requirement)
    if (!has_token) {
        cout << "You notice a shimmering 'SUN TOKEN' resting at the edge of the fountain." << endl;
        cout << "1. Pick up the SUN TOKEN" << endl;
    } else {
        cout << "The fountain is empty now." << endl;
    }

    cout << "2. Return to the STARTING CHAMBER" << endl;
    cout << "Enter your choice (1 or 2): ";
    
    if (!(cin >> choice)) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Invalid input. Please enter a number." << endl;
        garden_path(); // Loop back
        return;
    }

    if (choice == 1 && !has_token) {
        inventory.push_back("Sun Token");
        has_token = true;
        cout << "\nYou pick up the Sun Token and place it in your bag. It feels warm." << endl;
        garden_path(); // Stay in the room after interaction
    } else if (choice == 2) {
        start_room();
    } else {
        cout << "Invalid choice or action already completed." << endl;
        garden_path();
    }
}

/**
 * @brief Room 3: The Watchtower (Decision Point 3)
 * Purpose: The "lock" side of the lock-and-key mechanic.
 */
void watchtower() {
    int choice;
    cout << "\n========================================================" << endl;
    cout << "ROOM: WATCHTOWER" << endl;
    cout << "========================================================" << endl;

    cout << "The iron door creaks open. You ascend a spiral staircase to a dusty room." << endl;
    cout << "A pedestal stands in the center with a note that reads: 'THE KEY IS HIDDEN UNDER THE LOOSE FLAGSTONE'." << endl;
    
    // Lock-and-Key Mechanic (Gold requirement - Key pickup)
    if (!has_key) {
        cout << "1. Look under the loose flagstone." << endl;
    } else {
        cout << "The space under the flagstone is now empty." << endl;
    }
    
    cout << "2. Return to the STARTING CHAMBER." << endl;
    cout << "3. Proceed to the TREASURY (Exit)." << endl;
    cout << "Enter your choice (1, 2, or 3): ";
    
    if (!(cin >> choice)) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Invalid input. Please enter a number." << endl;
        watchtower(); // Loop back
        return;
    }

    if (choice == 1 && !has_key) {
        inventory.push_back("Iron Key");
        has_key = true;
        cout << "\nYou find a rusty 'IRON KEY' and add it to your inventory." << endl;
        watchtower(); // Stay in the room after interaction
    } else if (choice == 2) {
        start_room();
    } else if (choice == 3) {
        treasury();
    } else {
        cout << "Invalid choice." << endl;
        watchtower();
    }
}

/**
 * @brief Room 4: The Treasury (The Lock and Final Ending)
 * Purpose: The "key" side of the lock-and-key and the game ending.
 */
void treasury() {
    int choice;
    cout << "\n========================================================" << endl;
    cout << "ROOM: THE TREASURY" << endl;
    cout << "========================================================" << endl;

    cout << "A heavy oak door blocks your path. This must be the Treasury." << endl;

    // Lock-and-Key Mechanic (Gold requirement - Lock usage)
    if (!has_key) {
        cout << "The door is locked. You need a key to enter." << endl;
        cout << "1. Retreat to the WATCHTOWER." << endl;
        
        if (!(cin >> choice) || choice != 1) {
            cout << "Invalid choice. Retreating..." << endl;
            watchtower();
            return;
        }
        watchtower();
        return;
    } else {
        cout << "Using the IRON KEY, you unlock the door and step into a vast, empty room." << endl;
        cout << "A single, small pedestal sits in the center with a depression shaped like a token." << endl;
        
        if (has_token) {
            cout << "1. Place the SUN TOKEN in the pedestal." << endl;
        } else {
            cout << "You feel like you need a special item to place here." << endl;
        }

        cout << "2. Retreat to the WATCHTOWER." << endl;
        cout << "Enter your choice (1 or 2): ";

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input. Retreating..." << endl;
            watchtower();
            return;
        }

        if (choice == 1 && has_token) {
            game_win(); // Final Ending
        } else if (choice == 2) {
            watchtower();
        } else {
            cout << "Invalid action or missing item." << endl;
            treasury();
        }
    }
}

/**
 * @brief Game Ending (Gold requirement)
 */
void game_win() {
    cout << "\n========================================================" << endl;
    cout << "         V I C T O R Y ! ! ! " << endl;
    cout << "========================================================" << endl;
    cout << "As the Sun Token settles into the pedestal, a blinding light erupts." << endl;
    cout << "The walls dissolve, and you find yourself standing outside, free." << endl;
    cout << "You have completed the challenge and escaped the chamber." << endl;
    cout << "\n--- PROGRAM ENDS ---" << endl;
}