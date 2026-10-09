cmake_minimum_required(VERSION 3.16)

project(DesignPatternTest LANGUAGES CXX)

enable_testing()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 1. Safely pull Google Test for any OS
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/heads/main.zip
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)

# 2. Scope the Windows-specific runtime fix strictly to the MSVC compiler
if (MSVC)
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
endif()

FetchContent_MakeAvailable(googletest)

# --- Include Directories ---
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/..
    # ${CMAKE_CURRENT_SOURCE_DIR}/../Building
    # ${CMAKE_CURRENT_SOURCE_DIR}/../Entity
)

add_executable(DesignPatternTest
    main.cpp tst_building.cpp
    ${PROJECT_SOURCES}
)

# 3. Link the targets directly
target_link_libraries(DesignPatternTest PRIVATE
    # BuildingLib
    # EntityLib
    gtest
    gmock
)

add_test(NAME DesignPatternTest COMMAND DesignPatternTest)

include(GNUInstallDirs)
install(TARGETS DesignPatternTest
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)