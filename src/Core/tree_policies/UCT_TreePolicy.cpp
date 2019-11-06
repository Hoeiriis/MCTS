#include <UCT_TreePolicy.h>

std::shared_ptr<SearchNode> UCT_TreePolicy::treePolicy(SearchNode& node) {

    std::shared_ptr<SearchNode> current_node = std::make_shared<SearchNode>(node);
    while (!current_node->isTerminalState) {

        if (current_node->unvisited_child_states.empty()) {
            return  m_expand(*current_node);
        }

        current_node = m_bestChild(*current_node);
    }
    return current_node;
}
