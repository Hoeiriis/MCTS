cmake_minimum_required(VERSION 3.8)
project(MCTS_Library)

set(CMAKE_CXX_STANDARD 14)

set(OUTPUT_DIR "${PROJECT_SOURCE_DIR}/build")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${OUTPUT_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${OUTPUT_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_DIR}/bin)

add_executable(MCTS_Library src/main.cpp src/Core/MCTSBase.cpp src/Core/MCTSBase.h)
