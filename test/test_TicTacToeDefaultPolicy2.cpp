#include <TicTacToeDefaultPolicy.h>
#include <TicTacToeEnvironment.h>
#include <gmock/gmock.h>
#include <gtest/gtest.h>
/*
class tictactoe_defaultPolicy_test : public ::testing::Test {

  protected:
    void SetUp() override {

    }
};

// Testing behavior with a terminal state given
TEST_F(tictactoe_defaultPolicy_test, TestNoChildrenState) {
    // Arange
    State state = State("2.1");
    std::vector<State> validChildStates = {};

    // EXPECT_CALL(mock_env, GetValidChildStates(state)).Times(1).WillOnce(testing::Return(validChildStates));
    // EXPECT_CALL(mock_env, EvaluateTerminalState(state)).Times(1).WillOnce(testing::Return(2.1));


    std::function<std::vector<State>(State &)> getValidChildStates =
        std::bind(&MockTicTacToeEnv::GetValidChildStates, &mock_env, std::placeholders::_1);
    std::function<Reward(State &)> evaluateTerminalState =
        std::bind(&MockTicTacToeEnv::EvaluateTerminalState, &mock_env, std::placeholders::_1);


    TicTacToeDefaultPolicy t_defaultPolicy = TicTacToeDefaultPolicy(getValidChildStates, evaluateTerminalState);
    EXPECT_CALL(mock_env, GetValidChildStates(state)).Times(1).WillOnce(testing::Return(validChildStates));
    EXPECT_CALL(mock_env, EvaluateTerminalState(state)).Times(1).WillOnce(testing::Return(2.1));
    // Act
    double reward = t_defaultPolicy.defaultPolicy(state);

    // Assert
    EXPECT_DOUBLE_EQ(reward, 2.1);
}*/

// Testing a behavior where a child is terminal
TEST(TicTacToeDefaultPolicy, TestStateWithTerminalChild) {
    // Arange
    State state = State("1");
    std::vector<State> validChildStates = {State("1.1"), State("1.2")};
    std::vector<State> validChildStates_1 = {State("1.1.1")};
    std::vector<State> noValidChildStates = {};
    MockTicTacToeEnv mock_env = MockTicTacToeEnv();
    std::function<std::vector<State>(State &)> getValidChildStates =
        std::bind(&MockTicTacToeEnv::GetValidChildStates, &mock_env, std::placeholders::_1);
    std::function<Reward(State &)> evaluateTerminalState =
        std::bind(&MockTicTacToeEnv::EvaluateTerminalState, &mock_env, std::placeholders::_1);

    TicTacToeDefaultPolicy t_defaultPolicy = TicTacToeDefaultPolicy(getValidChildStates, evaluateTerminalState);
    // Simulates situation where second child is terminal one
    EXPECT_CALL(mock_env, GetValidChildStates(state))
        .Times(3)
        .WillOnce(testing::Return(validChildStates))
        .WillOnce(testing::Return(validChildStates_1))
        .WillOnce(testing::Return(noValidChildStates));
    EXPECT_CALL(mock_env, EvaluateTerminalState(state)).Times(1).WillOnce(testing::Return(1.2));

    // Act
    double reward = t_defaultPolicy.defaultPolicy(state);
    double other = 1.2;

    // Assert
    EXPECT_EQ(reward, other);
}