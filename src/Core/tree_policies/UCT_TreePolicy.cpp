#include <UCT_TreePolicy.h>

std::shared_ptr<SearchNode> UCT_TreePolicy::treePolicy(SearchNode *node) {

    SearchNode *current_node = node;
    while (!current_node->isTerminalState) {

        if (!current_node->unvisited_child_states.empty()) {
            return m_expand(current_node);
        }

        current_node = m_bestChild(current_node).get();
    }
    std::shared_ptr<SearchNode> node_to_return = std::make_shared<SearchNode>(std::move(*current_node));
    return node_to_return;
}
