#include <TicTacToeDefaultPolicy.h>
#include <random>

TicTacToeDefaultPolicy::TicTacToeDefaultPolicy(EnvironmentInterface &environment) : DefaultPolicyBase(environment){};

double TicTacToeDefaultPolicy::defaultPolicy(State state) {
    std::vector<State> validChildStates = _environment.GetValidChildStates(state);

    while (!validChildStates.empty()) {
        // Checking if any of the valid std::vector<State> are terminal (have no valid child std::vector<State>)
        for (auto &childState : validChildStates) {
            if (_environment.IsTerminal(childState)) {
                return (_environment.EvaluateRewardFunction(childState));
            }
        }
        // If there is no terminal child choose a state randomly
        std::uniform_int_distribution<int> uniformIntDistribution(0, validChildStates.size() - 1);
        int i_random = uniformIntDistribution(generator);
        state = validChildStates[i_random];
        validChildStates = _environment.GetValidChildStates(state);
    }

    return _environment.EvaluateRewardFunction(state);
};
