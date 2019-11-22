#include <EnvironmentBase.h>
#include <SearchNode.h>

class BackupBase {
  public:
    BackupBase();
    void backup(std::shared_ptr<SearchNode> node, Reward defaultPolicyScore);

  protected:
    void getAncestors(SearchNode *, std::vector<SearchNode *> &);
};