#include <TicTacToeDefaultPolicy.h>
#include <TicTacToeEnvironment.h>
#include <gmock/gmock.h>
#include <gtest/gtest.h>

using testing::Return;
using namespace std::placeholders;

class MockTicTacToeEnv : public TicTacToeEnv {
  public:
    MOCK_METHOD(std::vector<State>, GetValidChildStates, (State &));
    MOCK_METHOD(Reward, EvaluateTerminalState, (State &));
};

TEST(TicTacToeDefaultPolicy, TestNoChildrenState) {
    // Arange
    State state = new State(2.1);
    std::vector<State> validChildStates = {};
    MockTicTacToeEnv mock_env;
    std::function<std::vector<State>(State &)> getValidChildStates =
        std::bind(&MockTicTacToeEnv::GetValidChildStates, &mock_env, _1);
    std::function<Reward(State &)> evaluateTerminalState =
        std::bind(&MockTicTacToeEnv::EvaluateTerminalState, &mock_env, _1);

    TicTacToeDefaultPolicy t_defaultPolicy = TicTacToeDefaultPolicy(getValidChildStates, evaluateTerminalState);

    EXPECT_CALL(mock_env, GetValidChildStates(state)).Times(1).WillOnce(Return(validChildStates));
    EXPECT_CALL(mock_env, EvaluateTerminalState(state)).Times(1).WillOnce(Return(2.1));

    // Act
    Reward reward = t_defaultPolicy.defaultPolicy(state);

    // Assert
    EXPECT_EQ(reward, 2.1);
}

TEST(TicTacToeDefaultPolicy, TestStateWithTerminalChild) {
    // Arange
    State state = new State(1);
    std::vector<State> validChildStates = {new State(1.1), new State(1.2)};
    std::vector<State> noValidChildStates = {};
    MockTicTacToeEnv mock_env;
    std::function<std::vector<State>(State &)> getValidChildStates =
        std::bind(&MockTicTacToeEnv::GetValidChildStates, &mock_env, _1);
    std::function<Reward(State &)> evaluateTerminalState =
        std::bind(&MockTicTacToeEnv::EvaluateTerminalState, &mock_env, _1);

    TicTacToeDefaultPolicy t_defaultPolicy = TicTacToeDefaultPolicy(getValidChildStates, evaluateTerminalState);

    //Simulates situation where second child is terminal one
    EXPECT_CALL(mock_env, GetValidChildStates(state)).Times(2).WillOnce(Return(validChildStates))
                                                              .WillOnce(Return(validChildStates))
                                                              .WillOnce(Return(noValidChildStates));
    EXPECT_CALL(mock_env, EvaluateTerminalState(state)).Times(1).WillOnce(Return(1.2));

    // Act
    double reward = t_defaultPolicy.defaultPolicy(state);

    // Assert
    EXPECT_EQ(reward, 1.2);
}