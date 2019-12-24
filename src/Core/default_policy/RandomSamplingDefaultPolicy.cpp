#include <RandomSamplingDefaultPolicy.h>
#include <cassert>
#include <random>
#include <vector>

RandomSamplingDefaultPolicy::RandomSamplingDefaultPolicy(EnvironmentInterface &environment)
    : DefaultPolicyBase(environment){};

Reward RandomSamplingDefaultPolicy::defaultPolicy(State state) {
    std::vector<State> validChildStates = _environment.GetValidChildStates(state);
    int i_random;

    while (!_environment.IsTerminal(state)) {

        if (validChildStates.size() < 1) {
            break;
        }

        std::uniform_int_distribution<int> uniformIntDistribution(0, validChildStates.size() - 1);
        i_random = uniformIntDistribution(generator);
        state = validChildStates[i_random];
        validChildStates = _environment.GetValidChildStates(state);
    }

    return (_environment.EvaluateRewardFunction(state));
}
