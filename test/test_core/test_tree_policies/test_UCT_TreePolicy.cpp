#include <UCT_TreePolicy.h>
#include <gtest/gtest.h>
#include <memory>
#include <string>

class UCT_TreePolicyTest : public ::testing::Test {

  protected:
    void SetUp() override {

        // root
        State rootNode = State("rootNode");
        root = SearchNode::create_SearchNode(nullptr, rootNode, false);

        // root as parent
        State rootChild1State = State("rootChild1");
        State rootChild2State = State("rootChild2");
        std::shared_ptr<SearchNode> rootChild1 = SearchNode::create_SearchNode(root, rootChild1State, false);
        std::shared_ptr<SearchNode> rootChild2 = SearchNode::create_SearchNode(root, rootChild2State, false);


        std::function<std::shared_ptr<SearchNode>(std::shared_ptr<SearchNode>)> sExp =
            std::bind(&UCT_TreePolicyTest::simpleExpand, this, std::placeholders::_1);
        std::function<std::shared_ptr<SearchNode>(std::shared_ptr<SearchNode>, double)> sChild =
            std::bind(&UCT_TreePolicyTest::simpleChild, this, std::placeholders::_1, std::placeholders::_2);
        treePolicy = UCT_TreePolicy(sExp, sChild);
    }

    std::shared_ptr<SearchNode> root = SearchNode::create_SearchNode(nullptr, false);
    std::function<std::shared_ptr<SearchNode>(std::shared_ptr<SearchNode> node)> placeholderFunc =
        [](std::shared_ptr<SearchNode> node) { return node; };
    std::function<std::shared_ptr<SearchNode>(std::shared_ptr<SearchNode> node, double c)> placeholderFunc2 =
            [](std::shared_ptr<SearchNode> node, double c) { return node; };
    UCT_TreePolicy treePolicy = UCT_TreePolicy(placeholderFunc, placeholderFunc2);

    std::shared_ptr<SearchNode> simpleExpand(std::shared_ptr<SearchNode> node) {
        State state = node->unvisited_child_states.at(0);
        std::shared_ptr<SearchNode> expanded_node = SearchNode::create_SearchNode(node, state, false);
        return expanded_node;
    }

    std::shared_ptr<SearchNode> simpleChild(std::shared_ptr<SearchNode> node, double c=0) {
        auto firstChild = node->child_nodes.at(0);
        return firstChild;
    }
};

TEST_F(UCT_TreePolicyTest, ExpandRootsUnvisitedChildState) {
    // Arrange
    State rootChild3 = State("rootChild3");
    std::vector<State> unvisited_child_states{rootChild3};
    root->set_unvisited_child_states(unvisited_child_states);

    // Act
    auto expandedNode = treePolicy.treePolicy(root);

    // Assert
    EXPECT_EQ(expandedNode->parent, root.get());
    EXPECT_EQ(root->child_nodes.size(), 3);
}

TEST_F(UCT_TreePolicyTest, CallBestChildOnceThenExpandUnvisitedChildState) {
    // Arrange
    State rootChild1Child = State("rootChild1Child");
    std::vector<State> unvisited_child_states{rootChild1Child};
    auto bestChild = root->child_nodes.at(0);
    bestChild->set_unvisited_child_states(unvisited_child_states);

    // Act
    auto expandedNode = treePolicy.treePolicy(root);

    // Assert
    EXPECT_EQ(expandedNode->parent, bestChild.get());
    EXPECT_EQ(bestChild->child_nodes.size(), 1);
}

TEST_F(UCT_TreePolicyTest, CallBestChildTwiceThenExpandUnvisitedChildState) {

    // Arrange
    State secondBestChild = State("secondBestChild");
    State secondBestChildUnvisitedState = State("secondBestChildUnvisitedState");
    std::vector<State> unvisited_child_states{secondBestChildUnvisitedState};

    auto bestChild = root->child_nodes.at(0);
    auto bestChilds_bestChild = SearchNode::create_SearchNode(bestChild, secondBestChild, false);
    bestChilds_bestChild->set_unvisited_child_states(unvisited_child_states);

    // Act
    auto expandedNode = treePolicy.treePolicy(root);

    // Assert
    EXPECT_EQ(expandedNode->parent, bestChilds_bestChild.get());
    EXPECT_EQ(bestChilds_bestChild->child_nodes.size(), 1);
}

TEST_F(UCT_TreePolicyTest, ReturnTerminalNode) {
    // Arrange
    State secondBestChild = State("secondBestChild");
    auto bestChild = root->child_nodes.at(0);
    auto bestChilds_bestChild = SearchNode::create_SearchNode(bestChild, secondBestChild, true);

    // Act
    auto expandedNode = treePolicy.treePolicy(root);

    // Assert
    EXPECT_EQ(expandedNode.get(), bestChilds_bestChild.get());
    EXPECT_TRUE(bestChilds_bestChild->child_nodes.empty());
}
