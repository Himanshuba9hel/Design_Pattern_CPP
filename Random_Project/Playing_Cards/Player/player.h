#ifndef PLAYER_H
#define PLAYER_H
#include <vector>
#include <set>

class Deck;
class Card;

class Player
{
public:
    Player();
    ~Player();

    std::set<Card*> cardsInHand;
    void drawCard(Card* card);
    std::vector<Card*>* showCard();
};

#endif // PLAYER_H
