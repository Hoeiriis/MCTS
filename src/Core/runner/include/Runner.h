#ifndef MCTS_LIBRARY_RUNNER_H
#define MCTS_LIBRARY_RUNNER_H

#include <MCTSInterface.h>

class Runner {
  public:
    Runner(MCTSInterface &mctsAlgorithm);

    virtual void run(int n_games, int n_simulations) = 0;

  protected:
    MCTSInterface &mctsAlgorithm;
    int gamesRan = 0;
    virtual void runOneGame(int, int) = 0;
};

#endif // MCTS_LIBRARY_RUNNER_H