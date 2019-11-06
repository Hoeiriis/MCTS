#ifndef MCTS_LIBRARY_RANDOMDEFAULTPOLICY_H
#define MCTS_LIBRARY_RANDOMDEFAULTPOLICY_H

#include <DefaultPolicyBase.h>

typedef std::vector<State> States;

class RandomSamplingDefaultPolicy : DefaultPolicyBase {
  public:
    RandomSamplingDefaultPolicy(boost::function<States(State &)> &getValidChildStates,
                        boost::function<Reward(State &)> &evaluateTerminalState);
    virtual Reward defaultPolicy(State) override;

  private:
    States validStates;
};

#endif // MCTS_LIBRARY_RANDOMDEFAULTPOLICY_H