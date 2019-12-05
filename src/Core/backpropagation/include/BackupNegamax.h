#ifndef MCTS_LIBRARY_BACKUPNEGAMAX
#define MCTS_LIBRARY_BACKUPNEGAMAX
#include <BackupBase.h>

class BackupNegamax : public BackupBase {
  public:
    BackupNegamax();
    void backup(const std::shared_ptr<SearchNode>& node, Reward defaultPolicyScore, int currentPlayer);
};

#endif // MCTS_LIBRARY_BACKUPNEGAMAX