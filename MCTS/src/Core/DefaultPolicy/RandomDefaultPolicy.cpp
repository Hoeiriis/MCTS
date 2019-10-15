#include <RandomDefaultPolicy.h>
#include <vector>
#include <time>


RandomDefaultPolicy::RandomDefaultPolicy(function<States(State&)>& getValidChildStates,
                                         function<Reward(State&)>& evaluateTerminalState):
                                         DefaultPolicy(getValidChildStates),
                                         DefaultPolicy(evaluateTerminalState){}

double RandomDefaultPolicy::defaultPolicy(State::State state){
    States validStates = this.getValidChildStates(state)
    int i;
    std::srand((int)time(0);

    while (validStates.size() != 0){
        i=rand()%validStates.size();
        state = validStates[i];
        validStates = this.getValidChildStates(state);
    }

    return (this.evaluateTerminalState(state));
}