#include <BackupBase.h>

class BasicBackup : BackupBase {
  public:
    BasicBackup();
    virtual void backup(SearchNode &node, Reward defaultPolicyScore) override;
};