#include <UCT_TreePolicy.h>
#include <gtest/gtest.h>
#include <string>

State tempState(std::nullopt);

class UCT_TreePolicyTest : public ::testing::Test {

  protected:
    void SetUp() override {

        // root
        State rootNode = State("rootNode");
        root = SearchNode(NULL, rootNode, false);

        // root as parent
        State rootChild1State = State("rootChild1");
        State rootChild2State = State("rootChild2");
        SearchNode rootChild1 = SearchNode(&root, rootChild1State, false);
        SearchNode rootChild2 = SearchNode(&root, rootChild2State, false);
    }

    SearchNode root = SearchNode((SearchNode *)NULL, tempState, false);
    boost::function<SearchNode(SearchNode)> placeholderFunc = [](SearchNode node){return node;};
    UCT_TreePolicy treePolicy = UCT_TreePolicy(placeholderFunc, placeholderFunc);

    SearchNode simpleExpand(SearchNode &node) {
        State state = node.unvisited_child_states.at(0);
        SearchNode expanded_node = SearchNode(&node, state, false);
        return expanded_node;
    }

    inline SearchNode simpleChild(SearchNode &node) { return node.child_nodes.at(0); }
};

TEST_F(UCT_TreePolicyTest, ExpandNode) {
    // Arange
    State rootChild3 = State("rootChild3");
    std::vector<State> unvisited_child_states{rootChild3};
    root.set_unvisited_child_states(unvisited_child_states);

    // Act
    SearchNode expandedNode = treePolicy.treePolicy(root);

    // Assert
    EXPECT_EQ(expandedNode.parent, &root);
    EXPECT_EQ(root.child_nodes.size(), 3);
}

/*
TEST_F(UCT_TreePolicyTest, BestChildOnceThenExpand) {}

TEST_F(UCT_TreePolicyTest, BestChildTwiceThenExpand) {}

TEST_F(UCT_TreePolicyTest, NoExpand) {}
*/