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

if($ENV{BOOST_ROOT})
  set(BOOST_ROOT $ENV{BOOST_ROOT})
endif()

set(BOOST_COMPONENTS system)
find_package(Boost 1.69 REQUIRED COMPONENTS ${BOOST_COMPONENTS})

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
target_link_libraries(main TicTacToe) 

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

if(NOT TESTING)
  set(TESTING YES)
endif(NOT TESTING)


if("${TESTING}" STREQUAL "YES")
  enable_testing()
  add_subdirectory(test)
endif("${TESTING}" STREQUAL "YES")