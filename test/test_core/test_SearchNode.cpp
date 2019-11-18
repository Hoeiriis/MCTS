#include <SearchNode.h>
#include <gtest/gtest.h>

TEST(SearchNode, ParentChildRelationshipTest) {
    // Arrange
    State aState = State("root");
    State bState = State("childRoot");
    auto root = SearchNode::create_SearchNode(nullptr, aState, false);

    // Act
    auto child = SearchNode::create_SearchNode(root, bState, false);

    // Assert
    EXPECT_EQ(root.get(), child->parent);
    EXPECT_EQ(child.get(), root->child_nodes.at(0).get());
}

TEST(SearchNode, ParentChildRelationshipTwoLevelsTest) {
    // Arrange
    State aState = State("root");
    State bState = State("childRoot");
    State cState = State("childChildRoot");
    auto root = SearchNode::create_SearchNode(nullptr, aState, false);

    // Act
    auto child = SearchNode::create_SearchNode(root, bState, false);
    auto childChild = SearchNode::create_SearchNode(child, cState, false);
    // Assert
    EXPECT_EQ(root.get(), child->parent);
    EXPECT_EQ(child.get(), root->child_nodes.at(0).get());

    EXPECT_EQ(child.get(), childChild->parent);
    EXPECT_EQ(childChild.get(), child->child_nodes.at(0).get());

    EXPECT_EQ(root.get(), childChild->parent->parent);
    EXPECT_EQ(childChild.get(), root->child_nodes.at(0)->child_nodes.at(0).get());
}

TEST(SearchNode, SearchNode_SetUnvisitedChildStat_Test) {
    // Arrange
    std::string rootStr = "root";
    State aState = State(rootStr);
    auto root = SearchNode::create_SearchNode(nullptr, aState, false);

    std::string childStr = "childState";
    State bState = State(childStr);
    std::vector<State> unvisited_child_states{bState};

    // Act
    auto v = root.get();
    v->set_unvisited_child_states(unvisited_child_states);

    // Assert
    auto ostate1 = root->unvisited_child_states.at(0).getData<std::string>();
    auto ostate2 = bState.getData<std::string>();
    EXPECT_EQ(ostate1, ostate2);
}
