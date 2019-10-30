#include <BackupBase.h>

class BackupNegmax : BackupBase {
  public:
    BackupNegmax();
    virtual void backup(SearchNode &node, Reward defaultPolicyScore, int currentPlayer);

  private:
    int currentPlayer;
};