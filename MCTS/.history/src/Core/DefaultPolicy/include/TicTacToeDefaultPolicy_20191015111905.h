#ifndef MCTS_LIBRARY_TICTACTOEDEFAULTPOLICY_H
#define MCTS_LIBRARY_TICTACTOEDEFAULTPOLICY_H

#include <DefaultPolicyBase.h>

class TicTacToeDefaultPolicy:DefaultPolicyBase
{
    public:
        TicTacToeDefaultPolicy(function<States(State&)>& getValidChildStates,
                               function<Reward(State&)>& evaluateTerminalState);
        ~TicTacToeDefaultPolicy();

        double defaultPolicy() override;

    private:
        States validStates;


}
#endif //MCTS_LIBRARY_TICTACTOEDEFAULTPOLICY_H
