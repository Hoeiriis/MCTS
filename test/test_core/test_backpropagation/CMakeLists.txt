add_executable(test_basicbackup test_basicbackup.cpp)

target_link_libraries(test_basicbackup
                      ${TEST_TARGETS}
                      backpropagation)
                      
gtest_discover_tests(test_basicbackup)