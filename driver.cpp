/**********************************************************************************************
 *
 * CIS269 - Data Structures
 * Pima College - Spring 2024
 * Chapter 21 - Pg 1574 - Ex #8
 * Card Guessing Game - "driver.cpp"
 *
 * This program utilizes vectors and the Card class to create a Card Guessing Game. 
 * It gives the user the following choices:
 *	
 *	a. Guess only the face value of the card.
 *	b. Guess only the suit of the card.
 *	c. Guess both the face value and suit of the card.
 * 
 *	Before the start of the game, the program create a deck of cards. Before each guess,
 *	it uses the function random_shuffle to randomly shuffle the deck.
 *
 * Author: Sean Castle
 *
**********************************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cctype>
#include <string>
#include "card.h" // Include the card.h file

// Function to print the game menu
void printMenu() {
    std::cout << "Card Guessing Game\n";
    std::cout << "1. Guess the face value of the card\n";
    std::cout << "2. Guess the suit of the card\n";
    std::cout << "3. Guess both the face value and suit of the card\n";
    std::cout << "4. Exit\n";
}

// Static arrays for face value and suit strings
static const std::string faceValueStrings[] = { "ace", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "jack", "queen", "king" };
static const std::string suitStrings[] = { "clubs", "diamonds", "hearts", "spades" };

int main() {
    std::srand(std::time(nullptr)); // Seed the random number generator

    // Create a deck of cards
    std::vector<Card> deck;
    for (int suit = CLUBS; suit <= SPADES; ++suit) {
        for (int faceValue = ACE; faceValue <= KING; ++faceValue) {
            deck.emplace_back(static_cast<Suit>(suit), static_cast<FaceValue>(faceValue));
        }
    }

    int choice;
    do {
        printMenu(); // Print the game menu
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (choice == 4) {
            break;
        }

        std::random_shuffle(deck.begin(), deck.end()); // Shuffle the deck

        Card topCard = deck.back(); // Get the top card from the shuffled deck

        switch (choice) {
        case 1: {
            std::cout << "Guess the face value of the card: ";
            std::string guess;
            std::cin >> guess;
            std::transform(guess.begin(), guess.end(), guess.begin(), ::tolower); // Convert guess to lowercase

            if (std::find(std::begin(faceValueStrings), std::end(faceValueStrings), guess) != std::end(faceValueStrings)) {
                FaceValue guessedFaceValue = static_cast<FaceValue>(std::distance(std::begin(faceValueStrings), std::find(std::begin(faceValueStrings), std::end(faceValueStrings), guess)));
                if (guessedFaceValue == topCard.faceValue) {
                    std::cout << "Correct! The card was " << topCard << ".\n";
                }
                else {
                    std::cout << "Incorrect. The card was " << topCard << ".\n";
                }
            }
            else {
                std::cout << "Invalid face value. The card was " << topCard << ".\n";
            }
            break;
        }
        case 2: {
            std::cout << "Guess the suit of the card: ";
            std::string guess;
            std::cin >> guess;
            std::transform(guess.begin(), guess.end(), guess.begin(), ::tolower); // Convert guess to lowercase

            if (std::find(std::begin(suitStrings), std::end(suitStrings), guess) != std::end(suitStrings)) {
                Suit guessedSuit = static_cast<Suit>(std::distance(std::begin(suitStrings), std::find(std::begin(suitStrings), std::end(suitStrings), guess)));
                if (guessedSuit == topCard.suit) {
                    std::cout << "Correct! The card was " << topCard << ".\n";
                }
                else {
                    std::cout << "Incorrect. The card was " << topCard << ".\n";
                }
            }
            else {
                std::cout << "Invalid suit. The card was " << topCard << ".\n";
            }
            break;
        }
        case 3: {
            std::cout << "Guess the face value and suit of the card (e.g., \"Ace of Spades\"): ";
            std::string guess;
            std::getline(std::cin >> std::ws, guess); // Read the entire line
            std::transform(guess.begin(), guess.end(), guess.begin(), ::tolower); // Convert guess to lowercase

            std::string faceValueGuess, suitGuess;
            size_t ofPos = guess.find(" of ");
            if (ofPos != std::string::npos) {
                faceValueGuess = guess.substr(0, ofPos);
                suitGuess = guess.substr(ofPos + 4);

                if (std::find(std::begin(faceValueStrings), std::end(faceValueStrings), faceValueGuess) != std::end(faceValueStrings) &&
                    std::find(std::begin(suitStrings), std::end(suitStrings), suitGuess) != std::end(suitStrings)) {
                    FaceValue guessedFaceValue = static_cast<FaceValue>(std::distance(std::begin(faceValueStrings), std::find(std::begin(faceValueStrings), std::end(faceValueStrings), faceValueGuess)));
                    Suit guessedSuit = static_cast<Suit>(std::distance(std::begin(suitStrings), std::find(std::begin(suitStrings), std::end(suitStrings), suitGuess)));

                    if (guessedFaceValue == topCard.faceValue && guessedSuit == topCard.suit) {
                        std::cout << "Correct! The card was " << topCard << ".\n";
                    }
                    else {
                        std::cout << "Incorrect. The card was " << topCard << ".\n";
                    }
                }
                else {
                    std::cout << "Invalid guess. The card was " << topCard << ".\n";
                }
            }
            else {
                std::cout << "Invalid guess. The card was " << topCard << ".\n";
            }
            break;
        }
        default:
            std::cout << "Invalid choice. Try again.\n";
            break;
        }

        std::cout << "\n";
    } while (choice != 4);

    return 0;
} //End main