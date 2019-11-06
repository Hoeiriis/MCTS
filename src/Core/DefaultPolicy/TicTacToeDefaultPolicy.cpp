#include <TicTacToeDefaultPolicy.h>
#include <optional>

TicTacToeDefaultPolicy::TicTacToeDefaultPolicy(boost::function<States(State &)> &getValidChildStates,
                                               boost::function<Reward(State &)> &evaluateTerminalState)
    : DefaultPolicyBase(getValidChildStates, evaluateTerminalState){};

Reward TicTacToeDefaultPolicy::defaultPolicy(State state) {
    //States *validChildStates = &(this->getValidChildStates(state));
    States validChildStates = this->getValidChildStates(state);
    std::srand((int)time(0));

    while (validChildStates.size() != 0) {
        // Checking if any of the valid states are terminal (have no valid child states)
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
