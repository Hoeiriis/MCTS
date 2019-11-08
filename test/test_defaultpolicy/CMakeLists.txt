add_executable(test_defaultpolicy test_TicTacToeDefaultPolicy.cpp)

target_link_libraries(test_defaultpolicy
                      ${TEST_TARGETS}
                      DefaultPolicy)

gtest_discover_tests(test_defaultpolicy)


