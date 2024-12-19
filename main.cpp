//Programmer: Sophia Bhoria
//Date: 10/22/2024
//Purpose: A program that reads an input file and prints the number of characters and words in that file.

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>  // Needed for istringstream

using namespace std;

int main() {
    ifstream file("input.txt");  // Opening the input file
    if (!file.is_open()) {
        cerr << "Error: Could not open the file." << endl;
        return 1;
    }

    string line;
    int wordCount = 0;
    int charCount = 0;

    // Read the file line by line
    while (getline(file, line)) {
        charCount += line.length() + 1;  // Add number of characters in the line + 1 for the newline

        // Refined word count
        bool inWord = false;
        for (char c : line) {
            if (isspace(c)) {
                if (inWord) {
                    wordCount++;
                    inWord = false;
                }
            } else {
                inWord = true;
            }
        }
        // If the last character in the line is part of a word
        if (inWord) {
            wordCount++;
        }
    }

    file.close();  // Closing the file

    // Output the results
    cout << "Number of words: " << wordCount << endl;
    cout << "Number of characters: " << charCount << endl;

    return 0;
}
