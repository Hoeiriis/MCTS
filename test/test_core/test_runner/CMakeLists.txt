add_executable(test_RunnerTicTacToe test_RunnerTicTacToe.cpp)

target_link_libraries(test_RunnerTicTacToe
                      ${TEST_TARGETS}
                      gmock
                      gmock_main
                      runner)
                      
gtest_discover_tests(test_RunnerTicTacToe)