add_executable(test_UCT test_UCT.cpp)

target_link_libraries(test_UCT
                      ${TEST_TARGETS}
                      gmock
                      gmock_main
                      mcts)

gtest_discover_tests(test_UCT)


