#include <iostream>
#include <gtest/gtest.h>
#include <TicTacToeEnvironment.h>

TEST(GetStartState, InitialStateIsCorrect){
    TicTacToeEnv env;
    std::vector<int> start_state = env.GetStartState();

    EXPECT_EQ(start_state.size(), 9);
    for (auto& val : start_state){
        EXPECT_EQ(val, 0);
    }

}
