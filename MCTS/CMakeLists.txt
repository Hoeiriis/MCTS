cmake_minimum_required(VERSION 3.8)
project(MCTS_Library)

set(CMAKE_CXX_STANDARD 14)

add_executable(MCTS_Library src/main.cpp src/Core/MCTS_Base.cpp src/Core/MCTS_Base.h)