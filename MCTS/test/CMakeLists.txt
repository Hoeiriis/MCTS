enable_testing()
find_package(GTest REQUIRED)

add_executable(the_target_testing_main test_main.cpp)

target_link_libraries(the_target_testing_main GTest::GTest GTest::Main TicTacToe)

add_test(NAME "the thing testing main" COMMAND the_target_testing_main)
