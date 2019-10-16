#ifndef MCTS_LIBRARY_RANDOMDEFAULTPOLICY_H
#define MCTS_LIBRARY_RANDOMDEFAULTPOLICY_H

#include <DefaultPolicyBase.h>

typedef std::vector<State::State> States;

class RandomDefaultPolicy:DefaultPolicyBase
{
    public:
        RandomDefaultPolicy(boost::function<States(State&)>& getValidChildStates,
                            boost::function<Reward(State&)>& evaluateTerminalState);
        ~RandomDefaultPolicy();

        double defaultPolicy(State) override;

    private:
        States validStates;

};

#endif //MCTS_LIBRARY_RANDOMDEFAULTPOLICY_H