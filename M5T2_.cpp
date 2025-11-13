//Colby Watts
//CSC-134
//13NOV2025

#include <iostream>
#include <iomanip>

using namespace std;

// Function Prototypes
int square(int num);
void printAnswerLine(int original, int squared);

int main() {
    // Print a header for the output
    cout << "Number | Square" << endl;
    cout << "-------+--------" << endl;
    
    // Loop from 1 to 10
    for (int i = 1; i <= 10; ++i) {
        // 1. Calculate the square using the value-returning function
        int result = square(i);
        
        // 2. Print the formatted line using the void function
        printAnswerLine(i, result);
    }
    
    return 0;
}

// Function Definitions

/**
 * @brief
 * * @param num 
 * @return 
 */
int square(int num) {
    // Value-Returning Function
    return num * num; 
}
/**
 * @brief
 * * @param original 
 * @param squared
/**
 * @brief Void Function
 * @param squared
 */
void printAnswerLine(int original, int squared) {
    cout << setw(6) << original << " | " << setw(8) << squared << endl;
}