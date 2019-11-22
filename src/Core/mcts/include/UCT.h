#ifndef MCTS_LIBRARY_UCT_H
#define MCTS_LIBRARY_UCT_H

#include <MCTSInterface.h>

class UCT : MCTSInterface {
  public:
    UCT(EnvironmentBase &environement);
};

#endif // MCTS_LIBRARY_UCT_H
