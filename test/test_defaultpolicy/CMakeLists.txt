add_executable(test_defaultpolicy test_randomSamplingDefaultPolicy.cpp)
target_link_libraries(test_defaultpolicy
                      GTest::GTest
                      GTest::Main
                      DefaultPolicy)

gtest_discover_tests(test_defaultpolicy)


