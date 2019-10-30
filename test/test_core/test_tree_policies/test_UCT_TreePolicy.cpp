#include <UCT_TreePolicy.h>
#include <gtest/gtest.h>
#include <string>

class UCT_TreePolicyTest : public ::testing::Test {
  protected:

    void SetUp() override {
        treePolicy = UCT_TreePolicy(this->simpleExpand, this->simpleChild);

        // root
        State<std::string> rootNode = State<std::string>("rootNode");
        root = SearchNode(NULL, rootNode, false);

        // root as parent
        State<std::string> rootChild1State = State<std::string>("rootChild1");
        State<std::string> rootChild2State = State<std::string>("rootChild2");
        SearchNode rootChild1 = SearchNode(root, rootChild1State, false);
        SearchNode rootChild2 = SearchNode(root, rootChild2State, false);
    }

    SearchNode root;
    UCT_TreePolicy treePolicy;

      
    SearchNode simpleExpand(SearchNode &node) {
        State<std::string> state = node.unvisited_child_states.at(0);
        SearchNode expanded_node = SearchNode(node, state, false);
        return expanded_node;
    }

    inline SearchNode simpleChild(SearchNode &node) { return node.child_nodes.at(0); }
};

TEST_F(UCT_TreePolicyTest, ExpandNode) {
    // Arange
    State<std::string> rootChild3 = State<std::string>("rootChild3");
    std::vector<State<std::string>> unvisited_child_states{rootChild3};
    root.set_unvisited_child_states(unvisited_child_states);

    // Act
    SearchNode expandedNode = treePolicy.treePolicy(root);


    // Assert
    SearchNode *expandedParent = expandedNode.parent;
    SearchNode *pRoot = &root;
    EXPECT_EQ(expandedParent, pRoot);
    EXPECT_EQ(root.child_nodes.size(), 3);
}

/*
TEST_F(UCT_TreePolicyTest, BestChildOnceThenExpand) {}

TEST_F(UCT_TreePolicyTest, BestChildTwiceThenExpand) {}

TEST_F(UCT_TreePolicyTest, NoExpand) {}
*/