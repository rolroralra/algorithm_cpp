cmake_minimum_required(VERSION 3.17)
project(algorithm_cpp)

set(CMAKE_CXX_STANDARD 14)

include_directories(src/lib/header)

add_executable(algorithm_cpp
        src/main.cpp)
