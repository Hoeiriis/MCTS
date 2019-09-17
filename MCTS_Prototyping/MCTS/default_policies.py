import numpy as np


def random(get_valid_child_states, evaluate_terminal_state):

    def _random(state):
        valid_states=get_valid_child_states(state)
        
        while valid_states.size!=0:
            i=np.random.choice(len(valid_states))
            state=valid_states[i]
            valid_states=get_valid_child_states(state)

        return evaluate_terminal_state(state)

    return _random


def tictactoe_1(get_valid_child_states, evaluate_terminal_state):
    
    def _tictactoe_1(state):
        valid_states = get_valid_child_states(state)

        while valid_states.size != 0:

            # look at the valid child states and see if any is a terminal state. If yes, choose that
            for _state in valid_states:
                valid_child_states = get_valid_child_states(_state)
                if valid_child_states.size == 0:
                    state = _state
                    return evaluate_terminal_state(state)
            # if not choose a random state
            else:
                i = np.random.choice(len(valid_states))
                state = valid_states[i]
            valid_states = get_valid_child_states(state)

        return evaluate_terminal_state(state)
    
    return _tictactoe_1
