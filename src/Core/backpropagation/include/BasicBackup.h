#include <BackupBase.h>

class BasicBackup : BackupBase {
  public:
    BasicBackup();
    ~BasicBackup();
    void backup(SearchNode &node, Reward defaultPolicyScore);
};