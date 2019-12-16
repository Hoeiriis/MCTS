#include <TicTacToeDefaultPolicy.h>
#include <TicTacToeEnvironment.h>
#include <gmock/gmock.h>
#include <gtest/gtest.h>

using testing::Return;
using namespace std::placeholders;

class MockTicTacToeEnv: public EnvironmentInterface {
  public:
    MOCK_METHOD((std::vector<State>), GetValidChildStates, (State &));
    MOCK_METHOD(Reward, EvaluateRewardFunction, (State &));
    MOCK_METHOD(bool, IsTerminal, (State &));
    MOCK_METHOD(State, GetStartState, ());
};

// Testing behavior with a terminal state given
TEST(TicTacToeDefaultPolicy, TestNoChildrenState) {
    // Arange
    State state = State("2.1");
    std::vector<State> validChildStates = {};
    MockTicTacToeEnv mock_env;
    std::function<std::vector<State>(State &)> getValidChildStates =
        std::bind(&MockTicTacToeEnv::GetValidChildStates, &mock_env, _1);
    std::function<Reward(State &)> evaluateRewardFunction =
        std::bind(&MockTicTacToeEnv::EvaluateRewardFunction, &mock_env, _1);

    TicTacToeDefaultPolicy t_defaultPolicy = TicTacToeDefaultPolicy(mock_env);
    EXPECT_CALL(mock_env, GetValidChildStates).Times(1).WillOnce(Return(validChildStates));
    EXPECT_CALL(mock_env, EvaluateRewardFunction).Times(1).WillOnce(Return(2.1));

    // Act
    double reward = t_defaultPolicy.defaultPolicy(state);

    // Assert
    EXPECT_DOUBLE_EQ(reward, 2.1);
}

// Testing a behavior where a child is terminal
TEST(TicTacToeDefaultPolicy, TestStateWithTerminalChild) {
    // Arange
    State state = State("1");
    std::vector<State> validChildStates = {State("1.1"), State("1.2")};
    std::vector<State> validChildStates_1 = {State("1.1.1")};
    std::vector<State> noValidChildStates = {};
    MockTicTacToeEnv mock_env;
    std::function<std::vector<State>(State &)> getValidChildStates =
        std::bind(&MockTicTacToeEnv::GetValidChildStates, &mock_env, _1);
    std::function<Reward(State &)> evaluateRewardFunction =
        std::bind(&MockTicTacToeEnv::EvaluateRewardFunction, &mock_env, _1);

    TicTacToeDefaultPolicy t_defaultPolicy = TicTacToeDefaultPolicy(mock_env);
    // Simulates situation where second child is terminal one
    EXPECT_CALL(mock_env, GetValidChildStates)
        .Times(3)
        .WillOnce(Return(validChildStates))
        .WillOnce(Return(validChildStates_1))
        .WillOnce(Return(noValidChildStates));
    EXPECT_CALL(mock_env, EvaluateRewardFunction).Times(1).WillOnce(Return(1.2));

    // Act
    double reward = t_defaultPolicy.defaultPolicy(state);

    // Assert
    EXPECT_EQ(reward, 1.2);
}