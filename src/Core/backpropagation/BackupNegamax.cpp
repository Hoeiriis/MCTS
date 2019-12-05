#include <BackupNegamax.h>

BackupNegamax::BackupNegamax(){};

void BackupNegamax::backup(const std::shared_ptr<SearchNode>& node, Reward defaultPolicyScore, int currentPlayer) {
    std::vector<SearchNode *> ancestorsList = {};
    getAncestors(node.get(), ancestorsList);

    for (auto currentNode : ancestorsList) {
        currentNode->visits += 1;
        currentNode->score[currentPlayer] += defaultPolicyScore;

        defaultPolicyScore = -1 * (defaultPolicyScore);
        currentPlayer &= 1;
   }
}
