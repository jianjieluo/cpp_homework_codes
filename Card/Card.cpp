#include <sstream>
#include <string>
#include "Card.h"
using namespace std;

Card::Card(int cardFace, int cardSuit) {
    face = cardFace;
    suit = cardSuit;
}

const char* Card::faceNames[totalFaces] =
{ "Ace", "Deuce", "Three", "Four", "Five", "Six",
"Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King" };

const char* Card::suitNames[totalSuits] = {
    "Hearts", "Diamonds", "Clubs", "Spades"
};


string Card::toString() const {
    string str = "";
    str += faceNames[face];
    str += " of ";
    str += suitNames[suit];
    return str;
}

int Card::getFace() const {
    return face;
}

int Card::getSuit() const {
    return suit;
}

