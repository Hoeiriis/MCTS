#include <BasicBackup.h>

BasicBackup::BasicBackup(){};

void BasicBackup::backup(SearchNode &node, Reward defaultPolicyScore) {
    std::vector<SearchNode *> ancestorsList = {};
    getAncestors(&node, ancestorsList);

    for (SearchNode *currentNode : ancestorsList) {
        currentNode->visits += 1;
        currentNode->score += defaultPolicyScore;
    }
}