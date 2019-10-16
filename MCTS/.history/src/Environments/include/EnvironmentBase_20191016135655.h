#ifndef MCTS_LIBRARY_ENVIRONMENTBASE_H
#define MCTS_LIBRARY_ENVIRONMENTBASE_H
#include <vector>

typedef double Reward;
//typedef std::vector<double> State;

class EnvironmentBase {
public:
  EnvironmentBase() {}
  State GetStartState();
  std::vector<State> GetValidChildStates(State);
  Reward EvaluateTerminalState();
};

#endif // MCTS_LIBRARY_ENVIRONMENTBASE_H
