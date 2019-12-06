#include <EnvironmentBase.h>
#include <SearchNode.h>

class BackupBase {
  public:
    BackupBase()= default;;
    virtual void backup(std::shared_ptr<SearchNode> node, Reward defaultPolicyScore)=0;

  protected:
    void getAncestors(SearchNode *, std::vector<SearchNode *> &);
};