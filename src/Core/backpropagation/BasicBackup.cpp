#include <BasicBackup.h>

BasicBackup::BasicBackup(){};

void BasicBackup::backup(std::shared_ptr<SearchNode> node, Reward defaultPolicyScore) {
    std::vector<SearchNode *> ancestorsList = {};
    getAncestors(node.get(), ancestorsList);

    for (auto currentNode : ancestorsList) {
        currentNode->visits += 1;
        currentNode->score.at(0) += defaultPolicyScore;
    }
}