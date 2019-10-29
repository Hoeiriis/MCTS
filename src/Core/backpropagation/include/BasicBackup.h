#include <BackupBase.h>

class BasicBackup : BackupBase {
  public:
    BasicBackup();
    ~BasicBackup();
    virtual void backup(SearchNode &node, Reward defaultPolicyScore) override;
};