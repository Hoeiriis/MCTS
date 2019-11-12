#include <SearchNode.h>
#include <gtest/gtest.h>

TEST(SearchNode, ParentChildRelationshipTest) {
    // Arange
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
    // Arange
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