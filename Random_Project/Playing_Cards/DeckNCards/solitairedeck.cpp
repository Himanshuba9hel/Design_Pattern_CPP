#include "solitairedeck.h"
#include <iostream>
#include <iterator>
#include <cstddef>
#include <functional>
#include <optional>

SolitaireCard::SolitaireCard(Ranks rank, Suits suit, Visibility visibility):
    rank_(rank), suit_(suit), visibility_(visibility)
{}

const SolitaireCard::SolitaireCardInfo &SolitaireCard::getInfo() const
{
    switch (visibility_) {
    case NoOne:
        m_info = SolitaireCardInfo(visibility_);
        break;
    case OnlyHolder:
    case EveryOne:
        m_info = SolitaireCardInfo(visibility_, suit_, rank_);
        break;
    }
    return m_info;
}

SolitaireDeck::SolitaireDeck() : Deck()
{

}

unsigned int SolitaireDeck::totalCards()
{
    return static_cast<unsigned int>(cards.size());
}

std::optional<std::reference_wrapper<const Card>>
SolitaireDeck::findCard(std::size_t position) const
{
    if (position >= cards.size()) {
        return std::nullopt;
    }

    auto cardItr = cards.begin();
    std::advance(cardItr, position);
    if (*cardItr == nullptr) {
        return std::nullopt;
    }

    return std::cref(**cardItr);
}

const Card* SolitaireDeck::tryShowCard(std::size_t position) const
{
    if (position >= cards.size()) {
        return nullptr;
    }

    auto cardItr = cards.begin();
    std::advance(cardItr, position);
    return *cardItr; // already const Card* in a const member function
}

void SolitaireDeck::addCard(Card *card)
{
    cards.push_back(card);
}

void SolitaireDeck::addCards(std::list<Card *> newCards)
{
    for (Card *card : newCards) {
        cards.push_back(card);
    }
}

void SolitaireDeck::takeCard(std::list<Card *>::iterator cardItr)
{

}

void SolitaireDeck::takeCards(std::list<std::list<Card *>::iterator> cardsItrs)
{

}

SolitaireDeck generateSolitaireDeck()
{
    SolitaireDeck deck;
    const SolitaireCard::Visibility visibility = SolitaireCard::Visibility::EveryOne;

    for (int suit = static_cast<int>(SolitaireCard::Suits::Heart);
         suit <= static_cast<int>(SolitaireCard::Suits::Spade);
         ++suit) {
        for (int rank = static_cast<int>(SolitaireCard::Ranks::Two);
             rank <= static_cast<int>(SolitaireCard::Ranks::Ace);
             ++rank) {
            deck.addCard(new SolitaireCard(
                static_cast<SolitaireCard::Ranks>(rank),
                static_cast<SolitaireCard::Suits>(suit),
                visibility));
        }
    }

    return deck;
}
