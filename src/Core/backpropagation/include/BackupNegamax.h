#include <BackupBase.h>

class BackupNegamax : BackupBase {
  public:
    BackupNegamax();
    using BackupBase::backup;
    void backup(std::shared_ptr<SearchNode> node, Reward defaultPolicyScore, int currentPlayer);

  private:
    int currentPlayer;
};