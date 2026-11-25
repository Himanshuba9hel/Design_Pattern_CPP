#include <gtest/gtest.h>
#include "DeckNCards/solitairedeck.h"

TEST(SolitaireDeckTest, CardCreationEveryOne) {
    SolitaireCard card(SolitaireCard::Ace, SolitaireCard::Spade, SolitaireCard::EveryOne);
    const auto& info = card.getInfo();

    EXPECT_EQ(info.rank, SolitaireCard::Ace);
    EXPECT_EQ(info.suit, SolitaireCard::Spade);
    EXPECT_EQ(info.visibility, SolitaireCard::EveryOne);
}

TEST(SolitaireDeckTest, CardCreationNoOne) {
    SolitaireCard card(SolitaireCard::Ace, SolitaireCard::Spade, SolitaireCard::NoOne);
    const auto& info = card.getInfo();

    EXPECT_EQ(info.visibility, SolitaireCard::NoOne);
    EXPECT_FALSE(info.rank.has_value());
    EXPECT_FALSE(info.suit.has_value());
}

TEST(SolitaireDeckTest, DeckCreation) {
    SolitaireDeck deck = generateSolitaireDeck();
    EXPECT_EQ(deck.totalCards(), 52);

    const Card* card = deck.tryShowCard(0);
    ASSERT_NE(card, nullptr);

    const auto& info = static_cast<const SolitaireCard::SolitaireCardInfo&>(card->getInfo());
    EXPECT_EQ(info.visibility, SolitaireCard::EveryOne);
    ASSERT_TRUE(info.rank.has_value());
    ASSERT_TRUE(info.suit.has_value());
    EXPECT_EQ(*info.rank, SolitaireCard::Two);
    EXPECT_EQ(*info.suit, SolitaireCard::Heart);
}

