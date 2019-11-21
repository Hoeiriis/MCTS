#include <TicTacToeDefaultPolicy.h>
#include <random>

TicTacToeDefaultPolicy::TicTacToeDefaultPolicy(std::function<std::vector<State>(State &)> &getValidChildStates,
                                               std::function<Reward(State &)> &evaluateTerminalState)
    : DefaultPolicyBase(getValidChildStates, evaluateTerminalState){};

double TicTacToeDefaultPolicy::defaultPolicy(State state) {
    std::vector<State> validChildStates = this->getValidChildStates(state);


    while (!validChildStates.empty()) {
        // Checking if any of the valid std::vector<State> are terminal (have no valid child std::vector<State>)
        for (auto &childState : validChildStates) {
            if ((this->getValidChildStates(childState)).empty()) {
                return (this->evaluateTerminalState(childState));
            }
        }
        // If there is no terminal child choose a state randomly
        std::uniform_int_distribution<int> uniformIntDistribution(0, validChildStates.size());
        int i_random = uniformIntDistribution(generator);
        state = validChildStates[i_random];
        validChildStates = this->getValidChildStates(state);
    }

    return (this->evaluateTerminalState(state));
};
