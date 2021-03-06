#include <BasicBackup.h>
#include <SearchNode.h>
#include <State.h>
#include <gtest/gtest.h>

TEST(TestBasicBackup, TestUpdateVisitsAndScores) {
    // Arange
    State state = State(0);
    auto node = SearchNode::create_SearchNode(nullptr, state, false);
    auto node_1 = SearchNode::create_SearchNode(node, state, false);
    auto node_2 = SearchNode::create_SearchNode(node, state, false);
    auto node_1_1 = SearchNode::create_SearchNode(node_1, state, false);
    auto node_2_1 = SearchNode::create_SearchNode(node_2, state, false);
    auto node_2_2 = SearchNode::create_SearchNode(node_2, state, false);

    BasicBackup basic_backup = BasicBackup();

    // Act
    basic_backup.backup(node_2_1, 2);
    basic_backup.backup(node_2_1, 2);
    basic_backup.backup(node_2_2, 2);

    // Assert
    std::cout << node_1->visits << std::endl;
    EXPECT_EQ(node_1->visits, 0);
    EXPECT_EQ(node_1_1->visits, 0);
    EXPECT_EQ(node_2->visits, 3);
    EXPECT_EQ(node_2_1->visits, 2);
    EXPECT_EQ(node_2_2->visits, 1);

    EXPECT_EQ(node_1_1->score.at(0), 0);
    EXPECT_EQ(node_1->score.at(0), 0);
    EXPECT_EQ(node_2->score.at(0), 6);
    EXPECT_EQ(node_2_1->score.at(0), 4);
    EXPECT_EQ(node_2_2->score.at(0), 2);
}



