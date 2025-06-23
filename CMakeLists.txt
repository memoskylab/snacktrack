cmake_minimum_required(VERSION 3.31)
project(SnackTrack)

set(CMAKE_CXX_STANDARD 20)

add_executable(SnackTrack src/main.cpp
        src/customer.cpp
        include/customer.h
        src/menu.cpp
        include/menu.h
        src/order.cpp
        include/order.h
)
