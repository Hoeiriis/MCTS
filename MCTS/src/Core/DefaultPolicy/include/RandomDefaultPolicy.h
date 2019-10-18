#ifndef MCTS_LIBRARY_RANDOMDEFAULTPOLICY_H
#define MCTS_LIBRARY_RANDOMDEFAULTPOLICY_H

#include <DefaultPolicyBase.h>

typedef std::vector<State<boost::any>> States;

class RandomDefaultPolicy:DefaultPolicyBase
{
    public:
        RandomDefaultPolicy(boost::function<States(State<boost::any>&)>& getValidChildStates,
                            boost::function<Reward(State<boost::any>&)>& evaluateTerminalState);
        ~RandomDefaultPolicy();

        virtual Reward defaultPolicy(State<boost::any>) override;

    private:
        States validStates;

};

#endif //MCTS_LIBRARY_RANDOMDEFAULTPOLICY_H