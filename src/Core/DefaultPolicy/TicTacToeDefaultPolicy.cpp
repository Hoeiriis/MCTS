#include <TicTacToeDefaultPolicy.h>
#include <optional>

TicTacToeDefaultPolicy::TicTacToeDefaultPolicy(std::function<std::vector<State>(State &)>&getValidChildStates,
                                               std::function<Reward(State &)>&evaluateTerminalState)
    : DefaultPolicyBase(getValidChildStates, evaluateTerminalState){};

double TicTacToeDefaultPolicy::defaultPolicy(State state) {
    std::vector<State> validChildStates = this->getValidChildStates(state);
    std::srand((int)time(0));

    while (validChildStates.size() != 0) {
        // Checking if any of the valid std::vector<State> are terminal (have no valid child std::vector<State>)
        for (auto& childState : validChildStates) {
            if ((this->getValidChildStates(childState)).size() == 0) {
                return (this->evaluateTerminalState(childState));
            }
        }
        // If there is no terminal child choose a state randomly
        int i = std::rand() % validChildStates.size();
        state = validChildStates[i];
        validChildStates = this->getValidChildStates(state);
    }

    return (this->evaluateTerminalState(state));
};
