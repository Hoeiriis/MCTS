#ifndef MCTS_LIBRARY_ENVIRONMENTBASE_H
#define MCTS_LIBRARY_ENVIRONMENTBASE_H
#include <vector>

typedef std::vector<double> State;

class EnvironmentBase {
public:
  virtual State GetStartState();
  virtual std::vector<State> GetValidChildStates(State);
  virtual State EvaluateTerminalState();
};

#endif // MCTS_LIBRARY_ENVIRONMENTBASE_H
