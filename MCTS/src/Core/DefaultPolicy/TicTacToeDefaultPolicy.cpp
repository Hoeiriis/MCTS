#include <TicTacToeDefaultPolicy.h>

TicTacToeDefaultPolicy::TicTacToeDefaultPolicy(boost::function<States(State<boost::any>&)>& getValidChildStates,
                                               boost::function<Reward(State<boost::any>&)>& evaluateTerminalState):
                                               DefaultPolicyBase(getValidChildStates,evaluateTerminalState){};

double TicTacToeDefaultPolicy::defaultPolicy(State<boost::any> state){
    States validStates = this->getValidChildStates(state);
    States validChildStates;
    //TODO how to init?
    State<boost::any> tempState=state;

    std::srand((int)time(0));

    while (validStates.size() != 0){

        // Check if any of the valid states is terminal (has no valid child states)
        for (int i=0;i<validStates.size();i++){
            tempState=validStates[i];
            validChildStates=this->getValidChildStates(tempState);
            if (validChildStates.size()==0)
                return (this->evaluateTerminalState(tempState));
        }
        //If there is no terminal child choose a state randomly
        int i;
        i=std::rand()%validStates.size();
        tempState=validStates[i];
        validStates=this->getValidChildStates(tempState);

    }

    return (this->evaluateTerminalState(state));
};