cmake_minimum_required(VERSION 3.16)

project(Playing_Cards LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(GNUInstallDirs)

# -------------------------------------------------------------
# GoogleTest Setup (Locally fetched)
# -------------------------------------------------------------
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
# For Windows MSVC runtime compatibility
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
enable_testing()

# -------------------------------------------------------------
# Add Subprojects
# -------------------------------------------------------------
add_subdirectory(tests)


add_executable(Playing_Cards main.cpp

    Deck/deck.h Deck/deck.cpp)

include(GNUInstallDirs)
install(TARGETS Playing_Cards
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
