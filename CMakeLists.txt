cmake_minimum_required(VERSION 3.16)

project(Design_Pattern_CPP LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Design_Pattern_CPP main.cpp)

include(GNUInstallDirs)
install(TARGETS Design_Pattern_CPP
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

enable_testing()
add_subdirectory(Testing)