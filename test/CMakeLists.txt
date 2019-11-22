find_package(Threads REQUIRED)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_DIR}/test)

include(ExternalProject)

# Necessary for CMake to find this specific GTest install
set(GTEST_ROOT "${EXTERNAL_INSTALL_LOCATION}/GTest")
set(GTEST_DIR "${GTEST_ROOT}/lib/cmake")

ExternalProject_Add(googletest
                    INSTALL_DIR "${GTEST_ROOT}/install_prefix"
                    PREFIX "${PREFIX_LOCATION}/gtest"
                    GIT_REPOSITORY https://github.com/google/googletest
                    GIT_TAG v1.10.x
                    TIMEOUT 30
                    CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${GTEST_ROOT})


set(TEST_TARGETS GTest::GTest GTest::Main)
find_package(GTest QUIET)

if(GTest_FOUND)
  include_directories(${GTEST_ROOT}/include)
  link_directories(${GTEST_ROOT}/lib)
  include(GoogleTest)

  add_subdirectory(test_environments)
  add_subdirectory(test_core)

else()

  message(WARNING "\nGTest not found.\n\
It will probably be found after you have run `make` and then cmake again.\n\
If this warning persists I messed up.")

endif(GTest_FOUND)
