//Colby Watts
//M5HW1(Gold)
//CSC-134
//16NOV2025

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <limits> 

using namespace std;

// Function Prototypes
void calculateAverageRainfall();
void calculateBlockVolume();
void displayRomanNumeral();
void geometryCalculator();
void calculateDistanceTraveled();
void displayMainMenu(); 

// --- Q1: Average Rainfall ---
void calculateAverageRainfall() {
    cout << "\n--- Question 1: Average Rainfall ---\n";

    string month1, month2, month3;
    double rain1, rain2, rain3;

    // Helper for reading rainfall with basic type checking
    auto get_rainfall = [](const string& month) -> double {
        double rain;
        cout << "Enter rainfall for " << month << ": ";
        while (!(cin >> rain)) {
            cout << "Invalid input. Please enter a valid number for rainfall: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        return rain;
    };
    
    cout << "Enter month: ";
    cin >> month1;
    rain1 = get_rainfall(month1);
    
    cout << "Enter month: ";
    cin >> month2;
    rain2 = get_rainfall(month2);
    
    cout << "Enter month: ";
    cin >> month3;
    rain3 = get_rainfall(month3);

    double totalRainfall = rain1 + rain2 + rain3;
    double averageRainfall = totalRainfall / 3.0;

    // Display result rounded to 2 decimal places
    cout << "The average rainfall for " << month1 << ", " << month2 << ", and " << month3
         << " is " << fixed << setprecision(2) << averageRainfall << " inches.\n";
}

// --- Q2: Block Volume (with Validation) ---
void calculateBlockVolume() {
    cout << "\n--- Question 2: Block Volume (Hyperrectangle) ---\n";

    double width, length, height;

    // Helper for input and validation (no side can be zero or less)
    auto get_dimension = [](const string& dim_name) -> double {
        double value;
        do {
            cout << "Enter " << dim_name << " of the block: ";
            if (!(cin >> value)) {
                cout << "Invalid input. Please enter a valid number.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                value = 0; 
                continue;
            }
            if (value <= 0) {
                cout << "Input Validation: The " << dim_name << " cannot be zero or less.\n";
            }
        } while (value <= 0);
        return value;
    };
    
    width = get_dimension("width");
    length = get_dimension("length");
    height = get_dimension("height");

    double volume = width * length * height;
    cout << fixed << setprecision(2)
         << "The volume of the block is " << volume << ".\n";
}

// --- Q3: Roman Numeral Converter (with Validation) ---
void displayRomanNumeral() {
    cout << "\n--- Question 3: Roman Numeral Converter ---\n";

    int number;

    // Input Validation Loop (must be 1-10)
    do {
        cout << "Enter a number (1 - 10): ";
        if (!(cin >> number)) {
            cout << "Input Validation: Invalid input. Please enter an integer.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            number = 0; 
            continue;
        }
        if (number < 1 || number > 10) {
            cout << "Input Validation: Do not accept a number less than 1 or greater than 10.\n";
        }
    } while (number < 1 || number > 10);

    string romanNumeral;

    // Use a switch statement
    switch (number) {
        case 1: romanNumeral = "I"; break;
        case 2: romanNumeral = "II"; break;
        case 3: romanNumeral = "III"; break;
        case 4: romanNumeral = "IV"; break;
        case 5: romanNumeral = "V"; break;
        case 6: romanNumeral = "VI"; break;
        case 7: romanNumeral = "VII"; break;
        case 8: romanNumeral = "VIII"; break;
        case 9: romanNumeral = "IX"; break;
        case 10: romanNumeral = "X"; break;
    }

    cout << "The Roman numeral version of " << number << " is " << romanNumeral << ".\n";
}

// --- Q4: Geometry Calculator (with Validation) ---
void geometryCalculator() {
    cout << "\n--- Question 4: Geometry Calculator ---\n";

    int choice;
    const double PI = 3.14159;
    
    // Helper for non-negative input validation
    auto get_non_negative_value = [](const string& prompt, const string& error_msg) -> double {
        double value;
        do {
            cout << prompt;
            if (!(cin >> value)) {
                cout << "Invalid input. Please enter a valid number.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                value = -1.0;
                continue;
            }
            if (value < 0) {
                cout << error_msg << "\n";
            }
        } while (value < 0);
        return value;
    };


    // Display Menu and get valid choice (1-4)
    do {
        cout << "Geometry Calculator\n";
        cout << " 1. Calculate the Area of a Circle\n";
        cout << " 2. Calculate the Area of a Rectangle\n";
        cout << " 3. Calculate the Area of a Triangle\n";
        cout << " 4. Quit\n";
        cout << "Enter your choice (1-4): ";

        if (!(cin >> choice)) {
            cout << "The valid choices are 1 through 4. Run the program again and select one of those.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            choice = 0; 
            continue;
        }
        
        // Clear trailing newline AFTER reading integer choice
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (choice < 1 || choice > 4) {
            cout << "The valid choices are 1 through 4. Run the program again and select one of those.\n";
        }
    } while (choice < 1 || choice > 4);

    // Process the choice
    switch (choice) {
        case 1: {
            // Circle Area
            double radius = get_non_negative_value("Enter the circle's radius: ", "The radius cannot be less than zero.");
            double area = PI * pow(radius, 2);
            cout << "\nThe area is " << fixed << setprecision(5) << area << endl;
            break;
        }
        case 2: {
            // Rectangle Area
            double length = get_non_negative_value("Enter the rectangle's length: ", "Only enter positive values for length and width.");
            double width = get_non_negative_value("Enter the rectangle's width: ", "Only enter positive values for length and width.");

            double area = length * width;
            cout << "\nThe area is " << fixed << setprecision(2) << area << endl;
            break;
        }
        case 3: {
            // Triangle Area
            double base = get_non_negative_value("Enter the triangle's base length: ", "Only enter positive values for base and height.");
            double height = get_non_negative_value("Enter the triangle's height: ", "Only enter positive values for base and height.");

            double area = base * height * 0.5;
            cout << "\nThe area is " << fixed << setprecision(2) << area << endl;
            break;
        }
        case 4: {
            cout << "\nReturning to main menu.\n";
            break;
        }
    }
}

// --- Q5: Distance Traveled (with Validation) ---
void calculateDistanceTraveled() {
    cout << "\n--- Question 5: Distance Traveled ---\n";

    double speed;
    int hours;

    // Input Validation Loop for Speed (non-negative)
    do {
        cout << "What is the speed of the vehicle in mph? ";
        if (!(cin >> speed)) {
            cout << "Invalid input. Please enter a valid number for speed.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            speed = -1.0; 
            continue;
        }
        if (speed < 0.0) {
            cout << "Input Validation: Do not accept a negative number for speed.\n";
        }
    } while (speed < 0.0);

    // Input Validation Loop for Hours (1 or greater)
    do {
        cout << "How many hours has it traveled? ";
        if (!(cin >> hours)) {
            cout << "Invalid input. Please enter a valid integer for hours.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            hours = 0; 
            continue;
        }
        if (hours < 1) {
            cout << "Input Validation: Do not accept any value less than 1 for time traveled.\n";
        }
    } while (hours < 1);

    // Display Header
    cout << "\nHour  Distance Traveled\n";
    cout << "--------------------------------\n";

    // Loop to display distance for each hour
    for (int hour = 1; hour <= hours; ++hour) {
        double distance = speed * hour;
        cout << setw(4) << hour << setw(15) << fixed << setprecision(0) << distance << endl;
    }
}

// --- Q6: Main Menu Display Helper ---
void displayMainMenu() {
    cout << "\n========================================\n";
    cout << "           C++ Assignment Menu\n";
    cout << "========================================\n";
    cout << " 1. Calculate Average Rainfall (Q1)\n";
    cout << " 2. Calculate Block Volume (Q2)\n";
    cout << " 3. Display Roman Numeral (Q3)\n";
    cout << " 4. Geometry Calculator (Q4)\n";
    cout << " 5. Calculate Distance Traveled (Q5)\n";
    cout << " 6. Exit Program\n";
    cout << "----------------------------------------\n";
    cout << "Enter your choice (1-6): ";
}

// --- Q6: Main Program Entry Point ---
int main() {
    int choice;
    bool quit = false;

    // The main loop for the menu-driven program
    while (!quit) {
        displayMainMenu();

        // Input Validation for Menu Choice
        if (!(cin >> choice)) {
            // Handle non-integer input
            cout << "\nError: Invalid input. Please enter a number between 1 and 6.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue; 
        }
        
        // CRITICAL: Clear the buffer after reading the integer choice.
        // This ensures subsequent input operations (like cin.get() below) work correctly.
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (choice < 1 || choice > 6) {
            cout << "\nError: Invalid menu choice. Please select a number from 1 to 6.\n";
        } else {
            // Process the choice
            switch (choice) {
                case 1: calculateAverageRainfall(); break;
                case 2: calculateBlockVolume(); break;
                case 3: displayRomanNumeral(); break;
                case 4: geometryCalculator(); break;
                case 5: calculateDistanceTraveled(); break;
                case 6:
                    cout << "\nExiting the program. Goodbye! 👋\n";
                    quit = true;
                    break;
            }
        }
        
        // Pause before showing the menu again
        if (!quit) {
            cout << "\nPress Enter to return to the main menu...";
            // Wait for the user to press Enter
            cin.get(); 
        }
    }

    return 0;
}