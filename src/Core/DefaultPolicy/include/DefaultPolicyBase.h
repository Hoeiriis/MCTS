#ifndef MCTS_LIBRARY_DEFAULTPOLICYBASE_H
#define MCTS_LIBRARY_DEFAULTPOLICYBASE_H

#include <TicTacToeEnvironment.h>
#include <State.h>
#include <boost/function.hpp>
#include <boost/any.hpp>

typedef std::vector<State> States;

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

};

#endif //MCTS_LIBRARY_DEFAULTPOLICYBASE_H
