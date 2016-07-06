#include <vector>
#include "DeckOfCards.h"
using namespace std;

DeckOfCards::DeckOfCards() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 13; j++) {
            Card temp(j, i);
            deck.push_back(temp);
        }
    }
    currentCard = 0;
}

Card DeckOfCards::dealCard() {
    return deck[currentCard++];
}

bool DeckOfCards::moreCards() const {
    if (currentCard > 51) return false;
    else return true;
}

