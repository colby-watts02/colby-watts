//colby watts
//M2LAB
//CSC-134
//10DEC2025

#include <iostream>
#include <iomanip> // Required for formatting currency output

using namespace std;

int main()
{
    // 1. Define Constants
    // These values cannot be changed during program execution.
    const double COST_PER_CUBIC_FOOT = 0.10;
    const double CHARGE_PER_CUBIC_FOOT = 0.50;

    // 2. Define Variables
    double length, // Crate length
           width,  // Crate width
           height, // Crate height
           volume, // Crate volume
           cost,   // Cost to build the crate
           charge, // Price charged to the customer
           profit; // Profit made on the crate

    // 3. Set up Output Formatting
    cout << fixed << showpoint << setprecision(2);

    // 4. Input Phase: Get the crate dimensions from the user.
    cout << "Enter the length of the crate (in feet): ";
    cin >> length;

    cout << "Enter the width of the crate (in feet): ";
    cin >> width;

    cout << "Enter the height of the crate (in feet): ";
    cin >> height;

    // 5. Processing Phase: Perform the calculations.

    // Calculate the volume of the crate (Length x Width x Height)
    volume = length * width * height;

    // Calculate the cost to build the crate
    cost = volume * COST_PER_CUBIC_FOOT;

    // Calculate the customer's charge for the crate
    charge = volume * CHARGE_PER_CUBIC_FOOT;

    // Calculate the profit
    profit = charge - cost;

    // 6. Output Phase: Display the results.
    cout << "\n----------------------------------------\n";
    cout << "The volume of the crate is: " << volume << " cubic feet\n";
    cout << "Cost to build the crate: $" << cost << endl;
    cout << "Customer charge:         $" << charge << endl;
    cout << "Profit:                  $" << profit << endl;
    cout << "----------------------------------------\n";

    return 0;
}