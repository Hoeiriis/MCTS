add_executable(test_basicbackup test_basicbackup.cpp)
target_link_libraries(test_basicbackup
                      GTest::GTest
                      GTest::Main
                      basicBackup)

gtest_discover_tests(test_basicbackup)