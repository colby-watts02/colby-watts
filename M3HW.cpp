// CSC 134 
// M3HW1 - Gold 
// Name: Colby Watts
// Date: December 10, 2025

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib> // Required for rand() and srand()
#include <ctime>   // Required for time()

using namespace std;

int main()
{
    // Initialize random number generator for Question 4
    srand(time(0)); 

    cout << "============================================" << endl;
    cout << "           M3HW1 - GOLD TIER SOLUTION       " << endl;
    cout << "============================================" << endl;

    // -----------------------------------------------------------------
    // Question 1: Simple Chat Bot
    // -----------------------------------------------------------------
    cout << "\n--- Question 1: Simple Chat Bot ---\n";

    string user_feeling;

    cout << "Hello, I’m a C++ program!" << endl;
    cout << "Do you like me? Please type yes or no." << endl;
    cin >> user_feeling;

    if (user_feeling == "yes")
    {
        cout << "That’s great! I’m sure we’ll get along." << endl;
    }
    else if (user_feeling == "no")
    {
        cout << "Well, maybe you’ll learn to like me later." << endl;
    }
    else
    {
        cout << "If you’re not sure… that’s OK." << endl;
    }

    // -----------------------------------------------------------------
    // Question 2: Enhanced Receipt Calculator
    // -----------------------------------------------------------------
    cout << "\n--- Question 2: Enhanced Receipt Calculator ---\n";

    // Constants for the receipt calculation
    const double TAX_RATE = 0.08;   // Example tax rate (8%)
    const double TIP_RATE = 0.15;   // Tip rate for dine-in (15%)
    
    // Variables for Q2
    double meal_price_q2;
    int dine_in_or_takeaway;
    double tax_amount_q2;
    double tip_amount_q2 = 0.0; // Initialize tip to 0.0
    double total_amount_q2;

    cout << "--- Receipt Calculator ---" << endl;
    cout << "Please enter the price of the meal: $";
    cin >> meal_price_q2;

    cout << "Is the order dine in or takeaway?" << endl;
    cout << "Please enter 1 if the order is dine in, 2 if it is to go: ";
    cin >> dine_in_or_takeaway;

    // Calculate tax (applies to all orders)
    tax_amount_q2 = meal_price_q2 * TAX_RATE;

    // Apply tip if the order is dine in (1)
    if (dine_in_or_takeaway == 1)
    {
        tip_amount_q2 = meal_price_q2 * TIP_RATE;
    }

    // Calculate total
    total_amount_q2 = meal_price_q2 + tax_amount_q2 + tip_amount_q2;

    // Print Receipt
    cout << fixed << showpoint << setprecision(2);
    cout << "\n--- Your Receipt ---" << endl;
    cout << left << setw(15) << "Meal Price:" << "$" << right << setw(8) << meal_price_q2 << endl;
    cout << left << setw(15) << "Tax Amount:" << "$" << right << setw(8) << tax_amount_q2 << endl;
    cout << left << setw(15) << "Tip Amount:" << "$" << right << setw(8) << tip_amount_q2 << endl;
    cout << left << setw(15) << "Total Due:" << "$" << right << setw(8) << total_amount_q2 << endl;
    cout << "--------------------" << endl;


    // -----------------------------------------------------------------
    // Question 3: Simple Choose Your Own Adventure (CYOA) Game
    // -----------------------------------------------------------------
    cout << "\n--- Question 3: Choose Your Own Adventure ---\n";

    string first_choice_q3;
    string second_choice_q3;

    cout << "You wake up in a dark, dusty library. You see two paths." << endl;
    cout << "Do you go through the 'LEFT' door or the 'RIGHT' archway?" << endl;
    cout << "Type LEFT or RIGHT: ";
    cin >> first_choice_q3;

    if (first_choice_q3 == "RIGHT")
    {
        // Path to Game Over
        cout << "\nYou step into the archway. A giant, hungry cyclops is waiting." << endl;
        cout << "You become its midday snack. GAME OVER." << endl;
    }
    else if (first_choice_q3 == "LEFT")
    {
        // Path to the Second Choice (Nested if required here)
        cout << "\nBrave choice! The left door leads to a narrow corridor." << endl;
        cout << "At the end, you see a pedestal with a glowing SWORD and a dusty BOOK." << endl;
        cout << "Do you take the 'SWORD' or the 'BOOK'?" << endl;
        cout << "Type SWORD or BOOK: ";
        cin >> second_choice_q3;

        if (second_choice_q3 == "BOOK")
        {
            // Path to Defeat
            cout << "\nAs you grab the book, the floor gives way! You fall into a pit of spiders." << endl;
            cout << "DEFEAT." << endl;
        }
        else if (second_choice_q3 == "SWORD")
        {
            // Path to Victory
            cout << "\nYou take the glowing sword. The library shakes and a demon appears!" << endl;
            cout << "You use the ancient sword to banish the demon forever. VICTORY!" << endl;
        }
        else
        {
            cout << "\nIndecision is deadly. A hidden trap springs and locks you in a cage. DEFEAT." << endl;
        }
    }
    else
    {
        cout << "\nInvalid input. You stumble and trip over a book, knocking yourself unconscious. GAME OVER." << endl;
    }

    // -----------------------------------------------------------------
    // Question 4: Simple Math Practice Program
    // -----------------------------------------------------------------
    cout << "\n--- Question 4: Simple Math Practice ---\n";

    // Generate two random single-digit numbers (0-9)
    int num1 = rand() % 10;
    int num2 = rand() % 10;
    int correct_answer = num1 + num2;
    int user_answer;

    cout << "What is " << num1 << " plus " << num2 << "?" << endl;
    cout << "Your answer: ";
    cin >> user_answer;

    if (user_answer == correct_answer)
    {
        cout << "Correct! Great job." << endl;
    }
    else
    {
        cout << "Incorrect. The correct answer is " << correct_answer << "." << endl;
    }
    
    cout << "\n============================================" << endl;
    cout << "Program finished." << endl;
    
    return 0;
}