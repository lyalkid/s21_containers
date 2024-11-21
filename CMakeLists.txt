cmake_minimum_required(VERSION 3.25)
project(containers)

set(CMAKE_CXX_STANDARD 17)



add_executable(containers
        src/map/node.tpp
        src/map/binaryTree.tpp
        src/map/main.cpp
        src/map/s21_Map.h)
