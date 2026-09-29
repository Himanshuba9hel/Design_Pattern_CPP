#ifndef TABLE_H
#define TABLE_H

#include <set>
#include <vector>

class Deck;
class Player;
class Card;

class Table
{
public:
    Table();
    ~Table();
protected:
    std::set<Player*> players;
public:
    bool addPlayer(Player* player);
    bool removePlayer(Player* player);
    const std::vector<Player*>* showPlayer();

protected:
    Deck* deck = nullptr;
public:
    bool addDeck(Deck* deck);
    bool removeDeck();
    bool replaceDeck(Deck* deck);
};

#endif // TABLE_H
