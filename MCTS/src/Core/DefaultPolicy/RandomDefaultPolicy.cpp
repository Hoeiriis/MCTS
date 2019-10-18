#include <vector>
#include <RandomDefaultPolicy.h>

RandomDefaultPolicy::RandomDefaultPolicy(boost::function<States(State<boost::any>&)>& getValidChildStates, 
                                         boost::function<Reward(State<boost::any>&)>& evaluateTerminalState):
                                         DefaultPolicyBase(getValidChildStates,evaluateTerminalState){};

Reward RandomDefaultPolicy::defaultPolicy(State<boost::any> state){
    States validStates = this->getValidChildStates(state);
    int i;
    std::srand((int)time(0));

    while (validStates.size() != 0){
        i=std::rand()%validStates.size();
        state = validStates[i];
        validStates = this->getValidChildStates(state);
    }

    return (this->evaluateTerminalState(state));
};