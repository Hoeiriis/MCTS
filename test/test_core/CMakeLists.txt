add_subdirectory(test_tree_policies)
add_subdirectory(test_defaultpolicy)
add_subdirectory(test_backpropagation)
add_subdirectory(test_mcts)
add_subdirectory(test_runner)

add_executable(test_SearchNode test_SearchNode.cpp)
target_link_libraries(test_SearchNode
                      ${TEST_TARGETS}
                      Core)

gtest_discover_tests(test_SearchNode)
