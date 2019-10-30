#include <BackupBase.h>

class BackupNegmax : BackupBase {
  public:
    BackupNegmax();
    virtual void backup(SearchNode &node, Reward defaultPolicyScore, double currentPlayer) override;

  private:
    int currentPlayer;
};