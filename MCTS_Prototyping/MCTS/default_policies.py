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
