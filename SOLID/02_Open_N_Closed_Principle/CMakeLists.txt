cmake_minimum_required(VERSION 3.16)

project(02_Open_N_Closed_Principle LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(02_Open_N_Closed_Principle main.cpp)

include(GNUInstallDirs)
install(TARGETS 02_Open_N_Closed_Principle
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
