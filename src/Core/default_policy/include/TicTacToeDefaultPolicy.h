#ifndef MCTS_LIBRARY_TICTACTOEDEFAULTPOLICY_H
#define MCTS_LIBRARY_TICTACTOEDEFAULTPOLICY_H

#include <DefaultPolicyBase.h>

class TicTacToeDefaultPolicy : DefaultPolicyBase {
  public:
    TicTacToeDefaultPolicy(std::function<std::vector<State>(State &)> &getValidChildStates,
                           std::function<Reward(State &)> &evaluateTerminalState);
    Reward defaultPolicy(State) override;

  private:
    std::vector<State> validStates;
};

#endif // MCTS_LIBRARY_TICTACTOEDEFAULTPOLICY_H
