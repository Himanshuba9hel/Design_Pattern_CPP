cmake_minimum_required(VERSION 3.16)

project(Design_Pattern_CPP LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(DesignPatternLib
    Composite/component.h Composite/component.cpp
    Composite/filesystemcomponent.h Composite/filesystemcomponent.cpp
    Builder/computer.h Builder/computer.cpp
    Composite/accommodation.h Composite/accommodation.cpp
    Composite/playground.h Composite/playground.cpp
)
add_library(ResourceManagementLib
    ResourceManagement/holdernasset.h ResourceManagement/holdernasset.cpp
)
add_executable(Design_Pattern_CPP main.cpp)
target_link_libraries(Design_Pattern_CPP PRIVATE DesignPatternLib)

include(GNUInstallDirs)
install(TARGETS Design_Pattern_CPP
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

enable_testing()
add_subdirectory(Testing)