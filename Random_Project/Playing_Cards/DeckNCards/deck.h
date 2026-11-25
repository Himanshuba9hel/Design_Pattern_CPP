#ifndef DECK_H
#define DECK_H
#include <list>
#include <set>
#include <cstddef>
#include "card.h"

class Deck
{
public:
    virtual ~Deck() = default;
    virtual void shuffleCards();
    virtual void addCard(Card *card) = 0;
    virtual void addCards(std::list<Card*> cards) = 0;
    virtual Card* tryGiveCard(std::size_t position) = 0;
    virtual std::list<Card*> tryGiveCards(std::set<std::size_t> positions) = 0;
    virtual void tryTakeCard(Card* card) = 0;
    virtual void tryTakeCards(std::list<Card*> cards) = 0;
    virtual unsigned int totalCards() = 0;
};

#endif // DECK_H
