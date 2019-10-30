#include <UCT_TreePolicy.h>
#include <gtest/gtest.h>
#include <string>
#include <cstdlib>

class UCT_TreePolicyTest : public ::testing::Test {
  protected:
    void Setup() override {
        treePolicy = UCT_TreePolicy(simpleExpand,)

        // root
        State<string> rootNode = State<string>("rootNode");
        root = SearchNode(NULL, rootNode, false);

        // root as parent
        State<string> rootChild1 = State<string>("rootChild1");
        State<string> rootChild2 = State<string>("rootChild2");
        SearchNode rootChild1 = SearchNode(root, rootChild1, false);
        SearchNode rootChild2 = SearchNode(root, rootChild2, false);
    }

    SearchNode root;
    UCT_TreePolicy treePolicy;

    SearchNode simpleExpand(SearchNode &node){
        State<string> state = node.unvisited_child_states.at(0);
        SearchNode expanded_node = SearchNode(node, state, false);
        return 
    }

    SearchNode simpleChild(SearchNode &node){
        return node.child_nodes.at(0);
    }

}

TEST_F(UCT_TreePolicyTest, ExpandNode) {
    // Arange
    State<string> rootChild3 = State<string>("rootChild3");
    std::vector<State<string>> unvisited_child_states{rootChild3};
}

/*
TEST_F(UCT_TreePolicyTest, BestChildOnceThenExpand) {}

TEST_F(UCT_TreePolicyTest, BestChildTwiceThenExpand) {}

TEST_F(UCT_TreePolicyTest, NoExpand) {}
*/