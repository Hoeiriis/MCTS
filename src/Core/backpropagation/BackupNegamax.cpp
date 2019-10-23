#include <BackupNegamax.h>

BackupNegmax::BackupNegmax(SearchNode *node, Reward defaultPolicyScore, double currentPlayer)
    : BackupBase(node, defaultPolicyScore), currentPlayer(currentPlayer) {
    std::vector<SearchNode *> ancestorList = {};
    this->ancestors = getAncestors(node, ancestorList);
};

void BackupNegmax::backup() {
    for (SearchNode *currentNode : this->ancestors) {
        currentNode->visits += 1;
        currentNode->score += defaultPolicyScore;

        this->defaultPolicyScore = -1 * (this->defaultPolicyScore);
        if (this->currentPlayer == 1) {
            this->currentPlayer = 0;
        } else {
            this->currentPlayer = 1;
        }
    }
}