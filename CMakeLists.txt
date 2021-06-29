# cmake_minimum_required(VERSION <specify CMake version here>)
cmake_minimum_required(VERSION 3.19)
project(algorithm_cpp)

set(CMAKE_CXX_STANDARD 14)

include_directories(src/lib)
include_directories(src/lib/header)
include_directories(src/lib/header/bits)

add_executable(algorithm_cpp
        src/lib/header/bits/stdc++.h
        src/main.cpp)
