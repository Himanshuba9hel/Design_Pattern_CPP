#ifndef TABLE_H
#define TABLE_H

#include <unordered_set>
#include <vector>

class Deck;
class Player;
class Card;

class Table
{
public:
    Table();
private:
    std::unordered_set<Player*> player;
public:
    bool addPlayer(Player* player);
    bool removePlayer(Player* player);
    std::vector<Player*>* showPlayer();
};

#endif // TABLE_H
