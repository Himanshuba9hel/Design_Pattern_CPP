#include "memorymanagement.h"
#include <gtest/gtest.h>

// -------------------------------------------------------------
// Test Suite: Initialization & Basic Setup
// -------------------------------------------------------------
TEST(MemoryManagementTest, InitialStateWithoutAsset) {
    std::string m1_str = "m1 message";
    std::string m2_str = "m2 message";
    MemoryManagement* m1 = new MemoryManagement(m1_str);
    MemoryManagement* m2 = new MemoryManagement();
    m1->sendMessageTo(m2);
    EXPECT_STREQ(m2->getMessage().c_str(), m1_str.c_str());
    EXPECT_STREQ(m1->getMessage().c_str(),"");
}