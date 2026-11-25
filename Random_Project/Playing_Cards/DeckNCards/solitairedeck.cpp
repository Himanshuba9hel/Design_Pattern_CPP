#include "solitairedeck.h"
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

Card *SolitaireDeck::tryGiveCard(std::size_t position)
{
    if (position >= cards.size()) {
        return nullptr;
    }

    auto cardItr = cards.begin();
    std::advance(cardItr, position);
    Card *card = *cardItr;
    cards.erase(cardItr); // remove from deck so the card stays in one place
    return card;          // non-const Card* (not const Card*)
}

std::list<Card *> SolitaireDeck::tryGiveCards(std::set<std::size_t> positions)
{
    std::list<Card *> givenCards;
    if (positions.empty() || cards.empty()) {
        return givenCards;
    }

    // Iterate in descending order so erasing earlier positions does not
    // shift the indices of smaller positions still to be erased.
    for (auto rit = positions.rbegin(); rit != positions.rend(); ++rit) {
        const std::size_t pos = *rit;
        if (pos >= cards.size()) {
            continue; // or break, since positions is sorted ascending
        }

        auto cardItr = cards.begin();
        std::advance(cardItr, pos);
        givenCards.push_front(*cardItr); // preserve ascending position order
        cards.erase(cardItr);
    }

    return givenCards;
}

void SolitaireDeck::tryTakeCard(Card *card)
{
    if (card == nullptr) {
        return;
    }

    // Keep each card single in the deck (avoid duplicate pointers)
    const bool alreadyPresent =
        std::find(cards.begin(), cards.end(), card) != cards.end();
    if (!alreadyPresent) {
        cards.push_back(card);
    }
}

void SolitaireDeck::tryTakeCards(std::list<Card *> newCards)
{
    for (Card *card : newCards) {
        tryTakeCard(card);
    }
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
