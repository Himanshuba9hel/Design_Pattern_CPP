cmake_minimum_required(VERSION 3.16)

project(Playing_Cards LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 1. Library for deck, card, and holder logic
add_library(DeckLib STATIC
    DeckNCards/card.h
    DeckNCards/deck.h
    DeckNCards/deck.cpp
    CardHolder/holder.h
    CardHolder/holder.cpp
    CardHolder/table.h
    CardHolder/table.cpp
    DeckNCards/solitairedeck.h DeckNCards/solitairedeck.cpp
)
target_include_directories(DeckLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# 2. Library for player logic
add_library(PlayerLib STATIC
    Player/player.h
    Player/player.cpp
)
target_include_directories(PlayerLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(PlayerLib PUBLIC DeckLib)

# 3. Main executable
add_executable(Playing_Cards main.cpp)
target_link_libraries(Playing_Cards PRIVATE DeckLib PlayerLib)

include(GNUInstallDirs)
install(TARGETS Playing_Cards
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

set(CMAKE_TLS_VERIFY OFF)
enable_testing()
add_subdirectory(Testing)