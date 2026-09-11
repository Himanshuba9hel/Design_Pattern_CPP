cmake_minimum_required(VERSION 3.16)

project(Restaurant LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Restaurant main.cpp
    Staff/staff.h Staff/staff.cpp
    Customer/customer.h Customer/customer.cpp
    Customer/menu.h Customer/menu.cpp
    Restaurants/restaurants.h Restaurants/restaurants.cpp
    Order/order.h Order/order.cpp)

include(GNUInstallDirs)
install(TARGETS Restaurant
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
add_subdirectory(Testing)