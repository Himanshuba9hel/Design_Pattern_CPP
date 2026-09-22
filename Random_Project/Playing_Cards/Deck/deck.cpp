#include "deck.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

Deck::Deck() {}

void Deck::generateCards()
{
    cardsVec.reserve(52); // Pre-allocate memory for 52 cards

    for(int suit = static_cast<int>(Suits::Diamond);
         suit <= static_cast<int>(Suits::Spade); suit++) {
        for(int rank = static_cast<int>(Ranks::ace);
             rank <= static_cast<int>(Ranks::king); rank++) {

            Suits _suit = static_cast<Suits>(suit);
            Ranks _rank = static_cast<Ranks>(rank);
            Card* card = new Card(_suit, _rank);

            std::cout<<suit<<" : "<<rank<<std::endl;
            cards.insert(card);
            cardsVec.push_back(card);
        }
    }
}

void Deck::shuffleCards()
{
    std::random_device rd;
    std::mt19937 g(rd());

    std::shuffle(cardsVec.begin(), cardsVec.end(), g);
}

Card::Card(Suits suit, Ranks rank) : suit(suit), rank(rank) {}



