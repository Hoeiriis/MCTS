add_executable(test_UCT_TreePolicy test_UCT_TreePolicy.cpp)
target_link_libraries(test_UCT_TreePolicy
                      ${TEST_TARGETS}
                      tree_policies)

gtest_discover_tests(test_UCT_TreePolicy)                    