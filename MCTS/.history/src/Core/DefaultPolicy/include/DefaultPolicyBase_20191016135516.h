#ifndef MCTS_LIBRARY_DEFAULTPOLICYBASE_H
#define MCTS_LIBRARY_DEFAULTPOLICYBASE_H

#include <TicTacToeEnvironment.h>
#include <State.h>
#include <boost/function.hpp>

typedef std::vector<State::State> States;

class DefaultPolicyBase
{
    public:
        DefaultPolicyBase(boost::function<States(State::State&)>& getValidChildStates,
                          boost::function<Reward(State::State&)>& evaluateTerminalState);
        ~DefaultPolicyBase();

        virtual double defaultPolicy(State)=0;
        
    protected:
        boost::function<States(State::State&)> getValidChildStates;
        boost::function<Reward(State::State&)> evaluateTerminalState;

};

#endif //MCTS_LIBRARY_DEFAULTPOLICYBASE_H