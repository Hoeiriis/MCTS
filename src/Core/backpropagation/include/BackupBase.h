#include <EnvironmentBase.h>
#include <SearchNode.h>

class BackupBase {
  public:
    BackupBase();
    ~BackupBase();
    virtual void backup(SearchNode &node, Reward defaultPolicyScore) = 0;

  protected:
    void getAncestors(SearchNode *, std::vector<SearchNode *> &);
};