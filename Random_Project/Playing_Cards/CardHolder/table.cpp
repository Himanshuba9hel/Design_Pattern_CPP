#include <iostream>
#include "table.h"
#include "./Deck/deck.h"
#include "./Player/player.h"

Table::Table() {
    std::cout<<"Table Created addr:"<<this<<std::endl;
}

Table::~Table()
{
    std::cout<<"Table Deleted addr:"<<this<<std::endl;
}

bool Table::addPlayer(Player *player)
{
    auto playerItr = players.find(player);
    if(playerItr == players.end())
        players.insert(player);
        return true;
    return false;
}

bool Table::removePlayer(Player *player)
{
    auto playerItr = players.find(player);
    if(playerItr == players.end())
        delete player;
        players.erase(player);
        return true;
    return false;
}

const std::vector<Player *> *Table::showPlayer()
{
    const std::vector<Player*> *players = new std::vector<Player*>(this->players.begin(),this->players.end());
    return players;
}

bool Table::addDeck(Deck *deck)
{
    if(this->deck)
        return false;
    this->deck = deck;
    return true;
}

bool Table::removeDeck()
{
    if(!this->deck)
        return false;
    delete this->deck;
    return true;
}

bool Table::replaceDeck(Deck *deck)
{
    if(!this->deck)
        return false;
    this->deck = deck;
    return true;
}
