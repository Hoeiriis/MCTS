#include <UCT_TreePolicy.h>

SearchNode UCT_TreePolicy::treePolicy(SearchNode &node) {

    SearchNode c_node = node;
    while (c_node.isTerminalState) {

        if (c_node.unvisited_child_states.size() != 0) {
            SearchNode expanded_node = m_expand(c_node);
            return expanded_node;
        }

        SearchNode best_child = m_bestChild(node);
        c_node = best_child;
    }
    return c_node;
}