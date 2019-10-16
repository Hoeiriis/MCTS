#include <TicTacToeDefaultPolicy.h>

TicTacToeDefaultPolicy::TicTacToeDefaultPolicy(function<States(State&)>& getValidChildStates,
                                               function<Reward(State&)>& evaluateTerminalState):
                                               DefaultPolicy(getValidChildStates),
                                               DefaultPolicy(evaluateTerminalState){}


double TicTacToeDefaultPolicy::defaultPolicy(State::State state){
    States validStates = this.getValidChildStates(state);
    States validChildStates;
    State tempState;

    std::srand((int)time(0);

    while (validStates.size() != 0){

        // Check if any of the valid states is terminal (has no valid child states)
        for (int i=0;i<validStates.size();i++){
            tempState=validStates[i];
            validChildStates=this.getValidChildStates(tempState);
            if (validChildStates.size()==0)
                return (this.evaluateTerminalState(tempState));
        }
        //If there is no terminal child choose a state randomly
        int i;
        i=rand()%validStates.size();
        tempState=validStates[i];
        validStates=this.getValidChildStates(tempState);

    }

    return (this.evaluateTerminalState(state));
}