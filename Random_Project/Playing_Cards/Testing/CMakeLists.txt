cmake_minimum_required(VERSION 3.16)

# Prevent CMP0135 policy warning for timestamp extraction
if(POLICY CMP0135)
    cmake_policy(SET CMP0135 NEW)
endif()

project(Testing LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/heads/main.zip
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)

if (MSVC)
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
endif()

FetchContent_MakeAvailable(googletest)

# Match your actual test file name
add_executable(testing main.cpp tst_deck.cpp)

# Link against DeckLib and Google Test targets
target_link_libraries(testing PRIVATE
    DeckLib
    gtest
    gmock
    gtest_main
)

include(GoogleTest)
gtest_discover_tests(testing)