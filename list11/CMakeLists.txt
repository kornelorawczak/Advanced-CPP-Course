cmake_minimum_required(VERSION 3.27)
project(lista11)

set(CMAKE_CXX_STANDARD 17)

add_executable(lista11 main.cpp
        input.hpp
        input.cpp
        output.hpp
        output.cpp)
