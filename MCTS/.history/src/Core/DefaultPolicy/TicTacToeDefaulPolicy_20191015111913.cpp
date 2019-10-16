#include <TicTacToeDefaultPolicy.h>

TicTacToeDefaultPolicy::TicTacToeDefaultPolicy(function<States(State&)>& getValidChildStates,
                                               function<Reward(State&)>& evaluateTerminalState):
                                               DefaultPolicy(getValidChildStates),
                                               DefaultPolicy(evaluateTerminalState){}


double TicTacToeDefaultPolicy::defaultPolicy(State::State state){
    States validStates = this.getValidChildStates(state)
    int i;
    std::srand((int)time(0);

    while (validStates.size() != 0){

        //iterate through valid states one by one 
            //get valid child states
            //check if there is no valid children
                // evaluate that terminal state

            //else:
            i=rand()%validStates.size();
            state = validStates[i];
            validStates = this.getValidChildStates(state);
    }

    return (this.evaluateTerminalState(state));
}