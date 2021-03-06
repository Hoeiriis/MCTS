#ifndef MCTS_LIBRARY_BACKUP_BASE
#define MCTS_LIBRARY_BACKUP_BASE

#include <EnvironmentInterface.h>
#include <SearchNode.h>

class BackupBase {
  public:
    BackupBase() = default;
    ;

  protected:
    void getAncestors(SearchNode *, std::vector<SearchNode *> &);
};

#endif // MCTS_LIBRARY_BACKUP_BASE