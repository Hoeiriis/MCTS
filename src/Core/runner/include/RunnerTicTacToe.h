#ifndef MCTS_LIBRARY_RUNNERTICTACTOE_H
#define MCTS_LIBRARY_RUNNERTICTACTOE_H
#include <Runner.h>

class RunnerTicTacToe : Runner {
  public:
    RunnerTicTacToe(MCTSBase &mctsAlgorithm);

    virtual void runOneGame(int) override;
    virtual void run(int, int) override;

  private:
    bool draw = false;
    short player1 = 0;
    short player2 = 0;
};

#endif // MCTS_LIBRARY_RUNNERTICTACTOE_H