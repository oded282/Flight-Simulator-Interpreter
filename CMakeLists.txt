cmake_minimum_required(VERSION 3.13)
project(flight_simulator)

set(CMAKE_CXX_STANDARD 14)

add_executable(flight_simulator main.cpp Expression.h Minus.cpp Minus.h Number.cpp Number.h Plus.h Plus.cpp Mult.h Mult.cpp Div.h Div.cpp openDataServer.cpp openDataServer.h)