#ifndef MCTS_LIBRARY_TICTACTOEDEFAULTPOLICY_H
#define MCTS_LIBRARY_TICTACTOEDEFAULTPOLICY_H

#include <DefaultPolicyBase.h>

<<<<<<< HEAD
class TicTacToeDefaultPolicy : DefaultPolicyBase {
  public:
    TicTacToeDefaultPolicy(boost::function<States(State<boost::any> &)> &getValidChildStates,
                           boost::function<Reward(State<boost::any> &)> &evaluateTerminalState);
    virtual Reward defaultPolicy(State<boost::any>) override;
=======
class TicTacToeDefaultPolicy:DefaultPolicyBase
{
    public:
        TicTacToeDefaultPolicy(boost::function<States(State&)>& getValidChildStates,
                               boost::function<Reward(State&)>& evaluateTerminalState);
        ~TicTacToeDefaultPolicy();

        virtual Reward defaultPolicy(State) override;

    private:
        States validStates;
>>>>>>> master

  private:
    States validStates;
};

<<<<<<< HEAD
#endif // MCTS_LIBRARY_TICTACTOEDEFAULTPOLICY_H
=======
#endif //MCTS_LIBRARY_TICTACTOEDEFAULTPOLICY_H
>>>>>>> master
