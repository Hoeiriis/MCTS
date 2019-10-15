#ifndef MCTS_LIBRARY_RANDOMDEFAULTPOLICY_H
#define MCTS_LIBRARY_RANDOMDEFAULTPOLICY_H

#include <DefaultPolicyBase.h>
//#include <State.h>

typedef std::vector<State::State> States;

class RandomDefaultPolicy:DefaultPolicyBase
{
    public:
        RandomDefaultPolicy(function<States(State&)>& getValidChildStates,
                          function<Reward(State&)>& evaluateTerminalState);
        ~RandomDefaultPolicy();

        double defaultPolicy() override;

    private:
        States validStates;


}

#endif //MCTS_LIBRARY_RANDOMDEFAULTPOLICY_H