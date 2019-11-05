#include <RandomDefaultPolicy.h>
#include <vector>

RandomDefaultPolicy::RandomDefaultPolicy(boost::function<States(State &)> &getValidChildStates,
                                         boost::function<Reward(State &)> &evaluateTerminalState)
    : DefaultPolicyBase(getValidChildStates, evaluateTerminalState){};

Reward RandomDefaultPolicy::defaultPolicy(State state) {
    States validStates = this->getValidChildStates(state);
    int i;
    std::srand((int)time(0));

    while (validStates.size() != 0) {
        i = std::rand() % validStates.size();
        state = validStates[i];
        validStates = this->getValidChildStates(state);
    }

    return (this->evaluateTerminalState(state));
};
