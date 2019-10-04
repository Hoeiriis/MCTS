cmake_minimum_required(VERSION 3.8)
project(MCTS_Library)

set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

IF($ENV{BOOST_ROOT})
  set(BOOST_ROOT $ENV{BOOST_ROOT})
ENDIF()

set(BOOST_COMPONENTS system)
find_package(Boost 1.69 EXACT REQUIRED COMPONENTS ${BOOST_COMPONENTS})

set(OUTPUT_DIR "${PROJECT_SOURCE_DIR}/build")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${OUTPUT_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${OUTPUT_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_DIR}/bin)

add_subdirectory(src/Environments)

add_library(MCTS_Library src/Core/MCTSBase.cpp)
target_link_libraries(MCTS_Library Environment)

add_executable(main src/main.cpp)
target_link_libraries(main MCTS_Library Environment)

# target_compile_options(main PUBLIC -Wall -Wpedantic -O2)
# target_compile_features(main PUBLIC cxx_std_14)
