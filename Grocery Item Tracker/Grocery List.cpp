#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <iomanip>

// GroceryTracker class manages item frequency tracking
class GroceryTracker {
private:
    std::map<std::string, int> itemFrequencyMap; // Map to store item names and their purchase frequencies

public:
    // Loads items from input file and counts their frequency
    void LoadItemsFromFile(const std::string& filename) {
        std::ifstream inFile(filename);
        std::string item;
        while (inFile >> item) {
            ++itemFrequencyMap[item]; // Increment count for each item
        }
        inFile.close();
    }

    // Writes item frequencies to an output file
    void SaveFrequencyToFile(const std::string& filename) {
        std::ofstream outFile(filename);
        for (const auto& pair : itemFrequencyMap) {
            outFile << pair.first << " " << pair.second << std::endl; // Format: ItemName Frequency
        }
        outFile.close();
    }

    // Returns the frequency of a specific item
    int GetItemFrequency(const std::string& item) {
        if (itemFrequencyMap.count(item)) {
            return itemFrequencyMap[item];
        } else {
            return 0; // If item not found, return 0
        }
    }

    // Prints all items with their frequencies
    void PrintAllFrequencies() {
        for (const auto& pair : itemFrequencyMap) {
            std::cout << pair.first << " " << pair.second << std::endl;
        }
    }

    // Prints a histogram of item frequencies using asterisks
    void PrintHistogram() {
        for (const auto& pair : itemFrequencyMap) {
            std::cout << std::setw(12) << std::left << pair.first << " "; // Align item names
            for (int i = 0; i < pair.second; ++i) {
                std::cout << "*"; // One asterisk per occurrence
            }
            std::cout << std::endl;
        }
    }
};

// Displays the main menu
void ShowMenu() {
    std::cout << "\n=== Corner Grocer Menu ===\n";
    std::cout << "1. Search for Item Frequency\n";
    std::cout << "2. Display All Item Frequencies\n";
    std::cout << "3. Display Histogram\n";
    std::cout << "4. Exit\n";
    std::cout << "Choose an option: ";
}

int main() {
    GroceryTracker tracker;
    std::string inputFile = "CS210_Project_Three_Input_File.txt";
    std::string outputFile = "frequency.dat";

    tracker.LoadItemsFromFile(inputFile);     // Load and count items from input file
    tracker.SaveFrequencyToFile(outputFile);  // Save results to backup file

    int choice;
    do {
        ShowMenu(); // Display the menu
        std::cin >> choice;

        // Input validation: ensure user enters an integer between 1 and 4
        while (std::cin.fail() || choice < 1 || choice > 4) {
            std::cin.clear();                // Clear error flag
            std::cin.ignore(1000, '\n');     // Discard invalid input
            std::cout << "Invalid input. Enter 1-4: ";
            std::cin >> choice;
        }

        std::cin.ignore(); // Flush newline character after number input

        // Handle user's menu choice
        switch (choice) {
        case 1: {
            std::string item;
            std::cout << "Enter item name: ";
            std::getline(std::cin, item); // Read full line to allow for multi-word items
            std::cout << item << " was purchased " << tracker.GetItemFrequency(item) << " times.\n";
            break;
        }
        case 2:
            tracker.PrintAllFrequencies(); // Show all items with counts
            break;
        case 3:
            tracker.PrintHistogram(); // Show visual histogram
            break;
        case 4:
            std::cout << "Exiting... Goodbye!\n"; // Exit message
            break;
        }
    } while (choice != 4); // Loop until user chooses to exit

    return 0;
}
