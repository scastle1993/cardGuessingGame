// card.h
#ifndef CARD_H
#define CARD_H

#include <iostream>

enum Suit { CLUBS, DIAMONDS, HEARTS, SPADES };
enum FaceValue { ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING };

class Card {
public:
    Suit suit;
    FaceValue faceValue;

    Card(Suit s, FaceValue f);

    friend std::ostream& operator<<(std::ostream& os, const Card& card);
};

#endif