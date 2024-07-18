cmake_minimum_required(VERSION 3.27)
project(lista10)

set(CMAKE_CXX_STANDARD 17)

add_executable(lista10 main.cpp
        bst.hpp
        bst_impl.hpp)
