add_executable(test_tictactoe test_tictactoe.cpp)
target_link_libraries(test_tictactoe
                      GTest::GTest
                      GTest::Main
                      TicTacToe)

gtest_discover_tests(test_tictactoe)
