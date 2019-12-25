#include <RandomSamplingDefaultPolicy.h>
#include <random>
#include <vector>

RandomSamplingDefaultPolicy::RandomSamplingDefaultPolicy(EnvironmentInterface &environment)
    : DefaultPolicyBase(environment){};

Reward RandomSamplingDefaultPolicy::defaultPolicy(State state) {
    std::vector<State> validChildStates = _environment.GetValidChildStates(state);
    bool isTerminal = _environment.IsTerminal(state);
    int i_random;

    while (!validChildStates.empty() && !isTerminal) {


        // Choose new child state
        std::uniform_int_distribution<int> uniformIntDistribution(0, validChildStates.size() - 1);
        i_random = uniformIntDistribution(generator);
        state = validChildStates[i_random];

        // Fetch info from the new child state
        validChildStates = _environment.GetValidChildStates(state);
        isTerminal = _environment.IsTerminal(state);
    }
    
    return (_environment.EvaluateRewardFunction(state));
};