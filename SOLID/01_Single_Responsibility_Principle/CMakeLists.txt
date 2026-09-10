cmake_minimum_required(VERSION 3.16)

project(01_Single_Responsibility_Principle LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(01_Single_Responsibility_Principle main.cpp
    shapes.h shapes.cpp)

include(GNUInstallDirs)
install(TARGETS 01_Single_Responsibility_Principle
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
