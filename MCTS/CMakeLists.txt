cmake_minimum_required(VERSION 3.8)
project(MCTS_Library)

set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

if($ENV{BOOST_ROOT})
  set(BOOST_ROOT $ENV{BOOST_ROOT})
endif()

set(BOOST_COMPONENTS system)
find_package(Boost 1.69 REQUIRED COMPONENTS ${BOOST_COMPONENTS})

set(OUTPUT_DIR "${PROJECT_SOURCE_DIR}/build")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${OUTPUT_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${OUTPUT_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_DIR}/bin)

add_subdirectory(src/Environments)
add_subdirectory(src/Core)

add_executable(main src/main.cpp)
target_link_libraries(main Core mcts)

# compile_commands.json needs to be in the project root for my auto-completion
# to work properly #
set(PROJECT_ROOT "${PROJECT_SOURCE_DIR}/..")
execute_process(COMMAND "readlink"
                        "-f"
                        "-n"
                        "${PROJECT_ROOT}"
                OUTPUT_VARIABLE PROJECT_ROOT)

set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

# ##############################################################################
# Hackish solution to always move compile_commands.json to project root. Only
# guaranteed to run with make -k is given From the docs:
#
# -k, --keep-going
# Continue as much as possible after an error.  While the
# target that failed, and those that depend on it, cannot be remade, the other
# dependencies of these targets can be processed all the same. #
# ##############################################################################

add_custom_target(dummy_target ALL DEPENDS move_compile_commands)

add_custom_command(OUTPUT move_compile_commands
                   COMMAND mv ${PROJECT_SOURCE_DIR}/compile_commands.json
                           ${PROJECT_ROOT}/compile_commands.json
                   DEPENDS always_rebuild)

add_custom_command(OUTPUT always_rebuild COMMAND cmake -E echo)
