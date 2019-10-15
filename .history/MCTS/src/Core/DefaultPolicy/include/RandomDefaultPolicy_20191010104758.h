#ifndef MCTS_LIBRARY_RANDOMDEFAULTPOLICY_H
#define MCTS_LIBRARY_RANDOMDEFAULTPOLICY_H

#include <DefaultPolicyBase.h>

typedef std::vector<State> States;

class RandomDefaultPolicy:DefaultPolicyBase
{
    public:
        RandomDefaultPolicy();
        ~RandomDefaultPolicy();

        virtual double function defaultPolicy() override;

    private:
        States validStates;


}

#endif //MCTS_LIBRARY_RANDOMDEFAULTPOLICY_H