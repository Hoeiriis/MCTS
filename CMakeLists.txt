set(CMAKE_CXX_STANDARD 17)
cmake_minimum_required(VERSION 3.8)

project("MCTS Library" LANGUAGES "CXX" VERSION 0.1.0)

execute_process(COMMAND "git" "rev-parse" "HEAD"
                COMMAND "cut" "-c1-16" "-z"
                WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
                OUTPUT_VARIABLE PACKAGE_REVISION
                OUTPUT_STRIP_TRAILING_WHITESPACE)

string(TOUPPER "${PACKAGE_REVISION}" PACKAGE_REVISION)
set(PACKAGE_REVISION "rev. ${PACKAGE_REVISION}")


execute_process(COMMAND "git" "rev-parse" "--show-toplevel"
                OUTPUT_VARIABLE PROJECT_ROOT
                OUTPUT_STRIP_TRAILING_WHITESPACE)

set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

set(OUTPUT_DIR "${PROJECT_SOURCE_DIR}/build")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${OUTPUT_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${OUTPUT_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_DIR}/bin)
set(EXTERNAL_INSTALL_LOCATION "${PROJECT_ROOT}/ExternalLibs")
set(PREFIX_LOCATION "${PROJECT_ROOT}/.prefixes")

message(STATUS "Prefix=${PREFIX_LOCATION}")

add_subdirectory(src/Environments)
add_subdirectory(src/Core)

add_executable(main src/main.cpp)
target_link_libraries(main mcts TicTacToe Core tree_policies)

# Build doxygen documentation if possible #####################################
find_package(Doxygen)
if(DOXYGEN_FOUND AND DOXYGEN_DOT_FOUND)
  set(DOC_OUTPUT_DIR "${PROJECT_ROOT}/doc")

  configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in
                 ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile @ONLY)

  add_custom_target(doc ${DOXYGEN_EXECUTABLE}
                    ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile
                    WORKING_DIRECTORY ${PROJECT_ROOT}
                    COMMENT "Generating API documentation with Doxygen"
                    VERBATIM)
endif(DOXYGEN_FOUND AND DOXYGEN_DOT_FOUND)

if(NOT "${TESTING}" STREQUAL "NO")
  message("Testing is ENABLED")
  set(TESTING YES)
else()
  message("Testing is DISABLED")
endif(NOT "${TESTING}" STREQUAL "NO")


if("${TESTING}" STREQUAL "YES")
  enable_testing()
  add_subdirectory(test)
endif("${TESTING}" STREQUAL "YES")

target_compile_features(main PUBLIC cxx_std_17)