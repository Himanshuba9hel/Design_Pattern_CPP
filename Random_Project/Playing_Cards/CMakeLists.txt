cmake_minimum_required(VERSION 3.16)

project(Playing_Cards LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 1. Create a library for the game logic
add_library(DeckLib STATIC
    Deck/deck.h
    Deck/deck.cpp
    Table/holder.h Table/holder.cpp
)
target_include_directories(DeckLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# 2. Create a another library for the game logic
add_library(PlayerLib STATIC
    Player/player.h
    Player/player.cpp
)
target_include_directories(PlayerLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_library(TableLib STATIC
    Table/table.h
    Table/table.cpp
)
target_include_directories(TableLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# 2. Main executable
add_executable(Playing_Cards main.cpp)
target_link_libraries(Playing_Cards PRIVATE DeckLib PlayerLib TableLib)

include(GNUInstallDirs)
install(TARGETS Playing_Cards
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
set(CMAKE_TLS_VERIFY OFF)
enable_testing()
add_subdirectory(Testing)
