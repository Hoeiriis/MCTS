#include <BasicBackup.h>
#include <SearchNode.h>
#include <State.h>
#include <gtest/gtest.h>

TEST(TestBasicBackup, TestUpdateVisitsAndScores) {
    // Arange
    State state = State(0);
    SearchNode node = SearchNode(nullptr, state);
    SearchNode node_1 = SearchNode(&node, state);
    SearchNode node_2 = SearchNode(&node, state);
    SearchNode node_1_1 = SearchNode(&node_1, state);
    SearchNode node_2_1 = SearchNode(&node_2, state);
    SearchNode node_2_2 = SearchNode(&node_2, state);

    BasicBackup basic_backup = BasicBackup();

    // Act
    basic_backup.backup(node_2_1, 2);
    basic_backup.backup(node_2_1, 2);
    basic_backup.backup(node_2_2, 2);

    // Assert
    std::cout << node_1.visits << std::endl;
    EXPECT_EQ(node_1_1.visits, 0);
    EXPECT_EQ(node_1_1.score, 0);
    EXPECT_EQ(node_1.visits, 0);
    EXPECT_EQ(node_2.visits, 2);
    EXPECT_EQ(node_2_1.visits, 2);
    EXPECT_EQ(node_2_2.visits, 1);
    
    EXPECT_EQ(node.score, 0);
    EXPECT_EQ(node.visits, 0);
}