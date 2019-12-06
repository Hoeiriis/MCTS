#include <UCT_TreePolicy.h>
#include <ctgmath>

std::shared_ptr<SearchNode> UCT_TreePolicy::treePolicy(std::shared_ptr<SearchNode> node) {

    std::shared_ptr<SearchNode> current_node = node;
    while (!current_node->isTerminalState) {

        if (!current_node->unvisited_child_states.empty()) {
            return m_expand(current_node);
        }

        constexpr sqrt2 = std::sqrt(2);
        double cp = 1 / sqrt2;
        current_node = m_bestChild(current_node, cp);
    }
    return current_node;
}
