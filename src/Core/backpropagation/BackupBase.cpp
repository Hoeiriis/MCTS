#include <BackupBase.h>

BackupBase::BackupBase(SearchNode *node, Reward defaultPolicyScore)
    : node(node), defaultPolicyScore(defaultPolicyScore){};

std::vector<SearchNode *> BackupBase::getAncestors(SearchNode *node, std::vector<SearchNode *> ancestorsList) {
    ancestorsList.push_back(node);
    SearchNode *parent = node->parent;

    if (parent != nullptr) {
        BackupBase::getAncestors(parent, ancestorsList);
    }
    return ancestorsList;
};