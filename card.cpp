// card.cpp
// Implementation file for the Card class

#include "card.h"

// Constructor
Card::Card(Suit s, FaceValue f) : suit(s), faceValue(f) {}

// Overloaded stream insertion operator <<
// Allows for easy printing of Card objects
std::ostream& operator<<(std::ostream& os, const Card& card) {
    // String variables to store suit and face value as strings
    std::string suitStr, faceValueStr;

    // Switch statement to assign the suit string based on the suit enum value
    switch (card.suit) {
    case CLUBS:
        suitStr = "Clubs";
        break;
    case DIAMONDS:
        suitStr = "Diamonds";
        break;
    case HEARTS:
        suitStr = "Hearts";
        break;
    case SPADES:
        suitStr = "Spades";
        break;
    }

    // Switch statement to assign the face value string based on the faceValue enum value
    switch (card.faceValue) {
    case ACE:
        faceValueStr = "Ace";
        break;
    case TWO:
        faceValueStr = "Two";
        break;
    case THREE:
        faceValueStr = "Three";
        break;
    case FOUR:
        faceValueStr = "Four";
        break;
    case FIVE:
        faceValueStr = "Five";
        break;
    case SIX:
        faceValueStr = "Six";
        break;
    case SEVEN:
        faceValueStr = "Seven";
        break;
    case EIGHT:
        faceValueStr = "Eight";
        break;
    case NINE:
        faceValueStr = "Nine";
        break;
    case TEN:
        faceValueStr = "Ten";
        break;
    case JACK:
        faceValueStr = "Jack";
        break;
    case QUEEN:
        faceValueStr = "Queen";
        break;
    case KING:
        faceValueStr = "King";
        break;
    }

    // Output the face value and suit strings to the given output stream
    os << faceValueStr << " of " << suitStr;

    // Return the output stream for potential chaining
    return os;
}