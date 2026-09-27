#ifndef PLAYER_H
#define PLAYER_H
#include <vector>

class Card;
class Player
{
public:
    Player();
    std::vector<Card*> cardsInHand;
    void drawCard();
    void showCard();
};

#endif // PLAYER_H
