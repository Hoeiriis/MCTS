#include <RandomSamplingDefaultPolicy.h>
#include <vector>
#include <random>

RandomSamplingDefaultPolicy::RandomSamplingDefaultPolicy(
    std::function<std::vector<State>(State &)> &getValidChildStates,
    std::function<Reward(State &)> &evaluateTerminalState)
    : DefaultPolicyBase(getValidChildStates, evaluateTerminalState){};

Reward RandomSamplingDefaultPolicy::defaultPolicy(State state) {
    std::vector<State> validChildStates = this->getValidChildStates(state);
    int i_random;

    while (!validChildStates.empty()) {
        std::uniform_int_distribution<int> uniformIntDistribution(0, validChildStates.size());
        i_random = uniformIntDistribution(generator);
        state = validChildStates[i_random];
        validChildStates = this->getValidChildStates(state);
    }

    return (this->evaluateTerminalState(state));
};