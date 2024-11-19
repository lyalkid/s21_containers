cmake_minimum_required(VERSION 3.25)
project(containers)

set(CMAKE_CXX_STANDARD 17)



add_executable(containers
        src/main.cpp
        src/map/bst.cpp
        src/map/node.cpp)
