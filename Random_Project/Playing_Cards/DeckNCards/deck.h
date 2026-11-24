#ifndef DECK_H
#define DECK_H
#include <unordered_set>
#include <vector>
#include <stack>

#include "card.h"

class Deck
{
public:
    ~Deck() = default;
    void generateCards();
    void shuffleCards();

    std::vector<Card*> cardsVec;
    std::stack<Card*> deck;
    std::unordered_set<Card*> cards;
};

#endif // DECK_H
