#ifndef SOLITAIREDECK_H
#define SOLITAIREDECK_H
#include <optional>
#include "deck.h"
#include "card.h"

class SolitaireCard : public Card
{
public:
    enum Ranks {
        Two = 2,
        Three,
        Four,
        Five,
        Six,
        Seven,
        Eight,
        Nine,
        Ten,
        Jack,
        Qween,
        King,
        Ace
    };
    enum Suits {
        Heart   = 0,
        Diamond = 1,
        Clover  = 2,
        Spade   = 3,
    };
    enum Visibility {
        NoOne = 0,
        OnlyHolder,
        EveryOne,
    };

    struct SolitaireCardInfo : public CardInfo
    {
        Visibility visibility = Visibility::NoOne;
        std::optional<Suits> suit;
        std::optional<Ranks> rank;

        SolitaireCardInfo() = default;
        explicit SolitaireCardInfo(Visibility vis)
            : visibility(vis) {}
        SolitaireCardInfo(Visibility vis, Suits s, Ranks r)
            : visibility(vis), suit(s), rank(r) {}
    };

    SolitaireCard(Ranks rank, Suits suit, Visibility visibility = Visibility::NoOne);
    ~SolitaireCard() override = default;
    const SolitaireCardInfo &getInfo() const override;

private:
    Ranks rank_;
    Suits suit_;
    Visibility visibility_;
    mutable SolitaireCardInfo m_info;
};

class SolitaireDeck : public Deck
{
public:
    SolitaireDeck();
    ~SolitaireDeck() override = default;
    unsigned int totalCards() override;
    std::optional<std::reference_wrapper<const Card>> findCard(std::size_t position) const;
    const Card* tryShowCard(std::size_t position) const;

private:
    std::list<Card*> cards;
public:
    void addCard(Card *card) override;
    void addCards(std::list<Card*> cards) override;
    Card* tryGiveCard(std::size_t position) override;
    std::list<Card*> tryGiveCards(std::set<std::size_t> positions) override;
    void tryTakeCard(Card* card) override;
    void tryTakeCards(std::list<Card*> cards) override;

};

SolitaireDeck generateSolitaireDeck();

#endif // SOLITAIREDECK_H