#include <BackupNegamax.h>

BackupNegmax::BackupNegmax(){};

void BackupNegmax::backup(std::shared_ptr<SearchNode> node, Reward defaultPolicyScore, int currentPlayer) {
    std::vector<SearchNode *> ancestorsList = {};
    getAncestors(node.get(), ancestorsList);

    for (auto currentNode : ancestorsList) {
        currentNode->visits += 1;
        //currentNode->score[currentPlayer] += defaultPolicyScore;
        defaultPolicyScore = -1 * (defaultPolicyScore);
        currentPlayer &= 1;
   }
}