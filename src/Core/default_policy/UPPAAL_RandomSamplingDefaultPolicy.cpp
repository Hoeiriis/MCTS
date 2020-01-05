#include <UPPAAL_RandomSamplingDefaultPolicy.h>
#include <random>
#include <vector>

UPPAAL_RandomSamplingDefaultPolicy::UPPAAL_RandomSamplingDefaultPolicy(EnvironmentInterface &environment)
    : DefaultPolicyBase(environment){};

Reward UPPAAL_RandomSamplingDefaultPolicy::defaultPolicy(State state) {
    std::vector<State> validChildStates = _environment.GetValidChildStates(state);
    bool isTerminal = _environment.IsTerminal(state);
    int i_random;
    int states_unrolled = 0;


    // run default policy until we hit a terminal node or a node with no children or we have unrolled 50 nodes
    while (states_unrolled < 50 && (!validChildStates.empty()) && (!isTerminal)) {
        std::uniform_int_distribution<int> uniformIntDistribution(0, validChildStates.size() - 1);
        i_random = uniformIntDistribution(generator);
        state = validChildStates[i_random];

        // Fetch info from the new child state
        validChildStates = _environment.GetValidChildStates(state);
        isTerminal = _environment.IsTerminal(state);
        states_unrolled++;
    }
    
    return (_environment.EvaluateRewardFunction(state));
}
