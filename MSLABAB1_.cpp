
/*
CSC 134
M5LAB1 - Choose Your Own Adventure
colby watts
[11/09/2025]
This template serves as a starting point
for your own program. We'll be using
void functions to tell a simple story,
where the user gets to make choices.
*/

#include <iostream>
using namespace std;

// Function Prototypes (Declarations)
// -----------------------------------------------------
void main_menu();
void choice_front_door();
void choice_back_door();
void choice_go_home();
void choice_basement_door();
void choice_inner_hallway(); 
void choice_take_stairs_up();    
void choice_find_hidden_key();  
// -----------------------------------------------------

int main() {
  cout << "M5LAB1 - Choose Your Own Adventure" << endl;
  main_menu();
  cout << "Thanks for playing!" << endl;
  return 0; // finished with no errors
}

// FUNCTION DEFINITIONS (Implementations)
// -----------------------------------------------------

void main_menu() {
  int choice;
  bool valid_choice = false;

  // Use a DO-WHILE loop for robust validation
  do {
    cout << "---" << endl;
    cout << "Main Menu" << endl;
    cout << "You're in front of a **spooky old house**..." << endl;
    cout << "Do you:" << endl;
    cout << "1. Try the front door" << endl;
    cout << "2. **Sneak around back**" << endl;
    cout << "3. **Forget it, and go home**" << endl;
    cout << "4. [Quit]" << endl;
    cout << "Choose: ";

    if (!(cin >> choice)) {
      // Handle non-integer input (e.g., user types 'A')
      cout << "**That's not a valid input type (must be a number), please try again.**" << endl;
      cin.clear();
      cin.ignore(10000, '\n'); 
      choice = 0; // Set choice to invalid value to re-run loop
    } else {
      // Check for valid number range
      if (choice >= 1 && choice <= 4) {
        valid_choice = true; 
      } else {
        cout << "**That's not a valid choice (must be 1-4), please try again.**" << endl;
      }
    }
  } while (!valid_choice);

  // Execute the action based on valid choice
  if (1 == choice) {
    choice_front_door();
  } else if (2 == choice) {
    choice_back_door();
  } else if (3 == choice) {
    choice_go_home();
  } else if (4 == choice) {
    cout << "Ok, quitting game" << endl;
    return;
  }
}

void choice_front_door() {
  cout << "---" << endl;
  cout << "**Try the front door.**" << endl;
  cout << "It's locked. " << endl;
  cout << "Do you:" << endl;
  cout << "1. Check around back" << endl;
  cout << "2. Give up and go home" << endl;
  cout << "3. Try to force the lock (Hidden Path)" << endl;
  int choice;
  cout << "Choose: ";
  
  // Input read with basic validation check
  if (!(cin >> choice)) { choice = 0; cin.clear(); cin.ignore(10000, '\n'); }
  
  if (1 == choice) {
    choice_back_door();
  } else if (2 == choice) {
    choice_go_home();
  } else if (3 == choice) {
    choice_inner_hallway();
  } else {
    cout << "**Invalid choice. Going back to Main Menu.**" << endl;
    main_menu();
  }
}

void choice_back_door() {
  cout << "---" << endl;
  cout << "**You sneak around the back.** The air is cold and smells like mildew." << endl;
  cout << "You find a basement door. It's slightly ajar." << endl;
  cout << "Do you:" << endl;
  cout << "1. Push the door open and go in (Basement)." << endl;
  cout << "2. Go back to the front." << endl;
  cout << "3. Give up and go home." << endl;
  int choice;
  cout << "Choose: ";
  
  // Input read with basic validation check
  if (!(cin >> choice)) { choice = 0; cin.clear(); cin.ignore(10000, '\n'); }

  if (1 == choice) {
    choice_basement_door();
  } else if (2 == choice) {
    main_menu();
  } else if (3 == choice) {
    choice_go_home();
  } else {
    cout << "**Invalid choice. Going back to Main Menu.**" << endl;
    main_menu();
  }
}

void choice_go_home() {
  cout << "---" << endl;
  cout << "**You decide it's not worth the trouble.**" << endl;
  cout << "You walk back down the road, and the spooky house fades into the fog." << endl;
  cout << "You made it home safely. **The End.**" << endl;
  return;
}

