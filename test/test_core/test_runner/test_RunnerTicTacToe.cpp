#include <MCTSInterface.h>
#include <RunnerTicTacToe.h>
#include <TicTacToeEnvironment.h>
#include <gmock/gmock.h>
#include <gtest/gtest.h>

using namespace testing;
using namespace std::placeholders;
typedef std::shared_ptr<SearchNode> SearchNodes;

class MockEnv : public EnvironmentBase {
  public:
    MOCK_METHOD(Reward, EvaluateTerminalState, (State &));
    MOCK_METHOD(State, GetStartState, ());
    MOCK_METHOD((std::vector<State>), GetValidChildStates, (State &));
};

// TODO check mocking of func with default parameters
class MockMCTS : public MCTSInterface {
  public:
    MOCK_METHOD(State, run, (int), (override));
    MOCK_METHOD(EnvironmentBase &, getEnvironment, (), (override));

  private:
    MOCK_METHOD(SearchNodes, m_search, (int n_searches), (override));
    MOCK_METHOD(SearchNodes, m_tree_policy, (SearchNodes), (override));
    MOCK_METHOD(Reward, m_default_policy, (State &), (override));
    MOCK_METHOD(SearchNodes, m_best_child, (SearchNodes, double), (override));
    MOCK_METHOD(SearchNodes, m_expand, (SearchNodes), (override));
    MOCK_METHOD(void, m_backpropagation, (SearchNodes, Reward), (override));

    MockEnv mockEnv = MockEnv();
};

TEST(TestRunnerTicTacToe, TestVariousNumberOfGames) {
    // Arange
    MockEnv mockEnv;
    MockMCTS mockMCTS;
    State state = State("0");
    std::vector<State> childStates{};

    RunnerTicTacToe runner = RunnerTicTacToe(mockMCTS);
    EXPECT_CALL(mockMCTS, run).Times(AnyNumber()).WillRepeatedly(Return(state));
    EXPECT_CALL(mockMCTS, getEnvironment).Times(AnyNumber()).WillRepeatedly(ReturnRef(mockEnv));
    EXPECT_CALL(mockEnv, EvaluateTerminalState).Times(AnyNumber()).WillRepeatedly(Return(1));

    // Act
    for(int i=10; i<=2000; i+=10){
        runner.run(i,100);
    }

    // Assert
}