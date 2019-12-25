#include <BackupBase.h>

// getAncestores - stores simulated node and all the nodes visited in one rollout in one list
void BackupBase::getAncestors(SearchNode *node, std::vector<SearchNode *> &ancestorsList) {
    ancestorsList.push_back(node);
    if (node->parent != nullptr) {
        SearchNode *parent = node->parent;
        BackupBase::getAncestors(parent, ancestorsList);
    }
};