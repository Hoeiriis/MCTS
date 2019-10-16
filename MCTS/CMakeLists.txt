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

add_custom_target(move_compile_commands
                  COMMAND -E file
                          (COPY
                           "${PROJECT_SOURCE_DIR}/compile_commands.json"
                           DESTINATION
                           "${PROJECT_ROOT}")
                  COMMENT "Moving compile_commands"
                  DEPENDS main)

# if(EXISTS "${PROJECT_SOURCE_DIR}/compile_commands.json") file(COPY
# "${PROJECT_SOURCE_DIR}/compile_commands.json" DESTINATION "${PROJECT_ROOT}")
# endif()
