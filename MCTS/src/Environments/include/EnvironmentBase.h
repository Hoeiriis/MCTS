#ifndef MCTS_LIBRARY_ENVIRONMENTBASE_H
#define MCTS_LIBRARY_ENVIRONMENTBASE_H
#include <State.h>
#include <stdexcept>
#include <vector>

typedef double Reward;

/**
 * @brief      Defines barebones requirements for an environment
 *
 *
 *
 * @return     Environmentbase
 */
template <typename T> class EnvironmentBase {
public:
  EnvironmentBase();

  /**
   * @brief      Get the initial environment state
   *
   * @details    Every environment must define a starting state
   *
   * @return     State
   */
  virtual State<T> GetStartState() = 0;
  virtual std::vector<State<T>> GetValidChildStates(State<T>) = 0;
  virtual Reward EvaluateTerminalState() = 0;
};

#endif // MCTS_LIBRARY_ENVIRONMENTBASE_H
