#include "deck.h"
#include <vector>
#include <algorithm>
#include <random>

void Deck::shuffleCards()
{
    std::random_device rd;
    std::mt19937 g(rd());
    //std::shuffle(cardsVec.begin(), cardsVec.end(), g);
}



