#ifndef MCTS_LIBRARY_DEFAULTPOLICYBASE_H
#define MCTS_LIBRARY_DEFAULTPOLICYBASE_H

#include <TicTacToeEnvironment.h>
#include <State.h>
#include <boost/function.hpp>
#include <boost/any.hpp>

typedef std::vector<State<boost::any>> States;

class DefaultPolicyBase
{
    public:
        DefaultPolicyBase(boost::function<States(State<boost::any>&)>& getValidChildStates,
                          boost::function<Reward(State<boost::any>&)>& evaluateTerminalState);
        ~DefaultPolicyBase();

        virtual Reward defaultPolicy(State<boost::any>)=0;

    protected:
        boost::function<States(State<boost::any>&)> getValidChildStates;
        boost::function<Reward(State<boost::any>&)> evaluateTerminalState;

};

#endif //MCTS_LIBRARY_DEFAULTPOLICYBASE_H