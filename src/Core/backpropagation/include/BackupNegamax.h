#include <BackupBase.h>

class BackupNegmax : BackupBase {
  public:
    BackupNegmax(SearchNode *node, Reward defaultPolicyScore,double currentPlayer);
    ~BackupNegmax();
    virtual void backup() override;

  private:
    double currentPlayer;
};