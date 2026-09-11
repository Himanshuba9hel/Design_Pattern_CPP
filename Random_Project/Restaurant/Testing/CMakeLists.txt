cmake_minimum_required(VERSION 3.16)

project(dish LANGUAGES CXX)

enable_testing()

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 1. Safely pull Google Test for any OS
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/heads/main.zip
)

# 2. Scope the Windows-specific runtime fix strictly to the MSVC compiler
if (MSVC)
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
endif()

FetchContent_MakeAvailable(googletest)

add_executable(dish main.cpp tst_dish.cpp)
add_test(NAME dish COMMAND dish)

# 3. Link the targets directly
target_link_libraries(dish PRIVATE gtest gmock)

include(GNUInstallDirs)
install(TARGETS dish
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)