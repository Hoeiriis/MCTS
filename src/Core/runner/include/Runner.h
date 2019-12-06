#ifndef MCTS_LIBRARY_RUNNER_H
#define MCTS_LIBRARY_RUNNER_H

#include <MCTSBase.h>

class Runner {
  public:
    Runner(MCTSBase &mctsAlgorithm);

    virtual void runOneGame(int) = 0;
    virtual void run(int, int) = 0;

  protected:
    MCTSBase &mctsAlgorithm;
    int gamesRan = 0;
  
};

#endif // MCTS_LIBRARY_RUNNER_H