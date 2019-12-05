#include <UCT.h>

UCT::UCT(EnvironmentBase &environment) : MCTSInterface(environment), generator(std::mt19937(time(nullptr))){};

std::shared_ptr<SearchNode> UCT::m_tree_policy(std::shared_ptr<SearchNode> node) { return m_tpolicy.treePolicy(node); };

Reward UCT::m_default_policy(State &state) { return m_defaultPolicy.defaultPolicy(state); };

std::shared_ptr<SearchNode> UCT::m_best_child(std::shared_ptr<SearchNode> node, double c) {
    int best_child = 0;
    double best_score_so_far = -1;

    for (int i = 0; i < node->child_nodes.size(); i++) {
        auto child = node->child_nodes.at(i);
        double score = (child->score / (child->visits + 0.000000001)) +
                       c * std::sqrt((std::log(node->visits) / (child->visits + 0.000000001)));

        if (score > best_score_so_far) {
            best_score_so_far = score;
            best_child = i;
        } else if (score == best_score_so_far) {
            // randomly choose which become the new best
            std::uniform_int_distribution<int> uniformIntDistribution(0, 1);
            int coin_flip = uniformIntDistribution(generator);

            if (coin_flip) {
                best_score_so_far = score;
                best_child = i;
            }
        }
    }

    return node->child_nodes.at(best_child);
};

void UCT::m_backpropagation(std::shared_ptr<SearchNode> node, Reward score) { return m_backup.backup(node, score); }

std::shared_ptr<SearchNode> UCT::m_expand(std::shared_ptr<SearchNode> node) {
    // Get unvisited state randomly
    std::uniform_int_distribution<int> uniformIntDistribution(0, node->unvisited_child_states.size());
    int i_random = uniformIntDistribution(generator);

    State expanded_state = node->unvisited_child_states.at(i_random);

    // Create node from unvisited state
    auto is_terminal = m_environment.GetValidChildStates(expanded_state).empty();
    auto expanded_node = SearchNode::create_SearchNode(node, expanded_state, is_terminal);

    // Remove the state from unvisited states
    node->unvisited_child_states.erase(node->unvisited_child_states.begin() + i_random);

    return expanded_node;
}
