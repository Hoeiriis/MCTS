#include <BackupBase.h>

class BackupNegmax : BackupBase {
  public:
    BackupNegmax();
    ~BackupNegmax();
    virtual void backup(SearchNode &node, Reward defaultPolicyScore, double currentPlayer);

  private:
    double currentPlayer;
};