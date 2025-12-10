// CSC 134 
// M6BONUS1 - PPM Image Generator
// Name: Colby Watts
// Date: December 10, 2025

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm> // Required for std::min and std::max

using namespace std;

/**
 * @brief Generates a PPM image file with a diagonal gradient.
 * @param filename The name of the file to create (e.g., "image.ppm").
 */
void generate_ppm_image(const string& filename) {
    // --- Image Constants ---
    const int WIDTH = 256;
    const int HEIGHT = 256;
    const int MAX_COLOR = 255;

    // Use ofstream to write the image data to a file
    ofstream outfile(filename);

    if (!outfile.is_open()) {
        cerr << "Error: Could not open file " << filename << " for writing." << endl;
        return;
    }

    // --- 1. PPM Header (P3 format) ---
    // Line 1: Magic Number (P3 for plain text PPM)
    outfile << "P3" << endl; 
    // Line 2: Width and Height
    outfile << WIDTH << " " << HEIGHT << endl; 
    // Line 3: Maximum Color Value (255 for 24-bit color)
    outfile << MAX_COLOR << endl;

    // --- 2. Pixel Data Generation ---
    for (int y = 0; y < HEIGHT; ++y) { // Iterate through rows (Height)
        for (int x = 0; x < WIDTH; ++x) { // Iterate through columns (Width)
            
            // Calculate R, G, B components (0-255)
            int r, g, b;

            // Red Gradient (Left to Right): Fades from 255 (x=0) to 0 (x=255)
            r = MAX_COLOR - static_cast<int>(static_cast<double>(x) / WIDTH * MAX_COLOR);
            
            // Green Gradient (Top to Bottom): Fades from 0 (y=0) to 255 (y=255)
            g = static_cast<int>(static_cast<double>(y) / HEIGHT * MAX_COLOR);
            
            // Blue Component: Constant value for a purple tint
            b = 50; 

            // Safety check (ensure values are in range, though the calculation should prevent overflow)
            r = max(0, min(MAX_COLOR, r));
            g = max(0, min(MAX_COLOR, g));
            b = max(0, min(MAX_COLOR, b));

            // Write the RGB triplet for the current pixel
            outfile << r << " " << g << " " << b << " ";
        }
        // Newline after each row helps readability of the file
        outfile << endl;
    }

    // Close the file
    outfile.close();
    cout << "PPM image successfully generated and saved to: " << filename << endl;
}


int main() {
    // Start the image generation
    generate_ppm_image("M6BONUS1_Image.ppm");
    
    cout << "\n-----------------------------------------------------" << endl;
    cout << "To view the image, you must locate the file M6BONUS1_Image.ppm" << endl;
    cout << "and upload it to a compatible viewer." << endl;
    cout << "A suggested online viewer is: [jumpshare viewer](https://jumpshare.com/viewer/ppm)" << endl;
    cout << "-----------------------------------------------------" << endl;
    
    return 0;
}