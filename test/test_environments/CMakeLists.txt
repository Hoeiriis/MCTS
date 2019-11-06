add_executable(test_tictactoe test_tictactoe.cpp)

target_link_libraries(test_tictactoe
                      ${TEST_TARGETS}
                      TicTacToe)

gtest_discover_tests(test_tictactoe)

add_executable(test_state test_state.cpp)

target_link_libraries(test_state
                      ${TEST_TARGETS}
                      Environment)

gtest_discover_tests(test_state)
