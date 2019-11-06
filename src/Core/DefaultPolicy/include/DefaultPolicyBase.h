#ifndef MCTS_LIBRARY_DEFAULTPOLICYBASE_H
#define MCTS_LIBRARY_DEFAULTPOLICYBASE_H

#include <State.h>
#include <TicTacToeEnvironment.h>
#include <boost/function.hpp>

typedef std::vector<State> States;

class DefaultPolicyBase {
  public:
    DefaultPolicyBase(boost::function<States(State &)> &getValidChildStates,
                      boost::function<Reward(State &)> &evaluateTerminalState);

    virtual Reward defaultPolicy(State) = 0;

  protected:
    boost::function<States(State &)> getValidChildStates;
    boost::function<Reward(State &)> evaluateTerminalState;
};

#endif // MCTS_LIBRARY_DEFAULTPOLICYBASE_H
