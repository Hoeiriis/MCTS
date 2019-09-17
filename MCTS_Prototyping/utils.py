import concurrent.futures
import os

from anytree import Node


def get_state_transitions(terminal_node):
    return _get_states(terminal_node, [])


def _get_states(node, state_list):
    state_list.append(node.state)
    parent = node.parent

    if parent is not None:
        _get_states(parent, state_list)

    return state_list

def parallel(function, array, max_workers=None):
    """
    Call function on each entry in array utilising max_workers amount of cpus
    :param function:
    :param array: Collection
    :param max_workers: int, default os.cpu_count()
    :return function results over array if any, else None
    """

    if max_workers is None:
        max_workers = os.cpu_count()

    if max_workers < 2:
        return [function(func_input, idx) for idx, func_input in enumerate(array)]

    with concurrent.futures.ProcessPoolExecutor(max_workers=max_workers) as executor:
        futures = [executor.submit(function, func_input, idx) for idx, func_input in enumerate(array)]

        func_results = []

        for future in concurrent.futures.as_completed(futures):
            func_results.append(future.result())

        if any([entry is not None for entry in func_results]):
            return func_results
        else:
            return None

