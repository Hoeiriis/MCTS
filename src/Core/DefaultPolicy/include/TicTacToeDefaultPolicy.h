#ifndef MCTS_LIBRARY_TICTACTOEDEFAULTPOLICY_H
#define MCTS_LIBRARY_TICTACTOEDEFAULTPOLICY_H

#include <DefaultPolicyBase.h>

class TicTacToeDefaultPolicy : DefaultPolicyBase {
  public:
    TicTacToeDefaultPolicy(boost::function<States(State<boost::any> &)> &getValidChildStates,
                           boost::function<Reward(State<boost::any> &)> &evaluateTerminalState);
    virtual Reward defaultPolicy(State<boost::any>) override;

  private:
    States validStates;
};

#endif // MCTS_LIBRARY_TICTACTOEDEFAULTPOLICY_H