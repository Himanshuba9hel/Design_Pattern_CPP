#ifndef SOLITAIREDECK_H
#define SOLITAIREDECK_H

#include "deck.h"
#include "card.h"



class SolitaireDeck : public Deck
{
public:
    SolitaireDeck();
protected:
    std::list<Card*> cards;
};

struct SolitaireCardInfo : public CardInfo
{
    enum Ranks {
        Two = 2,
        Three,
        Four,
        Five,
        Six,
        Seven,
        Eight,
        Nine,
        Ten,
        Jack,
        Qween,
        King,
        Ace
    };
    enum Suits {
        Heart   = 0,
        Diamond = 1,
        Clover  = 2,
        Spade   = 3,
    };
    Ranks rank;
    Suits suit;
    bool faceUp = false;
};

class SolitaireCard : public Card
{
public:
    SolitaireCard();
    ~SolitaireCard() override = default;

    SolitaireCardInfo* getInfo() const override;

private:
    SolitaireCardInfo m_info;
};


#endif // SOLITAIREDECK_H