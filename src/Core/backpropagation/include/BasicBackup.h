#include <BackupBase.h>

class BasicBackup : BackupBase {
  public:
    BasicBackup(SearchNode *node, Reward defaultPolicyScore);
    ~BasicBackup();
    virtual void backup() override;
};