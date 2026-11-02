#include "holdernasset.h"
#include <gtest/gtest.h>

// -------------------------------------------------------------
// Test Suite: Initialization & Basic Setup
// -------------------------------------------------------------
TEST(HolderNAssetTest, InitialStateWithoutAsset) {
    Student student;

    EXPECT_EQ(student.getHolder(), &student);
    EXPECT_EQ(student.currentAsset(), nullptr);
    EXPECT_EQ(student.getGiver(), nullptr);
    EXPECT_EQ(student.getBorrower(), nullptr);
}

TEST(HolderNAssetTest, InitialStateWithAsset) {
    Pencil pencil;
    Student student(&pencil);

    EXPECT_EQ(student.currentAsset(), &pencil);
    EXPECT_EQ(pencil.getOwner(), &student);
    EXPECT_EQ(student.getGiver(), nullptr);
    EXPECT_EQ(student.getBorrower(), nullptr);
}

// -------------------------------------------------------------
// Test Suite: Single Borrow / Lend Lifecycle
// -------------------------------------------------------------
TEST(HolderNAssetTest, TransferAssetUpdatesPointersAndOwnership) {
    Student alice;
    Student bob;
    Pencil pencil(&alice);
    alice.takeAsset(nullptr, &pencil);

    ASSERT_EQ(pencil.getOwner(), &alice);
    ASSERT_EQ(alice.currentAsset(), &pencil);

    // Alice lends pencil to Bob
    alice.giveAsset(&bob);

    // Verify Alice's state
    EXPECT_EQ(alice.currentAsset(), nullptr);
    EXPECT_EQ(alice.getBorrower(), &bob);

    // Verify Bob's state
    EXPECT_EQ(bob.currentAsset(), &pencil);
    EXPECT_EQ(bob.getGiver(), &alice);
    EXPECT_EQ(bob.getBorrower(), nullptr);

    // Verify Pencil ownership
    EXPECT_EQ(pencil.getOwner(), &bob);
}

// -------------------------------------------------------------
// Test Suite: Chained Lending (Alice -> Bob -> Charlie)
// -------------------------------------------------------------
TEST(HolderNAssetTest, ChainedAssetTransfer) {
    Student alice;
    Student bob;
    Student charlie;
    Pencil pencil;

    alice.takeAsset(nullptr, &pencil);

    // Alice -> Bob
    alice.giveAsset(&bob);
    EXPECT_EQ(pencil.getOwner(), &bob);
    EXPECT_EQ(bob.currentAsset(), &pencil);

    // Bob -> Charlie
    bob.giveAsset(&charlie);
    EXPECT_EQ(pencil.getOwner(), &charlie);
    EXPECT_EQ(bob.currentAsset(), nullptr);
    EXPECT_EQ(bob.getBorrower(), &charlie);
    EXPECT_EQ(charlie.currentAsset(), &pencil);
    EXPECT_EQ(charlie.getGiver(), &bob);
}

// -------------------------------------------------------------
// Test Suite: Return Flow (Bob -> Alice)
// -------------------------------------------------------------
TEST(HolderNAssetTest, ReturnAssetToOriginalOwner) {
    Student alice;
    Student bob;
    Pencil pencil(&alice);
    alice.takeAsset(nullptr, &pencil);

    // Alice lends to Bob
    alice.giveAsset(&bob);
    ASSERT_EQ(bob.currentAsset(), &pencil);

    // Bob returns to Alice
    bob.giveAsset(&alice);

    EXPECT_EQ(pencil.getOwner(), &alice);
    EXPECT_EQ(bob.currentAsset(), nullptr);
    EXPECT_EQ(bob.getBorrower(), &alice);
    EXPECT_EQ(alice.currentAsset(), &pencil);
    EXPECT_EQ(alice.getGiver(), &bob);
}

// -------------------------------------------------------------
// Test Suite: Edge Cases & Null Safety
// -------------------------------------------------------------
TEST(HolderNAssetTest, GiveAssetWithoutHoldingOneDoesNothing) {
    Student alice; // Has no asset
    Student bob;

    alice.giveAsset(&bob);

    EXPECT_EQ(alice.getBorrower(), nullptr);
    EXPECT_EQ(bob.getGiver(), nullptr);
    EXPECT_EQ(bob.currentAsset(), nullptr);
}

TEST(HolderNAssetTest, GiveAssetToNullReceiverDoesNotLoseAsset) {
    Pencil pencil;
    Student alice(&pencil);

    alice.giveAsset(nullptr);

    EXPECT_EQ(alice.currentAsset(), &pencil);
    EXPECT_EQ(pencil.getOwner(), &alice);
    EXPECT_EQ(alice.getBorrower(), nullptr);
}