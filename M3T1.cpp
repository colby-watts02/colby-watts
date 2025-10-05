// CSC 134
// M3T1 
// Colby Watts
// 2/17/2025
// Ask the user for the width and length of two rectangles
// Find the area

#include <iostream>
#include <limits> // Required for numeric_limits

using namespace std;

// Function to handle input and error-checking for a single dimension
double get_dimension(const string& prompt) {
    double dimension;
    while (true) {
        cout << prompt;
        if (cin >> dimension) {
            // Input was successful, break the loop and return the dimension
            return dimension;
        } else {
            // Input failed (e.g., user entered a letter)
            cout << "Invalid input. Please enter a valid number.\n";
            // 1. Clear the fail state of cin
            cin.clear();
            // 2. Discard all characters in the input buffer up to the next newline
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

int main() {

    // Variables
    double len1, wid1, len2, wid2; 
    double area1, area2;

    // --- Input for First Rectangle (using the robust function) ---
    len1 = get_dimension("What's the length of the first rectangle? ");
    wid1 = get_dimension("What's the width of the first rectangle? ");

    // --- Input for Second Rectangle (using the robust function) ---
    // This is the part that was most likely being skipped due to bad input earlier.
    len2 = get_dimension("What's the length of the second rectangle? ");
    wid2 = get_dimension("What's the width of the second rectangle? ");

    // -----------------------------------------------------------------
    // Find the area
    area1 = len1 * wid1;
    area2 = len2 * wid2;

    // -----------------------------------------------------------------
    // Print the area
    cout << "\n--- Area Results ---\n";
    cout << "Rectangle 1:\n";
    cout << "Length: " << len1 << ", Width: " << wid1 << "\n";
    cout << "The area of the first rectangle is: " << area1 << "\n\n";

    cout << "Rectangle 2:\n";
    cout << "Length: " << len2 << ", Width: " << wid2 << "\n";
    cout << "The area of the second rectangle is: " << area2 << "\n";

    return 0;
}