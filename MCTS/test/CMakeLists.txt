find_package(Threads REQUIRED)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/test_binaries)

include(ExternalProject)

set(GTEST_ROOT "${EXTERNAL_INSTALL_LOCATION}/GTest")
set(GTEST_DIR "${GTEST_ROOT}/lib/cmake")

ExternalProject_Add(googletest
                    GIT_REPOSITORY https://github.com/google/googletest
                    CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${GTEST_ROOT})

include_directories(${GTEST_ROOT}/include)
link_directories(${GTEST_ROOT}/lib)

find_package(GTest)
include(GoogleTest)

add_subdirectory(test_environments)


# gtest_discover_tests(test_main)


# add_executable(FirstTest test_main.cpp) add_dependencies(FirstTest googletest)
# target_link_libraries(FirstTest gtest gtest_main TicTacToe pthread)

# add_executable(the_target_testing_main test_main.cpp)

# target_link_libraries(the_target_testing_main GTest::GTest GTest::Main
# TicTacToe)

# add_test(NAME "the thing testing main" COMMAND the_target_testing_main)
