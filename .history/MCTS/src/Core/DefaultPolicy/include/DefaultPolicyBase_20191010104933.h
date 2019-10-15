#ifndef MCTS_LIBRARY_DEFAULTPOLICYBASE_H
#define MCTS_LIBRARY_DEFAULTPOLICYBASE_H

#include <TicTacToeEnvironment.h>
#include <State.h>

typedef std::vector<State> States;
using namespace boost;

class DefaultPolicyBase
{
    boost::function<vector>
    public:
        //BoardState-->State ?
        DefaultPolicyBase(function<States(State&)> getValidChildStates,
                          function<Reward(State&)> evaluateTerminalState);
        ~DefaultPolicyBase();

        virtual double function defaultPolicy()=0;
        
    protected:
        function<States(State&)> getValidChildStates;
        function<Reward(State&)> evaluateTerminalState;


}



#endif //MCTS_LIBRARY_DEFAULTPOLICYBASE_H