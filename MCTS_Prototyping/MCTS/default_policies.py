import numpy as np

def default_policy_factory(get_valid_child_states, evaluate_terminal_state):

    def default_policy(state):
        valid_states=get_valid_child_states(state)
        
        while valid_states.size!=0:
            i=np.random.choice(len(valid_states))
            state=valid_states[i]
            valid_states=get_valid_child_states(state)

        return evaluate_terminal_state(state)

    return default_policy