cmake_minimum_required(VERSION 3.27)
project(lista3)

set(CMAKE_CXX_STANDARD 14)

add_executable(lista3
        all.cpp
        point.hpp
        segment.hpp
        triangle.hpp
        other.hpp
        point.cpp
        segment.cpp
        triangle.cpp
        other.cpp
        main.cpp)
