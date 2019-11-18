#ifndef MCTS_LIBRARY_DEFAULTPOLICYBASE_H
#define MCTS_LIBRARY_DEFAULTPOLICYBASE_H

#include <State.h>
#include <TicTacToeEnvironment.h>
#include <boost/function.hpp>

class DefaultPolicyBase {
  public:
    DefaultPolicyBase(std::function<std::vector<State>(State &)> &getValidChildStates,
                      std::function<Reward(State &)> &evaluateTerminalState);

    virtual Reward defaultPolicy(State) = 0;

  protected:
    std::function<std::vector<State>(State &)> &getValidChildStates;
    std::function<Reward(State &)> &evaluateTerminalState;
};

#endif // MCTS_LIBRARY_DEFAULTPOLICYBASE_H
