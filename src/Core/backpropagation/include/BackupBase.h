#include <EnvironmentBase.h>
#include <SearchNode.h>

class BackupBase {
  public:
    BackupBase(){};
    ~BackupBase();

    void backup(SearchNode &node, Reward defaultPolicyScore);
    void backup(SearchNode &node, Reward defaultPolicyScore, double currentPlayer);

  protected:
    std::vector<SearchNode *> ancestors = {};

    static std::vector<SearchNode *> getAncestors(SearchNode *, std::vector<SearchNode *>);
};