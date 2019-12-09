#ifndef MCTS_LIBRARY_RUNNERTICTACTOE_H
#define MCTS_LIBRARY_RUNNERTICTACTOE_H
#include <Runner.h>

class RunnerTicTacToe : Runner {
  public:
    RunnerTicTacToe(MCTSInterface &mctsAlgorithm);
    virtual void run(int n_games, int n_simulations) override;

  private:
    bool draw = false;
    short player1 = 0;
    short player2 = 0;
    virtual void runOneGame(int n_games, int n_simulations) override;
};

#endif // MCTS_LIBRARY_RUNNERTICTACTOE_H