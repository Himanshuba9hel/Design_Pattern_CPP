#include <gtest/gtest.h>
#include "DeckNCards/solitairedeck.h"
#include <list>
#include <set>

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

TEST(SolitaireDeckTest, TryGiveCardValidAndRemovesFromDeck) {
    SolitaireDeck deck = generateSolitaireDeck();
    ASSERT_EQ(deck.totalCards(), 52);

    const Card* expectedCard = deck.tryShowCard(2);
    ASSERT_NE(expectedCard, nullptr);

    Card* given = deck.tryGiveCard(2);
    EXPECT_EQ(given, expectedCard);
    EXPECT_EQ(deck.totalCards(), 51);

    // Card at index 2 is now what used to be at index 3
    const Card* nextAtTwo = deck.tryShowCard(2);
    ASSERT_NE(nextAtTwo, nullptr);
    EXPECT_NE(nextAtTwo, given);
}

TEST(SolitaireDeckTest, TryGiveCardOutOfBoundsReturnsNullptr) {
    SolitaireDeck deck = generateSolitaireDeck();

    EXPECT_EQ(deck.tryGiveCard(52), nullptr);
    EXPECT_EQ(deck.tryGiveCard(999), nullptr);
    EXPECT_EQ(deck.totalCards(), 52);
}

TEST(SolitaireDeckTest, TryGiveCardsMultipleIndicesInOrder) {
    SolitaireDeck deck = generateSolitaireDeck();
    ASSERT_EQ(deck.totalCards(), 52);

    const Card* c0 = deck.tryShowCard(0);
    const Card* c2 = deck.tryShowCard(2);
    const Card* c5 = deck.tryShowCard(5);
    ASSERT_NE(c0, nullptr);
    ASSERT_NE(c2, nullptr);
    ASSERT_NE(c5, nullptr);

    std::list<Card*> given = deck.tryGiveCards({5, 0, 2});
    EXPECT_EQ(given.size(), 3u);
    EXPECT_EQ(deck.totalCards(), 49);

    auto it = given.begin();
    EXPECT_EQ(*it++, c0);
    EXPECT_EQ(*it++, c2);
    EXPECT_EQ(*it++, c5);
}

TEST(SolitaireDeckTest, TryGiveCardsIgnoresOutOfBoundsAndEmptySet) {
    SolitaireDeck deck = generateSolitaireDeck();

    std::list<Card*> emptyGiven = deck.tryGiveCards({});
    EXPECT_TRUE(emptyGiven.empty());
    EXPECT_EQ(deck.totalCards(), 52);

    std::list<Card*> outOfRangeGiven = deck.tryGiveCards({52, 100});
    EXPECT_TRUE(outOfRangeGiven.empty());
    EXPECT_EQ(deck.totalCards(), 52);
}

TEST(SolitaireDeckTest, TryTakeCardPreventsDuplicatesAndNullptr) {
    SolitaireDeck deck = generateSolitaireDeck();
    Card* card = deck.tryGiveCard(0);
    ASSERT_NE(card, nullptr);
    ASSERT_EQ(deck.totalCards(), 51);

    // Nullptr should be ignored
    deck.tryTakeCard(nullptr);
    EXPECT_EQ(deck.totalCards(), 51);

    // Adding back once restores the card
    deck.tryTakeCard(card);
    EXPECT_EQ(deck.totalCards(), 52);

    // Adding the same card again should not duplicate it
    deck.tryTakeCard(card);
    EXPECT_EQ(deck.totalCards(), 52);
}

TEST(SolitaireDeckTest, TryTakeCardsBatchDeduplicates) {
    SolitaireDeck deck = generateSolitaireDeck();
    Card* c1 = deck.tryGiveCard(1);
    Card* c3 = deck.tryGiveCard(3);
    ASSERT_NE(c1, nullptr);
    ASSERT_NE(c3, nullptr);
    ASSERT_EQ(deck.totalCards(), 50);

    // Includes duplicates of c1/c3 and a nullptr
    deck.tryTakeCards({c1, c1, nullptr, c3, c3});
    EXPECT_EQ(deck.totalCards(), 52);
}
