#include <BackupBase.h>

class BackupNegmax : BackupBase {
  public:
    BackupNegmax();
    using BackupBase::backup;
    void backup(std::shared_ptr<SearchNode> node, Reward defaultPolicyScore, int currentPlayer);

  private:
    int currentPlayer;
};