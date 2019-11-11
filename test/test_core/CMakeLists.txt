add_subdirectory(test_tree_policies)

add_executable(test_SearchNode test_SearchNode.cpp)
target_link_libraries(test_SearchNode
                      ${TEST_TARGETS}
                      Core)

gtest_discover_tests(test_SearchNode)