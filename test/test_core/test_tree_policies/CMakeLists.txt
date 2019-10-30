add_executable(test_tree_policies test_UCT_TreePolicy.cpp)
target_link_libraries(test_tree_policies
                      GTest::GTest
                      GTest::Main
                      tree_policies)

gtest_discover_tests(test_tree_policies)                    