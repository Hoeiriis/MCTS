#include <UCT_TreePolicy.h>

SearchNode UCT_TreePolicy::treePolicy(SearchNode &node) {

    SearchNode &current_node = node;
    while (current_node.isTerminalState) {

        if (current_node.unvisited_child_states.size() != 0) {
            SearchNode expanded_node = m_expand(current_node);
            return expanded_node;
        }

        current_node = m_bestChild(current_node);
    }
    return current_node;
}
