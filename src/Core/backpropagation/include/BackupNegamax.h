#include <BackupBase.h>

class BackupNegmax : BackupBase {
  public:
    BackupNegmax();
    ~BackupNegmax();
    void backup(SearchNode *node, Reward defaultPolicyScore, double currentPlayer);

  private:
    double currentPlayer;
};