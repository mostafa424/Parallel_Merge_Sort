cmake_minimum_required(VERSION 3.24)
project(Lab4)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -pthread")

add_executable(Lab4 main.cpp)
