#ifndef MCTS_LIBRARY_RANDOMDEFAULTPOLICY_H
#define MCTS_LIBRARY_RANDOMDEFAULTPOLICY_H

#include <DefaultPolicyBase.h>

class RandomSamplingDefaultPolicy : DefaultPolicyBase {
  public:
    RandomSamplingDefaultPolicy(std::function<std::vector<State>(State &)> &getValidChildStates,
                                std::function<Reward(State &)> &evaluateTerminalState);
    Reward defaultPolicy(State) override;

  private:
    std::vector<State> validStates;
};

#endif // MCTS_LIBRARY_RANDOMDEFAULTPOLICY_H