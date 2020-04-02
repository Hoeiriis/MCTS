#FetchContent Only available in cmake 3.11 =>
include(FetchContent)
 FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest
  GIT_TAG        release-1.10.0
)

FetchContent_GetProperties(googletest)
if(NOT googletest_POPULATED)
  FetchContent_Populate(googletest)
  add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})
endif()

find_package(GTest QUIET)
if(GTest_FOUND)

  macro(package_add_test TESTNAME)
    # create an exectuable in which the tests will be stored
    add_executable(${TESTNAME} ${ARGN})
    # link the gtest and gmock
    # maybe do something with MCTS namespaces later
    target_link_libraries(${TESTNAME} gtest gmock gtest_main MCTS::MCTS)
    # gtest_discover_tests to discover the tests
    gtest_discover_tests(${TESTNAME})

    target_compile_features(${TESTNAME} PRIVATE cxx_std_17)

  endmacro()

  add_subdirectory(test_environments)
  add_subdirectory(test_core)

else()
    message(WARNING "\nGTest not found.\n\
    It will probably be found after you have run `make` and then cmake again.\n\
    If this warning persists I messed up.")

endif(GTest_FOUND)