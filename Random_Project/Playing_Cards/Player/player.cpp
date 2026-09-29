#include "player.h"
#include "./Deck/deck.h"
#include <iostream>

Player::Player() {}

void Player::drawCard(Card *card)
{
    std::cout<<"Table Deleted addr:"<<this<<std::endl;
}

std::vector<Card*>* Player::showCard()
{
    std::vector<Card*>* cards = new std::vector<Card*>;
    for(auto card: cardsInHand){
        cards->push_back(card);
    }
    return cards;
}
