def uct_factory(expand, best_child):
    def uct(node):

        expanded_node = expand(node)
        if expanded_node is None:
            return  best_child(node)

        return expanded_node
    return uct
