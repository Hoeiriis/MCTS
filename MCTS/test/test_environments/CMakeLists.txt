add_executable(test_tictactoe test_tictactoe.cpp)
target_link_libraries(test_tictactoe GTest::GTest GTest::Main TicTacToe)

add_test(NAME test_tictactoe COMMAND test_tictactoe)
