add_executable(test_tictactoe test_tictactoe.cpp)
target_link_libraries(test_tictactoe
                      GTest::GTest
                      GTest::Main
                      TicTacToe)

# add_test(NAME test_tictactoe COMMAND test_tictactoe)

gtest_add_tests(TARGET test_tictactoe)

# gtest_add_tests( TARGET name_of_target TEST_SUFFIX "just a string appended to
# the name of the test in the test output so you can tell tests apart if the
# same target is being run with different input arguments" TEST_LIST "argument
# list to be given as input to the test") TEST_SUFFIX "can be anything to tell"
# TEST_LSIT noArgsTests)
