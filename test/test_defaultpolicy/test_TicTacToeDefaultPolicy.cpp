#include <TicTacToeDefaultPolicy.h>
#include <TicTacToeEnvironment.h>
#include <gmock/gmock.h>
#include <gtest/gtest.h>

class MockTicTacToeEnv {
  public:
    // MOCK_METHOD((std::vector<int>), GetValidChildStates, (int));
    MOCK_METHOD(int, EvaluateTerminalState, (int));
};

// Testing behavior with a terminal state given
TEST(TicTacToeDefaultPolicy, TestNoChildrenState) {
    // Arange
    // State state = State("2.1");
    // std::vector<State> validChildStates = {};
    MockTicTacToeEnv mock_env;
    // EXPECT_CALL(mock_env, GetValidChildStates(state)).Times(1).WillOnce(testing::Return(validChildStates));
    EXPECT_CALL(mock_env, EvaluateTerminalState(1)).WillOnce(testing::Return(1));
    /*

        std::function<std::vector<State>(State &)> getValidChildStates =
            std::bind(&MockTicTacToeEnv::GetValidChildStates, &mock_env, _1);
        std::function<Reward(State &)> evaluateTerminalState =
            std::bind(&MockTicTacToeEnv::EvaluateTerminalState, &mock_env, _1);

        TicTacToeDefaultPolicy t_defaultPolicy = TicTacToeDefaultPolicy(getValidChildStates, evaluateTerminalState);
        EXPECT_CALL(mock_env, GetValidChildStates(state)).Times(1).WillOnce(Return(validChildStates));
        EXPECT_CALL(mock_env, EvaluateTerminalState(state)).Times(1).WillOnce(Return(2.1));

        // Act
        double reward = t_defaultPolicy.defaultPolicy(state);

        // Assert
        EXPECT_DOUBLE_EQ(reward, 2.1); */
}
/*
//Testing a behavior where a child is terminal
TEST(TicTacToeDefaultPolicy, TestStateWithTerminalChild) {
    // Arange
    State state = State("1");
    std::vector<State> validChildStates = {State("1.1"), State("1.2")};
    std::vector<State> validChildStates_1 = {State("1.1.1")};
    std::vector<State> noValidChildStates = {};
    MockTicTacToeEnv mock_env;
    std::function<std::vector<State>(State &)> getValidChildStates =
        std::bind(&MockTicTacToeEnv::GetValidChildStates, &mock_env, _1);
    std::function<Reward(State &)> evaluateTerminalState =
        std::bind(&MockTicTacToeEnv::EvaluateTerminalState, &mock_env, _1);

    TicTacToeDefaultPolicy t_defaultPolicy = TicTacToeDefaultPolicy(getValidChildStates, evaluateTerminalState);
    // Simulates situation where second child is terminal one
    EXPECT_CALL(mock_env, GetValidChildStates(state))
        .Times(3)
        .WillOnce(Return(validChildStates))
        .WillOnce(Return(validChildStates_1))
        .WillOnce(Return(noValidChildStates));
    EXPECT_CALL(mock_env, EvaluateTerminalState(state)).Times(1).WillOnce(Return(1.2));

    // Act
    double reward = t_defaultPolicy.defaultPolicy(state);

    // Assert
    EXPECT_EQ(reward, 1.2);
} */