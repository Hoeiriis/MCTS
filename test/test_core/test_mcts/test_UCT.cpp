#include <UCT.h>
#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <utility>

class MockEnv : public EnvironmentInterface {
  public:
    MOCK_METHOD((std::vector<State>), GetValidChildStates, (State &));
    MOCK_METHOD(Reward, EvaluateRewardFunction, (State &));
    MOCK_METHOD(bool, IsTerminal, (State &));
    MOCK_METHOD(State, GetStartState, ());
};

class UCTTesting : UCT, public ::testing::Test {

  public:
    UCTTesting() : UCT(mockEnv){};

    // The following methods needs a public wrapper for testing since they normally are protected

    std::shared_ptr<SearchNode> wrapper_m_best_child(std::shared_ptr<SearchNode> node, double c) {
        return this->m_best_child(std::move(node), c);
    }

    std::shared_ptr<SearchNode> wrapper_m_expand(std::shared_ptr<SearchNode> node) { return m_expand(std::move(node)); }

  protected:
    void SetUp() override {

        // Root
        State rootState = State("root");
        root = SearchNode::create_SearchNode(nullptr, rootState, false);

        // Child 1
        State child1 = State("Child1");
        child1Node = SearchNode::create_SearchNode(root, child1, false);

        // Child 2
        State child2 = State("Child2");
        child2Node = SearchNode::create_SearchNode(root, child2, false);

        // Child 3
        State child3 = State("Child3");
        child3Node = SearchNode::create_SearchNode(root, child3, false);

        // Child 3
        State child4 = State("Child4");
        child4Node = SearchNode::create_SearchNode(root, child4, false);
    }

    std::shared_ptr<SearchNode> root = SearchNode::create_SearchNode(nullptr, false);
    std::shared_ptr<SearchNode> child1Node = SearchNode::create_SearchNode(nullptr, false);
    std::shared_ptr<SearchNode> child2Node = SearchNode::create_SearchNode(nullptr, false);
    std::shared_ptr<SearchNode> child3Node = SearchNode::create_SearchNode(nullptr, false);
    std::shared_ptr<SearchNode> child4Node = SearchNode::create_SearchNode(nullptr, false);
    MockEnv mockEnv = MockEnv();
};

TEST_F(UCTTesting, BestChildChoosesChildCorrectly) {
    // Arrange
    root->visits = 6;

    // best child score: 1.2131
    child1Node->score.at(0) = 2;
    child1Node->visits = 3;

    // best child score: 0.9465
    child2Node->score.at(0) = 0;
    child2Node->visits = 1;

    // best child score: 0.9465
    child3Node->score.at(0) = 0;
    child3Node->visits = 1;

    // best child score: 1.6692 (best)
    child4Node->score.at(0) = 2;
    child4Node->visits = 2;

    double cp = 1 / std::sqrt(2);

    // Act
    auto bestChild = wrapper_m_best_child(root, cp);

    // Assert
    EXPECT_EQ(bestChild.get(), child4Node.get());
}

TEST_F(UCTTesting, ExpandedNodeHasCorrectParentAndStateValue) {
    // Arrange
    State unvisitedState = State("State5");
    std::vector<State> unvisitedStates{unvisitedState};
    root->set_unvisited_child_states(unvisitedStates);

    // Set return value of mockEnv
    State someState = State("SomeStateValue");
    std::vector<State> someUnvisitedStates{someState};
    EXPECT_CALL(mockEnv, GetValidChildStates)
        .Times(testing::AnyNumber())
        .WillRepeatedly(testing::Return(someUnvisitedStates));

    // Act
    auto expandedNode = wrapper_m_expand(root);

    // Assert
    EXPECT_EQ(expandedNode->parent, root.get());
    EXPECT_EQ(expandedNode->state.getData<const char *>(), unvisitedState.getData<const char *>());
    EXPECT_TRUE(root->unvisited_child_states.empty());
}