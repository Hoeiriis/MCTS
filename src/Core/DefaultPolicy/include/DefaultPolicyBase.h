#ifndef MCTS_LIBRARY_DEFAULTPOLICYBASE_H
#define MCTS_LIBRARY_DEFAULTPOLICYBASE_H

#include <State.h>
#include <TicTacToeEnvironment.h>
#include <boost/any.hpp>
#include <boost/function.hpp>

typedef std::vector<State<boost::any>> States;

class DefaultPolicyBase {
  public:
    DefaultPolicyBase(boost::function<States(State<boost::any> &)> &getValidChildStates,
                      boost::function<Reward(State<boost::any> &)> &evaluateTerminalState);
    virtual Reward defaultPolicy(State<boost::any>) = 0;

  protected:
    boost::function<States(State<boost::any> &)> getValidChildStates;
    boost::function<Reward(State<boost::any> &)> evaluateTerminalState;
};

#endif // MCTS_LIBRARY_DEFAULTPOLICYBASE_H