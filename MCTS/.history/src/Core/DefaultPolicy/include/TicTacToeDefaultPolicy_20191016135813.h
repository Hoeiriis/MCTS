#ifndef MCTS_LIBRARY_TICTACTOEDEFAULTPOLICY_H
#define MCTS_LIBRARY_TICTACTOEDEFAULTPOLICY_H

#include <DefaultPolicyBase.h>

class TicTacToeDefaultPolicy:DefaultPolicyBase
{
    public:
        TicTacToeDefaultPolicy(boost::function<States(State&)>& getValidChildStates,
                               boost::function<Reward(State&)>& evaluateTerminalState);
        ~TicTacToeDefaultPolicy();

        double defaultPolicy(State) override;

    private:
        States validStates;

};

#endif //MCTS_LIBRARY_TICTACTOEDEFAULTPOLICY_H
