#ifndef MCTS_LIBRARY_DEFAULTPOLICYBASE_H
#define MCTS_LIBRARY_DEFAULTPOLICYBASE_H

#include <State.h>
#include <TicTacToeEnvironment.h>
#include <functional>
#include <random>

class DefaultPolicyBase {
  public:
    explicit DefaultPolicyBase(EnvironmentInterface &environment);

    virtual Reward defaultPolicy(State) = 0;

  protected:
    EnvironmentInterface &_environment;
    std::mt19937 generator;
};

#endif // MCTS_LIBRARY_DEFAULTPOLICYBASE_H
