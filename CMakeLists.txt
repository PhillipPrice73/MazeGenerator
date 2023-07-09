cmake_minimum_required(VERSION 3.25)
project(MazeGenerator)

set(CMAKE_CXX_STANDARD 20)

add_executable(generate_maze main.cpp Grid.cpp Grid.h Cell.cpp Cell.h)
