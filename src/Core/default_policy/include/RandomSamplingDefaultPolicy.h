#ifndef MCTS_LIBRARY_RANDOMDEFAULTPOLICY_H
#define MCTS_LIBRARY_RANDOMDEFAULTPOLICY_H

#include <DefaultPolicyBase.h>

class RandomSamplingDefaultPolicy : DefaultPolicyBase {
  public:
    explicit RandomSamplingDefaultPolicy(EnvironmentInterface &environment);
    ~RandomSamplingDefaultPolicy() = default;

    Reward defaultPolicy(State) override;

  private:
    std::vector<State> validStates;
};

#endif // MCTS_LIBRARY_RANDOMDEFAULTPOLICY_H