#include <EnvironmentBase.h>
#include <SearchNode.h>

// TODO check whether & or *
class BackupBase {
  public:
    BackupBase(SearchNode *node, Reward defaultPolicyScore){};
    ~BackupBase();

    virtual void backup() = 0;

  protected:
    SearchNode *node;
    Reward defaultPolicyScore;
    std::vector<SearchNode *> ancestors = {};

    static std::vector<SearchNode *> getAncestors(SearchNode *, std::vector<SearchNode *>);
};