#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>

// Function to generate a strong random passphrase
std::string generateStrongPassphrase(int numWords, int wordLength) {
    const std::vector<std::string> wordlist = {
        "apple", "banana", "cherry", "dragon", "elephant",
        "flamingo", "giraffe", "hedgehog", "iguana", "jaguar",
        "koala", "lemur", "mongoose", "narwhal", "octopus"
    };

    std::string passphrase = "";

    // Seed the random number generator
    srand(static_cast<unsigned int>(time(0));

    for (int i = 0; i < numWords; ++i) {
        int randomIndex = rand() % wordlist.size();
        std::string word = wordlist[randomIndex];

        // Optionally, capitalize the first letter of each word
        if (rand() % 2 == 0) {
            word[0] = toupper(word[0]);
        }

        passphrase += word;

        // Add a separator between words, such as a space or hyphen
        if (i < numWords - 1) {
            if (rand() % 2 == 0) {
                passphrase += " ";
            } else {
                passphrase += "-";
            }
        }
    }

    return passphrase;
}

int main() {
    int numWords, wordLength;
    
    std::cout << "Welcome to the Strong Passphrase Generator!\n";
    std::cout << "Enter the number of words in the passphrase: ";
    std::cin >> numWords;

    std::cout << "Enter the desired word length (e.g., 4 for 'apple'): ";
    std::cin >> wordLength;

    if (numWords <= 0 || wordLength <= 0) {
        std::cout << "Invalid input. Please enter positive integers for the number of words and word length.\n";
    } else {
        std::string strongPassphrase = generateStrongPassphrase(numWords, wordLength);
        std::cout << "Your strong passphrase is: " << strongPassphrase << std::endl;
    }

    return 0;
}
