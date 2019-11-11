#include <SearchNode.h>
#include <gtest/gtest.h>

TEST(SearchNode, ParentChildRelationshipTest) {
    // Arange
    State aState = State("root");
    State bState = State("childRoot");
    SearchNode root = SearchNode(nullptr, aState, false);

    // Act
    SearchNode child = SearchNode(&root, bState, false);
    // Assert
    EXPECT_EQ(&root, child.parent);
    EXPECT_EQ(&child, root.child_nodes.at(0).get());
}

TEST(SearchNode, ParentChildRelationshipTwoLevelsTest) {
    // Arange
    State aState = State("root");
    State bState = State("childRoot");
    State cState = State("childChildRoot");
    SearchNode root = SearchNode(nullptr, aState, false);

    // Act
    SearchNode child = SearchNode(&root, bState, false);
    SearchNode childChild = SearchNode(&child, cState, false);
    // Assert
    EXPECT_EQ(&root, child.parent);
    EXPECT_EQ(&child, root.child_nodes.at(0).get());

    EXPECT_EQ(&child, childChild.parent);
    EXPECT_EQ(&childChild, child.child_nodes.at(0).get());

    EXPECT_EQ(&root, childChild.parent->parent);
    EXPECT_EQ(&childChild, root.child_nodes.at(0)->child_nodes.at(0).get());
}