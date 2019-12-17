#include <UCT_TreePolicy.h>
#include <ctgmath>

std::shared_ptr<SearchNode> UCT_TreePolicy::treePolicy(std::shared_ptr<SearchNode> node) {

    std::shared_ptr<SearchNode> current_node = node;
    while (!current_node->isTerminalState) {

        if (!current_node->unvisited_child_states.empty()) {
            return m_expand(current_node);
        }

        // 0.7071067811865475 = 1 / sqrt(2) which is the default cp value
        current_node = m_bestChild(current_node, 0.7071067811865475);
    }
    return current_node;
}

UCT_TreePolicy::~UCT_TreePolicy() {}
