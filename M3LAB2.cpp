/*
CSC 134
M3LAB3 - Grading critira
Colby Watts
10/11/25
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    // 1. Variable Declaration
    double numericGrade;
    
    // 2. User Input
    cout << "--- Number Grade to Letter Grade Converter ---" << endl;
    cout << "Enter your numerical grade (0-100): ";
    
    // Check if the input is a valid number
    if (!(cin >> numericGrade)) {
        cout << "Invalid input. Please enter a number." << endl;
        return 1; // Exit with error code
    }

    // 3. Input Validation
    if (numericGrade < 0 || numericGrade > 100) {
        cout << "Error: Grade must be between 0 and 100." << endl;
        return 1; // Exit with error code
    }

    // The checks must be performed in descending order of grade boundaries.
    
    char letterGrade;
    
    if (numericGrade >= 90) {
        letterGrade = 'A';
    } else if (numericGrade >= 80) {
        // This condition is true for grades 80.0 through 89.9...
        letterGrade = 'B';
    } else if (numericGrade >= 70) {
        letterGrade = 'C';
    } else if (numericGrade >= 60) {
        letterGrade = 'D';
    } else {
        letterGrade = 'F';
    }

    // 5. Output
    cout << "\nYour numerical grade is: " << fixed << setprecision(1) << numericGrade << endl;
    cout << "Your letter grade is: " << letterGrade << endl;

    return 0; // Program executed successfully
}