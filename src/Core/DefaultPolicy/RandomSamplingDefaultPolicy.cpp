#include <RandomSamplingDefaultPolicy.h>
#include <vector>

RandomSamplingDefaultPolicy::RandomSamplingDefaultPolicy(std::function<std::vector<State>(State &)>&getValidChildStates,
                                                         std::function<Reward(State &)>&evaluateTerminalState)
    : DefaultPolicyBase(getValidChildStates, evaluateTerminalState){};

Reward RandomSamplingDefaultPolicy::defaultPolicy(State state) {
    std::vector<State> validStates = this->getValidChildStates(state);
    int i;
    std::srand((int)time(0));

    while (validStates.size() != 0) {
        i = std::rand() % validStates.size();
        state = validStates[i];
        validStates = this->getValidChildStates(state);
    }

    return (this->evaluateTerminalState(state));
};