void choice_basement_door() {
    cout << "---" << endl;
    cout << "**You push the door and stumble down the dark, creaky stairs.**" << endl;
    cout << "The basement is damp and smells strongly of old earth." << endl;
    cout << "You hear a faint **clanking sound** coming from a dark corner." << endl;
    cout << "Do you:" << endl;
    cout << "1. Call out, 'Hello?'" << endl;
    cout << "2. Try to sneak back out the door." << endl;
    cout << "3. Look under the stairs for something useful." << endl; 
    int choice;
    cout << "Choose: ";

    // Input read with basic validation check
    if (!(cin >> choice)) { choice = 0; cin.clear(); cin.ignore(10000, '\n'); }

    if (1 == choice) {
        cout << "A rusty suit of armor clanks and turns its head toward you. It lifts a sword. **Game Over.**" << endl;
    } else if (2 == choice) {
        cout << "You try to sneak back up, but the door slams shut, locking you in! **Game Over.**" << endl;
    } else if (3 == choice) {
        choice_find_hidden_key();
    } else {
        cout << "**Invalid choice. The sounds stop, and you wait in the dark. Game Over.**" << endl;
    }
    return;
}

void choice_inner_hallway() {
    cout << "---" << endl;
    cout << "**You manage to pry open a hidden latch on the front door and slip into a wide, echoing hallway.**" << endl;
    cout << "There is a **staircase** leading up and a **shadowy doorway** on the left." << endl;
    cout << "Do you:" << endl;
    cout << "1. Take the stairs up." << endl; 
    cout << "2. Enter the shadowy doorway." << endl;
    cout << "3. Go back outside." << endl;
    int choice;
    cout << "Choose: ";

    // Input read with basic validation check
    if (!(cin >> choice)) { choice = 0; cin.clear(); cin.ignore(10000, '\n'); }

    if (1 == choice) {
        choice_take_stairs_up();
    } else if (2 == choice) {
        cout << "You enter the doorway and a ghost pushes you into a closet. **Game Over.**" << endl;
    } else if (3 == choice) {
        main_menu();
    } else {
        cout << "**Invalid choice. You stand paralyzed by fear. Game Over.**" << endl;
    }
}

void choice_take_stairs_up() {
    cout << "---" << endl;
    cout << "**You quietly climb the grand staircase.**" << endl;
    cout << "At the top, the hallway is lined with portraits whose eyes seem to follow you." << endl;
    cout << "A door at the end of the hall is slightly open, light spilling out." << endl;
    cout << "Do you:" << endl;
    cout << "1. Creep toward the light." << endl;
    cout << "2. Try to go back down the stairs." << endl;
    int choice;
    cout << "Choose: ";
    
    // Input read with basic validation check
    if (!(cin >> choice)) { choice = 0; cin.clear(); cin.ignore(10000, '\n'); }
    
    if (1 == choice) {
        cout << "You open the door and find a tea party with a dozen creepy dolls. They turn their heads in unison. **Game Over.**" << endl;
    } else if (2 == choice) {
        cout << "You hear a loud creak from below. You rush down, but the front door is sealed shut! **Game Over.**" << endl;
    } else {
        cout << "**Invalid choice. The portraits start whispering your name. Game Over.**" << endl;
    }
    return;
}

void choice_find_hidden_key() {
    cout << "---" << endl;
    cout << "**You crawl under the lowest stair, scraping your knees on the concrete.**" << endl;
    cout << "Your hand brushes against something cold and metallic: **A key!**" << endl;
    cout << "You pocket the key and look back toward the clanking sound." << endl;
    cout << "Do you:" << endl;
    cout << "1. Now investigate the clanking sound." << endl;
    cout << "2. Quickly use the key on the basement door." << endl;
    int choice;
    cout << "Choose: ";

    // Input read with basic validation check
    if (!(cin >> choice)) { choice = 0; cin.clear(); cin.ignore(10000, '\n'); }

    if (1 == choice) {
        cout << "The key slips from your pocket, landing at the foot of the rusty suit of armor, which stomps on it, breaking it. **Game Over.**" << endl;
    } else if (2 == choice) {
        cout << "You rush to the door, unlock it, and race outside! You made a clean escape! **You Win!**" << endl;
    } else {
        cout << "**Invalid choice. You hesitate, and the key vanishes from your hand. Game Over.**" << endl;
    }
    return;
}