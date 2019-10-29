#include <TicTacToeDefaultPolicy.h>

TicTacToeDefaultPolicy::TicTacToeDefaultPolicy(boost::function<States(State<boost::any> &)> &getValidChildStates,
                                               boost::function<Reward(State<boost::any> &)> &evaluateTerminalState)
    : DefaultPolicyBase(getValidChildStates, evaluateTerminalState){};

Reward TicTacToeDefaultPolicy::defaultPolicy(State<boost::any> state) {
    States childStates = this->getValidChildStates(state);
    States validChildStates;
    // TODO check the init of tempstate
    State<boost::any> tempState(NULL);

    std::srand((int)time(0));

    while (childStates.size()) {

        // Check if any of the valid states are terminal (have no valid child states)
        for (int i = 0; i < childStates.size(); i++) {
            tempState = childStates[i];
            validChildStates = this->getValidChildStates(tempState);
            if (validChildStates.size() == 0) {
                return this->evaluateTerminalState(tempState);
            }
        }
        // If there is no terminal child choose a state randomly
        int i;
        i = std::rand() % childStates.size();
        tempState = childStates[i];
        childStates = this->getValidChildStates(tempState);
    }

    return (this->evaluateTerminalState(state));
};