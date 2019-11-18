#ifndef MCTS_LIBRARY_DEFAULTPOLICYBASE_H
#define MCTS_LIBRARY_DEFAULTPOLICYBASE_H

#include <State.h>
<<<<<<< HEAD
#include <TicTacToeEnvironment.h>
#include <boost/any.hpp>
=======
>>>>>>> origin/master
#include <boost/function.hpp>

typedef std::vector<State> States;

<<<<<<< HEAD
class DefaultPolicyBase {
  public:
    DefaultPolicyBase(boost::function<States(State<boost::any> &)> &getValidChildStates,
                      boost::function<Reward(State<boost::any> &)> &evaluateTerminalState);
    ~DefaultPolicyBase();
    virtual Reward defaultPolicy(State<boost::any>) = 0;
=======
class DefaultPolicyBase
{
    public:
        DefaultPolicyBase(boost::function<States(State&)>& getValidChildStates,
                          boost::function<Reward(State&)>& evaluateTerminalState);
        ~DefaultPolicyBase();

        virtual Reward defaultPolicy(State)=0;

    protected:
        boost::function<States(State&)> getValidChildStates;
        boost::function<Reward(State&)> evaluateTerminalState;
>>>>>>> origin/master

  protected:
    boost::function<States(State<boost::any> &)> getValidChildStates;
    boost::function<Reward(State<boost::any> &)> evaluateTerminalState;
};

<<<<<<< HEAD
#endif // MCTS_LIBRARY_DEFAULTPOLICYBASE_H
=======
#endif //MCTS_LIBRARY_DEFAULTPOLICYBASE_H
>>>>>>> origin/master
