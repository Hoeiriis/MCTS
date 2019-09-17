
def UCT_tree_policy(expand, best_child):
    def _uct(node):

        expanded_node = expand(node)
        if expanded_node is None:
            return best_child(node)

        return expanded_node
    return _uct
