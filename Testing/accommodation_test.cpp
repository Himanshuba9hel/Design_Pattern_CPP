#include "../Composite/accommodation.h"
#include <gtest/gtest.h>
#include <type_traits>

// 1. Verify at compile-time and runtime that Entity cannot be copied
TEST(EntityTest, IsNonCopyableButMovable) {
    EXPECT_FALSE(std::is_copy_constructible_v<Entity>);
    EXPECT_FALSE(std::is_copy_assignable_v<Entity>);
    EXPECT_TRUE(std::is_move_constructible_v<Entity>);
    EXPECT_TRUE(std::is_move_assignable_v<Entity>);
}

// 2. Verify Entity memory address remains identical across nested transitions
TEST(AccommodationTest, PreservesEntityIdentityAcrossNestedMovements) {
    auto plaza = std::make_shared<Building>("Tech Plaza");
    auto floor1 = std::make_shared<Floor>(1);
    auto office = std::make_shared<Office>("Dev Suite 101");
    auto restaurant = std::make_shared<Restaurant>("Bistro 24");
    auto gamePark = std::make_shared<GamePark>("Arcade Zone");

    floor1->addChild(office);
    floor1->addChild(restaurant);
    floor1->addChild(gamePark);
    plaza->addChild(floor1);

    auto alice = std::make_unique<Entity>(42, "Alice");
    const int aliceId = alice->getId();
    // Record the exact initial heap memory address
    const Entity* const originalAddress = alice.get();

    // Enter Building
    plaza->enter(std::move(alice));
    EXPECT_EQ(alice, nullptr); // Ownership moved out of local unique_ptr
    EXPECT_TRUE(plaza->hasEntity(aliceId));
    EXPECT_EQ(plaza->getEntity(aliceId), originalAddress);

    // Move Building -> Floor 1
    plaza->transferTo(aliceId, *floor1);
    EXPECT_FALSE(plaza->hasEntity(aliceId));
    EXPECT_TRUE(floor1->hasEntity(aliceId));
    EXPECT_EQ(floor1->getEntity(aliceId), originalAddress);

    // Move Floor 1 -> Office
    floor1->transferTo(aliceId, *office);
    EXPECT_FALSE(floor1->hasEntity(aliceId));
    EXPECT_TRUE(office->hasEntity(aliceId));
    EXPECT_EQ(office->getEntity(aliceId), originalAddress);

    // Move Office -> Floor 1 -> Restaurant
    office->transferTo(aliceId, *floor1);
    floor1->transferTo(aliceId, *restaurant);
    EXPECT_FALSE(office->hasEntity(aliceId));
    EXPECT_TRUE(restaurant->hasEntity(aliceId));
    EXPECT_EQ(restaurant->getEntity(aliceId), originalAddress);

    // Move Restaurant -> Floor 1 -> GamePark
    restaurant->transferTo(aliceId, *floor1);
    floor1->transferTo(aliceId, *gamePark);
    EXPECT_FALSE(restaurant->hasEntity(aliceId));
    EXPECT_TRUE(gamePark->hasEntity(aliceId));
    EXPECT_EQ(gamePark->getEntity(aliceId), originalAddress);

    // Exit back to the outside world
    gamePark->transferTo(aliceId, *floor1);
    floor1->transferTo(aliceId, *plaza);
    std::unique_ptr<Entity> exitedAlice = plaza->exit(aliceId);

    EXPECT_EQ(plaza->getOccupantCount(), 0u);
    EXPECT_EQ(exitedAlice.get(), originalAddress);
    EXPECT_EQ(exitedAlice->getName(), "Alice");
}

// 3. Verify error handling when exiting or transferring a missing Entity
TEST(AccommodationTest, ThrowsWhenEntityNotPresent) {
    Building plaza("Tech Plaza");
    Floor floor1(1);

    EXPECT_THROW(plaza.exit(999), std::runtime_error);
    EXPECT_THROW(plaza.transferTo(999, floor1), std::runtime_error);
}

// 4. Verify leaf accommodations reject nested sub-accommodations
TEST(AccommodationTest, LeafAccommodationsRejectChildren) {
    auto office = std::make_shared<Office>("Suite 200");
    auto restaurant = std::make_shared<Restaurant>("Cafe");
    auto gamePark = std::make_shared<GamePark>("VR Zone");
    auto subRoom = std::make_shared<Office>("Sub-Office");

    EXPECT_THROW(office->addChild(subRoom), std::logic_error);
    EXPECT_THROW(restaurant->addChild(subRoom), std::logic_error);
    EXPECT_THROW(gamePark->addChild(subRoom), std::logic_error);
}