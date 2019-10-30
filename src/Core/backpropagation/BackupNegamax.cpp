#include <BackupNegamax.h>

BackupNegmax::BackupNegmax(){};

void BackupNegmax::backup(SearchNode &node, Reward defaultPolicyScore, int currentPlayer) {
    std::vector<SearchNode *> ancestorsList = {};
    getAncestors(&node, ancestorsList);

    for (SearchNode *currentNode : ancestorsList) {
        currentNode->visits += 1;
        currentNode->score += defaultPolicyScore;
        defaultPolicyScore = -1 * (defaultPolicyScore);
        currentPlayer &= 1;
    }
}