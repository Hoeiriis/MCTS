#ifndef MCTS_LIBRARY_TICTACTOEDEFAULTPOLICY_H
#define MCTS_LIBRARY_TICTACTOEDEFAULTPOLICY_H

#include <DefaultPolicyBase.h>

class TicTacToeDefaultPolicy : DefaultPolicyBase {
  public:
    explicit TicTacToeDefaultPolicy(EnvironmentInterface &environment);
    Reward defaultPolicy(State) override;

  private:
    std::vector<State> validStates;
};

#endif // MCTS_LIBRARY_TICTACTOEDEFAULTPOLICY_H
