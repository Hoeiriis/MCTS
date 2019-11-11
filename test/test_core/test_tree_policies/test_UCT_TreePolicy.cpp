#include <UCT_TreePolicy.h>
#include <boost/function.hpp>
#include <gtest/gtest.h>
#include <memory>
#include <string>

State tempState(std::nullopt);

class UCT_TreePolicyTest : public ::testing::Test {

  protected:
    void SetUp() override {

        // root
        State rootNode = State("rootNode");
        root = SearchNode(nullptr, rootNode, false);

        // root as parent
        State rootChild1State = State("rootChild1");
        State rootChild2State = State("rootChild2");
        SearchNode rootChild1 = SearchNode(&root, rootChild1State, false);
        SearchNode rootChild2 = SearchNode(&root, rootChild2State, false);

        std::function<std::shared_ptr<SearchNode>(SearchNode *)> sExp =
            std::bind(&UCT_TreePolicyTest::simpleExpand, this, std::placeholders::_1);
        std::function<std::shared_ptr<SearchNode>(SearchNode *)> sChild =
            std::bind(&UCT_TreePolicyTest::simpleChild, this, std::placeholders::_1);
        treePolicy = UCT_TreePolicy(sExp, sChild);
    }

    SearchNode root = SearchNode(nullptr, tempState, false);
    std::function<std::shared_ptr<SearchNode>(SearchNode *)> placeholderFunc = [](SearchNode *node) {
        return std::make_shared<SearchNode>(*node);
    };
    UCT_TreePolicy treePolicy = UCT_TreePolicy(placeholderFunc, placeholderFunc);

    std::shared_ptr<SearchNode> simpleExpand(SearchNode *node) {
        State state = node->unvisited_child_states.at(0);
        SearchNode expanded_node = SearchNode(node, state, false);
        std::shared_ptr<SearchNode> exp_node_ptr = std::make_shared<SearchNode>(expanded_node);
        return exp_node_ptr;
    }

    std::shared_ptr<SearchNode> simpleChild(SearchNode *node) {
        auto firstChild = *node->child_nodes.at(0).get();
        auto sChild = std::make_shared<SearchNode>(firstChild);
        return sChild;
    }
};

TEST_F(UCT_TreePolicyTest, ExpandNode) {
    // Arrange
    State rootChild3 = State("rootChild3");
    std::vector<State> unvisited_child_states{rootChild3};
    root.set_unvisited_child_states(unvisited_child_states);

    // Act
    auto expandedNode = treePolicy.treePolicy(&root);

    // Assert
    EXPECT_EQ(expandedNode->parent, &root);
    EXPECT_EQ(root.child_nodes.size(), 3);
}


TEST_F(UCT_TreePolicyTest, BestChildOnceThenExpand) {
    // Arrange
    State rootChild1Child = State("rootChild1Child");
    std::vector<State> unvisited_child_states{rootChild1Child};
    auto bestChild = root.child_nodes.at(0).get();
    bestChild->set_unvisited_child_states(unvisited_child_states);

    // Act
    auto expandedNode = treePolicy.treePolicy(&root);

    // Assert
    EXPECT_EQ(expandedNode->parent, bestChild);
    EXPECT_EQ(bestChild->child_nodes.size(), 1);
}

/*
TEST_F(UCT_TreePolicyTest, BestChildTwiceThenExpand) {}

TEST_F(UCT_TreePolicyTest, NoExpand) {}
*/