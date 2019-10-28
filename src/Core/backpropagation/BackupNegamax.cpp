#include <BackupNegamax.h>

BackupNegmax::BackupNegmax(){};

void BackupNegmax::backup(SearchNode *node, Reward defaultPolicyScore, double currentPlayer) {
    std::vector<SearchNode *> ancestorsList = {};
    this->ancestors = getAncestors(node, ancestorsList);

    for (SearchNode *currentNode : this->ancestors) {
        currentNode->visits += 1;
        currentNode->score += defaultPolicyScore;

        defaultPolicyScore = -1 * (defaultPolicyScore);
        if (currentPlayer == 1) {
            currentPlayer = 0;
        } else {
            currentPlayer = 1;
        }
    }
}