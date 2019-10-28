#include <BackupBase.h>

BackupBase::BackupBase(){};

// getAncestores - stores simulated node and all the nodes visited in one rollout in one list
std::vector<SearchNode *> BackupBase::getAncestors(SearchNode *node, std::vector<SearchNode *> ancestorsList) {
    ancestorsList.push_back(node);
    SearchNode *parent = node->parent;

    if (parent != nullptr) {
        BackupBase::getAncestors(parent, ancestorsList);
    }
    return ancestorsList;
};