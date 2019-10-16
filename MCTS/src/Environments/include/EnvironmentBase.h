#ifndef MCTS_LIBRARY_ENVIRONMENTBASE_H
#define MCTS_LIBRARY_ENVIRONMENTBASE_H
#include <vector>
#include <State.h>

typedef double Reward;

class EnvironmentBase {
public:
  EnvironmentBase();
    /**
   * @brief      Get the initial environment state
   *
   * @details    Every environment must define a starting state
   *
   * @return     State
   */
  virtual State GetStartState()=0;
  virtual std::vector<State> GetValidChildStates(State)=0;
  virtual Reward EvaluateTerminalState()=0;
};

#endif // MCTS_LIBRARY_ENVIRONMENTBASE_H
