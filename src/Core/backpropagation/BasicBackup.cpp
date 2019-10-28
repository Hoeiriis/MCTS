#include <BasicBackup.h>

BasicBackup::BasicBackup(){};

void BasicBackup::backup(SearchNode *node, Reward defaultPolicyScore) {
    std::vector<SearchNode *> ancestorsList = {};
    this->ancestors = getAncestors(node, ancestorsList);

    for (SearchNode *currentNode : this->ancestors) {
        currentNode->visits += 1;
        currentNode->score += defaultPolicyScore;
    }
}