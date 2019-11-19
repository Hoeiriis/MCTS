#include <BackupBase.h>

class BasicBackup : BackupBase {
  public:
    BasicBackup();
    void backup(std::shared_ptr<SearchNode> node, Reward defaultPolicyScore);
};