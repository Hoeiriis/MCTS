#ifndef MCTS_LIBRARY_DEFAULTPOLICYBASE_H
#define MCTS_LIBRARY_DEFAULTPOLICYBASE_H

#include <TicTacToeEnvironment.h>
#include <State.h>

typedef std::vector<State::State> States;
using namespace boost;
using namespace State;

class DefaultPolicyBase
{
    public:
        //BoardState-->State ?
        DefaultPolicyBase(function<States(State&)>& getValidChildStates,
                          function<Reward(State&)>& evaluateTerminalState);
        ~DefaultPolicyBase();

        virtual double defaultPolicy()=0;
        
    protected:
        function<States(State&)> getValidChildStates;
        function<Reward(State&)> evaluateTerminalState;

}



#endif //MCTS_LIBRARY_DEFAULTPOLICYBASE_H