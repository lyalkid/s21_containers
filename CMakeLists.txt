cmake_minimum_required(VERSION 3.25)
project(containers)

set(CMAKE_CXX_STANDARD 17)



add_executable(containers
        src/map/bst.tpp
        src/map/node.tpp
        src/map/main.cpp)
