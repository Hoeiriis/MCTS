from anytree import Node


def get_state_transitions(terminal_node):
    return _get_states(terminal_node, [])


def _get_states(node, state_list):
    state_list.append(node.state)
    parent = node.parent

    if parent is not None:
        _get_states(parent, state_list)

    return state_list

