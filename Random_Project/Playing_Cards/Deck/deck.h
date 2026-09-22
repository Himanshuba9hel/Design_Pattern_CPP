#ifndef DECK_H
#define DECK_H
#include <unordered_set>
#include <vector>

class Card;
enum class Suits;
enum class Ranks;

class Deck
{
public:
    Deck();
    void generateCards();
    void shuffleCards();

    std::vector<Card*> cardsVec;
    std::unordered_set<Card*> cards;
};


class Card
{
public:
    Card(Suits suit, Ranks rank);
    Suits suit;
    Ranks rank;
};

enum class Suits
{
    Diamond = 1,
    Heart,
    Club,
    Spade,
};

enum class Ranks
{
    ace = 1,
    two,
    three,
    four,
    five,
    six,
    seven,
    eight,
    nine,
    ten,
    jack,
    queen,
    king,
};


#endif // DECK_H
