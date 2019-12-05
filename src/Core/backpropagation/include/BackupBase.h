#ifndef MCTS_LIBRARY_BACKUP_BASE
#define MCTS_LIBRARY_BACKUP_BASE

#include <EnvironmentBase.h>
#include <SearchNode.h>

class BackupBase {
  public:
    BackupBase();

  protected:
    void getAncestors(SearchNode *, std::vector<SearchNode *> &);
};

#endif // MCTS_LIBRARY_BACKUP_BASE