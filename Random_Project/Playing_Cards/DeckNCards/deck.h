#ifndef DECK_H
#define DECK_H
#include <list>
#include "card.h"

class Deck
{
public:
    virtual ~Deck() = default;
    virtual void shuffleCards();
    virtual void addCard(Card *card) = 0;
    virtual void addCards(std::list<Card*> cards) = 0;
    virtual void takeCard(std::list<Card*>::iterator cardItr) = 0;
    virtual void takeCards(std::list<std::list<Card*>::iterator> cardsItrs) = 0;
    virtual unsigned int totalCards() = 0;
};

#endif // DECK_H
